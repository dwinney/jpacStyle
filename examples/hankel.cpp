// ---------------------------------------------------------------------------
// Example Script to generate complex valued plots with jpacStyle
//
// Author:       Daniel Winney (2020)
// Affiliation:  Joint Physics Analysis Center (JPAC)
// Email:        dwinney@iu.edu
// ---------------------------------------------------------------------------

#include "jpacGraph1Dc.hpp"

#include <cstring>
#include <complex>
#include <cmath>
#include <iostream>
#include <iomanip>

#include "Math/SpecFuncMathMore.h"
#include "TMath.h"

int main()
{
  // Unit real
  std::complex<double> xi(0.,1.);

  std::vector<double> x;
  std::vector<std::vector<std::complex<double>>> hankels;

  for (int alpha = 0; alpha < 10; alpha++)
  {
    std::vector<std::complex<double>> Hx;
    for (int i = 0; i <= 100; i++)
    {
      double x_i = (1.E-5) + double(i) * 20. / 100.;
      double Jx_i = ROOT::Math::cyl_bessel_j(alpha, x_i);
      double Yx_i = ROOT::Math::cyl_neumann(alpha, x_i);

      std::complex<double> Hx_i = Jx_i + xi * Yx_i;

      if (alpha == 0)
      {
        x.push_back(x_i);
      }
      Hx.push_back(Hx_i);
    }
    hankels.push_back(Hx);
  }

  // Initialize plotter object with the first entry
  jpacGraph1Dc* plotter = new jpacGraph1Dc(x, hankels[0], "#alpha = 1");

  //Add additional curves using AddEntry
  for (int alpha = 1; alpha < hankels.size(); alpha++)
  {
    plotter->AddEntry(x, hankels[alpha], "#alpha = " + std::to_string(alpha+1));
  }

  // Set the labels of the axes
  plotter->SetXaxis("#font[12]{W} (GeV)", 0., 20.);
  plotter->SetYaxis("#font[12]{d#sigma/dt} (#font[12]{nB}/GeV^{2})");

  plotter->SetLegend(.6, .2);

  // Output to a file
  plotter->Plot("hankel.pdf");
};
