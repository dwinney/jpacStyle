// The OFFICIAL JPAC graphing style for ROOT
//
// Author:       Daniel Winney (2020)
// Affiliation:  Joint Physics Analysis Center (JPAC)
// Email:        dwinney@iu.edu
// -----------------------------------------------------------------------------

#include "jpacPlot.hpp"

// -----------------------------------------------------------------------------
// JPAC Color Palette
Int_t jpacPlot::kjpacBlue = TColor::GetFreeColorIndex();
TColor * jpacPlot::jpacBlue = new TColor(kjpacBlue, 0.12156862745098039, 0.4666666666666667, 0.7058823529411765);

Int_t jpacPlot::kjpacRed = TColor::GetFreeColorIndex();
TColor * jpacPlot::jpacRed = new TColor(kjpacRed, 0.8392156862745098, 0.15294117647058825, 0.1568627450980392);

Int_t jpacPlot::kjpacGreen = TColor::GetFreeColorIndex();
TColor * jpacPlot::jpacGreen = new TColor(kjpacGreen, 0.0, 0.6196078431372549, 0.45098039215686275);

Int_t jpacPlot::kjpacOrange = TColor::GetFreeColorIndex();
TColor * jpacPlot::jpacOrange = new TColor(kjpacOrange, 0.8823529411764706, 0.4980392156862745, 0.054901960784313725);

Int_t jpacPlot::kjpacPurple = TColor::GetFreeColorIndex();
TColor * jpacPlot::jpacPurple = new TColor(kjpacPurple, 0.5803921568627451, 0.403921568627451, 0.7411764705882353);

Int_t jpacPlot::kjpacBrown = TColor::GetFreeColorIndex();
TColor * jpacPlot::jpacBrown = new TColor(kjpacBrown, 0.5490196078431373, 0.33725490196078434, 0.29411764705882354);

Int_t jpacPlot::kjpacPink = TColor::GetFreeColorIndex();
TColor * jpacPlot::jpacPink = new TColor(kjpacPink, 0.8901960784313725, 0.4666666666666667, 0.7607843137254902);

Int_t jpacPlot::kjpacGold = TColor::GetFreeColorIndex();
TColor * jpacPlot::jpacGold = new TColor(kjpacGold, 0.7372549019607844, 0.7411764705882353, 0.13333333333333333);

Int_t jpacPlot::kjpacAqua = TColor::GetFreeColorIndex();
TColor * jpacPlot::jpacAqua = new TColor(kjpacAqua, 0.09019607843137255, 0.7450980392156863, 0.8117647058823529);

Int_t jpacPlot::kjpacGrey = TColor::GetFreeColorIndex();
TColor * jpacPlot::jpacGrey = new TColor(kjpacGrey, 0.4980392156862745, 0.4980392156862745, 0.4980392156862745);

std::vector<Int_t> jpacPlot::jpacColors = {kjpacBlue, kjpacRed, kjpacGreen,
                                kjpacOrange, kjpacPurple, kjpacBrown,
                                kjpacPink, kjpacGold, kjpacAqua, kjpacGrey};

std::string jpacPlot::JPAC_BW = "#scale[1.3]{#font[72]{J}^{#font[112]{PAC}}}";

std::string jpacPlot::JPAC = "#scale[1.3]{#font[72]{#color[" + std::to_string(kjpacBlue) + "]{J}}"
                            + "^{#font[112]{" + "#color[" + std::to_string(kjpacBlue) + "]{P}"
                            + "#color[" + std::to_string(kjpacRed) + "]{A}"
                            + "#color[" + std::to_string(kjpacBlue) + "]{C}"
                            + "}}}";
