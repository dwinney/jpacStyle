// The OFFICIAL JPAC graphing style for ROOT
//
// Author:       Daniel Winney (2020)
// Affiliation:  Joint Physics Analysis Center (JPAC)
// Email:        dwinney@iu.edu
// -----------------------------------------------------------------------------

#ifndef _JPAC_STYLE_
#define _JPAC_STYLE_

#include <iostream>
#include <vector>
#include <string>

#include <TROOT.h>
#include <TCanvas.h>
#include <TColor.h>
#include <TStyle.h>
#include <TError.h>
#include <TLatex.h>

class jpacPlot
{
public:
  jpacPlot()
  {
    SetStyle();
    Set2DPalette();
  };

  ~jpacPlot()
  {
    delete jpacStyle;
    delete jpacBlue, jpacRed, jpacGreen;
    delete jpacOrange, jpacPurple, jpacBrown;
    delete jpacPink, jpacGold, jpacAqua, jpacGrey;
    delete canvas;
  };

  static Int_t  kjpacBlue, kjpacRed, kjpacGreen,
                kjpacOrange, kjpacPurple, kjpacBrown,
                kjpacPink, kjpacGold, kjpacAqua, kjpacGrey;

  static std::vector<Int_t> jpacColors;

  static TColor *jpacBlue, *jpacRed, *jpacGreen,
                *jpacOrange, *jpacPurple, *jpacBrown,
                *jpacPink, *jpacGold, *jpacAqua, *jpacGrey;

  static std::string JPAC, JPAC_BW;

  // Set all the style options
  TStyle* jpacStyle = new TStyle("jpacStyle", "JPAC Style");
  void SetStyle();

  // Stuff regarding the Logo
  TCanvas* canvas = new TCanvas("canvas", "canvas", 600, 600);

  // For the 2D contour plots
  void Set2DPalette();
};

#endif
