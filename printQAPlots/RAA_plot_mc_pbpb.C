// Owen Baron
// December 12 2016

#include <iostream>
#include <stdio.h>
#include <fstream>
#include <sstream>
#include <TH1F.h>
#include <TH1F.h>
#include <TH2F.h>
#include <TFile.h>
#include <TTree.h>
#include <TF1.h>
#include <TCanvas.h>
#include <TLegend.h>
#include <TGraphErrors.h>
#include <TGraphAsymmErrors.h>
#include <TH1.h>
#include <TH2.h>
#include <TH3.h>
#include <TFile.h>
#include <TNtuple.h>
#include <TStyle.h>
#include <TStopwatch.h>
#include <TRandom3.h>
#include <TChain.h>
#include <TProfile.h>
#include <TStopwatch.h>
#include <TEventList.h>
#include <TSystem.h>
#include <TCut.h>
#include <cstdlib>
#include <cmath>
#include "TLegend.h"
#include "TLatex.h"
#include "TMath.h"
#include "TLine.h"

//static const Int_t nbins_cent = 6;
//static const Double_t boundaries_cent[nbins_cent+1] = {0,2,4,12,20,28,36};// multiply by 2.5 to get your actual centrality % (old 2011 data) 
//const int radius = 3;

void RAA_plot_mc_pbpb(){
//TFile *f = TFile::Open("/net/hisrv0001/home/obaron/CMSSW_5_3_20/newdrawfiles/PbPb_MC/PbPb_MC_histograms_FromForest_akPu3_anabin_20_eta_20.root");
TFile *f = new TFile("/export/d00/scratch/ilaflott/5p02TeV_ppJetAnalysis/readForests/11.22.16_outputCondor/ppMC_Py8_CUETP8M1_QCDjetAllPtBins_ak3PFJets_11-22-16__loose_jetPlots/Py8_CUETP8M1_QCDjetAllPtBins_ak3PF-allFiles.root");
//TFile *file_B = new TFile("/net/hisrv0001/home/obaron/CMSSW_5_3_20/newdrawfiles/PbPb_MC/PbPb_MC_histograms_FromForest_akPu%d_anabin_20_eta_20.root");

TCanvas *EtaCan;
TCanvas *PhiCan;
TCanvas *rawpTCan;
TCanvas *recopTCan;

TH1F *hrawpT;
TH1F *hrawpT_cut;
TH1F *hrawpTratio;

	rawpTCan = new TCanvas("rawpTCan","rawpTCan",600,600);
	hrawpT_cut = (TH1F*)f->Get("hJetQA_1wJetID_jtpt");
	hrawpT = (TH1F*)f->Get("hJetQA_0wJetID_jtpt");
	hrawpTratio = new TH1F("rawpTratio","rawpTratio",500,0,5000);
	hrawpTratio->Divide(hrawpT,hrawpT_cut);
	hrawpTratio->SetMarkerStyle(kMultiply);
    hrawpTratio->SetMarkerSize(0.99);
    hrawpTratio->Scale(1./hrawpTratio->GetBinWidth(1));
	hrawpTratio->Draw();
	
	//EtaCan = new TCanvas("EtaCan","EtaCan",600,600);
	
	/*
	EtaRatCan[i] = new TCanvas(Form("EtaRatios_%d",i),Form("Eta Cut/Precut Ratios R%d %2.0f - %2.0f cent",radius,5*boundaries_cent[i],5*boundaries_cent[i+1]),1750,500);
	EtaRatCan[i]->Divide(3,1);
	EtaRatCan[i]->cd(1);
	EtaRatio80[i] = new TH1F(Form("E80%d",i),Form("Eta 80 Cut/Precut"),30,-2.5,2.5);
	EtaRatio80[i]->Divide(hEta80[i],hEtaPrecut80[i]);
	EtaRatio80[i]->GetXaxis()->SetTitle("Eta");
	EtaRatio80[i]->GetXaxis()->CenterTitle();
	EtaRatio80[i]->GetYaxis()->SetRangeUser(0.6,1.4);
	EtaRatio80[i]->Draw();
	EtaRatCan[i]->cd(2);
	EtaRatio65[i] = new TH1F(Form("E65%d",i),Form("Eta 65 Cut/Precut"),30,-2.5,2.5);
	EtaRatio65[i]->Divide(hEta65[i],hEtaPrecut65[i]);
	EtaRatio65[i]->GetXaxis()->SetTitle("Eta");
	EtaRatio65[i]->GetYaxis()->SetRangeUser(0.6,1.4);
	EtaRatio65[i]->GetXaxis()->CenterTitle();
	EtaRatio65[i]->Draw();
	EtaRatCan[i]->cd(3);
	EtaRatio55[i] = new TH1F(Form("E55%d",i),Form("Eta 55 Cut/Precut"),30,-2.5,2.5);
	EtaRatio55[i]->Divide(hEta55[i],hEtaPrecut55[i]);
	EtaRatio55[i]->GetXaxis()->SetTitle("Eta");
	EtaRatio55[i]->GetXaxis()->CenterTitle();
	EtaRatio55[i]->GetYaxis()->SetRangeUser(0.6,1.4);
	EtaRatio55[i]->Draw();
*/
	
/*
	EtaCan65[i] = new TCanvas(Form("EtaCan65_%d",i),Form("Jet65 R%d Eta and Phi plots %2.0f - %2.0f cent",radius,5*boundaries_cent[i],5*boundaries_cent[i+1]),1750,500);
	EtaCan65[i]->Divide(3,1);
	EtaCan65[i]->cd(1);
	hEta65[i] = (TH1F*)f->Get(Form("hpbpb_Jet65_etacent_R%d_cent%d",radius,i));
	hEta65[i]->GetXaxis()->SetTitle("Eta");
	hEta65[i]->GetXaxis()->CenterTitle();
	hEta65[i]->GetYaxis()->SetTitle("Multiplicity");
	hEta65[i]->GetYaxis()->CenterTitle();
	hEta65[i]->Draw();
	EtaCan65[i]->cd(2);
	hPhi65[i] = (TH1F*)f->Get(Form("hpbpb_Jet65_phicent_R%d_cent%d",radius,i));
	hPhi65[i]->GetXaxis()->SetTitle("Phi");
	hPhi65[i]->GetXaxis()->CenterTitle();
	hPhi65[i]->GetYaxis()->SetTitle("Multiplicity");
	hPhi65[i]->GetYaxis()->CenterTitle();
	hPhi65[i]->Draw();
	EtaCan65[i]->cd(3);
	hPhieta65[i] = (TH1F*)f->Get(Form("hpbpb_Jet65_phieta_R%d_cent%d",radius,i));
	hPhieta65[i]->GetXaxis()->SetTitle("Eta");
	hPhieta65[i]->GetXaxis()->CenterTitle();
	hPhieta65[i]->GetYaxis()->SetTitle("Phi");
	hPhieta65[i]->GetYaxis()->CenterTitle();
	hPhieta65[i]->Draw("colz,logz");
	
	EtaCan55[i] = new TCanvas(Form("EtaCan55_%d",i),Form("Jet55 R%d Eta and Phi plots %2.0f - %2.0f cent",radius,5*boundaries_cent[i],5*boundaries_cent[i+1]),1750,500);
	EtaCan55[i]->Divide(3,1);
	EtaCan55[i]->cd(1);
	hEta55[i] = (TH1F*)f->Get(Form("hpbpb_Jet55_etacent_R%d_cent%d",radius,i));
	hEta55[i]->GetXaxis()->SetTitle("Eta");
	hEta55[i]->GetXaxis()->CenterTitle();
	hEta55[i]->GetYaxis()->SetTitle("Multiplicity");
	hEta55[i]->GetYaxis()->CenterTitle();
	hEta55[i]->Draw();
	EtaCan55[i]->cd(2);
	hPhi55[i] = (TH1F*)f->Get(Form("hpbpb_Jet55_phicent_R%d_cent%d",radius,i));
	hPhi55[i]->GetXaxis()->SetTitle("Phi");
	hPhi55[i]->GetXaxis()->CenterTitle();
	hPhi55[i]->GetYaxis()->SetTitle("Multiplicity");
	hPhi55[i]->GetYaxis()->CenterTitle();
	hPhi55[i]->Draw();
	EtaCan55[i]->cd(3);
	hPhieta55[i] = (TH1F*)f->Get(Form("hpbpb_Jet55_phieta_R%d_cent%d",radius,i));
	hPhieta55[i]->GetXaxis()->SetTitle("Eta");
	hPhieta55[i]->GetXaxis()->CenterTitle();
	hPhieta55[i]->GetYaxis()->SetTitle("Phi");
	hPhieta55[i]->GetYaxis()->CenterTitle();
	hPhieta55[i]->Draw("colz,logz");
	
	pTCan[i] = new TCanvas(Form("pTCan%d",i),Form("pT plots R%d %2.0f - %2.0f cent",radius,5*boundaries_cent[i],5*boundaries_cent[i+1]),1167,500);
	pTCan[i]->Divide(2,1);
	pTCan[i]->cd(1);
	pTGen[i] = (TH1F*)f->Get(Form("hpbpb_gen_R%d_20_eta_20_cent%d",radius,i));
	pTGen[i]->GetXaxis()->SetTitle("Gen pT");
	pTGen[i]->GetXaxis()->CenterTitle();
	pTGen[i]->GetXaxis()->SetRange(0,300);
	pTGen[i]->Draw();
	pTCan[i]->cd(2);
	pTReco[i] = (TH1F*)f->Get(Form("hpbpb_reco_R%d_20_eta_20_cent%d",radius,i));
	pTReco[i]->GetXaxis()->SetTitle("Reco pT");
	pTReco[i]->GetXaxis()->CenterTitle();
	pTReco[i]->GetXaxis()->SetRange(0,300);
	pTReco[i]->Draw("logy");
	
	pTCan80[i] = new TCanvas(Form("pTCan80_%d",i),Form("Jet 80 pT plots R%d %2.0f - %2.0f cent",radius,5*boundaries_cent[i],5*boundaries_cent[i+1]),1167,500);
	pTCan80[i]->Divide(2,1);
	pTCan80[i]->cd(1);
	pTGen80[i] = (TH1F*)f->Get(Form("hpbpb_Jet80_gen_R%d_20_eta_20_cent%d",radius,i));
	pTGen80[i]->GetXaxis()->SetTitle("Jet 80 Gen pT");
	pTGen80[i]->GetXaxis()->CenterTitle();
	pTGen80[i]->GetXaxis()->SetRange(0,300);
	pTGen80[i]->Draw("logy");
	pTCan80[i]->cd(2);
	pTReco80[i] = (TH1F*)f->Get(Form("hpbpb_Jet80_reco_R%d_20_eta_20_cent%d",radius,i));
	pTReco80[i]->GetXaxis()->SetTitle("Jet 80 Reco pT");
	pTReco80[i]->GetXaxis()->CenterTitle();
	pTReco80[i]->GetXaxis()->SetRange(0,300);
	pTReco80[i]->Draw("logy");
	
	pTCan65[i] = new TCanvas(Form("pTCan65_%d",i),Form("Jet 65 pT plots R%d %2.0f - %2.0f cent",radius,5*boundaries_cent[i],5*boundaries_cent[i+1]),1167,500);
	pTCan65[i]->Divide(2,1);
	pTCan65[i]->cd(1);
	pTGen65[i] = (TH1F*)f->Get(Form("hpbpb_Jet65_gen_R%d_20_eta_20_cent%d",radius,i));
	pTGen65[i]->GetXaxis()->SetTitle("Jet 65 Gen pT");
	pTGen65[i]->GetXaxis()->CenterTitle();
	pTGen65[i]->GetXaxis()->SetRange(0,300);
	pTGen65[i]->Draw("logy");
	pTCan65[i]->cd(2);
	pTReco65[i] = (TH1F*)f->Get(Form("hpbpb_Jet65_reco_R%d_20_eta_20_cent%d",radius,i));
	pTReco65[i]->GetXaxis()->SetTitle("Jet 65 Reco pT");
	pTReco65[i]->GetXaxis()->CenterTitle();
	pTReco65[i]->GetXaxis()->SetRange(0,300);
	pTReco65[i]->Draw("logy");
	
	pTCan55[i] = new TCanvas(Form("pTCan55_%d",i),Form("Jet 55 pT plots R%d %2.0f - %2.0f cent",radius,5*boundaries_cent[i],5*boundaries_cent[i+1]),1167,500);
	pTCan55[i]->Divide(2,1);
	pTCan55[i]->cd(1);
	pTGen55[i] = (TH1F*)f->Get(Form("hpbpb_Jet55_gen_R%d_20_eta_20_cent%d",radius,i));
	pTGen55[i]->GetXaxis()->SetTitle("Jet 55 Gen pT");
	pTGen55[i]->GetXaxis()->CenterTitle();
	pTGen55[i]->GetXaxis()->SetRange(0,300);
	pTGen55[i]->Draw("logy");
	pTCan55[i]->cd(2);
	pTReco55[i] = (TH1F*)f->Get(Form("hpbpb_Jet55_reco_R%d_20_eta_20_cent%d",radius,i));
	pTReco55[i]->GetXaxis()->SetTitle("Jet 55 Reco pT");
	pTReco55[i]->GetXaxis()->CenterTitle();
	pTReco55[i]->GetXaxis()->SetRange(0,300);
	pTReco55[i]->Draw("logy");
	
	
	//SECOND FILE LOOP
	
	
	*/
	//SAVE
	rawpTCan->SaveAs("/net/hisrv0001/home/obaron/CMSSW_7_5_8/src/5p02TeV_ppJetAnalysis/printQAPlots/drawfiles/MC/rawpTratio.pdf","RECREATE");
	
	
	cout<<"end loop"<<endl;	


//pbpb plots here:
//TCanvas *t[radius][nbins_eta]

}
