#ifndef ReadTextFiles_h
#define ReadTextFiles_h

#include <fstream>
#include <stdio.h>
#include <iostream>
#include <stdlib.h>
#include <TROOT.h>
#include <TStyle.h>
#include <TDataType.h>
#include <TString.h>
#include <string>
//#include "Utils.h"
//#include "Parameters.h"


using namespace std;
const int tot_runlist= 10; // update max number of runs

int ReadHeader(float (&inc)[26]);

bool IsBadRun(  int runint, int *badruntable); 

int FillSingleRunMissRefInfos(string datatype, int (&tr) [22], int run);

int FillEffInfos(string datatype,int *runtable, float (&HMS_E_eff)[tot_runlist], float (&HMS_H_eff)[tot_runlist],
		float (&SHMS_E_eff)[tot_runlist], float (&SHMS_H_eff)[tot_runlist]);

int FillTriggerInfos(string datatype,int *runtable, float (&HMS34rates)[tot_runlist], float (&SHMS34rates)[tot_runlist],
		     float (&HMS_ST)[tot_runlist], float (&SHMS_ST)[tot_runlist], float (&C_T)[tot_runlist], float (&All_T)[tot_runlist]);

int FillRunInfos( string datatype, int *runtable,  float (&Eb)[tot_runlist], float (&target)[tot_runlist], float (&HMS_p_central)[tot_runlist],
		 float (&SHMS_p_central)[tot_runlist], float (&HMS_th_central)[tot_runlist], float (&SHMS_th_central)[tot_runlist],
		 float (&HMS_run_l)[tot_runlist], float (&SHMS_run_l)[tot_runlist],
		 float (&HMS_B2_cur)[tot_runlist], float (&SHMS_B2_cur)[tot_runlist],
		 float (&HMS_B4_cut)[tot_runlist], float (&SHMS_B4_cut)[tot_runlist], float (&HMS_B2_cur_cut)[tot_runlist], float (&SHMS_B2_cur_cut)[tot_runlist],
		 float (&HMS_live)[tot_runlist], float (&SHMS_live)[tot_runlist]);

int FillSingleRunEffInfos(string, int, float&, float&, float&, float&); 

int FillSingleRunTriggerInfos(string, int, float&, float&, float&, float&, float&, float&);

int FillSingleRunRunInfos(string datatype, int, float&, float&, float&, float&, float&, float&, float&, float&, float&, float&, float&, float&, float&, float&, float&, float&, float&, float&);

int GetRunNumList( int runnum, int *runtable , string datatype);


#endif
