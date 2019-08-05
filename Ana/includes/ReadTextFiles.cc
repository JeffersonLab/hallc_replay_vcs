#define ReadTextFiles_cxx
#include "ReadTextFiles.h"
using namespace std;

string dummyLine;

/////////////////////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////////////////

bool IsBadRun(  int runint, int * badruntable
	){ 
	
	//return badruntable[runint];
	return 0;
}

/////////////////////////////////////////////////////////////////////////////////////////////////////////////
int ReadHeader(float (&inc)[26]){

	printf("\nread header file ... ");
	ifstream infile;
	string ff, line;
	int test;
	ff = Form(VCS_REPLAY_PATH "/Ana/ANA_CUTS.input");
	infile.open(ff.c_str());
	if (!infile) {
		cout<<"ERROR unable to read header file"<<endl;
		return 0;
	}
        test=0;
	while (infile.good()){
	   getline(infile,line);
	   if ((!( line[0]=='*' || line[1]=='*' || line[2]=='*')) && !line.empty()){
	          inc[test]=(float) atof(line.c_str());
	          test++;
	    }
	}
	infile.close();

	return 1;
}

/////////////////////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////////////////

int FillSingleRunRunInfos(string datatype,int runID, float &Eb, float &targetmass, float &HMS_p_central, float &SHMS_p_central, 
			  float &HMS_th_central, float &SHMS_th_central, float &HMS_run_l, float &SHMS_run_l, 
			  float &HMS_B2_cur, float &SHMS_B2_cur, float &HMS_B4_cut, float &SHMS_B4_cut, 
			  float &HMS_act_tim, float &SHMS_act_tim,
			  float &HMS_B2_cur_cut, float &SHMS_B2_cur_cut, 
			  float &HMS_live, float &SHMS_live){

	float ra, rb, rc, rd, re, rf, rg, rh, ri, rj, rk, rl, rm, rt, rn, ro, rp, rq;
	string sa, sb, ssa, ssb; 
	//printf("\n fill trigger info ...");
	ifstream infile; 
        string ff;
        int jj=0, run=runID;

        ff = Form(VCS_REPLAY_PATH "/Ana/datainfo/singleruninfo/run_info_%d.txt",runID); 	
	infile.open(ff.c_str());
	
	if (!infile) {
		cout<<"ERROR unable to read file run info run info"<<endl;
		return 0;
	}
	
	infile >> run >> ra >> rt >> rb >> rc >> rd >> re >> rn >> ro >> rf >> rg >> rh >> ri >> rp >> rq  >> rj >> rk >> rl >> rm;
	//infile >> run >> ra >> rt >> rb >> rc >> rd >> re >> rn >> ro >> rf >> rg >> rh >> ri >> sa >> sb  >> rj >> rk >> rl >> rm;
	Eb = ra; 
	targetmass = rt; 
	HMS_p_central = rb; 
	SHMS_p_central = rc; 
	HMS_th_central = rd; 
	SHMS_th_central = re; 
	SHMS_run_l = rn;
	HMS_run_l = ro;
	HMS_B2_cur = rf; 
	SHMS_B2_cur = rg; 
	HMS_B4_cut = rh; 
	SHMS_B4_cut = ri; 
	HMS_B2_cur_cut = rj; 
	SHMS_B2_cur_cut = rk;
  SHMS_live = rl;	
  HMS_live = rm;	
	
	//ssa = sa.substr(0, sa.length()-2);        
	//ssb = sb.substr(0, sb.length()-2);        
	//rp=atof(ssa.c_str());
	//rq=atof(ssb.c_str());

	HMS_act_tim = rp;
	SHMS_act_tim = rq;

  //cout<<Eb<<" "<<targetmass<<" "<<HMS_p_central<<" "<<SHMS_p_central<<" "<<HMS_th_central<<" "<<SHMS_th_central<<" "<<SHMS_run_l<<" "<<HMS_run_l<<" "<<HMS_B2_cur<<" "<<SHMS_B2_cur<<" "<<HMS_B4_cut<<" "<<SHMS_B4_cut<<" "<<HMS_B2_cur_cut<<" "<<SHMS_B2_cur_cut<<" "<<SHMS_live<<" "<<HMS_live<<endl;

	infile.close();
	return 1;
}	
/////////////////////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////////////////


int FillSingleRunTriggerInfos(string datatype,int runID, float &HMS34rates, float &SHMS34rates, float &HMS_ST, float &SHMS_ST, float &C_T, float &All_T){

	float ra, rb, rc, rd, re, rf;
	ifstream infile; 
        string ff;
        int jj=0, run=runID;

        ff = Form(VCS_REPLAY_PATH "/Ana/datainfo/singleruninfo/trigger_info_%d.txt",runID); 	
	infile.open(ff.c_str());
	
	if (!infile) {
		cout<<"ERROR unable to read file trigger info trigger info"<<endl;
		return 0;
	}

        //if (!(infile >> run)) return 0;
	infile >> run >> ra >> rb >> rc >> rd >> re >> rf;  
	HMS34rates = rb; 
	SHMS34rates = ra; 
	HMS_ST = rc; 
	SHMS_ST = rd; 
	C_T = re; 
	All_T = rf;
	
	infile.close();
	return 1;
	
}
/////////////////////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////////////////

int FillSingleRunEffInfos(string datatype,int runID, float &HMS_E_eff, float &HMS_H_eff, float &SHMS_E_eff, float &SHMS_H_eff){

	float ra, rb, rc, rd;
	ifstream infile; 
        string ff;
        int jj=0, run=runID;

        ff = Form(VCS_REPLAY_PATH "/Ana/datainfo/singleruninfo/eff_info_%d.txt",runID); 	
	infile.open(ff.c_str());
	
	if (!infile) {
		cout<<"ERROR unable to read file efficiency info"<<endl;
		return 0;
	}

        // if (!(infile >> run)) return 0;
	infile >> run >> ra >> rb >> rc >> rd;  
	HMS_E_eff = rb; 
	HMS_H_eff = rd; 
	SHMS_E_eff = ra; 
	SHMS_H_eff = rc; 
	
	infile.close();
	return 1;
	
}

/////////////////////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////////////////

int FillSingleRunMissRefInfos(string datatype, int (&tr) [22], int run){

	ifstream infile; 
  string ff;
  int jj=0, runb;
  ff = Form(VCS_REPLAY_PATH "/Ana/datainfo/singleruninfo/missref_info_%d.txt",run); 	
	infile.open(ff.c_str());
	
	if (!infile) {
		cout<<"ERROR unable to read file efficiency info"<<endl;
		return 0;
	}

  // if (!(infile >> run)) return 0;
	infile >> runb >> tr[0] >> tr[1] >>tr[2] >>tr[3] >>tr[4] >>tr[5] >>tr[6] >>tr[7] >>tr[8] >>tr[9] >>tr[10] >>tr[11] >>tr[12] >>tr[13] >>tr[14] >>tr[15] >>tr[15] >>tr[16] >>tr[17] >>tr[18] >>tr[19] >>tr[20] >>tr[21]; 
	
	infile.close();
	return 1;
	
}

/////////////////////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////////////////

int FillEffInfos(string datatype,int *runtable,
		    	float (&HMS_E_eff)[tot_runlist], float (&HMS_H_eff)[tot_runlist], 
			float (&SHMS_E_eff)[tot_runlist], float (&SHMS_H_eff)[tot_runlist]
		){
	float ra, rb, rc, rd;
	printf("\n fill trigger info ...");
	ifstream infile; 
        string ff;
        int jj=0, run=-1;

        ff = Form(VCS_REPLAY_PATH "/Ana/datainfo/mergedruninfo/eff_mergedruninfo.txt"); 	
	infile.open(ff.c_str());
	
	if (!infile) {
		cout<<"ERROR unable to read file efficiency info"<<endl;
		return 0;
	}

	while (infile.good()){
                if (!(infile >> run)) break;
		infile >> ra >> rb >> rc >> rd;  
 
		jj = GetRunNumList(run, runtable,datatype); 
		 
		HMS_E_eff[jj] = rb; 
		HMS_H_eff[jj] = rd; 
		SHMS_E_eff[jj] = ra; 
		SHMS_H_eff[jj] = rc; 
	 
	}
	
	infile.close();
	return 1;
	

}
/////////////////////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////////////////

int FillTriggerInfos(string datatype,int *runtable,
		    	float (&HMS34rates)[tot_runlist], float (&SHMS34rates)[tot_runlist], 
			float (&HMS_ST)[tot_runlist], float (&SHMS_ST)[tot_runlist], float (&C_T)[tot_runlist], float (&All_T)[tot_runlist]
		){
	float ra, rb, rc, rd, re, rf;
	printf("\n fill trigger info ...");
	ifstream infile; 
        string ff;
        int jj=0, run=-1;

        ff = Form(VCS_REPLAY_PATH "/Ana/datainfo/mergedruninfo/trigger_mergedruninfo.txt"); 	
	infile.open(ff.c_str());
	
	if (!infile) {
		cout<<"ERROR unable to read file trigger info merged"<<endl;
		return 0;
	}

	while (infile.good()){
                if (!(infile >> run)) break;
		infile >> ra >> rb >> rc >> rd >> re >> rf;  
 
		jj = GetRunNumList(run, runtable,datatype); 
		 
		HMS34rates[jj] = rb; 
		SHMS34rates[jj] = ra; 
		HMS_ST[jj] = rc; 
		SHMS_ST[jj] = rd; 
		C_T[jj] = re; 
		All_T[jj] = rf;
	 
	}
	
	infile.close();
	return 1;
	

}

/////////////////////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////////////////
  
int FillRunInfos( string datatype, 
	int *runtable, 
	float (&Eb)[tot_runlist], float (&targetmass)[tot_runlist], 
	float (&HMS_p_central)[tot_runlist], float (&SHMS_p_central)[tot_runlist], float (&HMS_th_central)[tot_runlist], float (&SHMS_th_central)[tot_runlist],
	float (&HMS_run_l)[tot_runlist], float (&SHMS_run_l)[tot_runlist], 
	float (&HMS_B2_cur)[tot_runlist], float (&SHMS_B2_cur)[tot_runlist], 
	float (&HMS_B4_cut)[tot_runlist], float (&SHMS_B4_cut)[tot_runlist], float (&HMS_B2_cur_cut)[tot_runlist], float (&SHMS_B2_cur_cut)[tot_runlist],
	float (&HMS_live)[tot_runlist], float (&SHMS_live)[tot_runlist]
	){
	
	int run ;
	float ra, rb, rc, rd, re, rf, rg, rh, ri, rj, rk, rl, rm, rt, rn, ro;

        printf("Start to fill run tables ...");
        
        ifstream infile; 
        string ff;
        int jj=0;

	ff = Form(VCS_REPLAY_PATH "/Ana/datainfo/mergedruninfo/run_mergedruninfo.txt");	 
	
	infile.open(ff.c_str());
	
	if (!infile) {
		cout<<"ERROR unable to read file merged run info"<<endl;
		return 0;
	}

	while (infile.good()){
                if (!(infile >> run)) break;
		infile >> ra >> rt >> rb >> rc >> rd >> re >> rn >> ro >> rf >> rg >> rh >> ri >> rj >> rk >> rl >> rm;  
 
		jj = GetRunNumList(run, runtable,datatype); 
		 
		Eb[jj] = ra; 
		targetmass[jj] = rt; 
		HMS_p_central[jj] = rb; 
		SHMS_p_central[jj] = rc; 
		HMS_th_central[jj] = rd; 
		SHMS_th_central[jj] = re;
	        HMS_run_l[jj] = ro;
		SHMS_run_l[jj] = rn;	
		HMS_B2_cur[jj] = rf; 
		SHMS_B2_cur[jj] = rg; 
		HMS_B4_cut[jj] = rh; 
		SHMS_B4_cut[jj] = ri; 
		HMS_B2_cur_cut[jj] = rj; 
		HMS_B2_cur_cut[jj] = rk;
	        HMS_live[jj] = rm;	
	        SHMS_live[jj] = rl;	
	 
	}
	
	infile.close();
	return 1;

}

/////////////////////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////////////////

int GetRunNumList( int runnum, int *runtable, string datatype){
	int run=-1;
	
	if (datatype.compare("pp") == 0){
	
		for (int ii=0;ii<847;ii++) {
			if (ii==0){
				if (runnum>runtable[750]) ii=750;
				else if (runnum>runtable[600]) ii=600;
				else if (runnum>runtable[450]) ii=450;
				else if (runnum>runtable[300]) ii=300;
				else if (runnum>runtable[150]) ii=150;
			}
			if (runnum==runtable[ii]){
				run=ii;
				break;
			}	
		}
	} else { 
		for (int ii=0;ii<tot_runlist;ii++) {
			//cout<<"run: "<<runnum<<"runtable["<<ii<<"] " <<runtable[ii]<<endl;
			if (runnum==runtable[ii]){
				run=ii;
				break;
			}	
		}
	}
	 
	return run;
}

/////////////////////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////////////////



