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

void compare(){

	const char* file0 = "HcalPedestalWidths_ADC_2017plan1_v3.0_data_IOV2.txt"; //new
	const char* file1 = "HcalPedestalWidths_ADC_2017plan1_v3.0_data_IOV1.txt"; //prev
    
    //here you can change z-ranges for different
	float mr = 0.5; // z-range amplitude
	float r_a = 1 - 1 * mr, r_b = 1 + 1 * mr;//hb
	float r3_a = 1 - 1 * mr, r3_b = 1 + 1 * mr;//he
	float r4_a = 1 - 1 * mr, r4_b = 1 + 1 * mr;//ho
	float r2_a = 1 - 1 * mr, r2_b = 1 + 1 * mr;//hf

	float outR = 0.2;  // z-range amplitude for oputliers
	float  OUTLdown = 1 - outR, OUTLup = 1 + outR;

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
  TH2F *hHF_d3 = new TH2F("HF_d3", "          HF_d3", 83, -42, 42, 71, 1, 72);
  TH2F *hHF_d4 = new TH2F("HF_d4", "          HF_d4", 83, -42, 42, 71, 1, 72);


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
  TH2F *hHF_d3b = new TH2F("HF_d3b", "          HF_d3", 83, -42, 42, 71, 1, 72);
  TH2F *hHF_d4b = new TH2F("HF_d4b", "          HF_d4", 83, -42, 42, 71, 1, 72);
    
    
  int ieta2,iphi2,depth2, ieta0,iphi0,depth0;
  float cov[4][4], covb[4][4];
  char comment[500], SubDet1[160], SubDet2[160], DetID1[160], DetID2[160];
  
  fgets(comment,500,ft0);
  fgets(comment,500,ft0);

  for (int j=0; j<99999; j++) {
    if (feof(ft0)!=0) break;
     fscanf(ft0,"%d%d%d%s%f%f%f%f",&ieta0,&iphi0,&depth0, SubDet1, &cov[0][0], &cov[0][1], &cov[0][2], &cov[0][3]);
                                             fscanf(ft0, "%f%f%f%f\n", &cov[1][0], &cov[1][1], &cov[1][2], &cov[1][3]);
										     fscanf(ft0, "%f%f%f%f\n", &cov[2][0], &cov[2][1], &cov[2][2], &cov[2][3]);
										   fscanf(ft0, "%f%f%f%f%s\n", &cov[3][0], &cov[3][1], &cov[3][2], &cov[3][3], DetID1);
   
      float av_peda = (cov[0][0] + cov[1][1] + cov[2][2] + cov[3][3]) /4 ;

	  if (SubDet1[1] == 'B') {
		  if (depth0 == 1) hHB_d1->Fill(ieta0, iphi0, av_peda);
		  if (depth0 == 2) hHB_d2->Fill(ieta0, iphi0, av_peda);
	  }
	  if (SubDet1[1] == 'O') {
		  if (depth0>0)hHO_d1->Fill(ieta0, iphi0, av_peda);
	  }
	 
	  if (SubDet1[1] == 'E') {
		  if (depth0 == 1)hHE_d1->Fill(ieta0, iphi0, av_peda);
		  if (depth0 == 2)hHE_d2->Fill(ieta0, iphi0, av_peda);
		  if (depth0 == 3)hHE_d3->Fill(ieta0, iphi0, av_peda);
		  if (depth0 == 4)hHE_d4->Fill(ieta0, iphi0, av_peda);
		  if (depth0 == 5)hHE_d5->Fill(ieta0, iphi0, av_peda);
		  if (depth0 == 6)hHE_d6->Fill(ieta0, iphi0, av_peda);
		  if (depth0 == 7)hHE_d7->Fill(ieta0, iphi0, av_peda);
	  }
	  if (SubDet1[1] == 'F') {
		  if (depth0 == 1)hHF_d1->Fill(ieta0, iphi0, av_peda);
		  if (depth0 == 2)hHF_d2->Fill(ieta0, iphi0, av_peda);
		  if (depth0 == 3)hHF_d3->Fill(ieta0, iphi0, av_peda);
		  if (depth0 == 4)hHF_d4->Fill(ieta0, iphi0, av_peda);
	  }
  }

  fgets(comment, 500, ft1);
  fgets(comment, 500, ft1);

  for (int k = 0; k<99999; k++) {
	  if (feof(ft1) != 0) break;

	  fscanf(ft1,"%d%d%d%s %f%f%f%f",&ieta2,&iphi2,&depth2, SubDet2,  &covb[0][0], &covb[0][1], &covb[0][2], &covb[0][3]);
                                             fscanf(ft1, "%f%f%f%f\n", &covb[1][0], &covb[1][1], &covb[1][2], &covb[1][3]);
										     fscanf(ft1, "%f%f%f%f\n", &covb[2][0], &covb[2][1], &covb[2][2], &covb[2][3]);
										   fscanf(ft1, "%f%f%f%f%s\n", &covb[3][0], &covb[3][1], &covb[3][2], &covb[3][3], DetID2);

	  float av_pedb = (covb[0][0] + covb[1][1] + covb[2][2] + covb[3][3]) / 4;

	  if (SubDet2[1] == 'B') {
		  if (depth2 == 1) hHB_d1b->Fill(ieta2, iphi2, av_pedb);
		  if (depth2 == 2) hHB_d2b->Fill(ieta2, iphi2, av_pedb);
	  }
	  if (SubDet2[1] == 'O') {
		  if (depth2>0)hHO_d1b->Fill(ieta2, iphi2, av_pedb);
	  }

	  if (SubDet2[1] == 'E') {
		  if (depth2 == 1)hHE_d1b->Fill(ieta2, iphi2, av_pedb);
		  if (depth2 == 2)hHE_d2b->Fill(ieta2, iphi2, av_pedb);
		  if (depth2 == 3)hHE_d3b->Fill(ieta2, iphi2, av_pedb);
		  if (depth2 == 4)hHE_d4b->Fill(ieta2, iphi2, av_pedb);
		  if (depth2 == 5)hHE_d5b->Fill(ieta2, iphi2, av_pedb);
		  if (depth2 == 6)hHE_d6b->Fill(ieta2, iphi2, av_pedb);
		  if (depth2 == 7)hHE_d7b->Fill(ieta2, iphi2, av_pedb);
	  }
	  if (SubDet2[1] == 'F') {
		  if (depth2 == 1)hHF_d1b->Fill(ieta2, iphi2, av_pedb);
		  if (depth2 == 2)hHF_d2b->Fill(ieta2, iphi2, av_pedb);
		  if (depth2 == 3)hHF_d3b->Fill(ieta2, iphi2, av_pedb);
		  if (depth2 == 4)hHF_d4b->Fill(ieta2, iphi2, av_pedb);
	  }

  }
  
  hHB_d1->Divide(hHB_d1, hHB_d1b);
  hHB_d2->Divide(hHB_d2, hHB_d2b);

  hHO_d1->Divide(hHO_d1, hHO_d1b);

  hHE_d1->Divide(hHE_d1, hHE_d1b);
  hHE_d2->Divide(hHE_d2, hHE_d2b);
  hHE_d3->Divide(hHE_d3, hHE_d3b);
  hHE_d4->Divide(hHE_d4, hHE_d4b);
  hHE_d5->Divide(hHE_d5, hHE_d5b);
  hHE_d6->Divide(hHE_d6, hHE_d6b);
  hHE_d7->Divide(hHE_d7, hHE_d7b);

  hHF_d1->Divide(hHF_d1, hHF_d1b);
  hHF_d2->Divide(hHF_d2, hHF_d2b);
  hHF_d3->Divide(hHF_d3, hHF_d3b);
  hHF_d4->Divide(hHF_d4, hHF_d4b);


  for (int i = 1; i <= 83; i++) {
	  for (int k = 1; k <= 72; k++) {
		  if(hHB_d1->GetBinContent(i, k) == 0) hHB_d1->SetBinContent(i, k, -999);
		  if(hHB_d2->GetBinContent(i, k) == 0) hHB_d2->SetBinContent(i, k, -999);
		  if(hHO_d1->GetBinContent(i, k) == 0) hHO_d1->SetBinContent(i, k, -999);

		  if(hHE_d1->GetBinContent(i, k) == 0)hHE_d1->SetBinContent(i, k, -999);
		  if(hHE_d2->GetBinContent(i, k) == 0)hHE_d2->SetBinContent(i, k, -999);
		  if(hHE_d3->GetBinContent(i, k) == 0)hHE_d3->SetBinContent(i, k, -999);
		  if(hHE_d4->GetBinContent(i, k) == 0)hHE_d4->SetBinContent(i, k, -999);
		  if(hHE_d5->GetBinContent(i, k) == 0)hHE_d5->SetBinContent(i, k, -999);
		  if(hHE_d6->GetBinContent(i, k) == 0)hHE_d6->SetBinContent(i, k, -999);
		  if(hHE_d7->GetBinContent(i, k) == 0)hHE_d7->SetBinContent(i, k, -999);

		  if(hHF_d1->GetBinContent(i, k) == 0)hHF_d1->SetBinContent(i, k, -999);
		  if(hHF_d2->GetBinContent(i, k) == 0)hHF_d2->SetBinContent(i, k, -999);
		  if(hHF_d3->GetBinContent(i, k) == 0)hHF_d3->SetBinContent(i, k, -999);
		  if(hHF_d4->GetBinContent(i, k) == 0)hHF_d4->SetBinContent(i, k, -999);
	  }
  }
  
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
  hHO_d1->GetZaxis()->SetRangeUser(r4_a, r4_b);
  hHO_d1->GetYaxis()->SetTitleSize(0.06);
  hHO_d1->GetYaxis()->SetTitleOffset(0.80);
  hHO_d1->GetXaxis()->SetTitleSize(0.06);
  hHO_d1->GetXaxis()->SetTitleOffset(0.80);
  hHO_d1->GetYaxis()->SetLabelSize(0.055);
  hHO_d1->GetXaxis()->SetLabelSize(0.055);


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
  cout << "outliers:  " << endl;
  cout << "eta   phi  depth  subDet   ratio" << endl;
  for (int i = 1; i <= 83; i++) {
	  for (int k = 1; k <= 72; k++) {
		  if ((hHB_d1->GetBinContent(i, k) < OUTLdown || (hHB_d1->GetBinContent(i, k)) > OUTLup) && hHB_d1->GetBinContent(i, k) != -999) cout << i - 42 << "    " << k << "     " << 1 << "     HB     " << hHB_d1->GetBinContent(i, k) << endl;
		  if ((hHB_d2->GetBinContent(i, k) < OUTLdown || (hHB_d2->GetBinContent(i, k)) > OUTLup) && hHB_d2->GetBinContent(i, k) != -999) cout << i - 42 << "    " << k << "     " << 1 << "     HB     " << hHB_d2->GetBinContent(i, k) << endl;
	  }
  }

  for (int i = 1; i <= 83; i++) {
	  for (int k = 1; k <= 72; k++) {
		  if ((hHO_d1->GetBinContent(i, k) < OUTLdown || (hHO_d1->GetBinContent(i, k)) > OUTLup) && hHO_d1->GetBinContent(i, k) != -999) cout << i - 42 << "    " << k << "     " << 4 << "     HO     " << hHO_d1->GetBinContent(i, k) << endl;
	  }
  }

  for (int i = 1; i <= 83; i++) {
	  for (int k = 1; k <= 72; k++) {
		  if ((hHE_d1->GetBinContent(i, k) < OUTLdown || (hHE_d1->GetBinContent(i, k)) > OUTLup) && hHE_d1->GetBinContent(i, k) != -999) cout << i - 42 << "    " << k << "     " << 1 << "     HE     " << hHE_d1->GetBinContent(i, k) << endl;
		  if ((hHE_d2->GetBinContent(i, k) < OUTLdown || (hHE_d2->GetBinContent(i, k)) > OUTLup) && hHE_d2->GetBinContent(i, k) != -999) cout << i - 42 << "    " << k << "     " << 2 << "     HE     " << hHE_d2->GetBinContent(i, k) << endl;
		  if ((hHE_d3->GetBinContent(i, k) < OUTLdown || (hHE_d3->GetBinContent(i, k)) > OUTLup) && hHE_d3->GetBinContent(i, k) != -999) cout << i - 42 << "    " << k << "     " << 3 << "     HE     " << hHE_d3->GetBinContent(i, k) << endl;
		  if ((hHE_d4->GetBinContent(i, k) < OUTLdown || (hHE_d4->GetBinContent(i, k)) > OUTLup) && hHE_d4->GetBinContent(i, k) != -999) cout << i - 42 << "    " << k << "     " << 4 << "     HE     " << hHE_d4->GetBinContent(i, k) << endl;
		  if ((hHE_d5->GetBinContent(i, k) < OUTLdown || (hHE_d5->GetBinContent(i, k)) > OUTLup) && hHE_d5->GetBinContent(i, k) != -999) cout << i - 42 << "    " << k << "     " << 5 << "     HE     " << hHE_d5->GetBinContent(i, k) << endl;
		  if ((hHE_d6->GetBinContent(i, k) < OUTLdown || (hHE_d6->GetBinContent(i, k)) > OUTLup) && hHE_d6->GetBinContent(i, k) != -999) cout << i - 42 << "    " << k << "     " << 6 << "     HE     " << hHE_d6->GetBinContent(i, k) << endl;
		  if ((hHE_d7->GetBinContent(i, k) < OUTLdown || (hHE_d7->GetBinContent(i, k)) > OUTLup) && hHE_d7->GetBinContent(i, k) != -999) cout << i - 42 << "    " << k << "     " << 7 << "     HE     " << hHE_d7->GetBinContent(i, k) << endl;
	  }
  }

  for (int i = 1; i <= 83; i++) {
	  for (int k = 1; k <= 72; k++) {
		  if ((hHF_d1->GetBinContent(i, k) < OUTLdown || (hHF_d1->GetBinContent(i, k)) > OUTLup) && hHF_d1->GetBinContent(i, k) != -999) cout << i - 42 << "    " << k << "     " << 1 << "     HF     " << hHF_d1->GetBinContent(i, k) << endl;
		  if ((hHF_d2->GetBinContent(i, k) < OUTLdown || (hHF_d2->GetBinContent(i, k)) > OUTLup) && hHF_d2->GetBinContent(i, k) != -999) cout << i - 42 << "    " << k << "     " << 2 << "     HF     " << hHF_d2->GetBinContent(i, k) << endl;
		  if ((hHF_d3->GetBinContent(i, k) < OUTLdown || (hHF_d3->GetBinContent(i, k)) > OUTLup) && hHF_d3->GetBinContent(i, k) != -999) cout << i - 42 << "    " << k << "     " << 3 << "     HF     " << hHF_d3->GetBinContent(i, k) << endl;
		  if ((hHF_d4->GetBinContent(i, k) < OUTLdown || (hHF_d4->GetBinContent(i, k)) > OUTLup) && hHF_d4->GetBinContent(i, k) != -999) cout << i - 42 << "    " << k << "     " << 4 << "     HF     " << hHF_d4->GetBinContent(i, k) << endl;
	  }
  }

}
