#include <iostream>
#include "TFile.h"
#include "TH1F.h"
#include "TTreeReader.h"
#include "TTreeReaderValue.h"
using namespace std;


void Possibility(Int_t RunNum = 0, Int_t HMS_xmax1 = 0, Int_t HMS_xmax2 = 0, Int_t SHMS_xmax1 = 0, Int_t SHMS_xmax2 = 0)
{
	if(HMS_xmax1 = 0) {
		cout << "Enter a HMSxmax1 value: ";
		cin >> HMS_xmax1;
	}

	if(HMS_xmax2 = 0) {
		cout << "Enter a HMSxmax2 value: ";
		cin >> HMS_xmax2;
	}

	if(SHMS_xmax1 = 0) {
		cout << "Enter a SHMSxmax1 value: ";
		cin >> SHMS_xmax1;
	}

	if(SHMS_xmaxa2 = 0) {
		cout << "Enter a SHMSxmax2 value: ";
		cin >> SHMS_xmax2;
	}


		int HMS_bmin = hist_pDCREF1_cut2_full->GetXaxis()->FindBin(0);
		int HMS_bmax1 = hist_pDCREF1_cut2_full->GetXaxis()->FindBin(HMS_xmax1);
		int HMS_bmax2 = hist_pDCREF1_cut2_full->GetXaxis()->FindBin(HMS_xmax2);
		double HMS_integral1 = hist_pDCREF_cut2_full->Integral(HMS_bmin, HMS_bmax1);
		double HMS_integral2 = hist_pDCREF_cut2_full->Integral(HMS_bmin, HMS_bmax2);
		double HNS_percentage = HMS_integral1/HMS_integral2/2.;

		cout << "HMS background couts is: " << HMS_integral1 << "\n";
		cout << "HMS total counts is: " << HMS_integral2 << "\n";
		cout << "HMS possibility is: " << HMS_percentage << "\n";


		int SHMS_bmin = hist_pDCREF1_cut2_full->GetXaxis()->FindBin(0);
		int SHMS_bmax1 = hist_pDCREF1_cut2_full->GetXaxis()->FindBin(SHMS_xmax1);
		int SHMS_bmax2 = hist_pDCREF1_cut2_full->GetXaxis()->FindBin(SHMS_xmax2);
		double SHMS_integral1 = hist_pDCREF_cut2_full->Integral(SHMS_bmin, SHMS_bmax1);
		double SHMS_integral2 = hist_pDCREF_cut2_full->Integral(SHMS_bmin, SHMS_bmax2);
		double SHMS_percentage = SHMS_integral1/SHMS_integral2/2.;

		cout << "SHMS background couts is: " << SHMS_integral1 << "\n";
		cout << "SHMS total counts is: " << SHMS_integral2 << "\n";
		cout << "SHMS possibility is: " << SHMS_percentage << "\n";

/*
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
    hist_hDCREF1->SetLineColor(4);hist_hDCREF1->Draw("HIST");hist_hDCREF1->SetMinimum(1);hist_hDCREF1->GetXaxis()->SetTitle("TDC Channel");
	hist_hDCREF1_cut->SetLineColor(2);hist_hDCREF1_cut->Draw("HISTsame");hist_hDCREF1_cut->SetMinimum(1);
	l3->AddEntry("hist_hDCREF1","No cut","l");
	l3->AddEntry("hist_hDCREF1_cut","Multiplicity==1","l");
	l3->Draw();
	gPad->SetLogy();
	c1->cd(4);
	hist_hROC1_Multi->Draw("HIST");
	c1->cd(5);
	hist_hT2_Multi->Draw("HIST");
	c1->cd(6);
	hist_hDCREF1_Multi->Draw("HIST");
	c1->SaveAs(Form("/work/hallc/alphaE/ruonanli/report_%d.pdf(",RunNum));

/////////////////////second page/////////////////////////////////////////////////
	c1->Clear();
	c1->Divide(2,2);
	c1->cd(1);
	hist_hROC1_full->Draw("HIST");
	c1->cd(2);
	hist_hT2_full->Draw("HIST");
	c1->cd(3);
	hist_hDCREF1_full->Draw("HIST");
	c1->SaveAs(Form("/work/hallc/alphaE/ruonanli/report_%d.pdf",RunNum));

/////////////////////third page/////////////////////////////////////////////////
	c1->Clear();
	c1->Divide(3,2);
	c1->cd(1);
	auto l4 = new TLegend(0.1,0.7,0.48,0.9);
	hist_pROC2->SetLineColor(4);hist_pROC2->Draw("HIST");hist_pROC2->SetMinimum(1);hist_pROC2->GetXaxis()->SetTitle("ADC Channel");
    hist_pROC2_cut->SetLineColor(2);hist_pROC2_cut->Draw("HISTsame");hist_pROC2_cut->SetMinimum(1);
	l4->AddEntry("hist_pROC2","No cut","l");
	l4->AddEntry("hist_pROC2_cut","Multiciplity==2","l");
	l4->Draw();
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
	hist_pT1->SetLineColor(4);hist_pT1->Draw("HIST");hist_pT1->SetMinimum(1);hist_pT1->GetXaxis()->SetTitle("TDC Channel");
    hist_pT1_cut4->SetLineColor(2);hist_pT1_cut4->Draw("HISTsame");hist_pT1_cut4->SetMinimum(1);
	l6->AddEntry("hist_pT1","No cut","l");
	l6->AddEntry("hist_pT1_cut4","Multiplicity==4","l");
	l6->Draw();
	gPad->SetLogy();
	c1->cd(4);
	hist_pROC2_Multi->Draw("HIST");
	c1->cd(5);
	hist_pT1_Multi->Draw("HIST");
	c1->cd(6);
	hist_pT1_full->Draw("HIST");
	c1->SaveAs(Form("/work/hallc/alphaE/ruonanli/report_%d.pdf",RunNum));

///////////////////fourth page///////////////////////////////////////////////////////////////
	c1->Clear();
	c1->Divide(3,2); 
	c1->cd(1);
	auto l7 = new TLegend(0.1,0.7,0.48,0.9);
	hist_pDCREF1->SetLineColor(4);hist_pDCREF1->Draw("HIST");hist_pDCREF1->SetMinimum(1);hist_pDCREF1->GetXaxis()->SetTitle("TDC Channel");
    hist_pDCREF1_cut2->SetLineColor(2);hist_pDCREF1_cut2->Draw("HISTsame");hist_pDCREF1_cut2->SetMinimum(1);
	l7->AddEntry("hist_pDCREF1", "No cut", "l");
	l7->AddEntry("hist_pDCREF1_cut2", "Multiplicity cut==2", "l");
	l7->Draw();
	gPad->SetLogy();
	c1->cd(2);
	auto l8 = new TLegend(0.1,0.7,0.48,0.9);
	hist_pDCREF1->SetLineColor(4);hist_pDCREF1->Draw("HIST");hist_pDCREF1->SetMinimum(1);hist_pDCREF1->GetXaxis()->SetTitle("TDC Channel");
    hist_pDCREF1_cut4->SetLineColor(2);hist_pDCREF1_cut4->Draw("HISTsame");hist_pDCREF1_cut4->SetMinimum(1);
	l8->AddEntry("hist_pDCREF1", "No cut", "l");
	l8->AddEntry("hist_pDCREF1_cut4", "Multiplicity cut==4", "l");
	l8->Draw();
	gPad->SetLogy();
	c1->cd(3);
	auto l9 = new TLegend(0.1,0.7,0.48,0.9);
	hist_pDCREF1->SetLineColor(4);hist_pDCREF1->Draw("HIST");hist_pDCREF1->SetMinimum(1);hist_pDCREF1->GetXaxis()->SetTitle("TDC Channel");
    hist_pDCREF1_cut6->SetLineColor(2);hist_pDCREF1_cut6->Draw("HISTsame");hist_pDCREF1_cut6->SetMinimum(1);
	l9->AddEntry("hist_pDCREF1", "No cut", "l");
	l9->AddEntry("hist_pDCREF1_cut6", "Multiplicity cut==6", "l");
	l9->Draw();
	gPad->SetLogy();
	c1->cd(4);
	hist_pDCREF1_Multi->Draw("HIST");
	c1->cd(5);
	hist_pDCREF1_full->Draw("HIST");
	c1->SaveAs(Form("/work/hallc/alphaE/ruonanli/report_%d.pdf)",RunNum));
*/

	




}
