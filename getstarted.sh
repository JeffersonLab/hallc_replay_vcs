#!/bin/bash

# after you create your own analysis directory "/home/cdaq/ruonan/hallc_replay_vcs" (to modify below), run once this executable to change all the hardcoded path in source files. 
# don't forget to go to "Ana", then do: make clean && make

savepwd=$(pwd)
pwd
cd ${savepwd}
ls
sed -i -e "s%/home/cdaq/vcs2019/hallc_replay_vcs/%/w/hallc-scifs17exp/alphaE/ruonanli/analyzer/hallc_replay_vcs/%" run_ana_only.csh
sed -i -e "s%/home/cdaq/vcs2019/hallc_replay_vcs/%/w/hallc-scifs17exp/alphaE/ruonanli/analyzer/hallc_replay_vcs/%" set.csh
sed -i -e "s%/home/cdaq/vcs2019/hallc_replay_vcs/%/w/hallc-scifs17exp/alphaE/ruonanli/analyzer/hallc_replay_vcs/%" run_full_replay.csh
sed -i -e "s%/home/cdaq/vcs2019/hallc_replay_vcs/%/w/hallc-scifs17exp/alphaE/ruonanli/analyzer/hallc_replay_vcs/%" run_partial_replay.csh
sed -i -e "s%/home/cdaq/vcs2019/hallc_replay_vcs/%/w/hallc-scifs17exp/alphaE/ruonanli/analyzer/hallc_replay_vcs/%" build_singlecoinfile.csh
sed -i -e "s%/home/cdaq/vcs2019/hallc_replay_vcs/%/w/hallc-scifs17exp/alphaE/ruonanli/analyzer/hallc_replay_vcs/%" set.csh
sed -i -e "s%/home/cdaq/vcs2019/hallc_replay_vcs/%/w/hallc-scifs17exp/alphaE/ruonanli/analyzer/hallc_replay_vcs/%" Ana/HallCana.cc
sed -i -e "s%/home/cdaq/vcs2019/hallc_replay_vcs/%/w/hallc-scifs17exp/alphaE/ruonanli/analyzer/hallc_replay_vcs/%" Ana/includes/ReadHallCData.cc
sed -i -e "s%/home/cdaq/vcs2019/hallc_replay_vcs/%/w/hallc-scifs17exp/alphaE/ruonanli/analyzer/hallc_replay_vcs/%" Ana/includes/ReadTextFiles.cc
sed -i -e "s%/home/cdaq/vcs2019/hallc_replay_vcs/%/w/hallc-scifs17exp/alphaE/ruonanli/analyzer/hallc_replay_vcs/%" Ana/datainfo/get_runinfo.csh
sed -i -e "s%/home/cdaq/vcs2019/hallc_replay_vcs/%/w/hallc-scifs17exp/alphaE/ruonanli/analyzer/hallc_replay_vcs/%" Ana/datainfo/get_mergeinfo.csh


