// The Wrapper for quick two-dimensional graphs using JPAC style
//
// Author:       Daniel Winney (2020)
// Affiliation:  Joint Physics Analysis Center (JPAC)
// Email:        dwinney@iu.edu
// -----------------------------------------------------------------------------

#ifndef _JPAC_2D_
#define _JPAC_2D_

#include "jpacPlot.hpp"

#include <TLegend.h>
#include <TGraph2D.h>
#include <TH2D.h>
#include <TAxis.h>
#include <tuple>

class jpacGraph2D : public jpacPlot
{
public:
  jpacGraph2D()
  : jpacPlot()
  {};

  ~jpacGraph2D()
  {
    delete logo;
  };

  // Add in the data as vectors
  void SetData(std::vector<double> x, std::vector<double> y, std::vector<double> z)
  {
    data = new TGraph2D(x.size(), &(x[0]), &(y[0]), &(z[0]));
  };

  void SetXaxis(std::string label, double min = 0., double max = 0.);
  void SetYaxis(std::string label, double min = 0., double max = 0.);

  // Plot all the saved entries and print to file given by filename
  void Plot(std::string filename);

private:
  TGraph2D * data = NULL;

  // Axes Parameters
  bool xCustom = false, yCustom = false;
  std::string xLabel = "", yLabel = "";
  double xlow, xhigh, ylow, yhigh;

  void AddLogo();
  TLatex* logo = NULL;
};

#endif
