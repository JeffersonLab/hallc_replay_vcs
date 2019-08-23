#include <iostream>
#include "RefTime.h"


using namespace std;

void RefTime(Int_t RunNum = 0) {

	if(RunNum == 0) {
		cout <<"Enter a Run Number (-1 to exit): ";
		cin >> RunNum;
		if(RunNum <=0) return;
	}
//	if(EvtNum == 0) {
//		cout << "\nEvents Number: ";
//		cin >> EvtNum;
//		if(EvtNum == 0) {
//			cerr << "...Invalid entry\n";
//			exit;
//		}
//	}

	//Read initial rootfiles
	TChain *iChain = new TChain("T");
	iChain->Add(Form("/cache/hallc/alphaE/pass0/coin_replay_production_%d_-1.root",RunNum));

	//Define new rootfile
	TFile *myfile = new TFile(Form("/work/hallc/alphaE/ruonanli/RefTime_%d.root",RunNum),"recreate");

	if (myfile->IsOpen()) cout << "File is opened\n";

	TTree *CoinTime = new TTree("CoinTime", "Reference Time");
	
	//Set new branches
	CoinTime->Branch("hFADC_TREF_ROC1_adcMultiplicity", &hFADC_TREF_ROC1_adcMultiplicity, "hFADC_TREF_ROC1_adcMultiplicity/F");  
	CoinTime->Branch("hFADC_TREF_ROC1_adcPulseTime", &hFADC_TREF_ROC1_adcPulseTime, "hFADC_TREF_ROC1_adcPulseTime/F");
	CoinTime->Branch("hFADC_TREF_ROC1_adcPulseTimeRaw", &hFADC_TREF_ROC1_adcPulseTimeRaw, "hFADC_TREF_ROC1_adcPulseTimeRaw/F");
	CoinTime->Branch("hT1_tdcMultiplicity", &hT1_tdcMultiplicity, "hT1_tdcMultiplicity/F");
	CoinTime->Branch("hT1_tdcTime", &hT1_tdcTime, "hT1_tdcTime/F");
	CoinTime->Branch("hT1_tdcTimeRaw", &hT1_tdcTimeRaw, "hT1_tdcTimeRaw/F");
	CoinTime->Branch("hT2_tdcMultiplicity", &hT2_tdcMultiplicity, "hT2_tdcMultiplicity/F");
	CoinTime->Branch("hT2_tdcTime", &hT2_tdcTime, "hT2_tdcTime/F");
	CoinTime->Branch("hT2_tdcTimeRaw", &hT2_tdcTimeRaw, "hT2_tdcTimeRaw/F");
	CoinTime->Branch("hDCREF1_tdcMultiplicity", &hDCREF1_tdcMultiplicity, "hDCREF1_tdcMultiplicity/F");
	CoinTime->Branch("hDCREF1_tdcTime", &hDCREF1_tdcTime, "hDCREF1_tdcTime/F");
	CoinTime->Branch("hDCREF1_tdcTimeRaw", &hDCREF1_tdcTimeRaw, "hDCREF1_tdcTimeRaw/F");
	CoinTime->Branch("hDCREF2_tdcMultiplicity", &hDCREF2_tdcMultiplicity, "hDCREF2_tdcMultiplicity/F");
	CoinTime->Branch("hDCREF2_tdcTime", &hDCREF2_tdcTime, "hDCREF2_tdcTime/F");
	CoinTime->Branch("hDCREF2_tdcTimeRaw", &hDCREF2_tdcTimeRaw, "hDCREF2_tdcTimeRaw/F");
	CoinTime->Branch("hDCREF3_tdcMultiplicity", &hDCREF3_tdcMultiplicity, "hDCREF3_tdcMultiplicity/F");
	CoinTime->Branch("hDCREF3_tdcTime", &hDCREF3_tdcTime, "hDCREF3_tdcTime/F");
	CoinTime->Branch("hDCREF3_tdcTimeRaw", &hDCREF3_tdcTimeRaw, "hDCREF3_tdcTimeRaw/F");
	CoinTime->Branch("hDCREF4_tdcMultiplicity", &hDCREF4_tdcMultiplicity, "hDCREF4_tdcMultiplicity/F");
	CoinTime->Branch("hDCREF4_tdcTime", &hDCREF4_tdcTime, "hDCREF4_tdcTime/F");
	CoinTime->Branch("hDCREF4_tdcTimeRaw", &hDCREF4_tdcTimeRaw, "hDCREF4_tdcTimeRaw/F");
	CoinTime->Branch("hDCREF5_tdcMultiplicity", &hDCREF5_tdcMultiplicity, "hDCREF5_tdcMultiplicity/F");
	CoinTime->Branch("hDCREF5_tdcTime", &hDCREF5_tdcTime, "hDCREF5_tdcTime/F");
	CoinTime->Branch("hDCREF5_tdcTimeRaw", &hDCREF5_tdcTimeRaw, "hDCREF5_tdcTimeRaw/F");
	CoinTime->Branch("pFADC_TREF_ROC2_adcMultiplicity", &pFADC_TREF_ROC2_adcMultiplicity, "pFADC_TREF_ROC2_adcMultiplicity/F");
	CoinTime->Branch("pFADC_TREF_ROC2_adcPulseTime", &pFADC_TREF_ROC2_adcPulseTime, "pFADC_TREF_ROC2_adcPulseTime/F");
	CoinTime->Branch("pFADC_TREF_ROC2_adcPulseTimeRaw", &pFADC_TREF_ROC2_adcPulseTimeRaw, "pFADC_TREF_ROC2_adcPulseTimeRaw/F");
	CoinTime->Branch("pTRIG1_ROC1_tdcMultiplicity", &pTRIG1_ROC1_tdcMultiplicity, "pTRIG1_ROC1_tdcMultiplicity/F");
	CoinTime->Branch("pTRIG1_ROC1_tdcTime", &pTRIG1_ROC1_tdcTime, "pTRIG1_ROC1_tdcTime/F");
	CoinTime->Branch("pTRIG1_ROC1_tdcTimeRaw", &pTRIG1_ROC1_tdcTimeRaw, "pTRIG1_ROC1_tdcTimeRaw/F");
	CoinTime->Branch("pTRIG1_ROC2_tdcMultiplicity", &pTRIG1_ROC2_tdcMultiplicity, "pTRIG1_ROC2_tdcMultiplicity/F");
	CoinTime->Branch("pTRIG1_ROC2_tdcTime", &pTRIG1_ROC2_tdcTime, "pTRIG1_ROC2_tdcTime/F");
	CoinTime->Branch("pTRIG1_ROC2_tdcTimeRaw", &pTRIG1_ROC2_tdcTimeRaw, "pTRIG1_ROC2_tdcTimeRaw/F");
	CoinTime->Branch("pTRIG4_ROC1_tdcMultiplicity", &pTRIG4_ROC1_tdcMultiplicity, "pTRIG4_ROC1_tdcMultiplicity/F");
	CoinTime->Branch("pTRIG4_ROC1_tdcTime", &pTRIG4_ROC1_tdcTime, "pTRIG4_ROC1_tdcTime/F");
	CoinTime->Branch("pTRIG4_ROC1_tdcTimeRaw", &pTRIG4_ROC1_tdcTimeRaw, "pTRIG4_ROC1_tdcTimeRaw/F");
	CoinTime->Branch("pTRIG4_ROC2_tdcMultiplicity", &pTRIG4_ROC2_tdcMultiplicity, "pTRIG4_ROC2_tdcMultiplicity/F");
	CoinTime->Branch("pTRIG4_ROC2_tdcTime", &pTRIG4_ROC2_tdcTime, "pTRIG4_ROC2_tdcTime/F");
	CoinTime->Branch("pTRIG4_ROC2_tdcTimeRaw", &pTRIG4_ROC2_tdcTimeRaw, "pTRIG4_ROC2_tdcTimeRaw/F");
	CoinTime->Branch("pT1_tdcMultiplicity", &pT1_tdcMultiplicity, "pT1_tdcMultiplicity/F");
	CoinTime->Branch("pT1_tdcTime", &pT1_tdcTime, "pT1_tdcTime/F");
	CoinTime->Branch("pT1_tdcTimeRaw", &pT1_tdcTimeRaw, "pT1_tdcTimeRaw/F");
	CoinTime->Branch("pT2_tdcMultiplicity", &pT2_tdcMultiplicity, "pT2_tdcMultiplicity/F");
	CoinTime->Branch("pT2_tdcTime", &pT2_tdcTime, "pT2_tdcTime/F"); 
	CoinTime->Branch("pT2_tdcTimeRaw", &pT2_tdcTimeRaw, "pT2_tdcTimeRaw/F");
	CoinTime->Branch("pT3_tdcMultiplicity", &pT3_tdcMultiplicity, "pT3_tdcMultiplicity/F");
	CoinTime->Branch("pT3_tdcTime", &pT3_tdcTime, "pT3_tdcTime/F");   
	CoinTime->Branch("pT3_tdcTimeRaw", &pT3_tdcTimeRaw, "pT3_tdcTimeRaw/F");
	CoinTime->Branch("pDCREF1_tdcMultiplicity", &pDCREF1_tdcMultiplicity, "pDCREF1_tdcMultiplicity/F");
	CoinTime->Branch("pDCREF1_tdcTime", &pDCREF1_tdcTime, "pDCREF1_tdcTime/F");
	CoinTime->Branch("pDCREF1_tdcTimeRaw", &pDCREF1_tdcTimeRaw, "pDCREF1_tdcTimeRaw/F");
	CoinTime->Branch("pDCREF2_tdcMultiplicity", &pDCREF2_tdcMultiplicity, "pDCREF2_tdcMultiplicity/F");
	CoinTime->Branch("pDCREF2_tdcTime", &pDCREF2_tdcTime, "pDCREF2_tdcTime/F");
	CoinTime->Branch("pDCREF2_tdcTimeRaw", &pDCREF2_tdcTimeRaw, "pDCREF2_tdcTimeRaw/F");
	CoinTime->Branch("pDCREF3_tdcMultiplicity", &pDCREF3_tdcMultiplicity, "pDCREF3_tdcMultiplicity/F");
	CoinTime->Branch("pDCREF3_tdcTime", &pDCREF3_tdcTime, "pDCREF3_tdcTime/F");
	CoinTime->Branch("pDCREF3_tdcTimeRaw", &pDCREF3_tdcTimeRaw, "pDCREF3_tdcTimeRaw/F");
	CoinTime->Branch("pDCREF4_tdcMultiplicity", &pDCREF4_tdcMultiplicity, "pDCREF4_tdcMultiplicity/F");
	CoinTime->Branch("pDCREF4_tdcTime", &pDCREF4_tdcTime, "pDCREF4_tdcTime/F");
	CoinTime->Branch("pDCREF4_tdcTimeRaw", &pDCREF4_tdcTimeRaw, "pDCREF4_tdcTimeRaw/F");
	CoinTime->Branch("pDCREF5_tdcMultiplicity", &pDCREF5_tdcMultiplicity, "pDCREF5_tdcMultiplicity/F");
	CoinTime->Branch("pDCREF5_tdcTime", &pDCREF5_tdcTime, "pDCREF5_tdcTime/F");
	CoinTime->Branch("pDCREF5_tdcTimeRaw", &pDCREF5_tdcTimeRaw, "pDCREF5_tdcTimeRaw/F");
	CoinTime->Branch("pDCREF6_tdcMultiplicity", &pDCREF6_tdcMultiplicity, "pDCREF6_tdcMultiplicity/F");
	CoinTime->Branch("pDCREF6_tdcTime", &pDCREF6_tdcTime, "pDCREF6_tdcTime/F");
	CoinTime->Branch("pDCREF6_tdcTimeRaw", &pDCREF6_tdcTimeRaw, "pDCREF6_tdcTimeRaw/F");
	CoinTime->Branch("pDCREF7_tdcMultiplicity", &pDCREF7_tdcMultiplicity, "pDCREF7_tdcMultiplicity/F");
	CoinTime->Branch("pDCREF7_tdcTime", &pDCREF7_tdcTime, "pDCREF7_tdcTime/F");
	CoinTime->Branch("pDCREF7_tdcTimeRaw", &pDCREF7_tdcTimeRaw, "pDCREF7_tdcTimeRaw/F");
	CoinTime->Branch("pDCREF8_tdcMultiplicity", &pDCREF8_tdcMultiplicity, "pDCREF8_tdcMultiplicity/F");
	CoinTime->Branch("pDCREF8_tdcTime", &pDCREF8_tdcTime, "pDCREF8_tdcTime/F");
	CoinTime->Branch("pDCREF8_tdcTimeRaw", &pDCREF8_tdcTimeRaw , "pDCREF8_tdcTimeRaw/F");
	CoinTime->Branch("pDCREF9_tdcMultiplicity", &pDCREF9_tdcMultiplicity, "pDCREF9_tdcMultiplicity/F");
	CoinTime->Branch("pDCREF9_tdcTime", &pDCREF9_tdcTime, "pDCREF9_tdcTime/F");
	CoinTime->Branch("pDCREF9_tdcTimeRaw", &pDCREF9_tdcTimeRaw, "pDCREF9_tdcTimeRaw/F");
	CoinTime->Branch("pDCREF10_tdcMultiplicity", &pDCREF10_tdcMultiplicity, "pDCREF10_tdcMultiplicity/F");
	CoinTime->Branch("pDCREF10_tdcTime", &pDCREF10_tdcTime, "pDCREF10_tdcTime/F");
	CoinTime->Branch("pDCREF10_tdcTimeRaw", &pDCREF10_tdcTimeRaw, "pDCREF10_tdcTimeRaw/F");

	//Set BranchAddress
	iChain->SetBranchAddress("T.coin.hFADC_TREF_ROC1_adcMultiplicity",&hTREF_ROC1_Multi);
	iChain->SetBranchAddress("T.coin.hFADC_TREF_ROC1_adcPulseTime",&hTREF_ROC1_Time);
	iChain->SetBranchAddress("T.coin.hFADC_TREF_ROC1_adcPulseTimeRaw",&hTREF_ROC1_TimeRaw);
	iChain->SetBranchAddress("T.coin.hT1_tdcMultiplicity",&hT1_Multi);
	iChain->SetBranchAddress("T.coin.hT1_tdcTime",&hT1_Time);
	iChain->SetBranchAddress("T.coin.hT1_tdcTimeRaw",&hT1_TimeRaw);
	iChain->SetBranchAddress("T.coin.hT2_tdcMultiplicity",&hT2_Multi);
	iChain->SetBranchAddress("T.coin.hT2_tdcTime",&hT2_Time);
	iChain->SetBranchAddress("T.coin.hT2_tdcTimeRaw",&hT2_TimeRaw);
	iChain->SetBranchAddress("T.coin.hDCREF1_tdcMultiplicity",&hDCREF1_Multi);
	iChain->SetBranchAddress("T.coin.hDCREF1_tdcTime",&hDCREF1_Time);
	iChain->SetBranchAddress("T.coin.hDCREF1_tdcTimeRaw",&hDCREF1_TimeRaw);
	iChain->SetBranchAddress("T.coin.hDCREF2_tdcMultiplicity",&hDCREF2_Multi);
	iChain->SetBranchAddress("T.coin.hDCREF2_tdcTime",&hDCREF2_Time);
	iChain->SetBranchAddress("T.coin.hDCREF2_tdcTimeRaw",&hDCREF2_TimeRaw);
	iChain->SetBranchAddress("T.coin.hDCREF3_tdcMultiplicity",&hDCREF3_Multi);
	iChain->SetBranchAddress("T.coin.hDCREF3_tdcTime",&hDCREF3_Time);
	iChain->SetBranchAddress("T.coin.hDCREF3_tdcTimeRaw",&hDCREF3_TimeRaw);
	iChain->SetBranchAddress("T.coin.hDCREF4_tdcMultiplicity",&hDCREF4_Multi);
	iChain->SetBranchAddress("T.coin.hDCREF4_tdcTime",&hDCREF4_Time);
	iChain->SetBranchAddress("T.coin.hDCREF4_tdcTimeRaw",&hDCREF4_TimeRaw);
	iChain->SetBranchAddress("T.coin.hDCREF5_tdcMultiplicity",&hDCREF5_Multi);
	iChain->SetBranchAddress("T.coin.hDCREF5_tdcTime",&hDCREF5_Time);
	iChain->SetBranchAddress("T.coin.hDCREF5_tdcTimeRaw",&hDCREF5_TimeRaw);
	iChain->SetBranchAddress("T.coin.pFADC_TREF_ROC2_adcMultiplicity",&pTREF_ROC2_Multi);
	iChain->SetBranchAddress("T.coin.pFADC_TREF_ROC2_adcPulseTime",&pTREF_ROC2_Time);
	iChain->SetBranchAddress("T.coin.pFADC_TREF_ROC2_adcPulseTimeRaw",&pTREF_ROC2_TimeRaw);
	iChain->SetBranchAddress("T.coin.pTRIG1_ROC1_tdcMultiplicity",&pTRIG1_ROC1_Multi);
	iChain->SetBranchAddress("T.coin.pTRIG1_ROC1_tdcTime",&pTRIG1_ROC1_Time);
	iChain->SetBranchAddress("T.coin.pTRIG1_ROC1_tdcTimeRaw",&pTRIG1_ROC1_TimeRaw);
	iChain->SetBranchAddress("T.coin.pTRIG1_ROC2_tdcMultiplicity",&pTRIG1_ROC2_Multi);
	iChain->SetBranchAddress("T.coin.pTRIG1_ROC2_tdcTime",&pTRIG1_ROC2_Time);
	iChain->SetBranchAddress("T.coin.pTRIG1_ROC2_tdcTimeRaw",&pTRIG1_ROC2_TimeRaw);
	iChain->SetBranchAddress("T.coin.pTRIG4_ROC1_tdcMultiplicity",&pTRIG4_ROC1_Multi);
	iChain->SetBranchAddress("T.coin.pTRIG4_ROC1_tdcTime",&pTRIG4_ROC1_Time);
	iChain->SetBranchAddress("T.coin.pTRIG4_ROC1_tdcTimeRaw",&pTRIG4_ROC1_TimeRaw);
	iChain->SetBranchAddress("T.coin.pTRIG4_ROC2_tdcMultiplicity",&pTRIG4_ROC2_Multi);
	iChain->SetBranchAddress("T.coin.pTRIG4_ROC2_tdcTime",&pTRIG4_ROC2_Time);
	iChain->SetBranchAddress("T.coin.pTRIG4_ROC2_tdcTimeRaw",&pTRIG4_ROC2_TimeRaw);
	iChain->SetBranchAddress("T.coin.pT1_tdcMultiplicity",&pT1_Multi);
	iChain->SetBranchAddress("T.coin.pT1_tdcTime",&pT1_Time);
	iChain->SetBranchAddress("T.coin.pT1_tdcTimeRaw",&pT1_TimeRaw);
	iChain->SetBranchAddress("T.coin.pT2_tdcMultiplicity",&pT2_Multi);               
	iChain->SetBranchAddress("T.coin.pT2_tdcTime",&pT2_Time);                
	iChain->SetBranchAddress("T.coin.pT2_tdcTimeRaw",&pT2_TimeRaw);             
	iChain->SetBranchAddress("T.coin.pT3_tdcMultiplicity",&pT3_Multi);               
	iChain->SetBranchAddress("T.coin.pT3_tdcTime",&pT3_Time);                
	iChain->SetBranchAddress("T.coin.pT3_tdcTimeRaw",&pT3_TimeRaw);             
	iChain->SetBranchAddress("T.coin.pDCREF1_tdcMultiplicity",&pDCREF1_Multi);          
	iChain->SetBranchAddress("T.coin.pDCREF1_tdcTime",&pDCREF1_Time);            
	iChain->SetBranchAddress("T.coin.pDCREF1_tdcTimeRaw",&pDCREF1_TimeRaw);         
	iChain->SetBranchAddress("T.coin.pDCREF2_tdcMultiplicity",&pDCREF2_Multi);          
	iChain->SetBranchAddress("T.coin.pDCREF2_tdcTime",&pDCREF2_Time);            
	iChain->SetBranchAddress("T.coin.pDCREF2_tdcTimeRaw",&pDCREF2_TimeRaw);         
	iChain->SetBranchAddress("T.coin.pDCREF3_tdcMultiplicity",&pDCREF3_Multi);          
	iChain->SetBranchAddress("T.coin.pDCREF3_tdcTime",&pDCREF3_Time);            
	iChain->SetBranchAddress("T.coin.pDCREF3_tdcTimeRaw",&pDCREF3_TimeRaw);         
	iChain->SetBranchAddress("T.coin.pDCREF4_tdcMultiplicity",&pDCREF4_Multi);          
	iChain->SetBranchAddress("T.coin.pDCREF4_tdcTime",&pDCREF4_Time);            
	iChain->SetBranchAddress("T.coin.pDCREF4_tdcTimeRaw",&pDCREF4_TimeRaw);         
	iChain->SetBranchAddress("T.coin.pDCREF5_tdcMultiplicity",&pDCREF5_Multi);          
	iChain->SetBranchAddress("T.coin.pDCREF5_tdcTime",&pDCREF5_Time);            
	iChain->SetBranchAddress("T.coin.pDCREF5_tdcTimeRaw",&pDCREF5_TimeRaw);         
	iChain->SetBranchAddress("T.coin.pDCREF6_tdcMultiplicity",&pDCREF6_Multi);          
	iChain->SetBranchAddress("T.coin.pDCREF6_tdcTime",&pDCREF6_Time);            
	iChain->SetBranchAddress("T.coin.pDCREF6_tdcTimeRaw",&pDCREF6_TimeRaw);         
	iChain->SetBranchAddress("T.coin.pDCREF7_tdcMultiplicity",&pDCREF7_Multi);          
	iChain->SetBranchAddress("T.coin.pDCREF7_tdcTime",&pDCREF7_Time);            
	iChain->SetBranchAddress("T.coin.pDCREF7_tdcTimeRaw",&pDCREF7_TimeRaw);         
	iChain->SetBranchAddress("T.coin.pDCREF8_tdcMultiplicity",&pDCREF8_Multi);          
	iChain->SetBranchAddress("T.coin.pDCREF8_tdcTime",&pDCREF8_Time);            
	iChain->SetBranchAddress("T.coin.pDCREF8_tdcTimeRaw",&pDCREF8_TimeRaw);         
	iChain->SetBranchAddress("T.coin.pDCREF9_tdcMultiplicity",&pDCREF9_Multi);          
	iChain->SetBranchAddress("T.coin.pDCREF9_tdcTime",&pDCREF9_Time);            
	iChain->SetBranchAddress("T.coin.pDCREF9_tdcTimeRaw",&pDCREF9_TimeRaw);         
	iChain->SetBranchAddress("T.coin.pDCREF10_tdcMultiplicity",&pDCREF10_Multi);        
	iChain->SetBranchAddress("T.coin.pDCREF10_tdcTime",&pDCREF10_Time);           
	iChain->SetBranchAddress("T.coin.pDCREF10_tdcTimeRaw",&pDCREF10_TimeRaw);        
                                                                      
	//Loop over initial Tree to Fill new Tree
	for (Int_t i=0; i<iChain->GetEntries();i++) {
		
	//	if (i>5000) break;
		if (i%10000==0) cout << "# " << i << endl;
		iChain->GetEntry(i);
		if (i==0) cerr<<"enter loop"<<endl;

		hFADC_TREF_ROC1_adcMultiplicity=hTREF_ROC1_Multi;
		hFADC_TREF_ROC1_adcPulseTime=hTREF_ROC1_Time;
		hFADC_TREF_ROC1_adcPulseTimeRaw=hTREF_ROC1_TimeRaw;
		hT1_tdcMultiplicity=hT1_Multi;
		hT1_tdcTime=hT1_Time;
		hT1_tdcTimeRaw=hT1_TimeRaw;
		hT2_tdcMultiplicity=hT2_Multi;
		hT2_tdcTime=hT2_Time;
		hT2_tdcTimeRaw=hT2_TimeRaw;
		hDCREF1_tdcMultiplicity=hDCREF1_Multi;
		hDCREF1_tdcTime=hDCREF1_Time;
		hDCREF1_tdcTimeRaw=hDCREF1_TimeRaw;
		hDCREF2_tdcMultiplicity=hDCREF2_Multi;
		hDCREF2_tdcTime=hDCREF2_Time;
		hDCREF2_tdcTimeRaw=hDCREF2_TimeRaw;
		hDCREF3_tdcMultiplicity=hDCREF3_Multi;
		hDCREF3_tdcTime=hDCREF3_Time;
		hDCREF3_tdcTimeRaw=hDCREF3_TimeRaw;
		hDCREF4_tdcMultiplicity=hDCREF4_Multi;
		hDCREF4_tdcTime=hDCREF4_Time;
		hDCREF4_tdcTimeRaw=hDCREF4_TimeRaw;
		hDCREF5_tdcMultiplicity=hDCREF5_Multi;
		hDCREF5_tdcTime=hDCREF5_Time;
		hDCREF5_tdcTimeRaw=hDCREF5_TimeRaw;
		pFADC_TREF_ROC2_adcMultiplicity=pTREF_ROC2_Multi;
		pFADC_TREF_ROC2_adcPulseTime=pTREF_ROC2_Time;
		pFADC_TREF_ROC2_adcPulseTimeRaw=pTREF_ROC2_TimeRaw;
		pTRIG1_ROC1_tdcMultiplicity=pTRIG1_ROC1_Multi;
		pTRIG1_ROC1_tdcTime=pTRIG1_ROC1_Time;
		pTRIG1_ROC1_tdcTimeRaw=pTRIG1_ROC1_TimeRaw;
		pTRIG1_ROC2_tdcMultiplicity=pTRIG1_ROC2_Multi;
		pTRIG1_ROC2_tdcTime=pTRIG1_ROC2_Time;
		pTRIG1_ROC2_tdcTimeRaw=pTRIG1_ROC2_TimeRaw;
		pTRIG4_ROC1_tdcMultiplicity=pTRIG4_ROC1_Multi;
		pTRIG4_ROC1_tdcTime=pTRIG4_ROC1_Time;
		pTRIG4_ROC1_tdcTimeRaw=pTRIG4_ROC1_TimeRaw;
		pTRIG4_ROC2_tdcMultiplicity=pTRIG4_ROC2_Multi;
		pTRIG4_ROC2_tdcTime=pTRIG4_ROC2_Time;
		pTRIG4_ROC2_tdcTimeRaw=pTRIG4_ROC2_TimeRaw;
		pT1_tdcMultiplicity=pT1_Multi;
		pT1_tdcTime=pT1_Time;
		pT1_tdcTimeRaw=pT1_TimeRaw;
		pT2_tdcMultiplicity=pT2_Multi;
		pT2_tdcTime=pT2_Time;
		pT2_tdcTimeRaw=pT2_TimeRaw;
		pT3_tdcMultiplicity=pT3_Multi;
		pT3_tdcTime=pT3_Time;
		pT3_tdcTimeRaw=pT3_TimeRaw;
		pDCREF1_tdcMultiplicity=pDCREF1_Multi;
		pDCREF1_tdcTime=pDCREF1_Time;
		pDCREF1_tdcTimeRaw=pDCREF1_TimeRaw;
		pDCREF2_tdcMultiplicity=pDCREF2_Multi;
		pDCREF2_tdcTime=pDCREF2_Time;    
		pDCREF2_tdcTimeRaw=pDCREF2_TimeRaw; 
		pDCREF3_tdcMultiplicity=pDCREF3_Multi;   
		pDCREF3_tdcTime=pDCREF3_Time;    
		pDCREF3_tdcTimeRaw=pDCREF3_TimeRaw; 
		pDCREF4_tdcMultiplicity=pDCREF4_Multi;   
		pDCREF4_tdcTime=pDCREF4_Time;    
		pDCREF4_tdcTimeRaw=pDCREF4_TimeRaw; 
		pDCREF5_tdcMultiplicity=pDCREF5_Multi;   
		pDCREF5_tdcTime=pDCREF5_Time;    
		pDCREF5_tdcTimeRaw=pDCREF5_TimeRaw; 
		pDCREF6_tdcMultiplicity=pDCREF6_Multi;   
		pDCREF6_tdcTime=pDCREF6_Time;    
		pDCREF6_tdcTimeRaw=pDCREF6_TimeRaw; 
		pDCREF7_tdcMultiplicity=pDCREF7_Multi;   
		pDCREF7_tdcTime=pDCREF7_Time;    
		pDCREF7_tdcTimeRaw=pDCREF7_TimeRaw; 
		pDCREF8_tdcMultiplicity=pDCREF8_Multi;   
		pDCREF8_tdcTime=pDCREF8_Time;    
		pDCREF8_tdcTimeRaw=pDCREF8_TimeRaw; 
		pDCREF9_tdcMultiplicity=pDCREF9_Multi;   
		pDCREF9_tdcTime=pDCREF9_Time;    
		pDCREF9_tdcTimeRaw=pDCREF9_TimeRaw; 
		pDCREF10_tdcMultiplicity=pDCREF10_Multi;  
		pDCREF10_tdcTime=pDCREF10_Time;   
		pDCREF10_tdcTimeRaw=pDCREF10_TimeRaw;

	
		CoinTime->Fill();
	}
	
	CoinTime->Print();
	myfile->Write();
	myfile->Close();
	return ;

}

