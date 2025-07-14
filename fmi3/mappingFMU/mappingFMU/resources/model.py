import pickle
from fractions import Fraction
from enum import IntFlag
from mapping import mapping as mpp

class Model:
    def __init__(
            self,
            instance_name,
            instantiation_token,
            resource_path,
            visible,
            logging_on,
            event_mode_used,
            early_return_allowed,
            required_intermediate_variables,
    ) -> None:  
        self.instance_name = instance_name
        self.instantiation_token = instantiation_token
        self.resource_path = resource_path
        self.visible = visible
        self.logging_on = logging_on
        self.event_mode_used = event_mode_used
        self.early_return_allowed = early_return_allowed
        self.required_intermediate_variables = required_intermediate_variables
        self.state = FMIState.FMIInstantiatedState

        self.mapping = mpp.Mapping()
        self.mapping.start_mapping()
        self.feasibleMoveDiscreteCommand = False
        self.robotStopped = False
        self.gripperOpened = False
        self.collision = False
        self.closeGripperCommand = False
        self.gripperClosed = False
        self.nonfeasibleMoveDiscreteCommand = False
        self.moveCompleted = False
        self.openGripperCommand = False
        self.moveDiscreteCommand = False
        self.MovementArgs_target_X = 0
        self.MovementArgs_target_Y = 0
        self.MovementArgs_target_Z = 0
        self.movediscrete = False
        self.pick = False
        self.place = False
        self.target_X = 0
        self.target_Y = 0
        self.target_Z = 0
        self.closing_diameter = 0.0
        self.closing_speed = 0.0
        self.closing_force = 0.0
        self.opening_diameter = 0.0
        self.opening_speed = 0.0
        self.opening_force = 0.0
        self.stop = False
        self.movejoint = False
        self.target_q0 = 0.0
        self.target_q1 = 0.0
        self.target_q2 = 0.0
        self.target_q3 = 0.0
        self.target_q4 = 0.0
        self.target_q5 = 0.0
        self.movecartesian = False
        self.target_x = 0.0
        self.target_y = 0.0
        self.target_z = 0.0
        self.target_rx = 0.0
        self.target_ry = 0.0
        self.target_rz = 0.0
        self.setvelocity = False
        self.target_v = 0.0
        self.q0 = 0.0
        self.q1 = 0.0
        self.q2 = 0.0
        self.q3 = 0.0
        self.q4 = 0.0
        self.q5 = 0.0
        self.qd0 = 0.0
        self.qd1 = 0.0
        self.qd2 = 0.0
        self.qd3 = 0.0
        self.qd4 = 0.0
        self.qd5 = 0.0
        self.qdd0 = 0.0
        self.qdd1 = 0.0
        self.qdd2 = 0.0
        self.qdd3 = 0.0
        self.qdd4 = 0.0
        self.qdd5 = 0.0
        self.t0 = 0.0
        self.t1 = 0.0
        self.t2 = 0.0
        self.t3 = 0.0
        self.t4 = 0.0
        self.t5 = 0.0
        self.x = 0.0
        self.y = 0.0
        self.z = 0.0
        self.rx = 0.0
        self.ry = 0.0
        self.rz = 0.0

        self.reference_to_attribute = {
            42: "q0",
            43: "q1",
            44: "q2",
            45: "q3",
            46: "q4",
            47: "q5",
            48: "qd0",
            49: "qd1",
            50: "qd2",
            51: "qd3",
            52: "qd4",
            53: "qd5",
            54: "qdd0",
            55: "qdd1",
            56: "qdd2",
            57: "qdd3",
            58: "qdd4",
            59: "qdd5",
            60: "t0",
            61: "t1",
            62: "t2",
            63: "t3",
            64: "t4",
            65: "t5",
            66: "x",
            67: "y",
            68: "z",
            69: "rx",
            70: "ry",
            71: "rz",          
        }

        self.clocked_variables = {
            0: "feasibleMoveDiscreteCommand",
            1: "robotStopped",
            2: "gripperOpened",
            3: "collision",
            4: "closeGripperCommand",
            5: "gripperClosed",
            6: "nonfeasibleMoveDiscreteCommand",
            7: "moveCompleted",
            8: "openGripperCommand",
            9: "moveDiscreteCommand",
            10: "MovementArgs_target_X",
            11: "MovementArgs_target_Y",
            12: "MovementArgs_target_Z",
            13: "movediscrete",
            14: "pick",
            15: "place",
            16: "target_X",
            17: "target_Y",
            18: "target_Z",
            19: "closing_diameter",
            20: "closing_speed",
            21: "closing_force",
            22: "opening_diameter",
            23: "opening_speed",
            24: "opening_force",
            25: "stop",
            26: "movejoint",
            27: "target_q0",
            28: "target_q1",
            29: "target_q2",
            30: "target_q3",
            31: "target_q4",
            32: "target_q5",
            33: "movecartesian",
            34: "target_x",
            35: "target_y",
            36: "target_z",
            37: "target_rx",
            38: "target_ry",
            39: "target_rz",
            40: "setvelocity",
            41: "target_v",

        }

        self.parameters = {
            
        }

        self.tunable_parameters = {

        }

        self.tunable_structural_parameters = {
        }

        self.all_references = {**self.tunable_structural_parameters,
                               **self.parameters,
                               **self.tunable_parameters,
                               **self.clocked_variables,
                               **self.reference_to_attribute}
        
        self.all_parameters = {**self.tunable_structural_parameters,
                               **self.parameters,
                               **self.tunable_parameters}



    # ================= FMI3 =================

    # ================= doStep and updateDiscreteStates =================
    def fmi3DoStep(
            self,
            current_communication_point: float,
            communication_step_size: float,
            no_set_fmu_state_prior_to_current_point: bool,
    ):
        event_handling_needed = False
        terminate_simulation = False
        early_return = False
        last_successful_time = current_communication_point + communication_step_size

        ''' Inputs from the platform (checked on a periodic basis based on the steps) '''
        # Updating the data based on the platform
        self.q0 = self.mapping.get_joint_position("j0")
        self.q1 = self.mapping.get_joint_position("j1")
        self.q2 = self.mapping.get_joint_position("j2")
        self.q3 = self.mapping.get_joint_position("j3")
        self.q4 = self.mapping.get_joint_position("j4")
        self.q5 = self.mapping.get_joint_position("j5")
        self.qd0 = self.mapping.get_joint_velocity("j0")
        self.qd1 = self.mapping.get_joint_velocity("j1")
        self.qd2 = self.mapping.get_joint_velocity("j2")
        self.qd3 = self.mapping.get_joint_velocity("j3")
        self.qd4 = self.mapping.get_joint_velocity("j4")
        self.qd5 = self.mapping.get_joint_velocity("j5")
        self.t0 = self.mapping.get_joint_force("j0")
        self.t1 = self.mapping.get_joint_force("j1")
        self.t2 = self.mapping.get_joint_force("j2")
        self.t3 = self.mapping.get_joint_force("j3")
        self.t4 = self.mapping.get_joint_force("j4")
        self.t5 = self.mapping.get_joint_force("j5")
        self.x = self.mapping.get_cartesian_positions()[0]
        self.y = self.mapping.get_cartesian_positions()[1]
        self.z = self.mapping.get_cartesian_positions()[2]
        self.rx = self.mapping.get_cartesian_positions()[3]
        self.ry = self.mapping.get_cartesian_positions()[4]
        self.rz = self.mapping.get_cartesian_positions()[5]


        # Events (state cannot be updated in step mode)
        moveCompletedHolder = all(it == True for it in self.mapping.get_event("moveCompleted",args=None))
        

        robotStoppedHolder = all(it == True for it in self.mapping.get_event("robotStopped",args=None))

        args = {
            "equation_0": [0.05,0.083],
            "equation_1": [0.05,0.083],
        }
        gripperOpenedHolder = all(it == True for it in self.mapping.get_event("gripperOpened",args=args))

        args = {
            "equation_0": [0.05,0.083],
            "equation_1": [0.05,0.083],
        }
        gripperClosedHolder = all(it == True for it in self.mapping.get_event("gripperClosed",args=args))

        feasibleMoveDiscreteCommandHolder = True # workaround for problem with library

        nonfeasibleMoveDiscreteCommandHolder = False # workaround for problem with library

        # Collision: to be characterized
        args = {
            "equation_0": [self.qd0,self.t0,0.05,50],
            "equation_1": [self.qd1,self.t1,0.05,50],
            "equation_2": [self.qd2,self.t2,0.05,50],
            "equation_3": [self.qd3,self.t3,0.05,50],
            "equation_4": [self.qd4,self.t4,0.05,50],
            "equation_5": [self.qd5,self.t5,0.05,50]
        }
        collisionHolder = all(it == True for it in self.mapping.get_event("collision",args=args))

        if (moveCompletedHolder or robotStoppedHolder or collisionHolder or gripperClosedHolder or gripperOpenedHolder or feasibleMoveDiscreteCommandHolder or nonfeasibleMoveDiscreteCommandHolder):
            event_handling_needed = True
            # Returns activation for event mode
        

        return (
            Fmi3Status.ok,
            event_handling_needed,
            terminate_simulation,
            early_return,
            last_successful_time,
        )
    
    def fmi3UpdateDiscreteStates(self):
        status = Fmi3Status.ok
        discrete_states_need_update = False
        terminate_simulation = False
        nominals_continuous_states_changed = False
        values_continuous_states_changed = False
        next_event_time_defined = False
        next_event_time = 0.0

        ''' Inputs from the d-model software '''
        # Forwarding the commands to the platform
        
        if (self.movediscrete):
            # IK already inside the mapping module
            args = {
                "action_0":[self.target_X, self.target_Y, self.target_Z]
            }
            self.mapping.execute_operation("movediscrete",args=args)

        if (self.pick): # To be implemented. No gripper for now
            args = {
                "action_0":[self.closing_diameter,self.closing_force,self.closing_speed]
            }
            self.mapping.execute_operation("pick",args=None)

        if (self.place): # To be implemented. No gripper for now
            args = {
                "action_0":[self.opening_diameter,self.opening_force,self.opening_speed]
            }
            self.mapping.execute_operation("place",args=None)

        if (self.stop):
            self.mapping.execute_operation("stop",args=None)

        if (self.movecartesian): # Not used in this example
            args = {
                "action_0":[self.target_x,self.target_y,self.target_z]
            }
            self.mapping.execute_operation("movecartesian",args=args)

        if (self.movejoint): # Not used in this example
            args = {
                "action_0":[self.target_q0,self.target_q1,self.target_q2,self.target_q3,self.target_q4,self.target_q5]
            }
            self.mapping.execute_operation("movejoint",args=args)

        if (self.setvelocity): # Not used in this example
            args = {
                "action_0":[self.target_v],
                "action_1":[self.target_v],
                "action_2":[self.target_v],
                "action_3":[self.target_v],
                "action_4":[self.target_v],
                "action_5":[self.target_v],
            }
            #self.mapping.execute_operation("setvelocity",args=args)

        # Events (state updated - only in event mode)
        self.moveCompleted = all(it == True for it in self.mapping.get_event("moveCompleted",args=None))

        self.robotStopped = all(it == True for it in self.mapping.get_event("robotStopped",args=None))

        args = {
            "equation_0": [0.05,0.083],
            "equation_1": [0.05,0.083],
        }
        self.gripperOpened = all(it == True for it in self.mapping.get_event("gripperOpened",args=args))

        args = {
            "equation_0": [0.05,0.083],
            "equation_1": [0.05,0.083],
        }
        self.gripperClosed = all(it == True for it in self.mapping.get_event("gripperClosed",args=args))

        args = {
            "equation_0": [self.target_X,self.target_Y,self.target_Z],
        }
        #self.feasibleMoveDiscreteCommand = all(it == True for it in self.mapping.get_event("feasibleMoveDiscreteCommand",args=args))
        self.feasibleMoveDiscreteCommand = True # workaround for problem with library

        args = {
            "equation_0": [self.target_X,self.target_Y,self.target_Z],
        }
        #self.nonfeasibleMoveDiscreteCommand = all(it == True for it in self.mapping.get_event("nonfeasibleMoveDiscreteCommand",args=args))
        self.nonfeasibleMoveDiscreteCommand = False # workaround for problem with library

        # Collision: to be characterized
        args = {
            "equation_0": [self.qd0,self.t0,0.05,50],
            "equation_1": [self.qd1,self.t1,0.05,50],
            "equation_2": [self.qd2,self.t2,0.05,50],
            "equation_3": [self.qd3,self.t3,0.05,50],
            "equation_4": [self.qd4,self.t4,0.05,50],
            "equation_5": [self.qd5,self.t5,0.05,50]
        }
        self.collision = all(it == True for it in self.mapping.get_event("collision",args=args))        

        return (status, discrete_states_need_update, terminate_simulation, nominals_continuous_states_changed,
                values_continuous_states_changed, next_event_time_defined, next_event_time)

    # ================= Initialization, Enter, Termination, and Reset =================

    def fmi3EnterInitializationMode(
            self,
            tolerance_defined: bool,
            tolerance: float,
            start_time: float,
            stop_time_defined: bool,
            stop_time: float
    ):
        self.state = FMIState.FMIInitializationModeState
        return Fmi3Status.ok

    def fmi3ExitInitializationMode(self):
        self.state = FMIState.FMIEventModeState if self.event_mode_used else FMIState.FMIStepModeState
        return Fmi3Status.ok

    def fmi3EnterEventMode(self):
        self.state = FMIState.FMIEventModeState
        return Fmi3Status.ok

    def fmi3EnterStepMode(self):
        self.state = FMIState.FMIStepModeState
        return Fmi3Status.ok
    
    def fmi3EnterConfigurationMode(self):
        self.state = FMIState.FMIConfigurationModeState if self.state == FMIState.FMIInstantiatedState else FMIState.FMIReconfigurationModeState
        return Fmi3Status.ok

    def fmi3ExitConfigurationMode(self):
        if self.state == FMIState.FMIConfigurationModeState:
            self.state = FMIState.FMIInstantiatedState
        elif self.state == FMIState.FMIReconfigurationModeState:
            self.state = FMIState.FMIStepModeState
        else:
            return Fmi3Status.error
        return Fmi3Status.ok

    def fmi3Terminate(self):
        self.state = FMIState.FMITerminatedState
        self.mapping.stop_mapping()
        return Fmi3Status.ok

    def fmi3Reset(self):
        self.state = FMIState.FMIInstantiatedState
        self.feasibleMoveDiscreteCommand = False
        self.robotStopped = False
        self.gripperOpened = False
        self.collision = False
        self.closeGripperCommand = False
        self.gripperClosed = False
        self.nonfeasibleMoveDiscreteCommand = False
        self.moveCompleted = False
        self.openGripperCommand = False
        self.moveDiscreteCommand = False
        self.MovementArgs_target_X = 0
        self.MovementArgs_target_Y = 0
        self.MovementArgs_target_Z = 0
        self.movediscrete = False
        self.pick = False
        self.place = False
        self.target_X = 0
        self.target_Y = 0
        self.target_Z = 0
        self.closing_diameter = 0.0
        self.closing_speed = 0.0
        self.closing_force = 0.0
        self.opening_diameter = 0.0
        self.opening_speed = 0.0
        self.opening_force = 0.0
        self.stop = False
        self.movejoint = False
        self.target_q0 = 0.0
        self.target_q1 = 0.0
        self.target_q2 = 0.0
        self.target_q3 = 0.0
        self.target_q4 = 0.0
        self.target_q5 = 0.0
        self.movecartesian = False
        self.target_x = 0.0
        self.target_y = 0.0
        self.target_z = 0.0
        self.target_rx = 0.0
        self.target_ry = 0.0
        self.target_rz = 0.0
        self.setvelocity = False
        self.target_v = 0.0
        self.q0 = 0.0
        self.q1 = 0.0
        self.q2 = 0.0
        self.q3 = 0.0
        self.q4 = 0.0
        self.q5 = 0.0
        self.qd0 = 0.0
        self.qd1 = 0.0
        self.qd2 = 0.0
        self.qd3 = 0.0
        self.qd4 = 0.0
        self.qd5 = 0.0
        self.qdd0 = 0.0
        self.qdd1 = 0.0
        self.qdd2 = 0.0
        self.qdd3 = 0.0
        self.qdd4 = 0.0
        self.qdd5 = 0.0
        self.t0 = 0.0
        self.t1 = 0.0
        self.t2 = 0.0
        self.t3 = 0.0
        self.t4 = 0.0
        self.t5 = 0.0
        self.x = 0.0
        self.y = 0.0
        self.z = 0.0
        self.rx = 0.0
        self.ry = 0.0
        self.rz = 0.0


        return Fmi3Status.ok

    # ================= Serialization =================

    def fmi3SerializeFmuState(self):

        bytes = pickle.dumps(
            (
                self.state,
                self.feasibleMoveDiscreteCommand,
                self.robotStopped,
                self.gripperOpened,
                self.collision,
                self.closeGripperCommand,
                self.gripperClosed,
                self.nonfeasibleMoveDiscreteCommand,
                self.moveCompleted,
                self.openGripperCommand,
                self.moveDiscreteCommand,
                self.MovementArgs_target_X,
                self.MovementArgs_target_Y,
                self.MovementArgs_target_Z,
                self.movediscrete,
                self.pick,
                self.place,
                self.target_X,
                self.target_Y,
                self.target_Z,
                self.closing_diameter,
                self.closing_speed,
                self.closing_force,
                self.opening_diameter,
                self.opening_speed,
                self.opening_force,
                self.stop,
                self.movejoint,
                self.target_q0,
                self.target_q1,
                self.target_q2,
                self.target_q3,
                self.target_q4,
                self.target_q5,
                self.movecartesian,
                self.target_x,
                self.target_y,
                self.target_z,
                self.target_rx,
                self.target_ry,
                self.target_rz,
                self.setvelocity,
                self.target_v,
                self.q0,
                self.q1,
                self.q2,
                self.q3,
                self.q4,
                self.q5,
                self.qd0,
                self.qd1,
                self.qd2,
                self.qd3,
                self.qd4,
                self.qd5,
                self.qdd0,
                self.qdd1,
                self.qdd2,
                self.qdd3,
                self.qdd4,
                self.qdd5,
                self.t0,
                self.t1,
                self.t2,
                self.t3,
                self.t4,
                self.t5,
                self.x,
                self.y,
                self.z,
                self.rx,
                self.ry,
                self.rz,
            )
        )
        return Fmi3Status.ok, bytes

    def fmi3DeserializeFmuState(self, bytes: bytes):
        (
            state,
            feasibleMoveDiscreteCommand,
            robotStopped,
            gripperOpened,
            collision,
            closeGripperCommand,
            gripperClosed,
            nonfeasibleMoveDiscreteCommand,
            moveCompleted,
            openGripperCommand,
            moveDiscreteCommand,
            MovementArgs_target_X,
            MovementArgs_target_Y,
            MovementArgs_target_Z,
            movediscrete,
            pick,
            place,
            target_X,
            target_Y,
            target_Z,
            closing_diameter,
            closing_speed,
            closing_force,
            opening_diameter,
            opening_speed,
            opening_force,
            stop,
            movejoint,
            target_q0,
            target_q1,
            target_q2,
            target_q3,
            target_q4,
            target_q5,
            movecartesian,
            target_x,
            target_y,
            target_z,
            target_rx,
            target_ry,
            target_rz,
            setvelocity,
            target_v,
            q0,
            q1,
            q2,
            q3,
            q4,
            q5,
            qd0,
            qd1,
            qd2,
            qd3,
            qd4,
            qd5,
            qdd0,
            qdd1,
            qdd2,
            qdd3,
            qdd4,
            qdd5,
            t0,
            t1,
            t2,
            t3,
            t4,
            t5,
            x,
            y,
            z,
            rx,
            ry,
            rz,
        ) = pickle.loads(bytes)
        self.state = state
        self.feasibleMoveDiscreteCommand = feasibleMoveDiscreteCommand
        self.robotStopped = robotStopped
        self.gripperOpened = gripperOpened
        self.collision = collision
        self.closeGripperCommand = closeGripperCommand
        self.gripperClosed = gripperClosed
        self.nonfeasibleMoveDiscreteCommand = nonfeasibleMoveDiscreteCommand
        self.moveCompleted = moveCompleted
        self.openGripperCommand = openGripperCommand
        self.moveDiscreteCommand = moveDiscreteCommand
        self.MovementArgs_target_X = MovementArgs_target_X
        self.MovementArgs_target_Y = MovementArgs_target_Y
        self.MovementArgs_target_Z = MovementArgs_target_Z
        self.movediscrete = movediscrete
        self.pick = pick
        self.place = place
        self.target_X = target_X
        self.target_Y = target_Y
        self.target_Z = target_Z
        self.closing_diameter = closing_diameter
        self.closing_speed = closing_speed
        self.closing_force = closing_force
        self.opening_diameter = opening_diameter
        self.opening_speed = opening_speed
        self.opening_force = opening_force
        self.stop = stop
        self.movejoint = movejoint
        self.target_q0 = target_q0
        self.target_q1 = target_q1
        self.target_q2 = target_q2
        self.target_q3 = target_q3
        self.target_q4 = target_q4
        self.target_q5 = target_q5
        self.movecartesian = movecartesian
        self.target_x = target_x
        self.target_y = target_y
        self.target_z = target_z
        self.target_rx = target_rx
        self.target_ry = target_ry
        self.target_rz = target_rz
        self.setvelocity = setvelocity
        self.target_v = target_v
        self.q0 = q0
        self.q1 = q1
        self.q2 = q2
        self.q3 = q3
        self.q4 = q4
        self.q5 = q5
        self.qd0 = qd0
        self.qd1 = qd1
        self.qd2 = qd2
        self.qd3 = qd3
        self.qd4 = qd4
        self.qd5 = qd5
        self.qdd0 = qdd0
        self.qdd1 = qdd1
        self.qdd2 = qdd2
        self.qdd3 = qdd3
        self.qdd4 = qdd4
        self.qdd5 = qdd5
        self.t0 = t0
        self.t1 = t1
        self.t2 = t2
        self.t3 = t3
        self.t4 = t4
        self.t5 = t5
        self.x = x
        self.y = y
        self.z = z
        self.rx = rx
        self.ry = ry
        self.rz = rz


        return Fmi3Status.ok
    
    # ================= Getters =================

    def fmi3GetFloat32(self, value_references):
        return self._get_value(value_references)

    def fmi3GetFloat64(self, value_references):
        return self._get_value(value_references)

    def fmi3GetInt8(self, value_references):
        return self._get_value(value_references)

    def fmi3GetUInt8(self, value_references):
        return self._get_value(value_references)

    def fmi3GetInt16(self, value_references):
        return self._get_value(value_references)

    def fmi3GetUInt16(self, value_references):
        return self._get_value(value_references)

    def fmi3GetInt32(self, value_references):
        return self._get_value(value_references)

    def fmi3GetUInt32(self, value_references):
        return self._get_value(value_references)

    def fmi3GetInt64(self, value_references):
        return self._get_value(value_references)

    def fmi3GetUInt64(self, value_references):
        return self._get_value(value_references)

    def fmi3GetBoolean(self, value_references):
        return self._get_value(value_references)

    def fmi3GetString(self, value_references):
        return self._get_value(value_references)

    def fmi3GetBinary(self, value_references):
        return self._get_value(value_references)

    def fmi3GetClock(self, value_references):
        return self._get_value(value_references)

    def fmi3GetIntervalDecimal(self, value_references):
        intervals = []
        qualifiers = []

        for r in value_references:
            intervals.append(self.clock_reference_to_interval[r])
            qualifiers.append(2)

        return Fmi3Status.ok, intervals, qualifiers
    
    def fmi3GetIntervalFraction(self, value_references):
        counters = []
        resolutions = []
        qualifiers = []

        for r in value_references:
            fraction = Fraction(str(self.clock_reference_to_interval[r]))
            numerator = fraction.numerator
            denominator = fraction.denominator
            counters.append(numerator)
            resolutions.append(denominator)
            qualifiers.append(2)

        return Fmi3Status.ok, counters, resolutions, qualifiers
    
    def fmi3GetShiftDecimal(self, value_references):
        shifts = []

        for r in value_references:
            shifts.append(self.clock_reference_to_shift[r])

        return Fmi3Status.ok, shifts
    
    def fmi3GetShiftFraction(self, value_references):
        counters = []
        resolutions = []

        for r in value_references:
            fraction = Fraction(str(self.clock_reference_to_shift[r]))
            numerator = fraction.numerator
            denominator = fraction.denominator
            counters.append(numerator)
            resolutions.append(denominator)

        return Fmi3Status.ok, counters, resolutions
    
    # ================= Setters =================

    def fmi3SetFloat32(self, value_references, values):
        return self._set_value(value_references, values)

    def fmi3SetFloat64(self, value_references, values):
        return self._set_value(value_references, values)

    def fmi3SetInt8(self, value_references, values):
        return self._set_value(value_references, values)

    def fmi3SetUInt8(self, value_references, values):
        return self._set_value(value_references, values)

    def fmi3SetInt16(self, value_references, values):
        return self._set_value(value_references, values)

    def fmi3SetUInt16(self, value_references, values):
        return self._set_value(value_references, values)

    def fmi3SetInt32(self, value_references, values):
        return self._set_value(value_references, values)

    def fmi3SetUInt32(self, value_references, values):
        return self._set_value(value_references, values)

    def fmi3SetInt64(self, value_references, values):
        return self._set_value(value_references, values)

    def fmi3SetUInt64(self, value_references, values):
        return self._set_value(value_references, values)

    def fmi3SetBoolean(self, value_references, values):
        return self._set_value(value_references, values)

    def fmi3SetString(self, value_references, values):
        return self._set_value(value_references, values)

    def fmi3SetBinary(self, value_references, value_sizes, values):
        # Store 'value_sizes' somewhere if needed
        return self._set_value(value_references, values)

    def fmi3SetClock(self, value_references, values):
        status = self._set_value(value_references, values)
        return status
    
    def fmi3SetIntervalDecimal(self, value_references, intervals):
        for idx,r in enumerate(value_references):
            self.clock_reference_to_interval[r] = intervals[idx]
        return Fmi3Status.ok
    
    def fmi3SetIntervalFraction(self, value_references, counters, resolutions):
        for idx,r in enumerate(value_references):
            self.clock_reference_to_interval[r] = float(counters[idx])/float(resolutions[idx])
        return Fmi3Status.ok
    
    def fmi3SetShiftDecimal(self, value_references, shifts):
        for idx,r in enumerate(value_references):
            self.clock_reference_to_shift[r] = shifts[idx]
        return Fmi3Status.ok
    
    def fmi3SetShiftFraction(self, value_references, counters, resolutions):
        for idx,r in enumerate(value_references):
            self.clock_reference_to_shift[r] = float(counters[idx])/float(resolutions[idx])
        return Fmi3Status.ok

    

    # ================= Helpers =================

    def _set_value(self, references, values):
        if (self.state == FMIState.FMIConfigurationModeState or self.state == FMIState.FMIReconfigurationModeState):
            for r, v in zip(references, values):
                if (r in self.clocked_variables) or (r in self.reference_to_attribute):
                    return Fmi3Status.error 
                setattr(self, self.all_references[r], v)
        elif (self.state == FMIState.FMIEventModeState):
            for r, v in zip(references, values):
                if (r in self.reference_to_attribute) or (r in self.tunable_structural_parameters):
                    return Fmi3Status.error 
                setattr(self, self.all_references[r], v)
        elif (self.state == FMIState.FMIInitializationModeState):
            for r, v in zip(references, values):
                setattr(self, self.all_references[r], v)
        else:
            for r, v in zip(references, values):
                if ((self.event_mode_used) and (r in self.all_parameters)) or (r in self.clocked_variables):
                    return Fmi3Status.error              
                setattr(self, self.reference_to_attribute[r], v)
        return Fmi3Status.ok

    def _get_value(self, references):

        values = []
        for r in references:
            if r in self.clocked_variables:
                if not ((self.state == FMIState.FMIEventModeState) or (self.state == FMIState.FMIInitializationModeState)):
                    return Fmi3Status.error
            values.append(getattr(self, self.all_references[r]))

        return Fmi3Status.ok, values

class Fmi3Status():
    """
    Represents the status of an FMI3 FMU or the results of function calls.

    Values:
        * ok: all well
        * warning: an issue has arisen, but the computation can continue.
        * discard: an operation has resulted in invalid output, which must be discarded
        * error: an error has ocurred for this specific FMU instance.
        * fatal: an fatal error has ocurred which has corrupted ALL FMU instances.
    """

    ok = 0
    warning = 1
    discard = 2
    error = 3
    fatal = 4

class FMIState(IntFlag):
    FMIStartAndEndState         = 1 << 0,
    FMIInstantiatedState        = 1 << 1,
    FMIInitializationModeState  = 1 << 2,
    FMITerminatedState          = 1 << 3,
    FMIConfigurationModeState   = 1 << 4,
    FMIReconfigurationModeState = 1 << 5,
    FMIEventModeState           = 1 << 6,
    FMIContinuousTimeModeState  = 1 << 7,
    FMIStepModeState            = 1 << 8,
    FMIClockActivationMode      = 1 << 9


#if __name__ == "__main__":
