#include <iostream>
#include "RuonanReadData.h"


using namespace std;

void RuonanReadData()
{

	//Read initial rootfiles
	TChain *chain = new TChain("T");
	chain->Add("/work/hallc/alphaE/ruonanli/coin_replay_production_9187_100000.root");

	//Define new rootfile
	TFile *myfile = new TFile("/work/hallc/alphaE/ruonanli/RuonanTest.root","recreate");

	if (myfile->IsOpen()) cout << "File is opened\n";

	TTree *RuonanTree = new TTree("RuonanTree", "test tree");
	
	//Set new branches
	RuonanTree->Branch("HMS_dp", &HMS_dp, "HMS_dp/F");
	RuonanTree->Branch("HMS_theta", &HMS_theta, "HMS_theta/F");
	RuonanTree->Branch("HMS_phi", &HMS_phi, "HMS_phi/F");
	RuonanTree->Branch("SHMS_dp", &SHMS_dp, "SHMS_dp/F");
	RuonanTree->Branch("SHMS_theta", &SHMS_theta, "SHMS_theta/F");
	RuonanTree->Branch("SHMS_phi", &SHMS_phi, "SHMS_phi/F");
	RuonanTree->Branch("HMS_beta", &HMS_beta, "HMS_beta/F");
	RuonanTree->Branch("SHMS_beta", &SHMS_beta, "SHMS_beta/F");

	chain->SetBranchAddress("H.gtr.dp", &H_gtr_dp);
	chain->SetBranchAddress("H.gtr.th", &H_gtr_th);
	chain->SetBranchAddress("H.gtr.ph", &H_gtr_ph);
	chain->SetBranchAddress("P.gtr.dp", &P_gtr_dp);
	chain->SetBranchAddress("P.gtr.th", &P_gtr_th);
	chain->SetBranchAddress("P.gtr.ph", &P_gtr_ph);
	chain->SetBranchAddress("H.gtr.beta", &H_gtr_beta);
	chain->SetBranchAddress("P.gtr.beta", &P_gtr_beta);

	//Loop over initial Tree to Fill new Tree
	for (Int_t i=0; i<chain->GetEntries();i++) {
		
	//	if (i>100) break;
		if (i%10000==0) cout << "# " << i << endl;
		chain->GetEntry(i);
		if (i==0) cerr<<"enter loop"<<endl;

		if ( H_gtr_beta < 0.9 ) {
		HMS_dp = H_gtr_dp;
		HMS_theta = H_gtr_th;
		HMS_phi = H_gtr_ph;
		SHMS_dp = P_gtr_dp;
		SHMS_theta = P_gtr_th;
		SHMS_phi = P_gtr_ph;
		HMS_beta = H_gtr_beta;
		SHMS_beta = P_gtr_beta;

		}

		RuonanTree->Fill();
	}
	
	RuonanTree->Print();
	myfile->Write();
	myfile->Close();
	return ;

}

