#ifndef ROOTLOGON_C
#define ROOTLOGON_C

#include <TCanvas.h>
#include <TColor.h>
#include <TStyle.h>
#include <TError.h>
#include <TLatex.h>

// -----------------------------------------------------------------------------
// JPAC Color Palette
Int_t kjpacBlue = TColor::GetFreeColorIndex();
TColor * jpacBlue = new TColor(kjpacBlue, 0.12156862745098039, 0.4666666666666667, 0.7058823529411765);

Int_t kjpacRed = TColor::GetFreeColorIndex();
TColor * jpacRed = new TColor(kjpacRed, 0.8392156862745098, 0.15294117647058825, 0.1568627450980392);

Int_t kjpacGreen = TColor::GetFreeColorIndex();
TColor * jpacGreen = new TColor(kjpacGreen, 0.0, 0.6196078431372549, 0.45098039215686275);

Int_t kjpacOrange = TColor::GetFreeColorIndex();
TColor * jpacOrange = new TColor(kjpacOrange, 0.8823529411764706, 0.4980392156862745, 0.054901960784313725);

Int_t kjpacPurple = TColor::GetFreeColorIndex();
TColor * jpacPurple = new TColor(kjpacPurple, 0.5803921568627451, 0.403921568627451, 0.7411764705882353);

Int_t kjpacBrown = TColor::GetFreeColorIndex();
TColor * jpacBrown = new TColor(kjpacBrown, 0.5490196078431373, 0.33725490196078434, 0.29411764705882354);

Int_t kjpacPink = TColor::GetFreeColorIndex();
TColor * jpacPink = new TColor(kjpacPink, 0.8901960784313725, 0.4666666666666667, 0.7607843137254902);

Int_t kjpacGold = TColor::GetFreeColorIndex();
TColor * jpacGold = new TColor(kjpacGold, 0.7372549019607844, 0.7411764705882353, 0.13333333333333333);

Int_t kjpacAqua = TColor::GetFreeColorIndex();
TColor * jpacAqua = new TColor(kjpacAqua, 0.09019607843137255, 0.7450980392156863, 0.8117647058823529);

Int_t kjpacGrey = TColor::GetFreeColorIndex();
TColor * jpacGrey = new TColor(kjpacGrey, 0.4980392156862745, 0.4980392156862745, 0.4980392156862745);

void importStyle()
{
  TStyle* jpacStyle = new TStyle("jpacStyle", "JPAC Style");

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
void AddLogo()
{
  std::string JPAC = "#scale[1.2]{#font[72]{#color[" + std::to_string(kjpacBlue) + "]{J}";
  JPAC += "^{";
  JPAC += "#color[" + std::to_string(kjpacBlue) + "]{P}";
  JPAC += "#color[" + std::to_string(kjpacRed) + "]{A}";
  JPAC += "#color[" + std::to_string(kjpacBlue) + "]{C}";
  JPAC += "}}}";

  TLatex* logo = new TLatex(.88, .85,  JPAC.c_str());
  logo->SetNDC();
  logo->SetTextSize(2/30.);
  logo->SetTextAlign(32);
  logo->Draw();
};

#endif
