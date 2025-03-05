# Author: Santiago Gil

def create_mappingfmu_mdxml():
    print("*** For modeldescription.xml ***")
    # modeldescription.xml helper
    text_input = '''<ScalarVariable name="{}" valueReference="{}" variability="discrete" causality="input">
          <String start="" />
        </ScalarVariable>'''

    text_output = '''<ScalarVariable name="{}" valueReference="{}" variability="discrete" causality="output">
          <String />
        </ScalarVariable>'''

    text_real_input = '''<ScalarVariable name="{}" valueReference="{}" causality="input" variability="continuous">
          <Real start="0.0" />
        </ScalarVariable>'''

    text_real_output = '''<ScalarVariable name="{}" valueReference="{}" causality="output" variability="continuous">
          <Real />
        </ScalarVariable>'''

    text_boolean_input = '''<ScalarVariable name="{}" valueReference="{}" causality="input" variability="discrete">
          <Boolean start="false"/>
        </ScalarVariable>'''

    text_boolean_output = '''<ScalarVariable name="{}" valueReference="{}" causality="output" variability="discrete">
          <Boolean />
        </ScalarVariable>'''

    structure_output = '''<Unknown index="{}" />'''

    result_output_structure = ""
    result_output_structure = result_output_structure + structure_output.format(1) + "\n"
    print(text_output.format("d_model_event","0"))
    for i in range(10):
        k = i+1
        print(text_real_output.format("d_model_event_args_"+str(i),str(k)))
        result_output_structure = result_output_structure + structure_output.format(k+1) + "\n"

    print(text_boolean_output.format("done","11"))
    result_output_structure = result_output_structure + structure_output.format(12) + "\n"
    print(text_output.format("state","12"))
    result_output_structure = result_output_structure + structure_output.format(13) + "\n"
    print(text_output.format("target_state","13"))
    result_output_structure = result_output_structure + structure_output.format(14) + "\n"
    print(text_output.format("status","14"))
    result_output_structure = result_output_structure + structure_output.format(15) + "\n"

    print(text_boolean_input.format("input_event_0","15"))
    for i in range(2):
        k = i+16
        print(text_real_input.format("input_event_0_args_"+str(i),str(k)))

    for i in range(4):
        k = i+18
        print(text_boolean_input.format("input_event_{}".format(i+1),str(k)))


    print(text_real_output.format("lv","26"))
    result_output_structure = result_output_structure + structure_output.format(23) + "\n"
    print(text_real_output.format("av","27"))
    result_output_structure = result_output_structure + structure_output.format(24) + "\n"

    print(text_boolean_input.format("closestAngle","28"))
    print(text_boolean_input.format("closestDistance","29"))
    print(text_real_input.format("closest_angle","30"))
    print(text_real_input.format("closest_distance","31"))


    print("*** For outputs in modeldescription.xml ***")
    print(result_output_structure)


if __name__=='__main__':
    create_mappingfmu_mdxml()
