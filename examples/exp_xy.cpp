// ---------------------------------------------------------------------------
// Example Script to generate plots with jpacStyle
//
// Author:       Daniel Winney (2020)
// Affiliation:  Joint Physics Analysis Center (JPAC)
// Email:        dwinney@iu.edu
// ---------------------------------------------------------------------------

#include "jpacGraph2D.hpp"

#include <cstring>
#include <complex>
#include <cmath>
#include <iostream>
#include <iomanip>

int main()
{
  std::vector<double> x , y, z;
  for (int i = 0; i <= 400; i++)
  {
    for (int j = 0; j <= 400; j++)
    {
      double x_i = -1. + double(i) * 2. / 400.;
      double y_j = -1. + double(j) * 2. / 400.;

      double z_ij = exp(- x_i * x_i - y_j * y_j);

      x.push_back(x_i);
      y.push_back(y_j);
      z.push_back(z_ij);
    }
  }

  // Initialize graphing object
  // Can be empty and add data with SetData
  // jpacGraph2D* plotter = new jpacGraph2D();
  // plotter->SetData(x, y, z);

  // Or all in one command:
  jpacGraph2D* plotter = new jpacGraph2D(x, y, z);

  // Set up the labels and ranges of the axes
  plotter->SetXaxis("x", -1., 1.);
  plotter->SetYaxis("y", -1., 1.);

  // Print and pdf of the finished plot
  plotter->Plot("exp_xy.pdf");

  delete plotter;
  return 1.;
};
