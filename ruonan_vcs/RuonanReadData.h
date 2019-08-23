#include <iostream>
#include "TChain.h"



TChain *chain = new TChain("T");

//Define variables in new Tree
Float_t HMS_dp;
Float_t HMS_theta;
Float_t HMS_phi;
Float_t SHMS_dp;
Float_t SHMS_theta;
Float_t SHMS_phi;
Float_t HMS_beta;
Float_t SHMS_beta;

//Define variables in initial Tree
Double_t H_gtr_dp;
Double_t H_gtr_th;
Double_t H_gtr_ph;
Double_t P_gtr_dp;
Double_t P_gtr_th;
Double_t P_gtr_ph;
Double_t H_gtr_beta;
Double_t P_gtr_beta;


