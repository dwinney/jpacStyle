// The Wrapper for quick one-dimensional graphs with complex valued functions using JPAC style
//
// Author:       Daniel Winney (2020)
// Affiliation:  Joint Physics Analysis Center (JPAC)
// Email:        dwinney@iu.edu
// -----------------------------------------------------------------------------

#ifndef _JPAC_1DC_
#define _JPAC_1DC_

#include "jpacPlotter.hpp"

#include <complex>
#include <TLegend.h>
#include <TGraph.h>
#include <TAxis.h>
#include <tuple>

class jpacGraph1Dc : public jpacPlotter
{
public:
  // Default Constructor
  jpacGraph1Dc()
  {
    canvas->Divide(1,2, 0.01, 0.005);
    jpacStyle->SetTitleOffset(0.8, "y");

  };

  // Quick parameterized Constructor
  jpacGraph1Dc(std::vector<double> xs, std::vector<std::complex<double>> fxs, std::string name)
  {
    canvas->Divide(1,2, 0.01, 0.005);
    jpacStyle->SetTitleOffset(0.8, "y");

    AddEntry(xs, fxs, name);
  };

  // Destructor
  ~jpacGraph1Dc()
  {
    // For cleaning up make sure to delete all the saved pointers
    for (int i = 0; i < entries.size(); i++)
    {
      delete std::get<0>(entries[i]);
      delete std::get<1>(entries[i]);
    }
    delete imagTag, realTag, legend;
  };

  // Set up the Legend
  void SetLegend(bool ifremove);
  void SetLegend(double xx, double yy);

  // Take in x and f(x) values as a vector and a legend entry
  void AddEntry(std::vector<double> xs, std::vector<std::complex<double>> fxs, std::string name);

  // Plot all the saved entries and print to file given by filename
  void Plot(std::string filename);

private:
  // Legend Parameters
  TLegend * legend = NULL;
  double xCord, yCord;
  bool legCustom = false, legAdd = true;

  // Text to put on bottom right corner indicating real or imag part
  std::string sReal = "#scale[0.7]{#font[102]{Real Part}}";
  TLatex* realTag = new TLatex(.92, 0.17, sReal.c_str());

  std::string sImag = "#scale[0.7]{#font[102]{Imaginary Part}}";
  TLatex* imagTag = new TLatex(.92, 0.17, sImag.c_str());


  // Entries are saved in tuples with their legend title as a string
  std::vector<std::tuple<TGraph*, TGraph*, std::string>> entries;

  // Utilities to separate the real and imaginary parts into separate vectors
  std::vector<double> vec_real(std::vector<std::complex<double>> fx);
  std::vector<double> vec_imag(std::vector<std::complex<double>> fx);

  // Add the logo to both plots!
  void AddLogo();
};

#endif
