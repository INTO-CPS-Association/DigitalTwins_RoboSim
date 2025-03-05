#Author: Santiago Gil

import types
'''***** ROS2 *****'''
## Be sure the Python package is installed, and the ROS2 infrastructure is installed and running
## Visit https://github.com/ros2/rclpy for more information
import rclpy
from threading import Thread

class Operation():

    def __init__(self,name="",actions=[],**kwargs):
        self.name = name
        self.actions = actions
        self.arguments = kwargs

    def update_args(self,args):
        self.arguments = args

    def update_actions(self,actions):
        self.actions = actions

    def add_arg(self,dict):
        for key,value in dict.items():
            self.arguments[key] = value

    # This method overwrites all the objects of the same class
    def add_action(self,action):
        self.actions.append(action)

    def delete_actions(self):
        self.actions = []

    def delete_args(self):
        self.arguments = {}

    def execute(self,args):
        results_actions = []
        for action in self.actions:
            action_arguments = None
            idx = self.actions.index(action)
            if idx < len(self.arguments):
                action_arguments = tuple(self.arguments["action_" + str(idx)])
            if action_arguments != None:
                result = action(*action_arguments)
            else:
                result = action()
            if result != None:
                results_actions.append(result)
            else:
                results_actions.append("")
        return results_actions



class InputEvent():
    def __init__(self,name="",equations=[],**kwargs):
        self.name = name
        self.equations = equations
        self.arguments = kwargs

    def update_args(self,args):
        self.arguments = args

    def update_equations(self,equations):
        self.equations = actions

    def add_arg(self,dict):
        for key,value in dict.items():
            self.arguments[key] = value

    ## This method overwrites all the objects of the same class
    def add_equation(self,action):
        self.equations.append(equation)

    def delete_equations(self):
        self.equations = []

    def delete_args(self):
        self.arguments = {}

    def get_event_result(self,args):
        results_equations = []
        for equation in self.equations:
            equation_arguments = None
            idx = self.equations.index(equation)
            if idx < len(self.arguments):
                equation_arguments = tuple(self.arguments["equation_" + str(idx)])
            if equation_arguments != None:
                result = equation(*equation_arguments)
            else:
                result = equation()
            if result != None:
                results_equations.append(result)
            else:
                results_equations.append("")
        return results_equations

class Mapping():

    def __init__(self,host="localhost",port=23000):
        '''ROS2-specific'''
        rclpy.init(args=None) # Update with the corresponding host network information
        self.node = rclpy.create_node('PlatformMappingInterface')

        self.robot = {} # Robot

        '''Specific to the case study'''

        #Publisher for Operations to the robot
        '''These objects are to be initialized from the mapping generator'''
        '''Publishers : to send commands to the robot endpoint'''
        # TODO 1) self.operation_pub = self.node.create_publisher(Type, 'topic', QoS)
        # ...        

        '''Subscribers : to receive data from the robot endpoint'''
        # TODO 2) self.event_sub = self.node.create_subscription(Type, 'topic', self.event_callback, QoS)
        # ...

        # Initialize based on the joints to be monitored/controlled and the corresponding data

        # Initialize the robot object with the platform mapping variables and constants (variables/constants to and from sensors and actuators, or local variables) where RobotData is a ROS2 message type
        # TODO 3) self.robot["key(i)"] = RobotData()
        # ...

        ## Here the tricky part comes in
        #Transcribe the platform mapping from the RoboSim model (manual)
        '''Actions'''
        # The functions here should be assigned according to object type and robotic platform API
        #  TODO 4) actions_operation = [self.operation_callback(),...]
        #...

        '''Equations'''
        # TODO 5) equations_event = [lambda: self.robot["key(i)"] == 0,...] 
        #...

        '''Initialization of services -> Operations and Input Events. This should be initialized automatically from the mapping generator'''
        self.operations_list = []
        self.operations = types.SimpleNamespace() # To be refined with a proper dot notation
        # TODO 6) self.operations.operation = Operation(name="operation",actions=actions_operation)
        #...
        #self.operations_list.extend([self.operations.operation,...])
 
        self.input_events_list = []
        self.input_events = types.SimpleNamespace()
        # TODO 7) self.events.event = InputEvent(name="event",equations=equations_event)
        #...
        # TODO 8) self.input_events_list.extend([self.input_events.event,...])

    def start_mapping(self):
        self._start_mapping()

    def stop_mapping(self):
        self._stop_mapping()

    def execute_operation(self,operation_name,args=None):
        exec_op = None
        #for op in self.operations: # Does not work yet
        for op in self.operations_list:
            if op.name == operation_name:
                exec_op = op
        if args != None:
            exec_op.update_args(args)
        #print("Executing operation")
        result = exec_op.execute(exec_op.arguments)
        #print("Operation executed")
        return result

    def get_event(self,input_event_name,args=None):
        event = None
        for ev in self.input_events_list:
            if ev.name == input_event_name:
                event = ev
        if args != None:
            event.update_args(args)
        #print("Reading event")
        result = event.get_event_result(event.arguments)
        #print("Event read")
        return result

    # Write callback functions for steps 4 and 5 here which are in the platform mapping model (NOT ROS2)
    #  TODO 9) def operation_callback(self, args)
    # ...

    ### Specific to the remote interface###
    '''ROS2 Implementations'''
    def _ROS_thread(self):
        rclpy.spin(self.node)

    def _start_mapping(self):
        self.ros_thread = Thread(target=self._ROS_thread)
        self.ros_thread.start()

    def _stop_mapping(self):
        rclpy.try_shutdown()
        self.ros_thread.join()

    # Write the callback functions for the ROS2 subscribers:
    # TODO 10) def event_callback(self, msg)
    # ...

    # TODO 11) Additional functions eventually required by functions above
    # ...
