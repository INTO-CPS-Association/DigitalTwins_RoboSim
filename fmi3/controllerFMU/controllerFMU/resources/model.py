import pickle
from fractions import Fraction
from enum import IntFlag

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

        self.repeat_cycles = False

        self.state = FMIState.FMIInstantiatedState
        self.closeGripperCommand = False
        self.openGripperCommand = False
        self.moveDiscreteCommand = False
        self.MovementArgs_target_X = 0
        self.MovementArgs_target_Y = 0
        self.MovementArgs_target_Z = 0
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
            4: "closeGripperCommand",
            8: "openGripperCommand",
            9: "moveDiscreteCommand",
            10: "MovementArgs_target_X",
            11: "MovementArgs_target_Y",
            12: "MovementArgs_target_Z",
        }

        self.parameters = {
            100: "repeat_cycles",
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
        
        self._idx = 0 # For iteration in update discrete states
        self._saved_cosim_time = 0.0 # To keep the latest step for routines



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

        self._saved_cosim_time = current_communication_point
        if self.repeat_cycles:
            if (round(current_communication_point%25,1)==5.0) or (round(current_communication_point%25,1)==10.5) or (round(current_communication_point%25,1)==15.0) or (round(current_communication_point%25,1)==23.5):
                event_handling_needed = True
                # if self._idx > 0:
                #     self._idx += 1            
        else:
            if (round(current_communication_point,1)==5.0) or (round(current_communication_point,1)==10.5) or (round(current_communication_point,1)==15.0) or (round(current_communication_point,1)==23.5):
                event_handling_needed = True
                # if self._idx > 0:
                #     self._idx += 1
            
            

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

        if self.repeat_cycles:
            if (round(self._saved_cosim_time%25,1)==5.0):
                self.moveDiscreteCommand = True
                self.MovementArgs_target_X = 0
                self.MovementArgs_target_Y = 23
                self.MovementArgs_target_Z = 1
            elif (round(self._saved_cosim_time%25,1)==10.5):
                self.moveDiscreteCommand = True
                self.MovementArgs_target_X = 3
                self.MovementArgs_target_Y = 20
                self.MovementArgs_target_Z = 2

            elif (round(self._saved_cosim_time%25,1)==15.0):
                self.moveDiscreteCommand = True
                self.MovementArgs_target_X = 8
                self.MovementArgs_target_Y = 10
                self.MovementArgs_target_Z = 0
            elif (round(self._saved_cosim_time%25,1)==23.5):
                self.moveDiscreteCommand = True
                self.MovementArgs_target_X = 1
                self.MovementArgs_target_Y = 13
                self.MovementArgs_target_Z = 0
            else:
                self.moveDiscreteCommand = False
            #     self.MovementArgs_target_X = 0
            #     self.MovementArgs_target_Y = 0
            #     self.MovementArgs_target_Z = 0

        else:
            if (round(self._saved_cosim_time%25,1)==5.0):
                self.moveDiscreteCommand = True
                self.MovementArgs_target_X = 0
                self.MovementArgs_target_Y = 23
                self.MovementArgs_target_Z = 1
            elif (round(self._saved_cosim_time%25,1)==10.5):
                self.moveDiscreteCommand = True
                self.MovementArgs_target_X = 3
                self.MovementArgs_target_Y = 20
                self.MovementArgs_target_Z = 2
            elif (round(self._saved_cosim_time%25,1)==15.0):
                self.moveDiscreteCommand = True
                self.MovementArgs_target_X = 8
                self.MovementArgs_target_Y = 10
                self.MovementArgs_target_Z = 0
            elif (round(self._saved_cosim_time%25,1)==23.5):
                self.moveDiscreteCommand = True
                self.MovementArgs_target_X = 1
                self.MovementArgs_target_Y = 13
                self.MovementArgs_target_Z = 0
            else:
                self.moveDiscreteCommand = False
            #     self.MovementArgs_target_X = 0
            #     self.MovementArgs_target_Y = 0
            #     self.MovementArgs_target_Z = 0

        # self._idx += 1

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
        return Fmi3Status.ok

    def fmi3Reset(self):
        self.state = FMIState.FMIInstantiatedState
        self.closeGripperCommand = False
        self.openGripperCommand = False
        self.moveDiscreteCommand = False
        self.MovementArgs_target_X = 0
        self.MovementArgs_target_Y = 0
        self.MovementArgs_target_Z = 0
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
        self._idx = 0 # For iteration in update discrete states
        return Fmi3Status.ok

    # ================= Serialization =================

    def fmi3SerializeFmuState(self):

        bytes = pickle.dumps(
            (
                self.state,
                self.closeGripperCommand,
                self.openGripperCommand,
                self.moveDiscreteCommand,
                self.MovementArgs_target_X,
                self.MovementArgs_target_Y,
                self.MovementArgs_target_Z,
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
                self._idx,
            )
        )
        return Fmi3Status.ok, bytes

    def fmi3DeserializeFmuState(self, bytes: bytes):
        (
            state,
            closeGripperCommand,
            openGripperCommand,
            moveDiscreteCommand,
            MovementArgs_target_X,
            MovementArgs_target_Y,
            MovementArgs_target_Z,
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
            _idx,
        ) = pickle.loads(bytes)
        self.state = state
        self.closeGripperCommand = closeGripperCommand
        self.openGripperCommand = openGripperCommand
        self.moveDiscreteCommand = moveDiscreteCommand
        self.MovementArgs_target_X = MovementArgs_target_X
        self.MovementArgs_target_Y = MovementArgs_target_Y
        self.MovementArgs_target_Z = MovementArgs_target_Z
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
        self._idx = _idx
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
#    m = Model()
