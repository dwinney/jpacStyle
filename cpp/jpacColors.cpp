// The OFFICIAL JPAC graphing style for ROOT ;P
//
// Author:       Daniel Winney (2020)
// Affiliation:  Joint Physics Analysis Center (JPAC)
// Email:        dwinney@iu.edu
// -----------------------------------------------------------------------------

#include "jpacStyle.hpp"

// -----------------------------------------------------------------------------
// JPAC Color Palette
Int_t jpacGraph::kjpacBlue = TColor::GetFreeColorIndex();
TColor * jpacGraph::jpacBlue = new TColor(kjpacBlue, 0.12156862745098039, 0.4666666666666667, 0.7058823529411765);

Int_t jpacGraph::kjpacRed = TColor::GetFreeColorIndex();
TColor * jpacGraph::jpacRed = new TColor(kjpacRed, 0.8392156862745098, 0.15294117647058825, 0.1568627450980392);

Int_t jpacGraph::kjpacGreen = TColor::GetFreeColorIndex();
TColor * jpacGraph::jpacGreen = new TColor(kjpacGreen, 0.0, 0.6196078431372549, 0.45098039215686275);

Int_t jpacGraph::kjpacOrange = TColor::GetFreeColorIndex();
TColor * jpacGraph::jpacOrange = new TColor(kjpacOrange, 0.8823529411764706, 0.4980392156862745, 0.054901960784313725);

Int_t jpacGraph::kjpacPurple = TColor::GetFreeColorIndex();
TColor * jpacGraph::jpacPurple = new TColor(kjpacPurple, 0.5803921568627451, 0.403921568627451, 0.7411764705882353);

Int_t jpacGraph::kjpacBrown = TColor::GetFreeColorIndex();
TColor * jpacGraph::jpacBrown = new TColor(kjpacBrown, 0.5490196078431373, 0.33725490196078434, 0.29411764705882354);

Int_t jpacGraph::kjpacPink = TColor::GetFreeColorIndex();
TColor * jpacGraph::jpacPink = new TColor(kjpacPink, 0.8901960784313725, 0.4666666666666667, 0.7607843137254902);

Int_t jpacGraph::kjpacGold = TColor::GetFreeColorIndex();
TColor * jpacGraph::jpacGold = new TColor(kjpacGold, 0.7372549019607844, 0.7411764705882353, 0.13333333333333333);

Int_t jpacGraph::kjpacAqua = TColor::GetFreeColorIndex();
TColor * jpacGraph::jpacAqua = new TColor(kjpacAqua, 0.09019607843137255, 0.7450980392156863, 0.8117647058823529);
