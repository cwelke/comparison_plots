#!/bin/bash


scp uaf-7:/home/users/cwelke/Analysis/Spring2013/comparisonlooper/photon_template_MET_data_2jetbins_all.root .

root -b -q drawAllComparisons.cc+
# root -b -q gethighMETtable.cc+
