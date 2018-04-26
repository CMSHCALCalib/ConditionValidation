#include <vector>
#include <exception>
#include "TStyle.h"
#include "TFile.h"
#include "TMath.h"
#include "TF1.h"
#include "TH1.h"
#include "TH1F.h"
#include "TH2F.h"
#include "TCanvas.h"
#include "TLatex.h"
#include "TColor.h"
#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <iostream.h>


void compare() {


	//char* file0 = "Dump_L1TriggerObjects_Physics2017v0.txt"; //prew
	//char* file1 = "Gen_L1TriggerObjects_Physics2017v1Fix.txt"; //new


	char* file0 = "Dump_L1TriggerObjects_testPhysics2017v0try09a.txt"; //prew
	char* file1 = "Dump_L1TriggerObjects_Physics2017v0.txt"; //new
	


//char* file0 = "HCAL_Tables/2017Febsum/Gains_x_Resp_18.txt"; //new
//char* file1 = "HCAL_Tables/201623Sept/Gains_x_Resp_10.txt"; //prev


	char* plotname = "nothing.pdf"; //prev

    //gStyle->SetOptTitle(0);
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
    gStyle->SetPadRightMargin(0.16);
    gStyle->SetPadLeftMargin(0.16);
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

  int ieta1,iphi1,depth1,ieta0,iphi0,depth0;
  float c1, c0;
  float ped0, respxgains0, ped1, respxgains1;
  int status0, status1;
               
  float r_pm = 0.2;
  float r_a, r_b;//!!! these variables are lower and upper limits of Z-axis for ratio plots
  float r2_a, r2_b;
  float r3_a, r3_b;
  r_a = 1 - r_pm;  r_b = 1 + r_pm;
  r2_a = 1 - 1.0*r_pm;  r2_b = 1 + 1.0*r_pm; //hf
  r3_a = 1 - 1.0*r_pm;  r3_b = 1 + 1.0*r_pm; //he

  char stroka[500], SudDet0[160], DetId0[160], SudDet1[160], DetId1[160];
  fgets(stroka,500,ft0);
  fgets(stroka,500,ft1);

  fgets(stroka, 500, ft0);
  fgets(stroka, 500, ft1);

  fgets(stroka, 500, ft0);
  fgets(stroka, 500, ft1);
  /* 
  TH2F *hHB_d1 = new TH2F("HB_d1", "          HB_d1", 83, -42, 42, 71, 1, 72);
  TH2F *hHB_d2 = new TH2F("HB_d2", "          HB_d2", 83, -42, 42, 71, 1, 72);
  TH2F *hHO_d1 = new TH2F("HO_d4", "          HO_d4", 83, -42, 42, 71, 1, 72);
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
*/

 // TH2F *hHB_d1 = new TH2F("HB_d1", "          HB_d1", 83, -42, 42);
 // TH2F *hHB_d2 = new TH2F("HB_d2", "          HB_d2", 83, -42, 42);
 // TH2F *hHO_d1 = new TH2F("HO_d4", "          HO_d4", 83, -42, 42);

  TH1F *hHE_d1 = new TH1F("HE_d1", "          HE_d1", 83, -42, 42);
  TH1F *hHE_d2 = new TH1F("HE_d2", "          HE_d2", 83, -42, 42);
  TH1F *hHE_d3 = new TH1F("HE_d3", "          HE_d3", 83, -42, 42);
  TH1F *hHE_d4 = new TH1F("HE_d4", "          HE_d4", 83, -42, 42);
  TH1F *hHE_d5 = new TH1F("HE_d5", "          HE_d5", 83, -42, 42);
  TH1F *hHE_d6 = new TH1F("HE_d6", "          HE_d6", 83, -42, 42);
  TH1F *hHE_d7 = new TH1F("HE_d7", "          HE_d7", 83, -42, 42);

  TH1F *hHF_d1 = new TH1F("HF_d1u", "          HF_d1", 83, -42, 42);
  TH1F *hHF_d2 = new TH1F("HF_d2u", "          HF_d2", 83, -42, 42);
  TH1F *hHF_d3 = new TH1F("HF_d3u", "         HF_d3", 83, -42, 42);
  TH1F *hHF_d4 = new TH1F("HF_d4u", "         HF_d4", 83, -42, 42);


    
  TH1F *hHE_d1u = new TH1F("HE_d1u", "          HE_d1", 83, -42, 42);
  TH1F *hHE_d2u = new TH1F("HE_d2u", "          HE_d2", 83, -42, 42);
  TH1F *hHE_d3u = new TH1F("HE_d3u", "          HE_d3", 83, -42, 42);
  TH1F *hHE_d4u = new TH1F("HE_d4u", "          HE_d4", 83, -42, 42);
  TH1F *hHE_d5u = new TH1F("HE_d5u", "          HE_d5", 83, -42, 42);
  TH1F *hHE_d6u = new TH1F("HE_d6u", "          HE_d6", 83, -42, 42);
  TH1F *hHE_d7u = new TH1F("HE_d7u", "          HE_d7", 83, -42, 42);

  TH1F *hHF_d1u = new TH1F("HF_d1u", "          HF_d1", 83, -42, 42);
  TH1F *hHF_d2u = new TH1F("HF_d2u", "          HF_d2", 83, -42, 42);
  TH1F *hHF_d3u = new TH1F("HF_d3u", "         HF_d3", 83, -42, 42);
  TH1F *hHF_d4u = new TH1F("HF_d4u", "         HF_d4", 83, -42, 42);


  for (int j=0; j<99999; j++) {       
    if (feof(ft0)!=0) break;
    fscanf(ft0, "%d%d%d%s%f%f%d%s\r", &ieta0, &iphi0 ,&depth0, &SudDet0, &ped0, &respxgains0, &status0, &DetId0);
	fscanf(ft1, "%d%d%d%s%f%f%d%s\r", &ieta1, &iphi1, &depth1, &SudDet1, &ped1, &respxgains1, &status1, &DetId1);
    printf ("%5d %5d %5d %6s %9.7f %9.7f %6d %10s\r", &ieta0, &iphi0, &depth0, &SudDet0, &ped0, &respxgains0, &status0, &DetId0);
    // printf ("%7d%7d%7d%7s%9.5f%12s\n",&ieta0,&iphi0,&depth0,&fileword1,&c0,&fileword2);
	cout << respxgains0 << "  " << respxgains1 << endl;
      float ratio = respxgains1 / respxgains0;

      /*
      if(SudDet0[1]=='\B'){
          if(depth0==1) hHB_d1->Fill(ieta0,iphi0, ratio);
          if(depth0>1)hHB_d2->Fill(ieta0,iphi0, ratio);
      }
      if(SudDet0[1]=='\O'){
          if(depth0>0)hHO_d1->Fill(ieta0,iphi0, ratio);
      }
	  */

      if(SudDet0[1]=='\E'){
		  if (depth0 == 1) { hHE_d1->Fill(ieta0, ratio); hHE_d1u->Fill(ieta0, 1); }
		  if (depth0 == 2) { hHE_d2->Fill(ieta0, ratio); hHE_d2u->Fill(ieta0, 1); }
		  if (depth0 == 3) { hHE_d3->Fill(ieta0, ratio); hHE_d3u->Fill(ieta0, 1); }
		  if (depth0 == 4) { hHE_d4->Fill(ieta0, ratio); hHE_d4u->Fill(ieta0, 1); }
		  if (depth0 == 5) { hHE_d5->Fill(ieta0, ratio); hHE_d5u->Fill(ieta0, 1); }
		  if (depth0 == 6) { hHE_d6->Fill(ieta0, ratio); hHE_d6u->Fill(ieta0, 1); }
		  if (depth0 == 7) { hHE_d7->Fill(ieta0, ratio); hHE_d7u->Fill(ieta0, 1); }
      }
      if(SudDet0[1]=='\F'){
		  if (depth0 == 1) { hHF_d1->Fill(ieta0, ratio); hHF_d1u->Fill(ieta0, 1); }
		  if (depth0 == 2) { hHF_d2->Fill(ieta0, ratio); hHF_d2u->Fill(ieta0, 1); }
		  if (depth0 == 3) { hHF_d3->Fill(ieta0, ratio); hHF_d3u->Fill(ieta0, 1); }
		  if (depth0 == 4) { hHF_d4->Fill(ieta0, ratio); hHF_d4u->Fill(ieta0, 1); }
      }
  }
  
  hHE_d1->Divide(hHE_d1, hHE_d1u);
  hHE_d2->Divide(hHE_d2, hHE_d2u);
  hHE_d3->Divide(hHE_d3, hHE_d3u);
  hHE_d4->Divide(hHE_d4, hHE_d4u);
  hHE_d5->Divide(hHE_d5, hHE_d5u);
  hHE_d6->Divide(hHE_d6, hHE_d6u);
  hHE_d7->Divide(hHE_d7, hHE_d7u);

  hHF_d1->Divide(hHF_d1, hHF_d1u);
  hHF_d2->Divide(hHF_d2, hHF_d2u);
  hHF_d3->Divide(hHF_d3, hHF_d3u);
  hHF_d4->Divide(hHF_d4, hHF_d4u);

 
 /*
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
	hHB_d1->GetYaxis()->SetRangeUser(r_a, r_b );
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
	hHB_d2->GetYaxis()->SetRangeUser(r_a , r_b );
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
	hHO_d1->GetYaxis()->SetRangeUser(0.95, 1.05);
	hHO_d1->GetYaxis()->SetTitleSize(0.06);
	hHO_d1->GetYaxis()->SetTitleOffset(0.80);
	hHO_d1->GetXaxis()->SetTitleSize(0.06);
	hHO_d1->GetXaxis()->SetTitleOffset(0.80);
	hHO_d1->GetYaxis()->SetLabelSize(0.055);
	hHO_d1->GetXaxis()->SetLabelSize(0.055);

	*/
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
	hHE_d1->GetYaxis()->SetRangeUser(r3_a, r3_b);
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
	hHE_d2->GetYaxis()->SetRangeUser(r3_a, r3_b);
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
	hHE_d3->GetYaxis()->SetRangeUser(r3_a , r3_b );
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
	hHE_d4->GetYaxis()->SetRangeUser(r3_a, r3_b);
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
	hHE_d5->GetYaxis()->SetRangeUser(r3_a, r3_b);
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
	hHE_d6->GetYaxis()->SetRangeUser(r3_a, r3_b);
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
	hHE_d7->GetYaxis()->SetRangeUser(r3_a, r3_b);
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
	hHF_d1->GetYaxis()->SetRangeUser( r2_a , r2_b );
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
	hHF_d2->GetYaxis()->SetRangeUser(r2_a, r2_b);
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
	hHF_d3->GetYaxis()->SetRangeUser(r2_a, r2_b);
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
	hHF_d4->GetYaxis()->SetRangeUser(r2_a, r2_b);
	hHF_d4->GetYaxis()->SetTitleSize(0.06);
	hHF_d4->GetYaxis()->SetTitleOffset(0.80);
	hHF_d4->GetXaxis()->SetTitleSize(0.06);
	hHF_d4->GetXaxis()->SetTitleOffset(0.80);
	hHF_d4->GetYaxis()->SetLabelSize(0.055);
	hHF_d4->GetXaxis()->SetLabelSize(0.055);
	hHF_d4->SetContour(100);
    
   
}
