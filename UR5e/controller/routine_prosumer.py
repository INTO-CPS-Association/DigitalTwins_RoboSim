#!/usr/bin/env python3
import json
from datetime import datetime
import time
import threading
from threading import Thread
import logging
import amqpstorm
from amqpstorm import Connection

logging.basicConfig(level=logging.INFO)
LOGGER = logging.getLogger()

## Co-sim properties
step_size=0.5
max_time = 20.0

rabbitmq_host = "localhost"
rabbitmq_port = 5672
rabbitmq_username = "guest"
rabbitmq_password = "guest"

class ScalableConsumer(object):
    def __init__(self, hostname='localhost',
                 username='guest', password='guest',
                 queue='',
                 port=5672,
                 exchange='',
                 routing_key='',
                 number_of_consumers=1, max_retries=None):
        self.hostname = hostname
        self.username = username
        self.password = password
        self.queue = queue
        self.number_of_consumers = number_of_consumers
        self.max_retries = max_retries
        self.port = port
        self.exchange = exchange
        self.routing_key = routing_key
        self._connection = None
        self._consumers = []
        self._stopped = threading.Event()
        self.publisher = None

    def start(self):
        """Start the Consumers.

        :return:
        """
        self._stopped.clear()
        if not self._connection or self._connection.is_closed:
            self._create_connection()
        while not self._stopped.is_set():
            try:
                # Check our connection for errors.
                self._connection.check_for_errors()
                if not self._connection.is_open:
                    raise amqpstorm.AMQPConnectionError('connection closed')
                self._update_consumers()
            except amqpstorm.AMQPError as why:
                # If an error occurs, re-connect and let update_consumers
                # re-open the channels.
                LOGGER.warning(why)
                self._stop_consumers()
                self._create_connection()
            time.sleep(1)

    def increase_consumers(self):
        """Add one more consumer.

        :return:
        """
        if self.number_of_consumers <= 20:
            self.number_of_consumers += 1

    def decrease_consumers(self):
        """Stop one consumer.

        :return:
        """
        if self.number_of_consumers > 0:
            self.number_of_consumers -= 1

    def stop(self):
        """Stop all consumers.

        :return:
        """
        while self._consumers:
            consumer = self._consumers.pop()
            consumer.stop()
        self._stopped.set()
        self._connection.close()

    def _create_connection(self):
        """Create a connection.

        :return:
        """
        attempts = 0
        while True:
            attempts += 1
            if self._stopped.is_set():
                break
            try:
                self._connection = Connection(self.hostname,
                                              self.username,
                                              self.password,
                                              port=self.port)
                break
            except amqpstorm.AMQPError as why:
                LOGGER.warning(why)
                if self.max_retries and attempts > self.max_retries:
                    raise Exception('max number of retries reached')
                time.sleep(min(attempts * 2, 30))
            except KeyboardInterrupt:
                break

    def _update_consumers(self):
        """Update Consumers.

            - Add more if requested.
            - Make sure the consumers are healthy.
            - Remove excess consumers.

        :return:
        """
        # Do we need to start more consumers.
        consumer_to_start = min(
            max(self.number_of_consumers - len(self._consumers), 0), 2
        )
        for _ in range(consumer_to_start):
            consumer = Consumer(self.queue, self.publisher,exchange=self.exchange,routing_key=self.routing_key)
            self._start_consumer(consumer)
            self._consumers.append(consumer)

        # Check that all our consumers are active.
        for consumer in self._consumers:
            if consumer.active:
                continue
            self._start_consumer(consumer)
            break

        # Do we have any overflow of consumers.
        self._stop_consumers(self.number_of_consumers)

    def _stop_consumers(self, number_of_consumers=0):
        """Stop a specific number of consumers.

        :param number_of_consumers:
        :return:
        """
        while len(self._consumers) > number_of_consumers:
            consumer = self._consumers.pop()
            consumer.stop()

    def _start_consumer(self, consumer):
        """Start a consumer as a new Thread.

        :param Consumer consumer:
        :return:
        """
        thread = threading.Thread(target=consumer.start,
                                  args=(self._connection,))
        thread.daemon = True        
        thread.start()

    def set_publisher(self,publisher):
        self.publisher = publisher


class Consumer(object):
    def __init__(self, queue, publisher, exchange='',routing_key=''):
        self.queue = queue
        self.channel = None
        self.active = False
        self.exchange = exchange
        self.routing_key = routing_key
        self.queue_inst = None
        self.publisher = publisher
        self.simstep = 0.0

    def start(self, connection):
        self.channel = None
        try:
            self.active = True
            self.channel = connection.channel()
            self.channel.basic.qos(1)
            self.channel.exchange.declare(self.exchange)
            self.channel.queue.declare(self.queue)
            self.queue_inst = self.channel.queue
            self.queue_inst.bind(queue=self.queue,exchange=self.exchange,routing_key=self.routing_key)
            self.channel.basic.consume(self, self.queue, no_ack=False)
            self.channel.start_consuming()
            if not self.channel.consumer_tags:
                # Only close the channel if there is nothing consuming.
                # This is to allow messages that are still being processed
                # in __call__ to finish processing.
                self.channel.close()
        except amqpstorm.AMQPError:
            pass
        finally:
            self.active = False

    def stop(self):
        if self.channel:
            self.channel.close()

    def __call__(self, message):
        """Process the Payload.

        :param Message message:
        :return:
        """
        print("[x] Received:", message.body, threading.current_thread())
        message.ack()
        if "waiting for input data for simulation" in str(message.body):
            pub_thread = threading.Thread(target=self.publisher.start)
            pub_thread.daemon = True
            pub_thread.start()
            #self.publisher.start()
            #pass
        else:
            try:
                self.simstep = float(json.loads(message.body)["simstep"])
                self.publisher.set_simstep(self.simstep)
            except:
                pass



class Publisher(object):
    def __init__(self, step_size, max_time, hostname='localhost',
                 username='guest', password='guest',
                 queue='',
                 port=5672,
                 exchange='',
                 routing_key=''):
        self.step_size = step_size
        self.max_time = max_time
        self.hostname = hostname
        self.username = username
        self.password = password
        self.queue = queue
        self.port = port
        self.exchange = exchange
        self.routing_key = routing_key
        self._connection = Connection(self.hostname, self.username, self.password, port=self.port)
        self._channel = self._connection.channel()
        self._channel.queue.declare(self.queue)
        #self._queue_inst = self._channel.queue
        #self._queue_inst.bind(queue=self.queue,exchange=self.exchange,routing_key=self.routing_key)
        self.simstep = 0.0
        self.internal_sim_step = 0.0

    def close_connection(self):
        self._channel.close()
        self._connection.close()
    
    def set_simstep(self,simstep):
        self.simstep = simstep

    def start(self):
        #while (self.internal_sim_step)<=(self.max_time+self.step_size): # This one works asynchronously
        while (self.simstep/1000.0)<=(self.max_time+self.step_size): # This one ensures synchronization between RMQFMU and the publisher
            self.publish()
            time.sleep(self.step_size)
            self.internal_sim_step += self.step_size
        
    def publish(self):
        dt=datetime.strptime('2019-01-04T16:41:24+0200', "%Y-%m-%dT%H:%M:%S%z")
        sim_step_seconds = self.simstep/1000.0 # Synchronously
        # sim_step_seconds = self.internal_sim_step # Asynchronously
        msg = {}
        msg['time']= dt.isoformat()    

        msg['time']= datetime.now(tz = datetime.now().astimezone().tzinfo).isoformat(timespec='milliseconds')
        #if (i==2):
        if (round(sim_step_seconds,1)> (1.0-self.step_size) and round(sim_step_seconds,1)<(1.0+self.step_size) or (sim_step_seconds==1.0)):
            msg['moveDiscreteCommand'] = True
            msg['MovementArgs_target_X'] = 0
            msg['MovementArgs_target_Y'] = 23
            msg['MovementArgs_target_Z'] = 1

        #elif (i==11):
        elif (round(sim_step_seconds,1)> (5.5-self.step_size) and round(sim_step_seconds,1)<(5.5+self.step_size)) or (sim_step_seconds==5.5):
            
            msg['moveDiscreteCommand'] = True
            msg['MovementArgs_target_X'] = 3
            msg['MovementArgs_target_Y'] = 20
            msg['MovementArgs_target_Z'] = 2

        #elif (i==16):
        elif (round(sim_step_seconds,1)> (8.0-self.step_size) and round(sim_step_seconds,1)<(8.0+self.step_size) or (sim_step_seconds==8.0)):
            msg['moveDiscreteCommand'] = True
            msg['MovementArgs_target_X'] = 8
            msg['MovementArgs_target_Y'] = 10
            msg['MovementArgs_target_Z'] = 0

        #elif (i==30):
        elif (round(sim_step_seconds,1)> (15.0-self.step_size) and round(sim_step_seconds,1)<(15.0+self.step_size) or (sim_step_seconds==15.0)):
            msg['moveDiscreteCommand'] = True
            msg['MovementArgs_target_X'] = 1
            msg['MovementArgs_target_Y'] = 13
            msg['MovementArgs_target_Z'] = 0
        else:
            msg['moveDiscreteCommand'] = False
            msg['MovementArgs_target_X'] = 0
            msg['MovementArgs_target_Y'] = 0
            msg['MovementArgs_target_Z'] = 0
            msg['closeGripperCommand'] = False
            msg['openGripperCommand'] = False


        print(" [x] Sent %s" % json.dumps(msg))   
        self._channel.basic.publish(json.dumps(msg), routing_key=self.routing_key, exchange=self.exchange)

## Enabling twins
physical_twin = False
digital_twin = True

#if __name__ == '__main__':
print('Initializing routine publisher and consumer')

consumer_listening_pt = ScalableConsumer(hostname=rabbitmq_host,
            username=rabbitmq_username, password=rabbitmq_password,
            queue='',
            exchange='fmi_digital_twin_pt',
            routing_key='data.from_cosim')

publisher_pt = Publisher(step_size, max_time, hostname=rabbitmq_host,
            username=rabbitmq_username, password=rabbitmq_password,
            queue='',
            port=5672,
            exchange='fmi_digital_twin_pt',
            routing_key='data.to_cosim')

consumer_listening_pt.set_publisher(publisher_pt)


consumer_listening_dt = ScalableConsumer(hostname=rabbitmq_host,
            username=rabbitmq_username, password=rabbitmq_password,
            queue='',
            exchange='fmi_digital_twin_dt',
            routing_key='data.from_cosim')

publisher_dt = Publisher(step_size, max_time, hostname=rabbitmq_host,
            username=rabbitmq_username, password=rabbitmq_password,
            queue='',
            port=5672,
            exchange='fmi_digital_twin_dt',
            routing_key='data.to_cosim')

consumer_listening_dt.set_publisher(publisher_dt)

def start_consumer_pt():
    consumer_listening_pt.start()

def start_consumer_dt():
    consumer_listening_dt.start()

if physical_twin:
    consuming_thread_pt = Thread(target=start_consumer_pt)
    consuming_thread_pt.daemon=True
    consuming_thread_pt.start()
    #consuming_thread_pt.join()

if digital_twin:
    consuming_thread_dt = Thread(target=start_consumer_dt)
    consuming_thread_dt.daemon=True
    consuming_thread_dt.start()
    consuming_thread_dt.join()

