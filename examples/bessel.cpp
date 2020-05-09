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
#include "TF1.h"

int main()
{
  std::vector<double> x, b0, b1, b2;
  for (int i = 0; i < 100; i++)
  {
    double x_i = double(i) * 20. / 100.;
    double b0_i = ROOT::Math::cyl_bessel_j(0, x_i);
    double b1_i = ROOT::Math::cyl_bessel_j(1, x_i);
    double b2_i = ROOT::Math::cyl_bessel_j(2, x_i);

    x.push_back(x_i);
    b0.push_back(b0_i);
    b1.push_back(b1_i);
    b2.push_back(b2_i);
  };

  jpacGraph1D* plotter = new jpacGraph1D();
  plotter->AddEntry(x, b0, "#alpha = 0");
  plotter->AddEntry(x, b1, "#alpha = 1");
  plotter->AddEntry(x, b2, "#alpha = 2");

  plotter->Plot("bessel.pdf");

  delete plotter;
  return 1.;
};
