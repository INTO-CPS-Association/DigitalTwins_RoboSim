# Author: Santiago Gil
import numpy as np
import pandas as pd
import matplotlib.pyplot as plt
import argparse
from pathlib import Path


parser = argparse.ArgumentParser(description="A script that accepts one mandatory and one optional argument.")
    
# Path (mandatory)
parser.add_argument("path", type=str, help="Mandatory path argument")

# Optional flag for saving the plot
parser.add_argument("--save", action="store_true", help="Flag to save resulting plot")

args = parser.parse_args()

filename = args.path

save_file = args.save

script_path = Path(__file__).resolve().parent

font = {'font.family' : 'monospace',
        'font.weight' : 'bold',
        'axes.titlesize'   : 14,
        'axes.labelsize'   : 12,
        'legend.fontsize' : 8,
        'xtick.labelsize': 8,
        'ytick.labelsize': 8,
       }

plt.rcParams.update(font)

df_cosim = pd.read_csv(filename)

i = 1
fig, axes = plt.subplots(2,2, figsize=(16,16))
plt.subplot(2,2,i)


x_axis_values = df_cosim["sim_time"].to_list()
super_dense_time_values = df_cosim["super_dense_time"].to_list()
dmodel_event_axis_values = df_cosim["dmodel.movediscrete"].to_list()
controller_event_axis_values = df_cosim["controller.moveDiscreteCommand"].to_list()


plt.step(x_axis_values,controller_event_axis_values)
plt.title("({}) Controller's triggered clock".format(i))
plt.yticks([1.0, 0.0],["True","False"])
plt.legend(['moveDiscreteCommand'])
plt.xlabel('simulation time [s]')
plt.ylabel('state')
plt.grid()
plt.tight_layout()
i += 1

# plt.subplot(3,2,i)
# plt.step(x_axis_values,dmodel_event_axis_values)
# plt.title("({}) d-model FMU's triggered clock".format(i))
# plt.yticks([1.0, 0.0],["True","False"])
# plt.legend(['movediscrete (Operation)'])
# plt.xlabel('simulation time [s]')
# plt.ylabel('state')
# plt.grid()
# plt.tight_layout()
# i += 1


plt.subplot(2,2,i)
controller_targetX_values = df_cosim["controller.MovementArgs_target_X"].to_list()
controller_targetY_values = df_cosim["controller.MovementArgs_target_Y"].to_list()
controller_targetZ_values = df_cosim["controller.MovementArgs_target_Z"].to_list()


plt.step(x_axis_values,controller_targetX_values)
plt.step(x_axis_values,controller_targetY_values)
plt.step(x_axis_values,controller_targetZ_values)
plt.title("({}) Controller's target positions".format(i))
plt.xlabel('simulation time [s]')
plt.ylabel('discrete position (X,Y,Z)')
plt.legend(['MovementArgs.target_X','MovementArgs.target_Y','MovementArgs.target_Z'])
plt.grid()
plt.tight_layout()
i += 1

plt.subplot(2,2,i)

df_cosim.plot(x = "sim_time",y = ["mapping.q0","mapping.q1","mapping.q2","mapping.q3","mapping.q4","mapping.q5",],
             figsize=(12,12),
             ax=axes[1,0])
plt.title("({}) Joint positions (Mapping)".format(i))
plt.xlabel('simulation time [s]')
plt.ylabel('position [rad]')
plt.legend(['q0','q1','q2','q3','q4','q5'])
plt.grid()
plt.tight_layout()
i += 1

# plt.subplot(3,2,i)
# plt.step(x_axis_values,super_dense_time_values)
# plt.title("({}) Super dense time".format(i))
# plt.legend(['super_dense_time'])
# plt.xlabel('simulation time [s]')
# plt.ylabel('N° events')
# plt.grid()
# plt.tight_layout()
# i += 1

plt.subplot(2,2,i)
mapping_robotStopped_values = df_cosim["mapping.robotStopped"].to_list()
mapping_moveCompleted_values = df_cosim["mapping.moveCompleted"].to_list()

plt.step(x_axis_values,mapping_robotStopped_values)
plt.step(x_axis_values,mapping_moveCompleted_values)
plt.title("({}) Platform's events (Mapping)".format(i))
plt.yticks([1.0, 0.0],["True","False"])
plt.xlabel('simulation time [s]')
plt.ylabel('state')
plt.legend(['robotStopped','moveCompleted'])
plt.grid()
plt.tight_layout()
i += 1




plt.show()
if save_file:
    fig.savefig(script_path / 'plot.pdf', dpi=300)
    fig.savefig(script_path / 'plot.png', dpi=300)
    print("Plot saved in " + str(script_path))