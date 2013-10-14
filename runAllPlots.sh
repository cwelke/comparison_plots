#!/bin/bash

currentdate="141013"

if [ -d ~/Desktop/ZH_Plots/$currentdate/ ]; then
	echo "Directory ~/Desktop/ZH_Plots/$currentdate/ Already exists! making plots."
else
	echo "Directory ~/Desktop/ZH_Plots/$currentdate/ does not exist! Creating now."
	mkdir ~/Desktop/ZH_Plots/$currentdate/{data_bg{,/single_events},single_events}
fi

scp uaf-7:/home/users/cwelke/Analysis/Spring2013/comparisonlooper/photon_template_MET_data_2jetbins_all.root .

root -b -q drawAllComparisons.cc+
# root -b -q gethighMETtable.cc+
