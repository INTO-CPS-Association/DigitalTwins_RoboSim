# Author: Santiago

vars = {}

## RoboSim Module Name
robosim_module_name = "DiscreteGrippingArm"

### Fill in your var names and types e.g. vars["var_name"]=["Datatype","RoboSim type","Dependency(clock)"]
### e.g.:

# inputs
vars["feasibleMoveDiscreteCommand"]=["Clock","InputEvent"]
vars["robotStopped"]=["Clock","InputEvent"]
vars["gripperOpened"]=["Clock","InputEvent"]
vars["collision"]=["Clock","InputEvent"]
vars["closeGripperCommand"]=["Clock","InputEvent"]
vars["gripperClosed"]=["Clock","InputEvent"]
vars["nonfeasibleMoveDiscreteCommand"]=["Clock","InputEvent"]
vars["moveCompleted"]=["Clock","InputEvent"]
vars["openGripperCommand"]=["Clock","InputEvent"]
vars["moveDiscreteCommand"]=["Clock","InputEvent"]
vars["feasibleMoveDiscreteCommand"]=["Clock","InputEvent"]
vars["MovementArgs_target_X"]=["Int32","InputEventArgument","moveDiscreteCommand"]
vars["MovementArgs_target_Y"]=["Int32","InputEventArgument","moveDiscreteCommand"]
vars["MovementArgs_target_Z"]=["Int32","InputEventArgument","moveDiscreteCommand"]


# Outputs
vars["movediscrete"]=["Clock","Operation"]
vars["pick"]=["Clock","Operation"]
vars["place"]=["Clock","Operation"]
vars["target_X"]=["Int32","OperationArgument","movediscrete"]
vars["target_Y"]=["Int32","OperationArgument","movediscrete"]
vars["target_Z"]=["Int32","OperationArgument","movediscrete"]
vars["closing_diameter"]=["Float64","OperationArgument","pick"]
vars["closing_speed"]=["Float64","OperationArgument","pick"]
vars["closing_force"]=["Float64","OperationArgument","pick"]
vars["opening_diameter"]=["Float64","OperationArgument","place"]
vars["opening_speed"]=["Float64","OperationArgument","place"]
vars["opening_force"]=["Float64","OperationArgument","place"]
vars["stop"]=["Clock","Operation"]
vars["movejoint"]=["Clock","Operation"]
vars["target_q0"]=["Float64","OperationArgument","movejoint"]
vars["target_q1"]=["Float64","OperationArgument","movejoint"]
vars["target_q2"]=["Float64","OperationArgument","movejoint"]
vars["target_q3"]=["Float64","OperationArgument","movejoint"]
vars["target_q4"]=["Float64","OperationArgument","movejoint"]
vars["target_q5"]=["Float64","OperationArgument","movejoint"]
vars["movecartesian"]=["Clock","Operation"]
vars["target_x"]=["Float64","OperationArgument","movecartesian"]
vars["target_y"]=["Float64","OperationArgument","movecartesian"]
vars["target_z"]=["Float64","OperationArgument","movecartesian"]
vars["target_rx"]=["Float64","OperationArgument","movecartesian"]
vars["target_ry"]=["Float64","OperationArgument","movecartesian"]
vars["target_rz"]=["Float64","OperationArgument","movecartesian"]
vars["setvelocity"]=["Clock","Operation"]
vars["target_v"]=["Float64","OperationArgument","setvelocity"]

vars_list = list(vars)

# Define which variables are provided by the controller FMU
vars_controller = ["moveDiscreteCommand",
                   "MovementArgs_target_X",
                   "MovementArgs_target_Y",
                   "MovementArgs_target_Z",
                   "closeGripperCommand",
                   "openGripperCommand"]


# For mapping FMU: write down which variables are to be logged from the platform mapping FMU
vars_log_pmFMU = {}
vars_log_pmFMU["q0"] = "Float64"
vars_log_pmFMU["q1"] = "Float64"
vars_log_pmFMU["q2"] = "Float64"
vars_log_pmFMU["q3"] = "Float64"
vars_log_pmFMU["q4"] = "Float64"
vars_log_pmFMU["q5"] = "Float64"
vars_log_pmFMU["qd0"] = "Float64"
vars_log_pmFMU["qd1"] = "Float64"
vars_log_pmFMU["qd2"] = "Float64"
vars_log_pmFMU["qd3"] = "Float64"
vars_log_pmFMU["qd4"] = "Float64"
vars_log_pmFMU["qd5"] = "Float64"
vars_log_pmFMU["qdd0"] = "Float64"
vars_log_pmFMU["qdd1"] = "Float64"
vars_log_pmFMU["qdd2"] = "Float64"
vars_log_pmFMU["qdd3"] = "Float64"
vars_log_pmFMU["qdd4"] = "Float64"
vars_log_pmFMU["qdd5"] = "Float64"
vars_log_pmFMU["t0"] = "Float64"
vars_log_pmFMU["t1"] = "Float64"
vars_log_pmFMU["t2"] = "Float64"
vars_log_pmFMU["t3"] = "Float64"
vars_log_pmFMU["t4"] = "Float64"
vars_log_pmFMU["t5"] = "Float64"
vars_log_pmFMU["x"] = "Float64"
vars_log_pmFMU["y"] = "Float64"
vars_log_pmFMU["z"] = "Float64"
vars_log_pmFMU["rx"] = "Float64"
vars_log_pmFMU["ry"] = "Float64"
vars_log_pmFMU["rz"] = "Float64"

vars_log_pmFMU_list = list(vars_log_pmFMU)

# For RabbitMQ FMU: write down which variables are to be logged from the co-simulation via RMQFMU (connected to the pmFMU)

vars_log_RMQFMU = {}
vars_log_RMQFMU["q0"] = "Float64"
vars_log_RMQFMU["q1"] = "Float64"
vars_log_RMQFMU["q2"] = "Float64"
vars_log_RMQFMU["q3"] = "Float64"
vars_log_RMQFMU["q4"] = "Float64"
vars_log_RMQFMU["q5"] = "Float64"

vars_log_RMQFMU_list = list(vars_log_RMQFMU)

def create_mappingfmu_skeleton():

    print("*** (MappingFMU - model.py) For def __init__***")
    for k,v in vars.items():
        if v[0] == "Boolean":
            print("self." + k + " = False")
        elif v[0] == "Float64":
            print("self." + k + " = 0.0")
        elif v[0] == "Int32":
            print("self." + k + " = 0")
        elif v[0] == "String":
            print('self.' + k + ' = ""')
        elif v[0] == "Clock":
            print('self.' + k + ' = False')
    
    if len(vars_log_pmFMU)>0:
        for k,v in vars_log_pmFMU.items():
            if v == "Boolean":
                print("self." + k + " = False")
            elif v == "Float64":
                print("self." + k + " = 0.0")
            elif v == "Int32":
                print("self." + k + " = 0")
            elif v == "String":
                print('self.' + k + ' = ""')
            elif v == "Clock":
                print('self.' + k + ' = False')
        

    print("*** (MappingFMU - model.py) For self.clocked_variables***")
    for k,v in vars.items():
        print(str(vars_list.index(k)) + ': "' + k + '",')
    
    print("*** (MappingFMU - model.py) For self.reference_to_attribute***")
    if len(vars_log_pmFMU)>0:
        for k,v in vars_log_pmFMU.items():
            print(str(vars_log_pmFMU_list.index(k) + len(vars_list)) + ': "' + k + '",')



    print("*** (MappingFMU - model.py) For def fmi3SerializeFmuState***")
    for k,v in vars.items():
        print('self.' + k + ',')
    
    if len(vars_log_pmFMU)>0:
        for k,v in vars_log_pmFMU.items():
            print('self.' + k + ',')

    print("*** (MappingFMU - model.py) For def fmi3DeserializeFmuState (1st part)***")
    for k,v in vars.items():
        print(k + ',')

    if len(vars_log_pmFMU)>0:
        for k,v in vars_log_pmFMU.items():
            print(k + ',')

    print("*** (MappingFMU - model.py) For def fmi3DeserializeFmuState (2nd part)***")
    for k,v in vars.items():
        print('self.' + k + ' = ' + k)
    
    if len(vars_log_pmFMU)>0:
        for k,v in vars_log_pmFMU.items():
            print('self.' + k + ' = ' + k)


variables_init = '<ModelVariables>'
variables_end = '</ModelVariables>'
text_input = '''<String name="{}" valueReference="{}" variability="discrete" causality="input" clocks="{}">
      <Start value="" />
    </String>'''

text_output = '''<String name="{}" valueReference="{}" variability="discrete" causality="output" initial="calculated" clocks="{}"/>'''

text_float64_input = '''<Float64 name="{}" valueReference="{}" causality="input" variability="continuous" start="0.0" clocks="{}"/>'''

text_float64_output = '''<Float64 name="{}" valueReference="{}" causality="output" variability="continuous" initial="calculated" clocks="{}"/>'''

text_int32_input = '''<Int32 name="{}" valueReference="{}" causality="input" variability="discrete" start="0" clocks="{}"/>'''

text_int32_output = '''<Int32 name="{}" valueReference="{}" causality="output" variability="discrete" initial="calculated" clocks="{}"/>'''

text_boolean_input = '''<Boolean name="{}" valueReference="{}" causality="input" variability="discrete" start="false" clocks="{}"/>'''

text_boolean_output = '''<Boolean name="{}" valueReference="{}" causality="output" variability="discrete" initial="calculated" clocks="{}"/>'''

text_constant_clock = '''<Clock name="{}" valueReference="{}" causality="input" intervalVariability="constant" intervalDecimal="1.0" clocks="{}"/>'''

text_triggered_clock_input = '''<Clock name="{}" valueReference="{}" causality="input" intervalVariability="triggered" clocks="{}"/>'''

text_triggered_clock_output = '''<Clock name="{}" valueReference="{}" causality="output" intervalVariability="triggered" clocks="{}"/>'''

ms_init = '<ModelStructure>'
ms_end = '</ModelStructure>'

structure_output = '''<Output valueReference="{}" dependencies="{}" />'''
structure_initial_unknown = '''<InitialUnknown valueReference="{}" dependencies="{}" />'''

def create_mappingfmu_mdxml():
    print("*** For modeldescription.xml in MappingFMU ***")
    # modeldescription.xml helper

    result_output_structure = ""
    result_initial_unknown_structure = ""

    print('***** ModelDescription.xml - ModelVariables *****')
    print(variables_init)
    for k,v in vars.items():
        if len(v)==3:
            if "InputEvent" in v[1]:
                if k in vars_controller:
                    if v[0] == "Boolean":
                        print(text_boolean_input.format(k,str(vars_list.index(k)),vars_list.index(v[2])))
                    elif v[0] == "Float64":
                        print(text_float64_input.format(k,str(vars_list.index(k)),vars_list.index(v[2])))
                    elif v[0] == "Int32":
                        print(text_int32_input.format(k,str(vars_list.index(k)),vars_list.index(v[2])))
                    elif v[0] == "String":
                        print(text_input.format(k,str(vars_list.index(k)),vars_list.index(v[2])))
                    elif v[0] == "Clock":
                        print(text_triggered_clock_input.format(k,str(vars_list.index(k)),vars_list.index(v[2])))
                else:
                    if v[0] == "Boolean":
                        print(text_boolean_output.format(k,str(vars_list.index(k)),vars_list.index(v[2])))
                    elif v[0] == "Float64":
                        print(text_float64_output.format(k,str(vars_list.index(k)),vars_list.index(v[2])))
                    elif v[0] == "Int32":
                        print(text_int32_output.format(k,str(vars_list.index(k)),vars_list.index(v[2])))
                    elif v[0] == "String":
                        print(text_output.format(k,str(vars_list.index(k)),vars_list.index(v[2])))
                    elif v[0] == "Clock":
                        print(text_triggered_clock_output.format(k,str(vars_list.index(k)),""))
                    result_output_structure = result_output_structure + structure_output.format(vars_list.index(k),vars_list.index(v[2])) + "\n"
                    result_initial_unknown_structure = result_initial_unknown_structure + structure_initial_unknown.format(vars_list.index(k),vars_list.index(v[2])) + "\n"
            elif "Operation" in v[1]:
                if v[0] == "Boolean":
                    print(text_boolean_input.format(k,str(vars_list.index(k)),vars_list.index(v[2])))
                elif v[0] == "Float64":
                    print(text_float64_input.format(k,str(vars_list.index(k)),vars_list.index(v[2])))
                elif v[0] == "Int32":
                    print(text_int32_input.format(k,str(vars_list.index(k)),vars_list.index(v[2])))
                elif v[0] == "String":
                    print(text_input.format(k,str(vars_list.index(k)),vars_list.index(v[2])))
                elif v[0] == "Clock":
                    print(text_triggered_clock_input.format(k,str(vars_list.index(k)),vars_list.index(v[2])))
        else:
            if "InputEvent" in v[1]:
                if k in vars_controller:
                    if v[0] == "Boolean":
                        print(text_boolean_input.format(k,str(vars_list.index(k)),""))
                    elif v[0] == "Float64":
                        print(text_float64_input.format(k,str(vars_list.index(k)),""))
                    elif v[0] == "Int32":
                        print(text_int32_input.format(k,str(vars_list.index(k)),""))
                    elif v[0] == "String":
                        print(text_input.format(k,str(vars_list.index(k)),""))
                    elif v[0] == "Clock":
                        print(text_triggered_clock_input.format(k,str(vars_list.index(k)),""))
                else:
                    if v[0] == "Boolean":
                        print(text_boolean_output.format(k,str(vars_list.index(k)),""))
                    elif v[0] == "Float64":
                        print(text_float64_output.format(k,str(vars_list.index(k)),""))
                    elif v[0] == "Int32":
                        print(text_int32_output.format(k,str(vars_list.index(k)),""))
                    elif v[0] == "String":
                        print(text_output.format(k,str(vars_list.index(k)),""))
                    elif v[0] == "Clock":
                        print(text_triggered_clock_output.format(k,str(vars_list.index(k)),""))
                    result_output_structure = result_output_structure + structure_output.format(vars_list.index(k),"") + "\n"
                    result_initial_unknown_structure = result_initial_unknown_structure + structure_initial_unknown.format(vars_list.index(k),"") + "\n"
            elif "Operation" in v[1]:
                if v[0] == "Boolean":
                    print(text_boolean_input.format(k,str(vars_list.index(k)),""))
                elif v[0] == "Float64":
                    print(text_float64_input.format(k,str(vars_list.index(k)),""))
                elif v[0] == "Int32":
                    print(text_int32_input.format(k,str(vars_list.index(k)),""))
                elif v[0] == "String":
                    print(text_input.format(k,str(vars_list.index(k)),""))
                elif v[0] == "Clock":
                    print(text_triggered_clock_input.format(k,str(vars_list.index(k)),""))

    if len(vars_log_pmFMU)>0:
        for k,v in vars_log_pmFMU.items():
            if v == "Boolean":
                print(text_boolean_output.format(k,str(vars_log_pmFMU_list.index(k) + len(vars_list)),""))
            elif v == "Float64":
                print(text_float64_output.format(k,str(vars_log_pmFMU_list.index(k) + len(vars_list)),""))
            elif v == "Int32":
                print(text_int32_output.format(k,str(vars_log_pmFMU_list.index(k) + len(vars_list)),""))
            elif v == "String":
                print(text_output.format(k,str(vars_log_pmFMU_list.index(k) + len(vars_list)),""))
            elif v[0] == "Clock":
                    print(text_triggered_clock_output.format(k,str(vars_log_pmFMU_list.index(k) + len(vars_list)),""))
            result_output_structure = result_output_structure + structure_output.format(vars_log_pmFMU_list.index(k) + len(vars_list),"") + "\n"
            result_initial_unknown_structure = result_initial_unknown_structure + structure_initial_unknown.format(vars_log_pmFMU_list.index(k) + len(vars_list),"") + "\n"

    print(variables_end)

    print('***** ModelDescription.xml - ModelStructure ******')
    print(ms_init)
    print(result_output_structure)
    print(result_initial_unknown_structure)
    print(ms_end)




def create_dmodelfmu_data_struct():
    print("*** For dmodelFMU data struct (defs_fmi.h) ***")
    print("typedef struct {")
    for k,v in vars.items():
        if v[0] == "Boolean":
            print("\tbool " + k + ";")
        elif v[0] == "Float64":
            print("\tdouble " + k + ";")
        elif v[0] == "Int32":
            print("\tint " + k + ";")
        elif v[0] == "String":
            print("\tchar *" + k + ";")
        elif v[0] == "Clock":
            print("\tbool " + k + ";")

    print("\tchar *state;")
    print("\tchar *target_state;")
    print("\tchar *status;")
    print("\tbool done;")
    print("\tbool terminateSimulation;")
    print("} ModelData;")

def create_dmodelfmu_mdxml():
    print("*** For modeldescription.xml in dmodelFMU ***")
    # modeldescription.xml helper

    result_output_structure = ""
    result_initial_unknown_structure = ""

    print('***** ModelDescription.xml - ModelVariables *****')
    print(variables_init)
    for k,v in vars.items():
        if len(v)==3:
            if "InputEvent" in v[1]:
                if v[0] == "Boolean":
                    print(text_boolean_input.format(k,str(vars_list.index(k)),vars_list.index(v[2])))
                elif v[0] == "Float64":
                    print(text_float64_input.format(k,str(vars_list.index(k)),vars_list.index(v[2])))
                elif v[0] == "Int32":
                    print(text_int32_input.format(k,str(vars_list.index(k)),vars_list.index(v[2])))
                elif v[0] == "String":
                    print(text_input.format(k,str(vars_list.index(k)),vars_list.index(v[2])))
                elif v[0] == "Clock":
                    print(text_triggered_clock_input.format(k,str(vars_list.index(k)),vars_list.index(v[2])))
            elif "Operation" in v[1]:
                if v[0] == "Boolean":
                    print(text_boolean_output.format(k,str(vars_list.index(k)),vars_list.index(v[2])))
                elif v[0] == "Float64":
                    print(text_float64_output.format(k,str(vars_list.index(k)),vars_list.index(v[2])))
                elif v[0] == "Int32":
                    print(text_int32_output.format(k,str(vars_list.index(k)),vars_list.index(v[2])))
                elif v[0] == "String":
                    print(text_output.format(k,str(vars_list.index(k)),vars_list.index(v[2])))
                elif v[0] == "Clock":
                    print(text_triggered_clock_output.format(k,str(vars_list.index(k)),vars_list.index(v[2])))
                result_output_structure = result_output_structure + structure_output.format(vars_list.index(k),vars_list.index(v[2])) + "\n"
                result_initial_unknown_structure = result_initial_unknown_structure + structure_initial_unknown.format(vars_list.index(k),vars_list.index(v[2])) + "\n"
        else:
            if "InputEvent" in v[1]:
                if v[0] == "Boolean":
                    print(text_boolean_input.format(k,str(vars_list.index(k)),""))
                elif v[0] == "Float64":
                    print(text_float64_input.format(k,str(vars_list.index(k)),""))
                elif v[0] == "Int32":
                    print(text_int32_input.format(k,str(vars_list.index(k)),""))
                elif v[0] == "String":
                    print(text_input.format(k,str(vars_list.index(k)),""))
                elif v[0] == "Clock":
                    print(text_triggered_clock_input.format(k,str(vars_list.index(k)),""))
            elif "Operation" in v[1]:
                if v[0] == "Boolean":
                    print(text_boolean_output.format(k,str(vars_list.index(k)),""))
                elif v[0] == "Float64":
                    print(text_float64_output.format(k,str(vars_list.index(k)),""))
                elif v[0] == "Int32":
                    print(text_int32_output.format(k,str(vars_list.index(k)),""))
                elif v[0] == "String":
                    print(text_output.format(k,str(vars_list.index(k)),""))
                elif v[0] == "Clock":
                    print(text_triggered_clock_output.format(k,str(vars_list.index(k)),""))
                result_output_structure = result_output_structure + structure_output.format(vars_list.index(k),"") + "\n"
                result_initial_unknown_structure = result_initial_unknown_structure + structure_initial_unknown.format(vars_list.index(k),"") + "\n"


    print(text_output.format("state",len(vars_list),""))
    result_output_structure = result_output_structure + structure_output.format(len(vars_list),"") + "\n"
    result_initial_unknown_structure = result_initial_unknown_structure + structure_initial_unknown.format(len(vars_list),"") + "\n"
    print(text_output.format("target_state",len(vars_list)+1,""))
    result_output_structure = result_output_structure + structure_output.format(len(vars_list)+1,"") + "\n"
    result_initial_unknown_structure = result_initial_unknown_structure + structure_initial_unknown.format(len(vars_list)+1,"") + "\n"
    print(text_output.format("status",len(vars_list)+2,""))
    result_output_structure = result_output_structure + structure_output.format(len(vars_list)+2,"") + "\n"
    result_initial_unknown_structure = result_initial_unknown_structure + structure_initial_unknown.format(len(vars_list)+2,"") + "\n"
    print(text_boolean_output.format("done",len(vars_list)+3,""))
    result_output_structure = result_output_structure + structure_output.format(len(vars_list)+3,"") + "\n"
    result_initial_unknown_structure = result_initial_unknown_structure + structure_initial_unknown.format(len(vars_list)+3,"") + "\n"
    print(text_boolean_input.format("terminateSimulation",len(vars_list)+4,""))
    
    print(variables_end)

    print('***** ModelDescription.xml - ModelStructure ******')
    print(ms_init)
    print(result_output_structure)
    print(result_initial_unknown_structure)
    print(ms_end)

## Update
model_data_buffer = 'comp->modelData.{}'
bool_buffer = 'comp->fmiBuffer.booleanBuffer[{}]'
float64_buffer = 'comp->fmiBuffer.float64Buffer[{}]'
int32_buffer = 'comp->fmiBuffer.int32Buffer[{}]'
string_buffer = 'comp->fmiBuffer.stringBuffer[{}]'
clock_buffer = 'comp->fmiBuffer.clockBuffer[{}]'

def create_dmodel_skeleton_c():
    print("*** For skeleton.c in dmodelFMU ***")
    print("void initialize(ModelInstance* comp) {")
    print("init(&comp->modelData);")
    for k,v in vars.items():
        if v[0] == "Boolean":
            print(bool_buffer.format(str(vars_list.index(k))) + " = " + model_data_buffer.format(k) + ";")
        elif v[0] == "Float64":
            print(float64_buffer.format(str(vars_list.index(k))) + " = " + model_data_buffer.format(k) + ";")
        elif v[0] == "Int32":
            print(int32_buffer.format(str(vars_list.index(k))) + " = " + model_data_buffer.format(k) + ";")
        elif v[0] == "String":
            print(string_buffer.format(str(vars_list.index(k))) + " = " + model_data_buffer.format(k) + ";")
    # State data
    print(string_buffer.format(len(vars_list)) + " = " + model_data_buffer.format("state") + ";")
    print(string_buffer.format(len(vars_list)+1) + " = " + model_data_buffer.format("target_state") + ";") 
    print(string_buffer.format(len(vars_list)+2) + " = " + model_data_buffer.format("status") + ";") 
    print(bool_buffer.format(len(vars_list)+3) + " = " + model_data_buffer.format("done") + ";") 
    print("}")

    print("void updateDiscreteStates(ModelInstance* comp) {")

    print("// Inputs and arguments")
    for k,v in vars.items():
        if "InputEvent" in v[1]:
            if v[0] == "Boolean":
                print(model_data_buffer.format(k) + " = " + bool_buffer.format(str(vars_list.index(k))) + ";")
            elif v[0] == "Float64":
                print(model_data_buffer.format(k) + " = " + float64_buffer.format(str(vars_list.index(k))) + ";")
            elif v[0] == "Int32":
                print(model_data_buffer.format(k) + " = " + int32_buffer.format(str(vars_list.index(k))) + ";")
            elif v[0] == "String":
                print(model_data_buffer.format(k) + " = " + string_buffer.format(str(vars_list.index(k))) + ";")
            elif v[0] == "Clock":
                print(model_data_buffer.format(k) + " = " + clock_buffer.format(str(vars_list.index(k))) + ";")

    print("// updateDiscreteStates in the module")
    print("tick(&comp->modelData);")
    print("// Outputs")
    for k,v in vars.items():
        if "Operation" in v[1]:
            if v[0] == "Boolean":
                print(bool_buffer.format(str(vars_list.index(k))) + " = " + model_data_buffer.format(k) + ";")
            elif v[0] == "Float64":
                print(float64_buffer.format(str(vars_list.index(k))) + " = " + model_data_buffer.format(k) + ";")
            elif v[0] == "Int32":
                print(int32_buffer.format(str(vars_list.index(k))) + " = " + model_data_buffer.format(k) + ";")
            elif v[0] == "String":
                print(string_buffer.format(str(vars_list.index(k))) + " = " + model_data_buffer.format(k) + ";")
            elif v[0] == "Clock":
                print(clock_buffer.format(str(vars_list.index(k))) + " = " + model_data_buffer.format(k) + ";")
    # State data
    print(string_buffer.format(len(vars_list)) + " = " + model_data_buffer.format("state") + ";")
    print(string_buffer.format(len(vars_list)+1) + " = " + model_data_buffer.format("target_state") + ";") 
    print(string_buffer.format(len(vars_list)+2) + " = " + model_data_buffer.format("status") + ";") 
    print(bool_buffer.format(len(vars_list)+3) + " = " + model_data_buffer.format("done") + ";") 
    print("}")
    

setStartValues_structure = 'M({}) = {};'
def create_setStartValues():
    print("*** For " + robosim_module_name + ".c (name depends on RoboSim module) in dmodelFMU ***")
    print("void setStartValues(ModelData *comp) {")
    print("comp->terminateSimulation = false;")
    for k,v in vars.items():
        if v[0] == "Boolean":
            print(setStartValues_structure.format(k,"false"))
        elif v[0] == "Float64":
            print(setStartValues_structure.format(k,"0.0"))
        elif v[0] == "Int32":
            print(setStartValues_structure.format(k,"0"))
        elif v[0] == "String":
            print(setStartValues_structure.format(k,'""'))
        elif v[0] == "Clock":
            print(setStartValues_structure.format(k,"false"))
    print(setStartValues_structure.format("state",'""'))
    print(setStartValues_structure.format("target_state",'""'))
    print(setStartValues_structure.format("status",'""'))
    print(setStartValues_structure.format("done",'false'))
    print(setStartValues_structure.format("terminateSimulation",'false'))
    print("}")


read_input_structure = '''{2}if (fmi_data_interface->{0}) {{
        {{
            char _s0[256];
            sprintf(_s0, "%%s", "Found event {0}");
            printf("%%s", _s0);}}
        {{
            fmi_data_interface->{0} = false; // reset memory
            return create_M_{1}_input_{0}();
        }}
    }}'''
final_read_input_structure = '''else {{
        return create_M_{}_input__done_();
    }}'''
def set_read_input_interface():
    print("*** For read_input function in interface.h in dmodelFMU - NOTE: Update the arguments ***")
    idx = 0
    s = lambda idx: "else " if idx>0 else ""
    for k,v in vars.items():        
        if "InputEvent" == v[1]:
            print(read_input_structure.format(k,robosim_module_name,s(idx)))
        idx += 1
    print(final_read_input_structure.format(robosim_module_name))

write_output_structure = '''{2}if (_output_.type == M_{0}_output_{1}) {{
        {{
            fmi_data_interface->state = "some_state"; // update accordingly;
            fmi_data_interface->{1} = "some_value" // update accordingly;
        }}
    }}
'''
final_write_output_structure = '''else if (_output_.type == M_{}_output__done_) {{
    }}'''
def set_write_output_interface():
    print("*** For write_output function in interface.h in dmodelFMU - NOTE: Update the arguments ***")
    idx = 0
    s = lambda idx: "else " if idx>0 else ""
    for k,v in vars.items():
        if "Operation" == v[1]:
            print(write_output_structure.format(robosim_module_name,k,s(idx)))
        idx += 1
    print(final_write_output_structure.format(robosim_module_name))


def create_controllerfmu_mdxml(rmqfmu=False):
    print("*** For modeldescription.xml in controllerFMU (also valid for RMQFMU) ***")
    # modeldescription.xml helper

    result_output_structure = ""
    result_initial_unknown_structure = ""

    print('***** ModelDescription.xml - ModelVariables *****')
    print(variables_init)
    idx = 1
    if not rmqfmu:
        for k,v in vars.items():
            if len(v)==3:
                if k in vars_controller:
                    if v[0] == "Boolean":
                        print(text_boolean_output.format(k,str(vars_list.index(k)),vars_list.index(v[2])))
                    elif v[0] == "Float64":
                        print(text_float64_output.format(k,str(vars_list.index(k)),vars_list.index(v[2])))
                    elif v[0] == "Int32":
                        print(text_int32_output.format(k,str(vars_list.index(k)),vars_list.index(v[2])))
                    elif v[0] == "String":
                        print(text_output.format(k,str(vars_list.index(k)),vars_list.index(v[2])))
                    elif v[0] == "Clock":
                        print(text_triggered_clock_output.format(k,str(vars_list.index(k)),vars_list.index(v[2])))
                    result_output_structure = result_output_structure + structure_output.format(vars_list.index(k),vars_list.index(v[2])) + "\n"
                    result_initial_unknown_structure = result_initial_unknown_structure + structure_initial_unknown.format(vars_list.index(k),vars_list.index(v[2])) + "\n"
            else:
                if k in vars_controller:
                    if v[0] == "Boolean":
                        print(text_boolean_output.format(k,str(vars_list.index(k)),""))
                    elif v[0] == "Float64":
                        print(text_float64_output.format(k,str(vars_list.index(k)),""))
                    elif v[0] == "Int32":
                        print(text_int32_output.format(k,str(vars_list.index(k)),""))
                    elif v[0] == "String":
                        print(text_output.format(k,str(vars_list.index(k)),""))
                    elif v[0] == "Clock":
                        print(text_triggered_clock_output.format(k,str(vars_list.index(k)),""))
                    result_output_structure = result_output_structure + structure_output.format(vars_list.index(k),"") + "\n"
                    result_initial_unknown_structure = result_initial_unknown_structure + structure_initial_unknown.format(vars_list.index(k),"") + "\n"
    if len(vars_log_pmFMU_list) > 0:
            for k,v in vars_log_pmFMU.items():
                if v == "Boolean":
                    print(text_boolean_output.format(k,str(vars_log_pmFMU_list.index(k) + len(vars_list)),""))
                    print(text_boolean_input.format(k,str(vars_log_pmFMU_list.index(k) + len(vars_list)),""))
                elif v == "Float64":
                    print(text_float64_input.format(k,str(vars_log_pmFMU_list.index(k) + len(vars_list)),""))
                elif v == "Int32":
                    print(text_int32_input.format(k,str(vars_log_pmFMU_list.index(k) + len(vars_list)),""))
                elif v == "String":
                    print(text_input.format(k,str(vars_log_pmFMU_list.index(k) + len(vars_list)),""))
                elif v[0] == "Clock":
                    print(text_triggered_clock_input.format(k,str(vars_log_pmFMU_list.index(k) + len(vars_list)),""))
    if rmqfmu:
        iter = 0
        for k,v in vars.items():
            if len(v)==3:
                if k in vars_controller:
                    if v[0] == "Boolean":
                        print(text_boolean_output.format(k,str(20+iter),vars_list.index(v[2])))
                    elif v[0] == "Float64":
                        print(text_float64_output.format(k,str(20+iter),vars_list.index(v[2])))
                    elif v[0] == "Int32":
                        print(text_int32_output.format(k,str(20+iter),vars_list.index(v[2])))
                    elif v[0] == "String":
                        print(text_output.format(k,str(20+iter),vars_list.index(v[2])))
                    elif v[0] == "Clock":
                        print(text_triggered_clock_output.format(k,str(20+iter),vars_list.index(v[2])))
                    result_output_structure = result_output_structure + structure_output.format(vars_list.index(k),vars_list.index(v[2])) + "\n"
                    result_initial_unknown_structure = result_initial_unknown_structure + structure_initial_unknown.format(vars_list.index(k),vars_list.index(v[2])) + "\n"
                    idx += 1
                    iter += 1
            else:
                if k in vars_controller:
                    if v[0] == "Boolean":
                        print(text_boolean_output.format(k,str(20+iter),""))
                    elif v[0] == "Float64":
                        print(text_float64_output.format(k,str(20+iter),""))
                    elif v[0] == "Int32":
                        print(text_int32_output.format(k,str(20+iter),""))
                    elif v[0] == "String":
                        print(text_output.format(k,str(20+iter),""))
                    elif v[0] == "Clock":
                        print(text_triggered_clock_output.format(k,str(20+iter),""))
                    result_output_structure = result_output_structure + structure_output.format(vars_list.index(k),"") + "\n"
                    result_initial_unknown_structure = result_initial_unknown_structure + structure_initial_unknown.format(vars_list.index(k),"") + "\n"
                    idx += 1
                    iter += 1

        if len(vars_log_RMQFMU_list) > 0:
            for k,v in vars_log_RMQFMU.items():
                if len(v)==3:
                    if v == "Boolean":
                        print(text_boolean_input.format(k,str(20+vars_log_RMQFMU_list.index(k) + idx-1),vars_list.index(v[2])))
                    elif v == "Float64":
                        print(text_float64_input.format(k,str(20+vars_log_RMQFMU_list.index(k) + idx-1),vars_list.index(v[2])))
                    elif v == "Int32":
                        print(text_int32_input.format(k,str(20+vars_log_RMQFMU_list.index(k) + idx-1),vars_list.index(v[2])))
                    elif v == "String":
                        print(text_input.format(k,str(20+vars_log_RMQFMU_list.index(k) + idx-1),vars_list.index(v[2])))
                    elif v[0] == "Clock":
                        print(text_triggered_clock_input.format(k,str(20+vars_log_RMQFMU_list.index(k) + idx-1),vars_list.index(v[2])))
                else:
                    if v == "Boolean":
                        print(text_boolean_input.format(k,str(20+vars_log_RMQFMU_list.index(k) + idx-1),""))
                    elif v == "Float64":
                        print(text_float64_input.format(k,str(20+vars_log_RMQFMU_list.index(k) + idx-1),""))
                    elif v == "Int32":
                        print(text_int32_input.format(k,str(20+vars_log_RMQFMU_list.index(k) + idx-1),""))
                    elif v == "String":
                        print(text_input.format(k,str(20+vars_log_RMQFMU_list.index(k) + idx-1),""))
                    elif v[0] == "Clock":
                        print(text_triggered_clock_input.format(k,str(20+vars_log_RMQFMU_list.index(k) + idx-1),""))


    # for inputs (optional)
    # for k,v in vars.items():
    #     if k in vars_controller_inputs:
    #         if v[0] == "Boolean":
    #             print(text_boolean_input.format(k,str(vars_list.index(k))))
    #         elif v[0] == "Float64":
    #             print(text_float64_input.format(k,str(vars_list.index(k))))
    #         elif v[0] == "Int32":
    #             print(text_int32_input.format(k,str(vars_list.index(k))))
    #         elif v[0] == "String":
    #             print(text_input.format(k,str(vars_list.index(k))))



    print(variables_end)

    print('***** ModelDescription.xml - ModelStructure ******')
    print(ms_init)
    print(result_output_structure)
    print(result_initial_unknown_structure)
    print(ms_end)

def create_controllerfmu_skeleton():

    print("*** (controllerFMU - model.py) For def __init__***")
    for k,v in vars.items():
        if (k in vars_controller):
            if v[0] == "Boolean":
                print("self." + k + " = False")
            elif v[0] == "Float64":
                print("self." + k + " = 0.0")
            elif v[0] == "Int32":
                print("self." + k + " = 0")
            elif v[0] == "String":
                print('self.' + k + ' = ""')
            elif v[0] == "Clock":
                print('self.' + k + ' = False')
    if len(vars_log_pmFMU)>0:
        for k,v in vars_log_pmFMU.items():
            if v == "Boolean":
                print("self." + k + " = False")
            elif v == "Float64":
                print("self." + k + " = 0.0")
            elif v == "Int32":
                print("self." + k + " = 0")
            elif v == "String":
                print('self.' + k + ' = ""')
            elif v == "Clock":
                print('self.' + k + ' = False')
    

    print("*** (controllerFMU - model.py) For self.clocked_variables***")
    for k,v in vars.items():
        if k in vars_controller:
            print(str(vars_list.index(k)) + ': "' + k + '",')

    print("*** (controllerFMU - model.py) For self.reference_to_attribute***")
    if len(vars_log_pmFMU)>0:
        for k,v in vars_log_pmFMU.items():
            print(str(vars_log_pmFMU_list.index(k) + len(vars_list)) + ': "' + k + '",')

    print("*** (controllerFMU - model.py) For def fmi3SerializeFmuState***")
    for k,v in vars.items():
        if k in vars_controller:
            print('self.' + k + ',')
    if len(vars_log_pmFMU)>0:
        for k,v in vars_log_pmFMU.items():
            print('self.' + k + ',')

    print("*** (controllerFMU - model.py) For def fmi3DeserializeFmuState (1st part)***")
    for k,v in vars.items():
        if k in vars_controller:
            print(k + ',')
    if len(vars_log_pmFMU)>0:
        for k,v in vars_log_pmFMU.items():
            print(k + ',')

    print("*** (controllerFMU - model.py) For def fmi3DeserializeFmuState (2nd part)***")
    for k,v in vars.items():
        if k in vars_controller:
            print('self.' + k + ' = ' + k)

    if len(vars_log_pmFMU)>0:
        for k,v in vars_log_pmFMU.items():
            print('self.' + k + ' = ' + k)

def create_connections(rmqfmu=False):
    controller_name = "controller"
    if rmqfmu:
        controller_name = "rmqfmu"
    
    timed_struct_connections = ''
    timed_controller_connections = ''
    timed_logging_connections = ''
    clocked_struct_connections = ''
    clocked_controller_connections = ''
    clocked_logging_connections = ''
    print("*** For connections ***")
    
    for k,v in vars.items():
        if (v[0] == "Clock") or (v[2] != None):            
            if "InputEvent" in v[1]:
                if k in vars_controller:
                    clocked_controller_connections += '"{0}.{1}" : ["dmodel.{1}","mapping.{1}"],\n'.format(controller_name,k)
                else:
                    clocked_struct_connections += '"mapping.{}" : ["dmodel.{}"],\n'.format(k,k)
            elif "Operation" in v[1]:
                clocked_struct_connections += '"dmodel.{}" : ["mapping.{}"],\n'.format(k,k)

        else:
            if "InputEvent" in v[1]:
                if k in vars_controller:
                    timed_controller_connections += '"{0}.{1}" : ["dmodel.{1}","mapping.{1}"],\n'.format(controller_name,k)
                else:
                    timed_struct_connections += '"mapping.{}" : ["dmodel.{}"],\n'.format(k,k)
            elif "Operation" in v[1]:
                timed_struct_connections += '"dmodel.{}" : ["mapping.{}"],\n'.format(k,k)
    if rmqfmu:
        for k,v in vars_log_RMQFMU.items():
            timed_logging_connections += '"mapping.{1}" : ["{0}.{1}"],\n'.format(controller_name,k)
    
    if len(vars_log_pmFMU_list)>0:
        for k,v in vars_log_pmFMU.items():
            timed_logging_connections += '"mapping.{1}" : ["{0}.{1}"],\n'.format(controller_name,k)

    print("*** Clocked connections ***")
    print(clocked_controller_connections[:-1])
    print(clocked_struct_connections[:-1])
    print(clocked_logging_connections[:-2])
    print("*** Timed connections ***")
    print(timed_controller_connections[:-1])
    print(timed_struct_connections[:-1])
    print(timed_logging_connections[:-2])

if __name__=='__main__':
    print("Miscellaneous 1 - Step 5\n")
    create_connections(rmqfmu=False)
    
    print("\n\n\n\nMiscellaneous 2 - Step 6\n")
    create_mappingfmu_mdxml()
    
    print("\n\n\n\nMiscellaneous 3 - Steps 6 and 7\n")
    create_mappingfmu_skeleton()
    
    print("\n\n\n\nMiscellaneous 4 - Step 8\n")
    create_dmodelfmu_mdxml()
    
    print("\n\n\n\nMiscellaneous 5 - Step 9\n")
    create_dmodelfmu_data_struct()
    
    print("\n\n\n\nMiscellaneous 6 - Step 10\n")
    set_read_input_interface()
    
    print("\n\n\n\nMiscellaneous 7 - Step 10\n")
    set_write_output_interface()
    
    print("\n\n\n\nMiscellaneous 8 - Step 11\n")
    create_dmodel_skeleton_c()
    
    print("\n\n\n\nMiscellaneous 9 - Step 11\n")
    create_setStartValues()
    
    print("\n\n\n\nMiscellaneous 10 - Steps 12 and 13\n")
    create_controllerfmu_skeleton()
    
    print("\n\n\n\nMiscellaneous 11 - Step 13\n")
    create_controllerfmu_mdxml(rmqfmu=False)
    
    
    
