// The OFFICIAL JPAC graphing style for ROOT ;P
//
// Author:       Daniel Winney (2020)
// Affiliation:  Joint Physics Analysis Center (JPAC)
// Email:        dwinney@iu.edu
// -----------------------------------------------------------------------------

#ifndef _JPAC_STYLE_
#define _JPAC_STYLE_

#include <complex>
#include <vector>
#include <iterator>
#include <cmath>
#include <iostream>
#include <fstream>
#include <string>

#include <TROOT.h>
#include <TImage.h>
#include <TColor.h>
#include <TH2.h>
#include <TGraph2D.h>
#include <TCanvas.h>
#include <TGraph.h>
#include <TLegend.h>
#include <TStyle.h>
#include <TError.h>
#include <TLatex.h>

class jpacGraph
{
public:
  jpacGraph()
  {
    SetStyle();
  };

  ~jpacGraph()
  {
    delete jpacStyle;
    delete jpacBlue, jpacRed, jpacGreen;
    delete jpacOrange, jpacPurple, jpacBrown;
    delete jpacPink, jpacGold, jpacAqua;
    delete logo, legend;
  }

void plot(std::vector<double> s, std::vector<double> fx, std::string filename);

private:
  static Int_t  kjpacBlue, kjpacRed, kjpacGreen,
                kjpacOrange, kjpacPurple, kjpacBrown,
                kjpacPink, kjpacGold, kjpacAqua;

  static TColor *jpacBlue, *jpacRed, *jpacGreen,
                *jpacOrange, *jpacPurple, *jpacBrown,
                *jpacPink, *jpacGold, *jpacAqua;

  // Set all the style options
  TStyle* jpacStyle = new TStyle("jpacStyle", "JPAC Style");
  void SetStyle();

  // Stuff regarding the Logo
  TLatex* logo = NULL;
  TLegend* legend = NULL;
  void AddLogo();
};


#endif
