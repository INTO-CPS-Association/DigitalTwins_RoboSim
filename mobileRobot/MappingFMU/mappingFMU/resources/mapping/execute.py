# Author: Santiago Gil
import mapping as mpp
import time
from threading import Timer

mapping = mpp.Mapping()



def check_for_events():
    result = mapping.get_event("closestAngle",args=None)
    print("closestAngle platform event (timer): " + str(result))

    result = mapping.get_event("closestDistance",args=None)
    print("closestDistance platform event (timer): " + str(result))
    checking_timer.run()

checking_timer = Timer(0.5, check_for_events)
checking_timer.daemon = True

if __name__ == "__main__":
    try:
        print("Before starting application (execute.py)")
        mapping.start_mapping()
        ## The args should come from the c++ code
        # The args could also come as a dict of dicts (with the variable names)
        print("Application started (execute.py)")
        checking_timer.start()

        args = {
            "action_0":[0.8,0.7]
        }

        mapping.execute_operation("robot_move",args=args)
        time.sleep(5.0)

        ''' Inputs from the platform (checked on a periodic basis based on the steps) '''


        # Updating the values based on the platform
        closest_angle = mapping.get_closest_angle()
        closest_distance = mapping.get_closest_distance()

        args = {
            "action_0":[0.6,0.0]
        }

        mapping.execute_operation("robot_move",args=args)
        time.sleep(5.0)

    finally:
        mapping.stop_mapping()
        checking_timer.cancel()
        print("Application stopped")
