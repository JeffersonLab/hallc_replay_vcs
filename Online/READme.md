# Online monitor

## Overview

1.  Main directory hallc_replay_vcs/Online with subdirectories: bin, config,database,monitoring,ROOTfiles and scripts.
2.  Background processes are running which automatically fill the DBASE/COIN/standard.kinematics and Online/database/rundb_coin.json
3.  To monitor the background process use Online/bin/manage_processes
    *Help: manage_processes -h
    *Stop:  manage_processes stop
    *Start:  manage_processes start
    *restart:   manage_processes restart
    *expert mode:  manage_processes expert
4.  To monitor the singles rates
    *In the script run_full_replay.csh the script /Online/bin/monitor_singles is run
    *monitor_singles will do the following:            "
    *Replay the data using the latest run and 100k events if not specified.
    *Run the good event counters
    *Fill a json database with useful run information: database/rundb_hms.json and database/countdb_shms.json   
5. To monitor database and add comment
     *To see the table, run:Online/bin/make_vcs_table
     *To add a comment, run:Online/bin/run_comment nrun comment
6. In the code Ana/incudes/ReadHallCData.cc , code has been added to fill Online/database/VCSdb.json with the information from the full replay fits.


