#include <iostream>
#include "TFile.h"
#include "TH1F.h"
#include "TTreeReader.h"
#include "TTreeReaderValue.h"
using namespace std;


void RefTimePlots(Int_t RunNum = 0)
{
	if(RunNum == 0) {
		cout << "Enter a Run Number (-1 to exit): ";
		cin >> RunNum;
		if(RunNum <= 0) return;
	}

	TFile *myfile = TFile::Open(Form("/work/hallc/alphaE/ruonanli/RefTime_%d.root",RunNum));
	TTreeReader myReader("CoinTime",myfile);

	TTreeReaderValue<Float_t> hFADC_ROC1_Multi(myReader, "hFADC_TREF_ROC1_adcMultiplicity");
	TTreeReaderValue<Float_t> hFADC_ROC1_TimeRaw(myReader, "hFADC_TREF_ROC1_adcPulseTimeRaw");
	TTreeReaderValue<Float_t> hT1_Multi(myReader, "hT1_tdcMultiplicity");
	TTreeReaderValue<Float_t> hT1_TimeRaw(myReader, "hT1_tdcTimeRaw");
	TTreeReaderValue<Float_t> hT2_Multi(myReader, "hT2_tdcMultiplicity");
	TTreeReaderValue<Float_t> hT2_TimeRaw(myReader, "hT2_tdcTimeRaw");
	TTreeReaderValue<Float_t> hDCREF1_Multi(myReader, "hDCREF1_tdcMultiplicity");
	TTreeReaderValue<Float_t> hDCREF1_TimeRaw(myReader, "hDCREF1_tdcTimeRaw");
	TTreeReaderValue<Float_t> hDCREF2_Multi(myReader, "hDCREF2_tdcMultiplicity");
	TTreeReaderValue<Float_t> hDCREF2_TimeRaw(myReader, "hDCREF2_tdcTimeRaw");
	TTreeReaderValue<Float_t> hDCREF3_Multi(myReader, "hDCREF3_tdcMultiplicity");
	TTreeReaderValue<Float_t> hDCREF3_TimeRaw(myReader, "hDCREF3_tdcTimeRaw");
	TTreeReaderValue<Float_t> hDCREF4_Multi(myReader, "hDCREF4_tdcMultiplicity");
	TTreeReaderValue<Float_t> hDCREF4_TimeRaw(myReader, "hDCREF4_tdcTimeRaw");
	TTreeReaderValue<Float_t> hDCREF5_Multi(myReader, "hDCREF5_tdcMultiplicity");
	TTreeReaderValue<Float_t> hDCREF5_TimeRaw(myReader, "hDCREF5_tdcTimeRaw");
	TTreeReaderValue<Float_t> pFADC_ROC2_Multi(myReader, "pFADC_TREF_ROC2_adcMultiplicity");
	TTreeReaderValue<Float_t> pFADC_ROC2_TimeRaw(myReader, "pFADC_TREF_ROC2_adcPulseTimeRaw");
	TTreeReaderValue<Float_t> pTRIG1_ROC1_Multi(myReader, "pTRIG1_ROC1_tdcMultiplicity");
	TTreeReaderValue<Float_t> pTRIG1_ROC1_TimeRaw(myReader, "pTRIG1_ROC1_tdcTimeRaw");
	TTreeReaderValue<Float_t> pTRIG1_ROC2_Multi(myReader, "pTRIG1_ROC2_tdcMultiplicity");
	TTreeReaderValue<Float_t> pTRIG1_ROC2_TimeRaw(myReader, "pTRIG1_ROC2_tdcTimeRaw");
	TTreeReaderValue<Float_t> pTRIG4_ROC1_Multi(myReader, "pTRIG4_ROC1_tdcMultiplicity");
	TTreeReaderValue<Float_t> pTRIG4_ROC1_TimeRaw(myReader, "pTRIG4_ROC1_tdcTimeRaw");
	TTreeReaderValue<Float_t> pTRIG4_ROC2_Multi(myReader, "pTRIG4_ROC2_tdcMultiplicity");
	TTreeReaderValue<Float_t> pTRIG4_ROC2_TimeRaw(myReader, "pTRIG4_ROC2_tdcTimeRaw");
	TTreeReaderValue<Float_t> pT1_Multi(myReader, "pT1_tdcMultiplicity");
	TTreeReaderValue<Float_t> pT1_TimeRaw(myReader, "pT1_tdcTimeRaw");
	TTreeReaderValue<Float_t> pT2_Multi(myReader, "pT2_tdcMultiplicity");
	TTreeReaderValue<Float_t> pT2_TimeRaw(myReader, "pT2_tdcTimeRaw");
	TTreeReaderValue<Float_t> pDCREF1_Multi(myReader, "pDCREF1_tdcMultiplicity");
	TTreeReaderValue<Float_t> pDCREF1_TimeRaw(myReader, "pDCREF1_tdcTimeRaw");
	TTreeReaderValue<Float_t> pDCREF2_Multi(myReader, "pDCREF2_tdcMultiplicity");
	TTreeReaderValue<Float_t> pDCREF2_TimeRaw(myReader, "pDCREF2_tdcTimeRaw");
	TTreeReaderValue<Float_t> pDCREF3_Multi(myReader, "pDCREF3_tdcMultiplicity");
	TTreeReaderValue<Float_t> pDCREF3_TimeRaw(myReader, "pDCREF3_tdcTimeRaw");
	TTreeReaderValue<Float_t> pDCREF4_Multi(myReader, "pDCREF4_tdcMultiplicity");
	TTreeReaderValue<Float_t> pDCREF4_TimeRaw(myReader, "pDCREF4_tdcTimeRaw");
	TTreeReaderValue<Float_t> pDCREF5_Multi(myReader, "pDCREF5_tdcMultiplicity");
	TTreeReaderValue<Float_t> pDCREF5_TimeRaw(myReader, "pDCREF5_tdcTimeRaw");
	TTreeReaderValue<Float_t> pDCREF6_Multi(myReader, "pDCREF6_tdcMultiplicity");
	TTreeReaderValue<Float_t> pDCREF6_TimeRaw(myReader, "pDCREF6_tdcTimeRaw");
	TTreeReaderValue<Float_t> pDCREF7_Multi(myReader, "pDCREF7_tdcMultiplicity");
	TTreeReaderValue<Float_t> pDCREF7_TimeRaw(myReader, "pDCREF7_tdcTimeRaw");
	TTreeReaderValue<Float_t> pDCREF8_Multi(myReader, "pDCREF8_tdcMultiplicity");
	TTreeReaderValue<Float_t> pDCREF8_TimeRaw(myReader, "pDCREF8_tdcTimeRaw");
	TTreeReaderValue<Float_t> pDCREF9_Multi(myReader, "pDCREF9_tdcMultiplicity");
	TTreeReaderValue<Float_t> pDCREF9_TimeRaw(myReader, "pDCREF9_tdcTimeRaw");
	TTreeReaderValue<Float_t> pDCREF10_Multi(myReader, "pDCREF10_tdcMultiplicity");
	TTreeReaderValue<Float_t> pDCREF10_TimeRaw(myReader, "pDCREF10_tdcTimeRaw");

	//define all the TH1F
	TH1F *hist_hROC1 = new TH1F("hist_hROC1","HMS FADC_ROC1 RefTime",100,6300,7100);
	TH1F *hist_hROC1_full = new TH1F("hist_hROC1_full","T.coin.hFADC_TREF_ROC1_adcPulseTimeRaw",200,4000,7500);
	TH1F *hist_hROC1_Multi = new TH1F("hist_hROC1_Multi","HMS FADC_ROC1 Multiplicity",100,0,10);
	TH1F *hist_hROC1_cut = new TH1F("hist_hROC1_cut","hROC1_cut",100,6300,7100);

	TH1F *hist_hT2 = new TH1F("hist_hT2","HMS HODO tdc hT2 RefTime",100,3000,4900);
	TH1F *hist_hT2_full = new TH1F("hist_hT2_full","T.coin.hT2_TimeRaw",200,3000,4900);
	TH1F *hist_hT2_Multi = new TH1F("hist_hT2_Multi","HMS HODO tdc Multiplicity",100,0,10);
	TH1F *hist_hT2_cut = new TH1F("hist_hT2_cut", "hT2_cut",100,3000,4900);

	TH1F *hist_hT1 = new TH1F("hist_hT1","HMS TRIG tdc hT1 RefTime",100,3000,4900);
	TH1F *hist_hT1_full = new TH1F("hist_hT1_full","T.coin.hT1_TimeRaw",200,3000,4900);
	TH1F *hist_hT1_Multi = new TH1F("hist_hT1_Multi","HMS TRIG tdc Multiplicity",100,0,10);
	TH1F *hist_hT1_cut = new TH1F("hist_hT1_cut", "hT1_cut",100,3000,4900);
  
	TH1F *hist_hDCREF1 = new TH1F("hist_hDCREF1", "HMS DC tdc RefTime",100,16000,18000);
	TH1F *hist_hDCREF1_full = new TH1F("hist_hDCREF1_full","T.coin.hDCREF1_tdcTimeRaw",200,0,18000);
	TH1F *hist_hDCREF1_Multi = new TH1F("hist_hDCREF1_Multi","HMS DC Multiplicity",100,0,10);
	TH1F *hist_hDCREF1_cut = new TH1F("hist_hDCREF1_cut", "hDCREF1_cut",100,16000,18000);

	TH1F *hist_pROC2 = new TH1F("hist_pROC2","SHMS FADC_ROC2 RefTime",100,1000,7500);
	TH1F *hist_pROC2_full = new TH1F("hist_pROC2_full","T.coin.pFADC_TREF_ROC2_adcPulseTimeRaw",200,0,7500);
	TH1F *hist_pROC2_Multi = new TH1F("hist_pROC2_Multi","SHMS FADC_ROC2 Multiplicity",100,0,10);
	TH1F *hist_pROC2_cut = new TH1F("hist_pROC2_cut","pROC2_cut",100,1000,7500);

	TH1F *hist_pTRIG1_ROC1 = new TH1F("hist_pTRIG1_ROC1","SHMS TRIG1_ROC1 RefTime",100,4500,6500);
	TH1F *hist_pTRIG1_ROC1_full = new TH1F("hist_pTRIG1_ROC1_full","T.coin.pTRIG1_ROC1_tdcTimeRaw",200,3000,6500);
	TH1F *hist_pTRIG1_ROC1_Multi = new TH1F("hist_pTRIG1_ROC1_Multi","SHMS TRIG1_ROC1 Multiplicity",100,0,10);
	TH1F *hist_pTRIG1_ROC1_cut = new TH1F("hist_pTRIG1_ROC1_cut","pTRIG_ROC1_cut",100,4500,6500);

	TH1F *hist_pTRIG1_ROC2 = new TH1F("hist_pTRIG1_ROC2","SHMS TRIG1_ROC2 RefTime",100,4500,7000);
	TH1F *hist_pTRIG1_ROC2_full = new TH1F("hist_pTRIG1_ROC2_full","T.coin.pTRIG1_ROC2_tdcTimeRaw",200,3000,7000);
	TH1F *hist_pTRIG1_ROC2_Multi = new TH1F("hist_pTRIG1_ROC2_Multi","SHMS TRIG1_ROC2 Multiplicity",100,0,10);
	TH1F *hist_pTRIG1_ROC2_cut = new TH1F("hist_pTRIG1_ROC2_cut","pTRIG_ROC2_cut",100,4500,7000);
	TH1F *hist_pTRIG1_ROC2_cut2 = new TH1F("hist_pTRIG1_ROC2_cut2","pTRIG_ROC2_cut2",100,4500,7000);

	TH1F *hist_pTRIG4_ROC1 = new TH1F("hist_pTRIG4_ROC1","SHMS TRIG4_ROC1 RefTime",100,4500,6500);
	TH1F *hist_pTRIG4_ROC1_full = new TH1F("hist_pTRIG4_ROC1_full","T.coin.pTRIG4_ROC1_tdcTimeRaw",200,3000,6500);
	TH1F *hist_pTRIG4_ROC1_Multi = new TH1F("hist_pTRIG4_ROC1_Multi","SHMS TRIG4_ROC1 Multiplicity",100,0,10);
	TH1F *hist_pTRIG4_ROC1_cut = new TH1F("hist_pTRIG4_ROC1_cut","pRTRIG4_ROC1_cut",100,4500,6500);

	TH1F *hist_pTRIG4_ROC2 = new TH1F("hist_pTRIG4_ROC2","SHMS TRIG4_ROC2 RefTime",100,5000,7000);
	TH1F *hist_pTRIG4_ROC2_full = new TH1F("hist_pTRIG4_ROC2_full","T.coin.pTRIG4_ROC2_tdcTimeRaw",200,3000,7000);
	TH1F *hist_pTRIG4_ROC2_Multi = new TH1F("hist_pTRIG4_ROC2_Multi","SHMS TRIG4_ROC2 Multiplicity",100,0,10);
	TH1F *hist_pTRIG4_ROC2_cut = new TH1F("hist_pTRIG4_ROC2_cut","pRTRIG4_ROC2_cut",100,5000,7000);
	
	TH1F *hist_pT1 = new TH1F("hist_pT1", "SHMS HODO tdc T1 RefTime",100,3500,6000);
	TH1F *hist_pT1_full = new TH1F("hist_pT1_full", "T.coin.pT1_tdcTimeRaw",100,0,7000);
	TH1F *hist_pT1_cut2 = new TH1F("hist_pT1_cut2", "pT1_cut2",100,3500,6000);
	TH1F *hist_pT1_cut4 = new TH1F("hist_pT1_cut4", "pT1_cut4",100,3500,6000);
	TH1F *hist_pT1_Multi = new TH1F("hist_pT1_Multi","SHMS HODO Multiplicity", 100, 0, 10);

    TH1F *hist_pT2 = new TH1F("hist_pT2", "SHMS HODO/TRIG tdc T2 RefTime",100,3500,6000);
	TH1F *hist_pT2_full = new TH1F("hist_pT2_full", "T.coin.pT2_tdcTimeRaw",100,0,7000);
	TH1F *hist_pT2_cut2 = new TH1F("hist_pT2_cut2", "pT2_cut2",100,3500,6000);
	TH1F *hist_pT2_Multi = new TH1F("hist_pT2_Multi","SHMS HODO/TRIG Multiplicity", 100, 0, 10);
    
	TH1F *hist_pDCREF1 = new TH1F("hist_pDCREF1", "SHMS DC tdc RefTime",100,13000,17000);
    TH1F *hist_pDCREF1_full = new TH1F("hist_pDCREF1_full", "T.coin.pDCREF1_tdcTimeRaw",200,0,17000);
	TH1F *hist_pDCREF1_cut2 = new TH1F("hist_pDCREF1_cut2", "pDCREF1_cut2",100,13000,17000);
	TH1F *hist_pDCREF1_cut4 = new TH1F("hist_pDCREF1_cut4", "pDCREF1_cut4",100,13000,17000);
	TH1F *hist_pDCREF1_cut6 = new TH1F("hist_pDCREF1_cut6", "pDCREF1_cut6",100,13000,17000);
	TH1F *hist_pDCREF1_Multi = new TH1F("hist_pDCREF1_Multi","SHMS DC Multiplicity",100,0,10);


	while(myReader.Next()){
		
		hist_hROC1->Fill(*hFADC_ROC1_TimeRaw);
		hist_hROC1_full->Fill(*hFADC_ROC1_TimeRaw);
		hist_hROC1_Multi->Fill(*hFADC_ROC1_Multi);
		if(*hFADC_ROC1_Multi == 1.){
			hist_hROC1_cut->Fill(*hFADC_ROC1_TimeRaw);
		}
       
		hist_hT2->Fill(*hT2_TimeRaw);
		hist_hT2_full->Fill(*hT2_TimeRaw);
		hist_hT2_Multi->Fill(*hT2_Multi);
		if(*hT2_Multi==1.){
			hist_hT2_cut->Fill(*hT2_TimeRaw);
		}
		
		hist_hT1->Fill(*hT1_TimeRaw);
		hist_hT1_full->Fill(*hT1_TimeRaw);
		hist_hT1_Multi->Fill(*hT1_Multi);
		if(*hT1_Multi==1.){
			hist_hT1_cut->Fill(*hT1_TimeRaw);
		}

		hist_hDCREF1_Multi->Fill(*hDCREF1_Multi);
		hist_hDCREF1_full->Fill(*hDCREF1_TimeRaw);
        hist_hDCREF1->Fill(*hDCREF1_TimeRaw);    
		if(*hDCREF1_Multi==1.){
			hist_hDCREF1_cut->Fill(*hDCREF1_TimeRaw);
		}

		hist_pROC2->Fill(*pFADC_ROC2_TimeRaw);
		hist_pROC2_full->Fill(*pFADC_ROC2_TimeRaw);
		hist_pROC2_Multi->Fill(*pFADC_ROC2_Multi);
		if(*pFADC_ROC2_Multi == 2.){
			hist_pROC2_cut->Fill(*pFADC_ROC2_TimeRaw);
		}
       
        
		hist_pTRIG1_ROC1->Fill(*pTRIG1_ROC1_TimeRaw);
	//	hist_pTRIG1_ROC1_full->Fill(*pTRIG1_ROC1_TimeRaw);
		hist_pTRIG1_ROC1_Multi->Fill(*pTRIG1_ROC1_Multi);
		if(*pTRIG1_ROC1_Multi == 1.){
			hist_pTRIG1_ROC1_cut->Fill(*pTRIG1_ROC1_TimeRaw);
		}


		hist_pTRIG1_ROC2->Fill(*pTRIG1_ROC2_TimeRaw);
	//	hist_pTRIG1_ROC2_full->Fill(*pTRIG1_ROC2_TimeRaw);
		hist_pTRIG1_ROC2_Multi->Fill(*pTRIG1_ROC2_Multi);
		if(*pTRIG1_ROC2_Multi == 1.){
			hist_pTRIG1_ROC2_cut->Fill(*pTRIG1_ROC2_TimeRaw);
		}
		if(*pTRIG1_ROC2_Multi == 2.){
			hist_pTRIG1_ROC2_cut2->Fill(*pTRIG1_ROC2_TimeRaw);
		}

	
		hist_pTRIG4_ROC1->Fill(*pTRIG4_ROC1_TimeRaw);
	//	hist_pTRIG4_ROC1_full->Fill(*pTRIG4_ROC1_TimeRaw);
		hist_pTRIG4_ROC1_Multi->Fill(*pTRIG4_ROC1_Multi);
		if(*pTRIG4_ROC1_Multi == 1.){
			hist_pTRIG4_ROC1_cut->Fill(*pTRIG4_ROC1_TimeRaw);
		}


		hist_pTRIG4_ROC2->Fill(*pTRIG4_ROC2_TimeRaw);
	//	hist_pTRIG4_ROC2_full->Fill(*pTRIG4_ROC2_TimeRaw);
		hist_pTRIG4_ROC2_Multi->Fill(*pTRIG4_ROC2_Multi);
		if(*pTRIG4_ROC2_Multi == 1.){
			hist_pTRIG4_ROC2_cut->Fill(*pTRIG4_ROC2_TimeRaw);
		}

		hist_pT1_Multi->Fill(*pT1_Multi);
		hist_pT1_full->Fill(*pT1_TimeRaw);
		hist_pT1->Fill(*pT1_TimeRaw);    
		if(*pT1_Multi==4.){
			hist_pT1_cut4->Fill(*pT1_TimeRaw);
		}

		if(*pT1_Multi==2.){
			hist_pT1_cut2->Fill(*pT1_TimeRaw);
		}

		hist_pT2_Multi->Fill(*pT2_Multi);
		hist_pT2_full->Fill(*pT2_TimeRaw);
		hist_pT2->Fill(*pT2_TimeRaw);    
		if(*pT2_Multi==2.){
			hist_pT2_cut2->Fill(*pT2_TimeRaw);
		}

	    hist_pDCREF1_Multi->Fill(*pDCREF1_Multi);
		hist_pDCREF1_full->Fill(*pDCREF1_TimeRaw);    
        hist_pDCREF1->Fill(*pDCREF1_TimeRaw);    
		if(*pDCREF1_Multi==2.){
			hist_pDCREF1_cut2->Fill(*pDCREF1_TimeRaw);
		}

		if(*pDCREF1_Multi==4.){
			hist_pDCREF1_cut4->Fill(*pDCREF1_TimeRaw);
		}

		if(*pDCREF1_Multi==6.){
			hist_pDCREF1_cut6->Fill(*pDCREF1_TimeRaw);
		}


	}

////////////////////////////first page/////////////////////////////////////
	auto c1 = new TCanvas("c1","c1");
	c1->Divide(3,2);
	c1->cd(1);
	auto l1 = new TLegend(0.1,0.7,0.48,0.9);
	hist_hROC1->SetLineColor(4);hist_hROC1->Draw("HIST");hist_hROC1->SetMinimum(1);hist_hROC1->GetXaxis()->SetTitle("ADC Channel");
    hist_hROC1_cut->SetLineColor(2);hist_hROC1_cut->Draw("HISTsame");hist_hROC1_cut->SetMinimum(1);
	l1->AddEntry("hist_hROC1","No cut","l");
	l1->AddEntry("hist_hROC1_cut","Multiciplity==1","l");
	l1->Draw();
	gPad->SetLogy();
    c1->cd(2);
	auto l2 = new TLegend(0.1,0.7,0.48,0.9);
	hist_hT2->SetLineColor(4);hist_hT2->Draw("HIST");hist_hT2->SetMinimum(1);hist_hT2->GetXaxis()->SetTitle("TDC Channel");
    hist_hT2_cut->SetLineColor(2);hist_hT2_cut->Draw("HISTsame");hist_hT2_cut->SetMinimum(1);
	l2->AddEntry("hist_hT2","No cut","l");
	l2->AddEntry("hist_hT2_cut","Multiplicity==1","l");
	l2->Draw();
	gPad->SetLogy();
	c1->cd(3);
	auto l3 = new TLegend(0.1,0.7,0.48,0.9);
	hist_hT1->SetLineColor(4);hist_hT1->Draw("HIST");hist_hT1->SetMinimum(1);hist_hT1->GetXaxis()->SetTitle("TDC Channel");
    hist_hT1_cut->SetLineColor(2);hist_hT1_cut->Draw("HISTsame");hist_hT1_cut->SetMinimum(1);
	l3->AddEntry("hist_hT1","No cut","l");
	l3->AddEntry("hist_hT1_cut","Multiplicity==1","l");
	l3->Draw();
	gPad->SetLogy();
	c1->cd(4);
	hist_hROC1_Multi->Draw("HIST");
	c1->cd(5);
	hist_hT2_Multi->Draw("HIST");
	c1->cd(6);
	hist_hT1_Multi->Draw("HIST");
	c1->SaveAs(Form("/work/hallc/alphaE/ruonanli/report_%d.pdf(",RunNum));

/////////////////////second page/////////////////////////////////////////////////
	c1->Clear();
	c1->Divide(2,2);
	c1->cd(1);
	auto l4 = new TLegend(0.1,0.7,0.48,0.9);
    hist_hDCREF1->SetLineColor(4);hist_hDCREF1->Draw("HIST");hist_hDCREF1->SetMinimum(1);hist_hDCREF1->GetXaxis()->SetTitle("TDC Channel");
	hist_hDCREF1_cut->SetLineColor(2);hist_hDCREF1_cut->Draw("HISTsame");hist_hDCREF1_cut->SetMinimum(1);
	l4->AddEntry("hist_hDCREF1","No cut","l");
	l4->AddEntry("hist_hDCREF1_cut","Multiplicity==1","l");
	l4->Draw();
	gPad->SetLogy();
	c1->cd(2);
	hist_hDCREF1_Multi->Draw("HIST");
	c1->cd(3);
	hist_hDCREF1_full->Draw("HIST");
	c1->SaveAs(Form("/work/hallc/alphaE/ruonanli/report_%d.pdf",RunNum));

/////////////////////third page/////////////////////////////////////////////////
	c1->Clear();
	c1->Divide(3,2);
	c1->cd(1);
	auto l12 = new TLegend(0.1,0.7,0.48,0.9);
	hist_pROC2->SetLineColor(4);hist_pROC2->Draw("HIST");hist_pROC2->SetMinimum(1);hist_pROC2->GetXaxis()->SetTitle("ADC Channel");
    hist_pROC2_cut->SetLineColor(2);hist_pROC2_cut->Draw("HISTsame");hist_pROC2_cut->SetMinimum(1);
	l12->AddEntry("hist_pROC2","No cut","l");
	l12->AddEntry("hist_pROC2_cut","Multiciplity==2","l");
	l12->Draw();
	gPad->SetLogy();
    c1->cd(2);
	auto l5 = new TLegend(0.1,0.7,0.48,0.9);
	hist_pT1->SetLineColor(4);hist_pT1->Draw("HIST");hist_pT1->SetMinimum(1);hist_pT1->GetXaxis()->SetTitle("TDC Channel");
    hist_pT1_cut2->SetLineColor(2);hist_pT1_cut2->Draw("HISTsame");hist_pT1_cut2->SetMinimum(1);
	l5->AddEntry("hist_pT1","No cut","l");
	l5->AddEntry("hist_pT1_cut2","Multiplicity==2","l");
	l5->Draw();
	gPad->SetLogy();
	c1->cd(3);
	auto l6 = new TLegend(0.1,0.7,0.48,0.9);
	hist_pT2->SetLineColor(4);hist_pT2->Draw("HIST");hist_pT2->SetMinimum(1);hist_pT2->GetXaxis()->SetTitle("TDC Channel");
    hist_pT2_cut2->SetLineColor(2);hist_pT2_cut2->Draw("HISTsame");hist_pT2_cut2->SetMinimum(1);
	l6->AddEntry("hist_pT2","No cut","l");
	l6->AddEntry("hist_pT2_cut2","Multiplicity==2","l");
	l6->Draw();
	gPad->SetLogy();
	c1->cd(4);
	hist_pROC2_Multi->Draw("HIST");
	c1->cd(5);
	hist_pT1_Multi->Draw("HIST");
	c1->cd(6);
	hist_pT2_Multi->Draw("HIST");
	c1->SaveAs(Form("/work/hallc/alphaE/ruonanli/report_%d.pdf",RunNum));

///////////////////fourth page///////////////////////////////////////////////////////////////
	c1->Clear();
	c1->Divide(2,2); 
	c1->cd(1);
	auto l7 = new TLegend(0.1,0.7,0.48,0.9);
	hist_pDCREF1->SetLineColor(4);hist_pDCREF1->Draw("HIST");hist_pDCREF1->SetMinimum(1);hist_pDCREF1->GetXaxis()->SetTitle("TDC Channel");
    hist_pDCREF1_cut2->SetLineColor(2);hist_pDCREF1_cut2->Draw("HISTsame");hist_pDCREF1_cut2->SetMinimum(1);
	l7->AddEntry("hist_pDCREF1", "No cut", "l");
	l7->AddEntry("hist_pDCREF1_cut2", "Multiplicity cut==2", "l");
	l7->Draw();
	gPad->SetLogy();
	c1->cd(2);
	hist_pDCREF1_Multi->Draw("HIST");
	c1->cd(3);
	hist_pDCREF1_full->Draw("HIST");
	c1->SaveAs(Form("/work/hallc/alphaE/ruonanli/report_%d.pdf",RunNum));

//////////////////fifth page////////////////////////////////////////////////////////////////
	c1->Clear();
	c1->Divide(3,2);
	c1->cd(1);
	auto l9 = new TLegend(0.1,0.7,0.48,0.9);
	hist_pTRIG4_ROC2->SetLineColor(4);hist_pTRIG4_ROC2->Draw("HIST");hist_pTRIG4_ROC2->SetMinimum(1);hist_pTRIG4_ROC2->GetXaxis()->SetTitle("TDC Channel");
	hist_pTRIG4_ROC2_cut->SetLineColor(2);hist_pTRIG4_ROC2_cut->Draw("HISTsame");hist_pTRIG4_ROC2_cut->SetMinimum(1);
	l9->AddEntry("hist_pTRIG4_ROC2", "No cut", "l");
	l9->AddEntry("hist_pTRIG4_ROC2_cut", "Multiplicity cut ==1", "l");
	l9->Draw();
	c1->cd(2);
	auto l8 = new TLegend(0.1,0.7,0.48,0.9);
	hist_pTRIG1_ROC2->SetLineColor(4);hist_pTRIG1_ROC2->Draw("HIST");hist_pTRIG1_ROC2->SetMinimum(1);hist_pTRIG1_ROC2->GetXaxis()->SetTitle("TDC Channel");
	hist_pTRIG1_ROC2_cut->SetLineColor(2);hist_pTRIG1_ROC2_cut->Draw("HISTsame");hist_pTRIG1_ROC2_cut->SetMinimum(1);
	l8->AddEntry("hist_pTRIG1_ROC2", "No cut", "l");
	l8->AddEntry("hist_pTRIG1_ROC2_cut", "Multiplicity cut ==1", "l");
	l8->Draw();
	c1->cd(3);
	auto l13 = new TLegend(0.1,0.7,0.48,0.9);
	hist_pTRIG1_ROC2->SetLineColor(4);hist_pTRIG1_ROC2->Draw("HIST");hist_pTRIG1_ROC2->SetMinimum(1);hist_pTRIG1_ROC2->GetXaxis()->SetTitle("TDC Channel");
	hist_pTRIG1_ROC2_cut2->SetLineColor(2);hist_pTRIG1_ROC2_cut2->Draw("HISTsame");hist_pTRIG1_ROC2_cut2->SetMinimum(1);
	l13->AddEntry("hist_pTRIG1_ROC2", "No cut", "l");
	l13->AddEntry("hist_pTRIG1_ROC2_cut2", "Multiplicity cut ==2", "l");
	l13->Draw();
	c1->cd(4);
	hist_pTRIG4_ROC2_Multi->Draw();
	c1->cd(5);
	hist_pTRIG1_ROC2_Multi->Draw();
	c1->SaveAs(Form("/work/hallc/alphaE/ruonanli/report_%d.pdf",RunNum));

//////////////////sixth page//////////////////////////////////////////////////////////////////
	c1->Clear();
	c1->Divide(2,2);
	c1->cd(1);
	auto l10 = new TLegend(0.1,0.7,0.48,0.9);
	hist_pTRIG1_ROC1->SetLineColor(4);hist_pTRIG1_ROC1->Draw("HIST");hist_pTRIG1_ROC1->SetMinimum(1);hist_pTRIG1_ROC1->GetXaxis()->SetTitle("TDC Channel");
	hist_pTRIG1_ROC1_cut->SetLineColor(2);hist_pTRIG1_ROC1_cut->Draw("HISTsame");hist_pTRIG1_ROC1_cut->SetMinimum(1);
	l10->AddEntry("hist_pTRIG1_ROC1", "No cut", "l");
	l10->AddEntry("hist_pTRIG1_ROC1_cut", "Multiplicity cut ==1", "l");
	l10->Draw();
	c1->cd(2);
	auto l11 = new TLegend(0.1,0.7,0.48,0.9);
	hist_pTRIG4_ROC1->SetLineColor(4);hist_pTRIG4_ROC1->Draw("HIST");hist_pTRIG4_ROC1->SetMinimum(1);hist_pTRIG4_ROC1->GetXaxis()->SetTitle("TDC Channel");
	hist_pTRIG4_ROC1_cut->SetLineColor(2);hist_pTRIG4_ROC1_cut->Draw("HISTsame");hist_pTRIG4_ROC1_cut->SetMinimum(1);
	l11->AddEntry("hist_pTRIG4_ROC1", "No cut", "l");
	l11->AddEntry("hist_pTRIG4_ROC1_cut", "Multiplicity cut ==1", "l");
	l11->Draw();
	c1->cd(3);
	hist_pTRIG1_ROC1_Multi->Draw();
	c1->cd(4);
	hist_pTRIG4_ROC1_Multi->Draw();
	c1->SaveAs(Form("/work/hallc/alphaE/ruonanli/report_%d.pdf)",RunNum));
}
