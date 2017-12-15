#include <vector>
#include <exception>
#include "TStyle.h"
#include "TFile.h"
#include "TMath.h"
#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <iostream.h>
#include <fstream>


void produce(){

char* file1 = "HcalGains.txt";
char* file0 = "HcalRespCorrs.txt";
char* fout = "Gains_x_Resp.txt";
  
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
 
  FILE *fto;
  if ((fto = fopen(fout,"w"))==NULL){         // Open new file
    printf("\nNo output file open => EXIT\n\n");
    return;
  }
  printf("\n\n output file open \n\n");
  
  char stroka[500], SudDet0[50], SudDet1[50], DetId0[50], DetId1[50];
  int ieta1, iphi1, depth1, ieta0, iphi0, depth0;
  float c0, c1, cov[4];

  fgets(stroka, 500, ft0);
  fgets(stroka, 500, ft1);
    
  for (int j=0; j<99999; j++) {
    if (feof(ft0)!=0) break;
      fscanf(ft0,"%d%d%d%s%f%s\r",&ieta0,&iphi0,&depth0,&SudDet0,&c0,&DetId0);
	  fscanf(ft1, "%d%d%d%s%f%f%f%f%s\r", &ieta1, &iphi1, &depth1, &SudDet1, &cov[0], &cov[1], &cov[2], &cov[3], &DetId1);
	  if ((ieta0 == ieta1 && iphi0 == iphi1) && (depth0 == depth1 && SudDet0[1] == SudDet1[1])) {
		  float cn = c0*(cov[0] + cov[1] + cov[2] + cov[3])/4;
		  printf("%17d %15d %15d %15s %8.5f %10s\n", ieta0, iphi0, depth0, SudDet0, cn, DetId1);
		  fprintf(fto, "%17d %15d %15d %15s %9.7f %10s\n", ieta0, iphi0, depth0, SudDet0, cn, DetId1);
	  }// end  id comparison     
}// end of file reading
  
    fclose(ft0);
    fclose(ft1);
    fclose(fto);
    
}
