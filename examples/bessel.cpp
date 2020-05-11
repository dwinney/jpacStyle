// ---------------------------------------------------------------------------
// Example Script to generate plots with jpacStyle
//
// Author:       Daniel Winney (2020)
// Affiliation:  Joint Physics Analysis Center (JPAC)
// Email:        dwinney@iu.edu
// ---------------------------------------------------------------------------

#include "jpacGraph1D.hpp"

#include <cstring>
#include <complex>
#include <cmath>
#include <iostream>
#include <iomanip>

#include "Math/SpecFuncMathMore.h"
#include "TMath.h"

int main()
{
  std::vector<double> x;
  std::vector<std::vector<double>> bessels;

  for (int alpha = 0; alpha < 10; alpha++)
  {
    std::vector<double> bx;
    for (int i = 0; i < 100; i++)
    {
      double x_i = double(i) * 20. / 100.;
      double bx_i = ROOT::Math::cyl_bessel_j(alpha, x_i);

      if (alpha == 0)
      {
        x.push_back(x_i);
      }

      bx.push_back(bx_i);
    }
    bessels.push_back(bx);
  }

  // Initialize the plotting object
  // Can be initialized empty or with the first curve
  jpacGraph1D* plotter = new jpacGraph1D(x, bessels[0], "#alpha = 1");
  // jpacGraph1D* plotter = new jpacGraph1D();

  //Add additional curves using AddEntry
  for (int alpha = 1; alpha < bessels.size(); alpha++)
  {
    plotter->AddEntry(x, bessels[alpha], "#alpha = " + std::to_string(alpha+1));
  }

  // Choose the relative coordinates of the bottom right corner of legend
  // Without defining explicit coordinates will default to ROOT autoplacement
  plotter->SetLegend(.45, .70);

  // Alternatively choose to not have a legend at all
  // plotter->SetLegend(false);

  // Set the label and range of x axis
  // Font 12 is italics
  plotter->SetXaxis("#font[12]{W}  (GeV)", 0., 20.);

  // Set the label and range of y axis
  plotter->SetYaxis("#font[12]{d#sigma/dt}  (#font[12]{nB/} GeV^{2})", -0.5, 1.);

  // Print and pdf of the finished plot
  plotter->Plot("bessel.pdf");

  // Any of ROOT's TGraph->Print outputs are available by changing filename extension
  // plotter->Plot("bessel.eps");

  delete plotter;
  return 1.;
};
