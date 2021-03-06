#ifndef Utils_h
#define Utils_h
#include <cmath>
#include <iostream>
#include <fstream>
#include <stdio.h> 
#include <stdlib.h> 
#include <time.h> 
#include <TF1.h>
#include <TGraph.h>
#include <TH1.h>
#include <TAxis.h>
#include <TLorentzVector.h>

void Line(TH1* h1,Double_t ordonnee);
float SetBins(double var,  float varbins[] , const int maxvarbins); 
float LinearBins(const int& nbins,  const double& min, const double& max ,const int& ibin);
float LogBins(const int& nbins,  const double& min, const double& max ,const int& ibin); 
float SetBins2D(double var1, double var2, float varbins[][2][2], const int maxvarbins);
double Random_Expo(double lambda); // give a random number with an exponential distribution
void degtorad(double &Adeg);
void radtodeg(double &Arad);
void FillArray_LV(TLorentzVector LV, float *Ar);
#endif


