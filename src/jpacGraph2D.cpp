// The Wrapper for quick two-dimensional graphs using JPAC style
//
// Author:       Daniel Winney (2020)
// Affiliation:  Joint Physics Analysis Center (JPAC)
// Email:        dwinney@iu.edu
// -----------------------------------------------------------------------------

#include "jpacGraph2D.hpp"

// -----------------------------------------------------------------------------
// Set the axes
void jpacGraph2D::SetXaxis(std::string label, double low, double high)
{
  xLabel = label;

  if (std::abs(low) > 0.000001 || std::abs(high) > 0.000001)
  {
    xlow = low; xhigh = high;
    xCustom = true;
  }
};

void jpacGraph2D::SetYaxis(std::string label, double low, double high)
{
  yLabel = label;
  if (std::abs(low) > 0.000001 || std::abs(high) > 0.000001)
  {
    ylow = low; yhigh = high;
    yCustom = true;
  }
};

// -----------------------------------------------------------------------------
// Add the J^{PAC} logo in black and white in top right corner
void jpacGraph2D::AddLogo()
{
  logo = new TLatex(.82, .89,  JPAC_BW.c_str());
  logo->SetNDC();
  logo->SetTextSize(2/30.);
  logo->SetTextAlign(32);
  logo->Draw();
};


// -----------------------------------------------------------------------------
void jpacGraph2D::Plot(std::string filename)
{
  // Force the canvas to be square
  // Also make sure to give enough room for the axes labels
  canvas->SetRightMargin(0.15);
  canvas->SetLeftMargin(0.15);
  canvas->SetBottomMargin(0.12);
  canvas->SetTopMargin(0.05);

  TAxis* xAxis = data->GetHistogram()->GetXaxis();
  xAxis->SetTitle(xLabel.c_str());
  xAxis->CenterTitle(true);
  if (xCustom == true)
  {
    xAxis->SetRangeUser(xlow, xhigh);
  }

  TAxis* yAxis = data->GetHistogram()->GetYaxis();
  yAxis->SetTitle(yLabel.c_str());
  yAxis->CenterTitle(true);
  if (yCustom == true)
  {
    yAxis->SetRangeUser(ylow, yhigh);
  }

  data->SetTitle("");
  data->Draw("COLZ");

  // Add the logo
  AddLogo();

  // Print to file
  canvas->Print(filename.c_str());
};
