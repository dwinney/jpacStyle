// The Wrapper for quick one-dimensional graphs using JPAC style
//
// Author:       Daniel Winney (2020)
// Affiliation:  Joint Physics Analysis Center (JPAC)
// Email:        dwinney@iu.edu
// -----------------------------------------------------------------------------

#include "jpacGraph1D.hpp"

// -----------------------------------------------------------------------------
// Take in x and f(x) values as a vector and a legend entry
void jpacGraph1D::AddEntry(std::vector<double> xs, std::vector<double> fxs, std::string name)
{
  TGraph *g = new TGraph(xs.size(), &(xs[0]), &(fxs[0]));
  auto entry = std::make_tuple(g, name);
  entries.push_back(entry);
};

// -----------------------------------------------------------------------------
// Set the axes
void jpacGraph1D::SetXaxis(std::string label, double low, double high)
{
  xLabel = label;

  if (std::abs(low) > 0.000001 || std::abs(high) > 0.000001)
  {
    xlow = low; xhigh = high;
    xCustom = true;
  }
};

void jpacGraph1D::SetYaxis(std::string label, double low, double high)
{
  yLabel = label;
  if (std::abs(low) > 0.000001 || std::abs(high) > 0.000001)
  {
    ylow = low; yhigh = high;
    yCustom = true;
  }
};

// -----------------------------------------------------------------------------
// Plot all the saved entries and print to file given by filename
void jpacGraph1D::Plot(std::string filename)
{
  if (entries.size() > 10)
  {
      std::cout << "Warning! Number of curve greater than number of colors (9)! \n";
  }

  // Set up the Legend
  legend = new TLegend(xCord, yCord, xCord + .3, yCord + .15);
  legend->SetFillStyle(0);
  if (entries.size() > 4)
  {
    legend->SetNColumns(2);
  }

  // Draw the first entry
  std::get<0>(entries[0])->UseCurrentStyle();
  std::get<0>(entries[0])->SetTitle("");
  std::get<0>(entries[0])->SetLineWidth(3);
  std::get<0>(entries[0])->SetLineColor(jpacColors[0]);

  // Set up the axes
  TAxis* xAxis = std::get<0>(entries[0])->GetXaxis();
  xAxis->SetTitle(xLabel.c_str());
  xAxis->CenterTitle(true);
  if (xCustom == true)
  {
    xAxis->SetRangeUser(xlow, xhigh);
  }

  TAxis* yAxis = std::get<0>(entries[0])->GetYaxis();
  yAxis->SetTitle(yLabel.c_str());
  yAxis->CenterTitle(true);
  if (yCustom == true)
  {
    yAxis->SetRangeUser(ylow, yhigh);
  }

  // Draw the first curve
  std::get<0>(entries[0])->Draw("AL");
  legend->AddEntry(std::get<0>(entries[0]), std::get<1>(entries[0]).c_str(), "l");

  // Add the logo
  AddLogo();

  // And any subsequent ones on the same canvas
  for (int i = 1; i < entries.size(); i++)
  {
    std::get<0>(entries[i])->SetLineWidth(3);
    std::get<0>(entries[i])->SetLineColor(jpacColors[i]);
    std::get<0>(entries[i])->Draw("same");

    legend->AddEntry(std::get<0>(entries[i]), std::get<1>(entries[i]).c_str(), "l");
  };

  legend->Draw();
  canvas->Print(filename.c_str());
};
