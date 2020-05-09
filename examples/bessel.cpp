// ---------------------------------------------------------------------------
// Example Script to generate plots with jpacStyle
//
// Author:       Daniel Winney (2020)
// Affiliation:  Joint Physics Analysis Center (JPAC)
// Email:        dwinney@iu.edu
// ---------------------------------------------------------------------------

#include "jpacStyle.hpp"

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
  std::vector<double> x, fx;
  for (int i = 0; i < 100; i++)
  {
    double x_i = double(i) * 20. / 100.;
    double fx_i = ROOT::Math::cyl_bessel_j(0, x_i);

    x.push_back(x_i);
    fx.push_back(fx_i);
  };

  jpacGraph* plotter = new jpacGraph();
  plotter->plot(x, fx, "bessel");


  return 1.;
};
