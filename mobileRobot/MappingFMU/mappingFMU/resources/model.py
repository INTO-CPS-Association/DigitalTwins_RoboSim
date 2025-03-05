import pickle
from mapping import mapping as mpp
import time

class Model:
    def __init__(self) -> None:
        self.mapping = mpp.Mapping()
        self.mapping.start_mapping()
        '''controller events (from external controller - not d-model)'''
        self.closestDistance = True
        self.closest_distance = 0.0
        self.closestAngle = True
        self.closest_angle = 0.0
        self.move = False
        self.lv = 0.0
        self.av = 0.0
        



        '''internal variables'''
        self._first_iteration = False



        self.reference_to_attribute = {
            0: "closestDistance",
            1: "closest_distance",
            2: "closestAngle",
            3: "closest_angle",
            4: "move",
            5: "lv",
            6: "av"
        }


    def fmi2DoStep(self, current_time, step_size, no_step_prior):
        '''Resetting outputs'''

        ''' Input coming from the controller'''

        # Bypassing this - Connected directly to d-model

        ''' Inputs from the d-model software '''
        # Forwarding the commands to the platform (Implementation)
        if (self.move == True):
            args = {
                "action_0":[self.lv, self.av] # lv, av
            }
            self.mapping.execute_operation("move",args=args)

        ''' Inputs from the platform (checked on a periodic basis based on the steps) '''
        # Updating the values based on the platform
        self.closest_angle = self.mapping.get_closest_angle()
        self.closest_distance = self.mapping.get_closest_distance()

        # Events
        result = self.mapping.get_event("closestAngle",args=None)
        self.closestAngle = all(it == True for it in result)     
        print("closestAngle platform event: " + str(self.closestAngle))

        result = self.mapping.get_event("closestDistance",args=None)
        self.closestDistance = all(it == True for it in result)
        print("closestDistance platform event: " + str(self.closestDistance))

        if self._first_iteration == False:
            self.closestAngle = True
            self.closestDistance = True
            self._first_iteration = True

        return Fmi2Status.ok

    def fmi2EnterInitializationMode(self):
        return Fmi2Status.ok

    def fmi2ExitInitializationMode(self):
        return Fmi2Status.ok

    def fmi2SetupExperiment(self, start_time, stop_time, tolerance):
        return Fmi2Status.ok

    def fmi2SetReal(self, references, values):
        return self._set_value(references, values)

    def fmi2SetInteger(self, references, values):
        return self._set_value(references, values)

    def fmi2SetBoolean(self, references, values):
        return self._set_value(references, values)

    def fmi2SetString(self, references, values):
        return self._set_value(references, values)

    def fmi2GetReal(self, references):
        return self._get_value(references)

    def fmi2GetInteger(self, references):
        return self._get_value(references)

    def fmi2GetBoolean(self, references):
        return self._get_value(references)

    def fmi2GetString(self, references):
        return self._get_value(references)

    def fmi2Reset(self):
        return Fmi2Status.ok

    def fmi2Terminate(self):
        return Fmi2Status.ok

    def fmi2ExtSerialize(self):

        bytes = pickle.dumps(
            (
                self.closestDistance,
                self.closest_distance,
                self.closestAngle,
                self.closest_angle,
                self.move,
                self.lv,
                self.av,
            )
        )
        return Fmi2Status.ok, bytes

    def fmi2ExtDeserialize(self, bytes) -> int:
        (
            closestDistance,
            closest_distance,
            closestAngle,
            closest_angle,
            move,
            lv,
            av,
        ) = pickle.loads(bytes)
        self.closestDistance = closestDistance
        self.closest_distance = closest_distance
        self.closestAngle = closestAngle
        self.closest_angle = closest_angle
        self.move = move
        self.lv = lv
        self.av = av


        return Fmi2Status.ok

    def fmi2Terminate(self):
        self.mapping.stop_mapping()
        return Fmi2Status.ok

    def fmi2FreeInstance(self):
        self.mapping.stop_mapping()
        return Fmi2Status.ok

    def _set_value(self, references, values):
        for r, v in zip(references, values):
            setattr(self, self.reference_to_attribute[r], v)

        return Fmi2Status.ok

    def _get_value(self, references):

        values = []

        for r in references:
            values.append(getattr(self, self.reference_to_attribute[r]))

        return Fmi2Status.ok, values




class Fmi2Status:
    """Represents the status of the FMU or the results of function calls.

    Values:
        * ok: all well
        * warning: an issue has arisen, but the computation can continue.
        * discard: an operation has resulted in invalid output, which must be discarded
        * error: an error has ocurred for this specific FMU instance.
        * fatal: an fatal error has ocurred which has corrupted ALL FMU instances.
        * pending: indicates that the FMu is doing work asynchronously, which can be retrived later.

    Notes:
        FMI section 2.1.3

    """

    ok = 0
    warning = 1
    discard = 2
    error = 3
    fatal = 4
    pending = 5


'''if __name__ == "__main__":
    m = Model()
    assert m.fmi2DoStep(0.0, 1.0, False) == Fmi2Status.ok
    time.sleep(1.0)
    m.fmi2DoStep(1.0, 1.0, False)
    time.sleep(1.0)
    m.fmi2Terminate()'''
