// The OFFICIAL JPAC graphing style for ROOT ;P
//
// Author:       Daniel Winney (2020)
// Affiliation:  Joint Physics Analysis Center (JPAC)
// Email:        dwinney@iu.edu
// -----------------------------------------------------------------------------

#include "jpacStyle.hpp"

void jpacGraph::plot(std::vector<double> s, std::vector<double> fx, std::string filename)
{
  TCanvas* c = new TCanvas("c", "c");
  TGraph *gRe  = new TGraph(s.size(), &(s[0]), &(fx[0]));
  TGraph *gRe2  = new TGraph(s.size(), &(s[0]), &(fx[0]));

  gRe->UseCurrentStyle();
  gRe->SetTitle("");
  gRe->SetLineStyle(1);
  gRe->SetLineWidth(3);
  gRe->SetLineColor(kjpacBlue);
  gRe->Draw("AL");

  gRe2->UseCurrentStyle();
  gRe2->SetTitle("");
  gRe2->SetLineStyle(1);
  gRe2->SetLineWidth(3);
  gRe2->SetLineColor(kjpacRed);
  gRe2->Draw("AL");

  AddLogo();
  legend->AddEntry(gRe, "#rho exchange", "l");
  legend->AddEntry(gRe2, "#rho_2 exchange", "l");

  legend->Draw();

  std::string namepdf = filename + ".pdf";
  c->Print(namepdf.c_str());

  delete c, gRe;
};
