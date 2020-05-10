// The Wrapper for quick one-dimensional graphs using JPAC style
//
// Author:       Daniel Winney (2020)
// Affiliation:  Joint Physics Analysis Center (JPAC)
// Email:        dwinney@iu.edu
// -----------------------------------------------------------------------------

#ifndef _JPAC_1D_
#define _JPAC_1D_

#include "jpacPlot.hpp"

#include <TLegend.h>
#include <tuple>

class jpacGraph1D : public jpacPlot
{
public:
  jpacGraph1D() : jpacPlot()
  {};

  ~jpacGraph1D()
  {
    // For cleaning up make sure to delete all the saved pointers
    for (int i = 0; i < entries.size(); i++)
    {
      delete std::get<0>(entries[i]);
    }
    delete legend;
  };

  // Take in x and f(x) values as a vector and a legend entry
  void AddEntry(std::vector<double> xs, std::vector<double> fxs, std::string name);

  // Plot all the saved entries and print to file given by filename
  void Plot(std::string filename);

  // Set label and range for x axis
  void SetXaxis(std::string label, double low = 0., double high = 0.);
  void SetYaxis(std::string label, double low = 0., double high = 0.);

  // Set up the Legend
  void SetLegend(double xx, double yy)
  {
    xCord = xx; yCord = yy;
  };

private:
  // Legend Parameters
  TLegend * legend = NULL;
  double xCord, yCord;

  // Axes Parameters
  bool xCustom = false, yCustom = false;
  std::string xLabel = "", yLabel = "";
  double xlow, xhigh, ylow, yhigh;

  // Entries are saved in tuples with their legend title as a string
  std::vector<std::tuple<TGraph*, std::string>> entries;
};

#endif
