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

  jpacGraph1D* plotter = new jpacGraph1D();
  for (int alpha = 0; alpha < bessels.size(); alpha++)
  {
    plotter->AddEntry(x, bessels[alpha], "#alpha=" + std::to_string(alpha+1));
  }

  // Choose the relative coordinates of the bottom right corner of legend
  plotter->SetLegend(.45, .65);

  // Set the label and range of x axis
  plotter->SetXaxis("W  [GeV]", 0., 20.);

  // Set the label and range of y axis
  plotter->SetYaxis("d#sigma/dt  [nB/GeV^{2}]", -0.5, 1.);

  // Print and pdf of the finished plot
  plotter->Plot("bessel.pdf");

  delete plotter;
  return 1.;
};
