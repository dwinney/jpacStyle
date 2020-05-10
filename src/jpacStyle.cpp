// The OFFICIAL JPAC graphing style for ROOT
//
// Author:       Daniel Winney (2020)
// Affiliation:  Joint Physics Analysis Center (JPAC)
// Email:        dwinney@iu.edu
// -----------------------------------------------------------------------------

#include "jpacPlot.hpp"

// -----------------------------------------------------------------------------
// All other noncolor settings
void jpacPlot::SetStyle()
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
  jpacStyle->SetLegendTextSize(0.04);

  // Axis titles
  jpacStyle->SetNdivisions(5, "xy");
  jpacStyle->SetTitleSize(.045, "xyz");
  jpacStyle->SetTitleOffset(1.0, "xyz");

  // More space for y-axis to avoid clashing with big numbers
  jpacStyle->SetTitleOffset(1.2, "y");

  // This applies the same settings to the overall plot title
  jpacStyle->SetTitleSize(.055, "");
  jpacStyle->SetTitleOffset(.8, "");

  // Axis labels (numbering)
  jpacStyle->SetLabelSize(.035, "xyz");
  jpacStyle->SetLabelOffset(.01, "xyz");


  const int kjpacFont = 82;
  jpacStyle->SetStatFont(kjpacFont);
  jpacStyle->SetLabelFont(kjpacFont, "xyz");
  jpacStyle->SetTitleFont(kjpacFont, "xyz");
  jpacStyle->SetTitleFont(kjpacFont, ""); // Apply same setting to plot titles
  jpacStyle->SetTextFont(kjpacFont);
  jpacStyle->SetLegendFont(kjpacFont);

  // Make it the global default style
  gROOT->SetStyle("jpacStyle");
};

// -----------------------------------------------------------------------------
// Add the J^{PAC} logo in appropriate colors at the top right of the plot
void jpacPlot::AddLogo()
{
  std::string JPAC = "#scale[1.2]{#font[72]{#color[" + std::to_string(kjpacBlue) + "]{J}";
  JPAC += "^{";
  JPAC += "#color[" + std::to_string(kjpacBlue) + "]{P}";
  JPAC += "#color[" + std::to_string(kjpacRed) + "]{A}";
  JPAC += "#color[" + std::to_string(kjpacBlue) + "]{C}";
  JPAC += "}}}";

  logo = new TLatex(.88, .85,  JPAC.c_str());
  logo->SetNDC();
  logo->SetTextSize(2/30.);
  logo->SetTextAlign(32);
  logo->Draw();
};
