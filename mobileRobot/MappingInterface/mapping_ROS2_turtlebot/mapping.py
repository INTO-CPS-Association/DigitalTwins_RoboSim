#Author: Santiago Gil

import io
import types
'''***** ROS2 *****'''
## Be sure the Python package is installed, and the ROS2 infrastructure is installed and running
## Visit https://github.com/ros2/rclpy for more information
import rclpy
from std_msgs.msg import String, Float32, Bool
from sensor_msgs.msg import LaserScan
from geometry_msgs.msg import Twist
from threading import Thread

'''***** Specific to the case study*****'''

class Operation():
    ## No need to update
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
    ## No need to update
    def __init__(self,name="",equations=[],**kwargs):
        self.name = name
        self.equations = equations
        self.arguments = kwargs

    def update_args(self,args):
        self.arguments = args

    def update_equations(self,equations):
        self.equations = equations

    def add_arg(self,dict):
        for key,value in dict.items():
            self.arguments[key] = value

    def add_equation(self,equation):
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

        '''Specific to the case study'''

        '''Publishers : to send commands to the robot endpoint'''
        self.cmd = self.node.create_publisher(Twist, '/robot1/cmd_vel', 10)

        # Add more publishers accordingly

        '''Subscribers : to receive data from the robot endpoint'''
        self.LaserScan = self.node.create_subscription(LaserScan, '/robot1/scan', self._callback_scan, 10)


        # ROS2 subscriber called
        self.subCalledDistance = False
        self.subCalledAngle = False
        # Initialize based on the joints to be monitored/controlled and the corresponding data

        self.robot = {} # Robot

        self.robot["scan"] = LaserScan()
        self.robot["move"] = Twist()

        self.MIN_RANGE = 0.2
        self.MAX_RANGE = 1.0
        self.closest_angle = 0.0
        self.closest_distance = 0.0

        '''Actions'''
        # Actions per operation defined in the RoboSim module
        actions_move = [self._set_robot_cmd]

        '''Equations'''
        # Equations per input event defined in the RoboSim module
        equations_closestAngle = [lambda: self._closestAngleEvent()]
        equations_closestDistance = [lambda: self._closestDistanceEvent()]

        '''Initialization of services -> Operations and Input Events'''
        self.operations_list = []
        self.operations = types.SimpleNamespace() # To be refined with a proper dot notation
        self.operations.move = Operation(name="move",actions=actions_move)
        self.operations_list.extend([self.operations.move,])

        self.input_events_list = []
        self.input_events = types.SimpleNamespace()
        self.input_events.closestAngle = InputEvent(name="closestAngle",equations=equations_closestAngle)
        self.input_events.closestDistance = InputEvent(name="closestDistance",equations=equations_closestDistance)
        self.input_events_list.extend([self.input_events.closestAngle,
                                     self.input_events.closestDistance,])

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

    def get_closest_angle(self):
        return self._get_closest_angle()
    
    def get_closest_distance(self):
        return self._get_closest_distance()

    ### Implementations - Update accordingly (specifically to the API of the robotic platform) ###

    '''ROS2 Implementations'''
    def _ROS_thread(self):
        rclpy.spin(self.node)

    def _start_mapping(self):
        self.ros_thread = Thread(target=self._ROS_thread)
        self.ros_thread.start()
        #rclpy.spin(self.node)

    def _stop_mapping(self):
        rclpy.try_shutdown()
        self.ros_thread.join()

    def _zero_twist(self):
        twist = Twist()
        twist.linear.x = 0.0
        twist.linear.y = 0.0
        twist.linear.z = 0.0

        twist.angular.x = 0.0
        twist.angular.y = 0.0
        twist.angular.z = 0.0
        return twist
    
    def _set_robot_cmd(self,lv,av):
        msg = self._zero_twist()
        msg.linear.x = lv
        msg.angular.z = av
        self.cmd.publish(msg)

    def _get_closest_angle(self):
        closest_distance = self.robot["scan"].range_max
        # Identify closest obstacle within the angle range of -120 to 120 degrees
        for angle_index, scan_range in enumerate(self.robot["scan"].ranges):
            # Convert the index to the corresponding angle in degrees
            angle = angle_index if angle_index <= 180 else angle_index - 360
            # Check if the angle is within the -110 to 110 degree range
            if -150 <= angle <= 150:
                # Check if the range is greater than the desired minimum (to avoid e.g. robot components) and less than the current closest distance and the maximum range
                if scan_range >= self.MIN_RANGE and scan_range < closest_distance and scan_range < self.MAX_RANGE:
                    closest_distance = scan_range                    
                    self.closest_angle = angle
                
        return self.closest_angle
    
    def _get_closest_distance(self):
        closest_distance = self.robot["scan"].range_max
        # Identify closest obstacle within the angle range of -120 to 120 degrees
        for angle_index, scan_range in enumerate(self.robot["scan"].ranges):
            # Convert the index to the corresponding angle in degrees
            angle = angle_index if angle_index <= 180 else angle_index - 360
            # Check if the angle is within the -110 to 110 degree range
            if -150 <= angle <= 150:
                # Check if the range is greater than the desired minimum (to avoid e.g. robot components) and less than the current closest distance and the maximum range
                if scan_range >= self.MIN_RANGE and scan_range < closest_distance and scan_range < self.MAX_RANGE:
                    self.closest_distance = scan_range                    
        return self.closest_distance


    '''Specific callbacks for ROS - update according to the subscribers'''

    def _callback_scan(self, msg):
        self.robot["scan"] = msg
        self.subCalledDistance = True
        self.subCalledAngle = True

    def _closestAngleEvent(self):
        s = self.subCalledAngle
        self.subCalledAngle = False
        return True if s else False
    
    def _closestDistanceEvent(self):
        s = self.subCalledDistance
        self.subCalledDistance = False
        return True if s else False


 ## How it works
'''if __name__=='__main__':
    # Instantiate an object of the parameterized platform mapping interface
    mapping = Mapping(host="localhost",port=23000)
    try:
        # Initialize the mapping interface
        mapping.start_mapping()
        # Do something
        ## Example input event
        input_event_args = {
            "equation_0": some_values_in_a_list,
            "equation_1": [0.1,20.0],
            ...
        }
        result = mapping.get_event("some_input_event",args=input_event_args)

        ## Example operation
        operation_args = {
            "action_0":some_values_in_another_list,
            "action_1":[-3.1415/2],
            ...
        }
        mapping.execute_operation("some_operation",args=operation_args)

        ## Optional: loops

    finally:
        # Stop the mapping interface
        mapping.stop_mapping()
        
'''
