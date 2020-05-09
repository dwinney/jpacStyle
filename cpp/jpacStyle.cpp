// The OFFICIAL JPAC graphing style for ROOT
//
// Author:       Daniel Winney (2020)
// Affiliation:  Joint Physics Analysis Center (JPAC)
// Email:        dwinney@iu.edu
// -----------------------------------------------------------------------------

#include "jpacStyle.hpp"

// -----------------------------------------------------------------------------
// All other noncolor settings
void jpacGraph::SetStyle()
{
  gErrorIgnoreLevel = kWarning;

  // remove info box
  jpacStyle->SetOptStat(0);

  // Centre title
  jpacStyle->SetTitleAlign(22);
  jpacStyle->SetTitleX(.5);
  jpacStyle->SetTitleY(.95);
  jpacStyle->SetTitleBorderSize(0);

  // set background colors to white
  jpacStyle->SetFillColor(10);
  jpacStyle->SetFrameFillColor(10);
  jpacStyle->SetCanvasColor(10);
  jpacStyle->SetPadColor(10);
  jpacStyle->SetTitleFillColor(0);
  jpacStyle->SetStatColor(10);

  // Don't put a colored frame around the plots
  jpacStyle->SetFrameBorderMode(0);
  jpacStyle->SetCanvasBorderMode(0);
  jpacStyle->SetPadBorderMode(0);

  // No border on legends
  jpacStyle->SetLegendBorderSize(0);
  jpacStyle->SetLegendTextSize(0.03);

  // Axis titles
  jpacStyle->SetTitleSize(.055, "xyz");
  jpacStyle->SetTitleOffset(.8, "xyz");

  // More space for y-axis to avoid clashing with big numbers
  jpacStyle->SetTitleOffset(.9, "y");

  // This applies the same settings to the overall plot title
  jpacStyle->SetTitleSize(.055, "");
  jpacStyle->SetTitleOffset(.8, "");

  // Axis labels (numbering)
  jpacStyle->SetLabelSize(.04, "xyz");
  jpacStyle->SetLabelOffset(.005, "xyz");


  const int kjpacFont = 42;
  jpacStyle->SetStatFont(kjpacFont);
  jpacStyle->SetLabelFont(kjpacFont, "xyz");
  jpacStyle->SetTitleFont(kjpacFont, "xyz");
  jpacStyle->SetTitleFont(kjpacFont, ""); // Apply same setting to plot titles
  jpacStyle->SetTextFont(kjpacFont);
  jpacStyle->SetLegendFont(kjpacFont);

  // Make it the global default style
  gROOT->SetStyle("jpacStyle");

  // Set up the legend
  legend = new TLegend();
  legend->SetFillStyle(0);
  legend->SetEntrySeparation(0.05);
};

void jpacGraph::AddLogo()
{
  std::string JPAC = "#font[72]{#color[" + std::to_string(kjpacBlue) + "]{J}";
  JPAC += "^{";
  JPAC += "#color[" + std::to_string(kjpacBlue) + "]{P}";
  JPAC += "#color[" + std::to_string(kjpacRed) + "]{A}";
  JPAC += "#color[" + std::to_string(kjpacBlue) + "]{C}";
  JPAC += "}}";

  logo = new TLatex(.88, .85,  JPAC.c_str());
  logo->SetNDC();
  logo->SetTextSize(2/30.);
  logo->SetTextAlign(32);
  logo->Draw();
};
