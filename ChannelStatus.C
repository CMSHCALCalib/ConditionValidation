#include <vector>
#include <exception>
#include "TStyle.h"
#include "TFile.h"
#include "TF1.h"
#include "TH2.h"
#include "TH1F.h"
#include "TH2F.h"
#include "TProfile.h"
#include "TCanvas.h"
#include "TColor.h"
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

void compare() {

	const char* file0 = "HcalChannelQuality_2018_v4.0_data_run324878.txt"; //new
	const char* file1 = "HcalChannelQuality_2018_v4.0_data_test.txt"; //pre

	//const char* file0 = "HCAL/producers/HEM15_16/DumpChannelQuality_Run1.txt"; //pre
	

	float mr = 1; // range amplitude
	float r_a = -1 * mr, r_b = 1 * mr;//hb
	float r3_a = -1 * mr, r3_b = 1 * mr;//he
	float r4_a = -1 * mr, r4_b = 1 * mr;//ho
	float r2_a = -1 * mr, r2_b = 1 * mr;//hf

	float outR = 1.0;  // the differences new vs prev for outliers
	
  gStyle->SetOptStat(0);
  gStyle->SetOptStat(0);
  gStyle->SetOptFit(0);
  gStyle->SetLabelFont(42);
  gStyle->SetLabelFont(42);
  gStyle->SetTitleFont(42);
  gStyle->SetTitleFont(42);
  gStyle->SetMarkerSize(0);
  gStyle->SetTitleOffset(1.3,"Y");
  gStyle->SetTitleOffset(1.0,"X");
  gStyle->SetNdivisions(510);
  gStyle->SetStatH(0.11);
  gStyle->SetStatW(0.33);
  gStyle->SetTitleW(0.4);
  gStyle->SetTitleX(0.13);
  gROOT->ForceStyle();
  gStyle->SetPadTickX(1);
  gStyle->SetPadTickY(1);
   

  FILE *ft0;
  if ((ft0 = fopen(file0,"r"))==NULL){ 
    printf("\nNo file %s open => EXIT\n\n",file0);
    exit(1);
  }
  printf("File '%s' open \n",file0);

  FILE *ft1;
  if ((ft1 = fopen(file1,"r"))==NULL){ 
    printf("\nNo file %s open => EXIT\n\n",file1);
    exit(1);
  }
  printf("File '%s' open \n",file1);

 
  TH2F *hHB_d1 = new TH2F("HB_d1", "          HB_d1", 83, -42, 42, 71, 1, 72);
  TH2F *hHB_d2 = new TH2F("HB_d2", "          HB_d2", 83, -42, 42, 71, 1, 72);
  TH2F *hHO_d1 = new TH2F("HO_d1", "          HO_d4", 83, -42, 42, 71, 1, 72);
  TH2F *hHE_d1 = new TH2F("HE_d1", "          HE_d1", 83, -42, 42, 71, 1, 72);
  TH2F *hHE_d2 = new TH2F("HE_d2", "          HE_d2", 83, -42, 42, 71, 1, 72);
  TH2F *hHE_d3 = new TH2F("HE_d3", "          HE_d3", 83, -42, 42, 71, 1, 72);
  TH2F *hHE_d4 = new TH2F("HE_d4", "          HE_d4", 83, -42, 42, 71, 1, 72);
  TH2F *hHE_d5 = new TH2F("HE_d5", "          HE_d5", 83, -42, 42, 71, 1, 72);
  TH2F *hHE_d6 = new TH2F("HE_d6", "          HE_d6", 83, -42, 42, 71, 1, 72);
  TH2F *hHE_d7 = new TH2F("HE_d7", "          HE_d7", 83, -42, 42, 71, 1, 72);
  TH2F *hHF_d1 = new TH2F("HF_d1", "          HF_d1", 83, -42, 42, 71, 1, 72);
  TH2F *hHF_d2 = new TH2F("HF_d2", "          HF_d2", 83, -42, 42, 71, 1, 72);
  TH2F *hHF_d3 = new TH2F("HF_d3", "         HF_d3", 83, -42, 42, 71, 1, 72);
  TH2F *hHF_d4 = new TH2F("HF_d4", "         HF_d4", 83, -42, 42, 71, 1, 72);

  TH2F *hHB_d1b = new TH2F("HB_d1b", "          HB_d1", 83, -42, 42, 71, 1, 72);
  TH2F *hHB_d2b = new TH2F("HB_d2b", "          HB_d2", 83, -42, 42, 71, 1, 72);
  TH2F *hHO_d1b = new TH2F("HO_d1b", "          HO_d4", 83, -42, 42, 71, 1, 72);
  TH2F *hHE_d1b = new TH2F("HE_d1b", "          HE_d1", 83, -42, 42, 71, 1, 72);
  TH2F *hHE_d2b = new TH2F("HE_d2b", "          HE_d2", 83, -42, 42, 71, 1, 72);
  TH2F *hHE_d3b = new TH2F("HE_d3b", "          HE_d3", 83, -42, 42, 71, 1, 72);
  TH2F *hHE_d4b = new TH2F("HE_d4b", "          HE_d4", 83, -42, 42, 71, 1, 72);
  TH2F *hHE_d5b = new TH2F("HE_d5b", "          HE_d5", 83, -42, 42, 71, 1, 72);
  TH2F *hHE_d6b = new TH2F("HE_d6b", "          HE_d6", 83, -42, 42, 71, 1, 72);
  TH2F *hHE_d7b = new TH2F("HE_d7b", "          HE_d7", 83, -42, 42, 71, 1, 72);
  TH2F *hHF_d1b = new TH2F("HF_d1b", "          HF_d1", 83, -42, 42, 71, 1, 72);
  TH2F *hHF_d2b = new TH2F("HF_d2b", "          HF_d2", 83, -42, 42, 71, 1, 72);
  TH2F *hHF_d3b = new TH2F("HF_d3b", "         HF_d3", 83, -42, 42, 71, 1, 72);
  TH2F *hHF_d4b = new TH2F("HF_d4b", "         HF_d4", 83, -42, 42, 71, 1, 72);

  //legend of channel status;
  TH1F* PlaceHolder = new TH1F("PH", "PH", 1, 0, 1.0);
  TH1F* hStatus[4];
  for (int i = 0; i < 4; i++) {
	  hStatus[i]= (TH1F*)PlaceHolder->Clone();
	  hStatus[i]->SetMarkerStyle(21);
	  hStatus[i]->SetMarkerSize(2);
  }

  hStatus[0]->SetMarkerColor(kGreen);
  hStatus[1]->SetMarkerColor(kRed);
  hStatus[2]->SetMarkerColor(kSpring+10);
  hStatus[3]->SetMarkerColor(kViolet);

  for (int i = 1; i <= 83; i++) {
	  for (int k = 1; k <= 72; k++) {
		  hHB_d1->SetBinContent(i, k, -999);
		  hHB_d2->SetBinContent(i, k, -999);
		  hHO_d1->SetBinContent(i, k, -999);
		  hHE_d1->SetBinContent(i, k, -999);
		  hHE_d2->SetBinContent(i, k, -999);
		  hHE_d3->SetBinContent(i, k, -999);
		  hHE_d4->SetBinContent(i, k, -999);
		  hHE_d5->SetBinContent(i, k, -999);
		  hHE_d6->SetBinContent(i, k, -999);
		  hHE_d7->SetBinContent(i, k, -999);
		  hHF_d1->SetBinContent(i, k, -999);
		  hHF_d2->SetBinContent(i, k, -999);
		  hHF_d3->SetBinContent(i, k, -999);
		  hHF_d4->SetBinContent(i, k, -999);
	  }
  }
    
  int ieta2,iphi2,depth2, ieta0,iphi0,depth0;
  float c1, c2;
  char comment[500], SubDet1[160], SubDet2[160], DetID1[160], DetID2[160], base[10], base2[10];
  
  fgets(comment,500,ft0);
  

    
  for (int j=0; j<99999; j++) {
    if (feof(ft0)!=0) break;
	fscanf(ft0, "%d%d%d%s%s%f%s\r", &ieta0, &iphi0, &depth0, SubDet1, base, &c1, DetID1);

	//cout << " here 1 " << endl;
   
      c1 = c1+999;

	  if (SubDet1[1] == 'B') {
		  if (depth0 == 1) hHB_d1->Fill(ieta0, iphi0, c1);
		  if (depth0 == 2) hHB_d2->Fill(ieta0, iphi0, c1);
	  }
	  if (SubDet1[1] == 'O') {
		  if (depth0>0)hHO_d1->Fill(ieta0, iphi0, c1);
	  }
	  if (SubDet1[1] == 'E') {
		  if (depth0 == 1)hHE_d1->Fill(ieta0, iphi0, c1);
		  if (depth0 == 2)hHE_d2->Fill(ieta0, iphi0, c1);
		  if (depth0 == 3)hHE_d3->Fill(ieta0, iphi0, c1);
		  if (depth0 == 4)hHE_d4->Fill(ieta0, iphi0, c1);
		  if (depth0 == 5)hHE_d5->Fill(ieta0, iphi0, c1);
		  if (depth0 == 6)hHE_d6->Fill(ieta0, iphi0, c1);
		  if (depth0 == 7)hHE_d7->Fill(ieta0, iphi0, c1);
	  }
	  if (SubDet1[1] == '\F') {
		  if (depth0 == 1)hHF_d1->Fill(ieta0, iphi0, c1);
		  if (depth0 == 2)hHF_d2->Fill(ieta0, iphi0, c1);
		  if (depth0 == 3)hHF_d3->Fill(ieta0, iphi0, c1);
		  if (depth0 == 4)hHF_d4->Fill(ieta0, iphi0, c1);
	  }
  }


  fgets(comment, 500, ft1);
  for (int k = 0; k<99999; k++) {
	  if (feof(ft1) != 0) break;

	  fscanf(ft1, "%d%d%d%s%s%f%s\r", &ieta2, &iphi2, &depth2, SubDet2, base2, &c2, DetID2);
	  if (c2 != 0) c2 = c2 + 0.99;// to mark channels wich are dead for long time

	  if (SubDet2[1] == 'B') {
		  if (depth2 == 1) hHB_d1b->Fill(ieta2, iphi2, c2);
		  if (depth2 == 2) hHB_d2b->Fill(ieta2, iphi2, c2);
	  }
	  if (SubDet2[1] == 'O') {
		  if (depth2>0)hHO_d1b->Fill(ieta2, iphi2, c2);
	  }
	  if (SubDet2[1] == 'E') {
		  if (depth2 == 1)hHE_d1b->Fill(ieta2, iphi2, c2);
		  if (depth2 == 2)hHE_d2b->Fill(ieta2, iphi2, c2);
		  if (depth2 == 3)hHE_d3b->Fill(ieta2, iphi2, c2);
		  if (depth2 == 4)hHE_d4b->Fill(ieta2, iphi2, c2);
		  if (depth2 == 5)hHE_d5b->Fill(ieta2, iphi2, c2);
		  if (depth2 == 6)hHE_d6b->Fill(ieta2, iphi2, c2);
		  if (depth2 == 7)hHE_d7b->Fill(ieta2, iphi2, c2);
	  }
	  if (SubDet2[1] == 'F') {
		  if (depth2 == 1)hHF_d1b->Fill(ieta2, iphi2, c2);
		  if (depth2 == 2)hHF_d2b->Fill(ieta2, iphi2, c2);
		  if (depth2 == 3)hHF_d3b->Fill(ieta2, iphi2, c2);
		  if (depth2 == 4)hHF_d4b->Fill(ieta2, iphi2, c2);
	  }
  }
  
  hHB_d1->Add(hHB_d1, hHB_d1b, 1, -1);
  hHB_d2->Add(hHB_d2, hHB_d2b, 1, -1);
  hHO_d1->Add(hHO_d1, hHO_d1b, 1, -1);
  hHE_d1->Add(hHE_d1, hHE_d1b, 1, -1);
  hHE_d2->Add(hHE_d2, hHE_d2b, 1, -1);
  hHE_d3->Add(hHE_d3, hHE_d3b, 1, -1);
  hHE_d4->Add(hHE_d4, hHE_d4b, 1, -1);
  hHE_d5->Add(hHE_d5, hHE_d5b, 1, -1);
  hHE_d6->Add(hHE_d6, hHE_d6b, 1, -1);
  hHE_d7->Add(hHE_d7, hHE_d7b, 1, -1);
  hHF_d1->Add(hHF_d1, hHF_d1b, 1, -1);
  hHF_d2->Add(hHF_d2, hHF_d2b, 1, -1);
  hHF_d3->Add(hHF_d3, hHF_d3b, 1, -1);
  hHF_d4->Add(hHF_d4, hHF_d4b, 1, -1);
  
  TCanvas *cv1 = new TCanvas("cv1", "HBHO", 1000, 1000);
  cv1->Divide(2, 2);

  cv1->cd(1);
  cv1->GetPad(1)->SetGridx(1);
  cv1->GetPad(1)->SetGridy(1);
  hHB_d1->Draw("colz");
  hHB_d1->SetContour(100);
  hHB_d1->GetXaxis()->SetTitle("ieta");
  hHB_d1->GetYaxis()->SetTitle("iphi");
  hHB_d1->GetXaxis()->CenterTitle();
  hHB_d1->GetYaxis()->CenterTitle();
  hHB_d1->GetZaxis()->SetRangeUser(r_a, r_b);
  hHB_d1->GetYaxis()->SetTitleSize(0.06);
  hHB_d1->GetYaxis()->SetTitleOffset(0.80);
  hHB_d1->GetXaxis()->SetTitleSize(0.06);
  hHB_d1->GetXaxis()->SetTitleOffset(0.80);
  hHB_d1->GetYaxis()->SetLabelSize(0.055);
  hHB_d1->GetXaxis()->SetLabelSize(0.055);

  cv1->cd(2);
  cv1->GetPad(2)->SetGridx(1);
  cv1->GetPad(2)->SetGridy(1);
  hHB_d2->Draw("colz");
  hHB_d2->SetContour(100);
  hHB_d2->GetXaxis()->SetTitle("ieta");
  hHB_d2->GetYaxis()->SetTitle("iphi");
  hHB_d2->GetXaxis()->CenterTitle();
  hHB_d2->GetYaxis()->CenterTitle();
  hHB_d2->GetZaxis()->SetRangeUser(r_a, r_b);
  hHB_d2->GetYaxis()->SetTitleSize(0.06);
  hHB_d2->GetYaxis()->SetTitleOffset(0.80);
  hHB_d2->GetXaxis()->SetTitleSize(0.06);
  hHB_d2->GetXaxis()->SetTitleOffset(0.80);
  hHB_d2->GetYaxis()->SetLabelSize(0.055);
  hHB_d2->GetXaxis()->SetLabelSize(0.055);
  hHB_d1->SetContour(100);

  cv1->cd(3);
  cv1->GetPad(3)->SetGridx(1);
  cv1->GetPad(3)->SetGridy(1);
  hHO_d1->Draw("colz");
  hHO_d1->SetContour(100);
  hHO_d1->GetXaxis()->SetTitle("ieta");
  hHO_d1->GetYaxis()->SetTitle("iphi");
  hHO_d1->GetXaxis()->CenterTitle();
  hHO_d1->GetYaxis()->CenterTitle();
  hHO_d1->GetZaxis()->SetRangeUser(r_a, r_b);
  hHO_d1->GetYaxis()->SetTitleSize(0.06);
  hHO_d1->GetYaxis()->SetTitleOffset(0.80);
  hHO_d1->GetXaxis()->SetTitleSize(0.06);
  hHO_d1->GetXaxis()->SetTitleOffset(0.80);
  hHO_d1->GetYaxis()->SetLabelSize(0.055);
  hHO_d1->GetXaxis()->SetLabelSize(0.055);

  cv1->cd(4);
  TH2D* hPlaceHolder2d =  new TH2D("Legend", "Channel Status",1,0,1,1,0,1);
  hPlaceHolder2d->Draw();
  TLegend *legend3 = new TLegend(0.30, 0.50, 0.7, 0.72);
  legend3->SetTextSize(0.05);
  legend3->SetTextFont(42);
  legend3->AddEntry(hStatus[0], "healthy", "p");
  legend3->AddEntry(hStatus[2], "unmasked", "p");
  legend3->AddEntry(hStatus[1], "newly bad", "p");
  legend3->AddEntry(hStatus[3], "long dead", "p");
  legend3->SetFillColor(kWhite);
  legend3->SetLineColor(kWhite);
  legend3->Draw();

  TCanvas *cv2 = new TCanvas("cv2", "HE", 1000, 1000);
  cv2->Divide(3, 3);

  cv2->cd(1);
  cv2->GetPad(1)->SetGridx(1);
  cv2->GetPad(1)->SetGridy(1);
  hHE_d1->SetContour(100);
  hHE_d1->Draw("colz");
  hHE_d1->GetXaxis()->SetTitle("ieta");
  hHE_d1->GetYaxis()->SetTitle("iphi");
  hHE_d1->GetXaxis()->CenterTitle();
  hHE_d1->GetYaxis()->CenterTitle();
  hHE_d1->GetZaxis()->SetRangeUser(r3_a, r3_b);
  hHE_d1->GetYaxis()->SetTitleSize(0.06);
  hHE_d1->GetYaxis()->SetTitleOffset(0.80);
  hHE_d1->GetXaxis()->SetTitleSize(0.06);
  hHE_d1->GetXaxis()->SetTitleOffset(0.80);
  hHE_d1->GetYaxis()->SetLabelSize(0.055);
  hHE_d1->GetXaxis()->SetLabelSize(0.055);

  cv2->cd(2);
  cv2->GetPad(2)->SetGridx(1);
  cv2->GetPad(2)->SetGridy(1);
  hHE_d2->Draw("colz");
  hHE_d2->SetContour(100);
  hHE_d2->GetXaxis()->SetTitle("ieta");
  hHE_d2->GetYaxis()->SetTitle("iphi");
  hHE_d2->GetXaxis()->CenterTitle();
  hHE_d2->GetYaxis()->CenterTitle();
  hHE_d2->GetZaxis()->SetRangeUser(r3_a, r3_b);
  hHE_d2->GetYaxis()->SetTitleSize(0.06);
  hHE_d2->GetYaxis()->SetTitleOffset(0.80);
  hHE_d2->GetXaxis()->SetTitleSize(0.06);
  hHE_d2->GetXaxis()->SetTitleOffset(0.80);
  hHE_d2->GetYaxis()->SetLabelSize(0.055);
  hHE_d2->GetXaxis()->SetLabelSize(0.055);

  cv2->cd(3);
  cv2->GetPad(3)->SetGridx(1);
  cv2->GetPad(3)->SetGridy(1);
  hHE_d3->Draw("colz");
  hHE_d3->SetContour(100);
  hHE_d3->GetXaxis()->SetTitle("ieta");
  hHE_d3->GetYaxis()->SetTitle("iphi");
  hHE_d3->GetXaxis()->CenterTitle();
  hHE_d3->GetYaxis()->CenterTitle();
  hHE_d3->GetZaxis()->SetRangeUser(r3_a, r3_b);
  hHE_d3->GetYaxis()->SetTitleSize(0.06);
  hHE_d3->GetYaxis()->SetTitleOffset(0.80);
  hHE_d3->GetXaxis()->SetTitleSize(0.06);
  hHE_d3->GetXaxis()->SetTitleOffset(0.80);
  hHE_d3->GetYaxis()->SetLabelSize(0.055);
  hHE_d3->GetXaxis()->SetLabelSize(0.055);

  cv2->cd(4);
  cv2->GetPad(4)->SetGridx(1);
  cv2->GetPad(4)->SetGridy(1);
  hHE_d4->Draw("colz");
  hHE_d4->SetContour(100);
  hHE_d4->GetXaxis()->SetTitle("ieta");
  hHE_d4->GetYaxis()->SetTitle("iphi");
  hHE_d4->GetXaxis()->CenterTitle();
  hHE_d4->GetYaxis()->CenterTitle();
  hHE_d4->GetZaxis()->SetRangeUser(r3_a, r3_b);
  hHE_d4->GetYaxis()->SetTitleSize(0.06);
  hHE_d4->GetYaxis()->SetTitleOffset(0.80);
  hHE_d4->GetXaxis()->SetTitleSize(0.06);
  hHE_d4->GetXaxis()->SetTitleOffset(0.80);
  hHE_d4->GetYaxis()->SetLabelSize(0.055);
  hHE_d4->GetXaxis()->SetLabelSize(0.055);

  cv2->cd(5);
  cv2->GetPad(5)->SetGridx(1);
  cv2->GetPad(5)->SetGridy(1);
  hHE_d5->Draw("colz");
  hHE_d5->SetContour(100);
  hHE_d5->GetXaxis()->SetTitle("ieta");
  hHE_d5->GetYaxis()->SetTitle("iphi");
  hHE_d5->GetXaxis()->CenterTitle();
  hHE_d5->GetYaxis()->CenterTitle();
  hHE_d5->GetZaxis()->SetRangeUser(r3_a, r3_b);
  hHE_d5->GetYaxis()->SetTitleSize(0.06);
  hHE_d5->GetYaxis()->SetTitleOffset(0.80);
  hHE_d5->GetXaxis()->SetTitleSize(0.06);
  hHE_d5->GetXaxis()->SetTitleOffset(0.80);
  hHE_d5->GetYaxis()->SetLabelSize(0.055);
  hHE_d5->GetXaxis()->SetLabelSize(0.055);

  cv2->cd(6);
  cv2->GetPad(6)->SetGridx(1);
  cv2->GetPad(6)->SetGridy(1);
  hHE_d6->Draw("colz");
  hHE_d6->SetContour(100);
  hHE_d6->GetXaxis()->SetTitle("ieta");
  hHE_d6->GetYaxis()->SetTitle("iphi");
  hHE_d6->GetXaxis()->CenterTitle();
  hHE_d6->GetYaxis()->CenterTitle();
  hHE_d6->GetZaxis()->SetRangeUser(r3_a, r3_b);
  hHE_d6->GetYaxis()->SetTitleSize(0.06);
  hHE_d6->GetYaxis()->SetTitleOffset(0.80);
  hHE_d6->GetXaxis()->SetTitleSize(0.06);
  hHE_d6->GetXaxis()->SetTitleOffset(0.80);
  hHE_d6->GetYaxis()->SetLabelSize(0.055);
  hHE_d6->GetXaxis()->SetLabelSize(0.055);

  cv2->cd(7);
  cv2->GetPad(7)->SetGridx(1);
  cv2->GetPad(7)->SetGridy(1);
  hHE_d7->Draw("colz");
  hHE_d7->SetContour(100);
  hHE_d7->GetXaxis()->SetTitle("ieta");
  hHE_d7->GetYaxis()->SetTitle("iphi");
  hHE_d7->GetXaxis()->CenterTitle();
  hHE_d7->GetYaxis()->CenterTitle();
  hHE_d7->GetZaxis()->SetRangeUser(r3_a, r3_b);
  hHE_d7->GetYaxis()->SetTitleSize(0.06);
  hHE_d7->GetYaxis()->SetTitleOffset(0.80);
  hHE_d7->GetXaxis()->SetTitleSize(0.06);
  hHE_d7->GetXaxis()->SetTitleOffset(0.80);
  hHE_d7->GetYaxis()->SetLabelSize(0.055);
  hHE_d7->GetXaxis()->SetLabelSize(0.055);

  TLegend *legend2 = new TLegend(0.30, 0.40, 0.65, 0.72);
  legend2->SetTextSize(0.055);
  legend2->SetTextFont(42);
  legend2->AddEntry(hStatus[0], "healthy", "p");
  legend2->AddEntry(hStatus[2], "unmasked", "p");
  legend2->AddEntry(hStatus[1], "newly bad", "p");
  legend2->AddEntry(hStatus[3], "long dead", "p");
  legend2->SetFillColor(kWhite);
  legend2->SetLineColor(kWhite);
  legend2->Draw();


  TCanvas *cv3 = new TCanvas("cv3", "HF", 1000, 1000);
  cv3->Divide(2, 2);

  cv3->cd(1);
  cv3->GetPad(1)->SetGridx(1);
  cv3->GetPad(1)->SetGridy(1);
  hHF_d1->Draw("colz");
  hHF_d1->SetContour(100);
  hHF_d1->GetXaxis()->SetTitle("ieta");
  hHF_d1->GetYaxis()->SetTitle("iphi");
  hHF_d1->GetXaxis()->CenterTitle();
  hHF_d1->GetYaxis()->CenterTitle();
  hHF_d1->GetZaxis()->SetRangeUser(r2_a, r2_b);
  hHF_d1->GetYaxis()->SetTitleSize(0.06);
  hHF_d1->GetYaxis()->SetTitleOffset(0.80);
  hHF_d1->GetXaxis()->SetTitleSize(0.06);
  hHF_d1->GetXaxis()->SetTitleOffset(0.80);
  hHF_d1->GetYaxis()->SetLabelSize(0.055);
  hHF_d1->GetXaxis()->SetLabelSize(0.055);

  TLegend *legend3 = new TLegend(0.30, 0.50, 0.7, 0.72);
  legend3->SetTextSize(0.05);
  legend3->SetTextFont(42);
  legend3->AddEntry(hStatus[0], "healthy", "p");
  legend3->AddEntry(hStatus[2], "unmasked", "p");
  legend3->AddEntry(hStatus[1], "newly bad", "p");
  legend3->AddEntry(hStatus[3], "long dead", "p");
  legend3->SetFillColor(kWhite);
  legend3->SetLineColor(kWhite);
  legend3->Draw();

  cv3->cd(2);
  cv3->GetPad(2)->SetGridx(1);
  cv3->GetPad(2)->SetGridy(1);
  hHF_d2->Draw("colz");
  hHF_d2->GetXaxis()->SetTitle("ieta");
  hHF_d2->GetYaxis()->SetTitle("iphi");
  hHF_d2->GetXaxis()->CenterTitle();
  hHF_d2->GetYaxis()->CenterTitle();
  hHF_d2->GetZaxis()->SetRangeUser(r2_a, r2_b);
  hHF_d2->GetYaxis()->SetTitleSize(0.06);
  hHF_d2->GetYaxis()->SetTitleOffset(0.80);
  hHF_d2->GetXaxis()->SetTitleSize(0.06);
  hHF_d2->GetXaxis()->SetTitleOffset(0.80);
  hHF_d2->GetYaxis()->SetLabelSize(0.055);
  hHF_d2->GetXaxis()->SetLabelSize(0.055);
  hHF_d2->SetContour(100);

  cv3->cd(3);
  cv3->GetPad(3)->SetGridx(1);
  cv3->GetPad(3)->SetGridy(1);
  hHF_d3->Draw("colz");
  hHF_d3->SetContour(100);
  hHF_d3->GetXaxis()->SetTitle("ieta");
  hHF_d3->GetYaxis()->SetTitle("iphi");
  hHF_d3->GetXaxis()->CenterTitle();
  hHF_d3->GetYaxis()->CenterTitle();
  hHF_d3->GetZaxis()->SetRangeUser(r2_a, r2_b);
  hHF_d3->GetYaxis()->SetTitleSize(0.06);
  hHF_d3->GetYaxis()->SetTitleOffset(0.80);
  hHF_d3->GetXaxis()->SetTitleSize(0.06);
  hHF_d3->GetXaxis()->SetTitleOffset(0.80);
  hHF_d3->GetYaxis()->SetLabelSize(0.055);
  hHF_d3->GetXaxis()->SetLabelSize(0.055);

  cv3->cd(4);
  cv3->GetPad(4)->SetGridx(1);
  cv3->GetPad(4)->SetGridy(1);
  hHF_d4->Draw("colz");
  hHF_d4->GetXaxis()->SetTitle("ieta");
  hHF_d4->GetYaxis()->SetTitle("iphi");
  hHF_d4->GetXaxis()->CenterTitle();
  hHF_d4->GetYaxis()->CenterTitle();
  hHF_d4->GetZaxis()->SetRangeUser(r2_a, r2_b);
  hHF_d4->GetYaxis()->SetTitleSize(0.06);
  hHF_d4->GetYaxis()->SetTitleOffset(0.80);
  hHF_d4->GetXaxis()->SetTitleSize(0.06);
  hHF_d4->GetXaxis()->SetTitleOffset(0.80);
  hHF_d4->GetYaxis()->SetLabelSize(0.055);
  hHF_d4->GetXaxis()->SetLabelSize(0.055);
  hHF_d4->SetContour(100);

  
  //preparing list of  list of outliers
  cout << endl << endl;
  cout<<  "outliers:  "<<endl;
  cout << "eta   phi  depth  subDet   differnce" << endl;
  for (int i = 1; i <= 83; i++) {
	  for (int k = 1; k <= 72; k++) {
		  if (fabs(hHB_d1->GetBinContent(i, k)) > outR && hHB_d1->GetBinContent(i, k) != -999) cout << i  -42 << "    " << k << "     " << 1 << "     HB     " << (int) hHB_d1->GetBinContent(i, k) << endl;
		  if (fabs(hHB_d2->GetBinContent(i, k)) > outR && hHB_d2->GetBinContent(i, k) != -999) cout << i - 42 << "    " << k << "     " << 1 << "     HB     " << (int) hHB_d2->GetBinContent(i, k) << endl;
		  if (fabs(hHO_d1->GetBinContent(i, k)) > outR && hHO_d1->GetBinContent(i, k) != -999) cout << i - 42 << "    " << k << "     " << 4 << "     HO     " << (int) hHO_d1->GetBinContent(i, k) << endl;
		  if (fabs(hHE_d1->GetBinContent(i, k)) > outR && hHE_d1->GetBinContent(i, k) != -999) cout << i  -42 << "    " << k << "     " << 1 << "     HE     " << (int)hHE_d1->GetBinContent(i, k) << endl;
		  if (fabs(hHE_d2->GetBinContent(i, k)) > outR && hHE_d2->GetBinContent(i, k) != -999) cout << i - 42 << "    " << k << "     " << 2 << "     HE     " << (int)hHE_d2->GetBinContent(i, k) << endl;
		  if (fabs(hHE_d3->GetBinContent(i, k)) > outR && hHE_d3->GetBinContent(i, k) != -999) cout << i - 42 << "    " << k << "     " << 3 << "     HE     " << (int)hHE_d3->GetBinContent(i, k) << endl;
		  if (fabs(hHE_d4->GetBinContent(i, k)) > outR && hHE_d4->GetBinContent(i, k) != -999) cout << i - 42 << "    " << k << "     " << 4 << "     HE     " << (int)hHE_d4->GetBinContent(i, k) << endl;
		  if (fabs(hHE_d5->GetBinContent(i, k)) > outR && hHE_d5->GetBinContent(i, k) != -999) cout << i - 42 << "    " << k << "     " << 5 << "     HE     " << (int)hHE_d5->GetBinContent(i, k) << endl;
		  if (fabs(hHE_d6->GetBinContent(i, k)) > outR && hHE_d6->GetBinContent(i, k) != -999) cout << i - 42 << "    " << k << "     " << 6 << "     HE     " << (int)hHE_d6->GetBinContent(i, k) << endl;
		  if (fabs(hHE_d7->GetBinContent(i, k)) > outR && hHE_d7->GetBinContent(i, k) != -999) cout << i - 42 << "    " << k << "     " << 7 << "     HE     " << (int)hHE_d7->GetBinContent(i, k) << endl;
		  if (fabs(hHF_d1->GetBinContent(i, k)) > outR && hHF_d1->GetBinContent(i, k) != -999) cout << i - 42 << "    " << k << "     " << 1 << "     HF     " << (int)hHF_d1->GetBinContent(i, k) << endl;
		  if (fabs(hHF_d2->GetBinContent(i, k)) > outR && hHF_d2->GetBinContent(i, k) != -999) cout << i - 42 << "    " << k << "     " << 2 << "     HF     " << (int)hHF_d2->GetBinContent(i, k) << endl;
		  if (fabs(hHF_d3->GetBinContent(i, k)) > outR && hHF_d3->GetBinContent(i, k) != -999) cout << i - 42 << "    " << k << "     " << 3 << "     HF     " << (int)hHF_d3->GetBinContent(i, k) << endl;
		  if (fabs(hHF_d4->GetBinContent(i, k)) > outR && hHF_d4->GetBinContent(i, k) != -999) cout << i - 42 << "    " << k << "     " << 4 << "     HF     " << (int)hHF_d4->GetBinContent(i, k) << endl;
	 //checking unmasked channels and marking  the in kSpring+10;
     // channel that are dead in both conditions are marked with value -0.99 
		  
		  if (hHB_d1->GetBinContent(i, k) < -0.999 && hHB_d1->GetBinContent(i, k) != -999) hHB_d1->SetBinContent(i, k, 0.5);
		  if (hHB_d2->GetBinContent(i, k) < -0.999 && hHB_d2->GetBinContent(i, k) != -999) hHB_d2->SetBinContent(i, k, 0.5);
		  if (hHO_d1->GetBinContent(i, k) < -0.999 && hHO_d1->GetBinContent(i, k) != -999) hHO_d1->SetBinContent(i, k, 0.5);
		  if (hHE_d1->GetBinContent(i, k) < -0.999 && hHE_d1->GetBinContent(i, k) != -999) hHE_d1->SetBinContent(i, k, 0.5);
		  if (hHE_d2->GetBinContent(i, k) < -0.999 && hHE_d2->GetBinContent(i, k) != -999) hHE_d2->SetBinContent(i, k, 0.5);
		  if (hHE_d3->GetBinContent(i, k) < -0.999 && hHE_d3->GetBinContent(i, k) != -999) hHE_d3->SetBinContent(i, k, 0.5);
		  if (hHE_d4->GetBinContent(i, k) < -0.999 && hHE_d4->GetBinContent(i, k) != -999) hHE_d4->SetBinContent(i, k, 0.5);
		  if (hHE_d5->GetBinContent(i, k) < -0.999 && hHE_d5->GetBinContent(i, k) != -999) hHE_d5->SetBinContent(i, k, 0.5);
		  if (hHE_d6->GetBinContent(i, k) < -0.999 && hHE_d6->GetBinContent(i, k) != -999) hHE_d6->SetBinContent(i, k, 0.5);
		  if (hHE_d7->GetBinContent(i, k) < -0.999 && hHE_d7->GetBinContent(i, k) != -999) hHE_d7->SetBinContent(i, k, 0.5);
		  if (hHF_d1->GetBinContent(i, k) < -0.999 && hHF_d1->GetBinContent(i, k) != -999) hHF_d1->SetBinContent(i, k, 0.5);
		  if (hHF_d2->GetBinContent(i, k) < -0.999 && hHF_d2->GetBinContent(i, k) != -999) hHF_d2->SetBinContent(i, k, 0.5);
		  if (hHF_d3->GetBinContent(i, k) < -0.999 && hHF_d3->GetBinContent(i, k) != -999) hHF_d3->SetBinContent(i, k, 0.5);
		  if (hHF_d4->GetBinContent(i, k) < -0.999 && hHF_d4->GetBinContent(i, k) != -999) hHF_d4->SetBinContent(i, k, 0.5);  
	  }
  }

}
