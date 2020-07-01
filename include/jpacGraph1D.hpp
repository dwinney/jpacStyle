// The Wrapper for quick one-dimensional graphs using JPAC style
//
// Author:       Daniel Winney (2020)
// Affiliation:  Joint Physics Analysis Center (JPAC)
// Email:        dwinney@iu.edu
// -----------------------------------------------------------------------------

#ifndef _JPAC_1D_
#define _JPAC_1D_

#include "jpacPlotter.hpp"

#include <TLegend.h>
#include <TGraph.h>
#include <TAxis.h>
#include <TGaxis.h>
#include <tuple>

// -----------------------------------------------------------------------------
// Abstract class for the jpac style
class jpacGraph1D : public jpacPlotter
{
public:
  // Default Constructor
  jpacGraph1D()
  {};

  // Parameterized constructor useful for if only one curve
  jpacGraph1D(std::vector<double> xs, std::vector<double> fxs, std::string name)
  {
    AddEntry(xs, fxs, name);
  };

  ~jpacGraph1D()
  {
    // For cleaning up make sure to delete all the saved pointers
    for (int i = 0; i < entries.size(); i++)
    {
      delete std::get<0>(entries[i]);
    }
    delete legend, logo;
  };

  // Take in x and f(x) values as a vector and a legend entry
  void AddEntry(std::vector<double> xs, std::vector<double> fxs, std::string name);

  // Clear all added entries
  void ClearData();

  // Set up the Legend
  void SetLegend(bool ifremove);
  void SetLegend(double xx, double yy, std::string header = "");

  // Add a second Y-axis
  void AddSecondScale(double ylow, double yhigh, std::string label = "");

  // Plot to file
  void Plot(std::string filename);

private:
  // Legend Parameters
  TLegend * legend = NULL;
  double xCord, yCord;
  std::string header;
  bool legCustom = false, legAdd = true;

  // Second y-axis parameters;
  double y2low, y2high;
  std::string y2label;
  bool SECOND_Y = false;

  // Position the logo in to top right
  void AddLogo();

  // Entries are saved in tuples with their legend title as a string
  std::vector<std::tuple<TGraph*, std::string>> entries;
};

#endif
