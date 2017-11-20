#include <vector>
#include <exception>
#include "TStyle.h"
#include "TFile.h"
#include "TTree.h"
#include "TMath.h"
#include "TF1.h"
#include "TH2.h"
#include "TH1F.h"
#include "TH2F.h"
#include "TProfile.h"
#include "TCanvas.h"
#include "TLatex.h"
#include "TColor.h"
#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <math.h>


void compare(){

	const char* file0 = "HcalChannelQuality_2017IOV4.txt"; //new 
	const char* file1 = "HcalChannelQuality_2017IOV1.txt";//pref
	

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

  FILE *fout;
  if ((fout = fopen("SanityCheck_IOV4.txt", "w")) == NULL) {         // Open new file
	  printf("\nNo output file open => EXIT\n\n");
	  return;
  }
  printf("\n\n output file open \n\n");

  char info[] = "#   ieta     iphi     depth      det     prev     new     DetId    Difference";
  const char* status;
  printf("%s\n", info);
  fprintf(fout, "%s\n", info);

  int ieta1,iphi1,depth1,ieta0,iphi0,depth0;
  int c1, c0;
  char comment[500], type[100], SubDet1[160], SubDet2[160], DetID1[160], DetID2[160];
  fgets(comment, 500, ft0);
  fgets(comment, 500, ft1);
 
  //it is assumed that channels have same order in both files
  for (int j=0; j<99999; j++) {       
    if (feof(ft0)!=0) break;
      fscanf(ft0,"%d%d%d%s%s%d%s\r",&ieta0,&iphi0,&depth0, SubDet1, type, &c0, DetID1);
      fscanf(ft1,"%d%d%d%s%s%d%s\r",&ieta0,&iphi0,&depth0, SubDet2, type, &c1, DetID2);
      if(c0!=0 || c1!=0){
		  status = " ";
		  if (c0 != c1) status = " changed ";
          printf (" %8d %8d %8d %8s %8d %8d %10s %6s\n",ieta0,iphi0,depth0, SubDet1,c1, c0, DetID1, status);
		  fprintf(fout, "%8d %8d %8d %8s %8d %8d %10s %8s\n", ieta0, iphi0, depth0, SubDet1, c1, c0, DetID1, status);
      }
  }
  
}
