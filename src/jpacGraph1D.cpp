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
// Plot all the saved entries and print to file given by filename
void jpacGraph1D::Plot(std::string filename)
{

  legend = new TLegend();
  legend->SetFillStyle(0);

  // Draw the first entry
  std::get<0>(entries[0])->SetTitle("");
  std::get<0>(entries[0])->SetLineWidth(3);
  std::get<0>(entries[0])->SetLineColor(jpacColors[0]);
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
