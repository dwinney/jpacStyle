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
    for (int i = 0; i < dashed_entries.size(); i++)
    {
      delete dashed_entries[i];
    }
    delete legend;
  };

  // Take in x and f(x) values as a vector and a legend entry
  void AddEntry(std::vector<double> xs, std::vector<double> fxs, std::string name, int DASH = 0);

  // Dashed entries reset the color order and dont add a legend entry
  void AddDashedEntry(std::vector<double> xs, std::vector<double> fxs);

  // Clear all added entries
  void ClearData();

  // Set up the Legend
  void SetLegend(bool ifremove);
  void SetLegend(double xx, double yy, std::string header = "");
  void SetLegendOffset(double xx, double yy);

  // Add a second Y-axis
  void AddSecondScale(double ylow, double yhigh, std::string label = "");

  // Plot to file
  void Draw();
  void Plot(std::string filename);

protected:
  int line_width = 3.;
  TAxis * xAxis = NULL;
  TAxis * yAxis = NULL;
  
  // Legend Parameters
  TLegend * legend = NULL;
  double xCord, yCord;
  double xLegOffset = 0.3, yLegOffset = .15;
  std::string header;
  bool legCustom = false, legAdd = true;

  // Second y-axis parameters;
  double y2low, y2high;
  std::string y2label;
  bool SECOND_Y = false;

  // Position the logo in to top right
  void AddLogo();

  // Overrideable function called at end of Plot()
  virtual void AddExtra(){};

  // Entries are saved in tuples with their legend title as a string
  std::vector<std::tuple<TGraph*, std::string>> entries;
  std::vector<TGraph*> dashed_entries;
};

#endif
