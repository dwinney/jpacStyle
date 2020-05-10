# jpacStyle
Library for making plots in C++/[ROOT](https://root.cern/) for the JPAC Collaboration.

Compile the library with the following command:
```
mkdir build
cd build
cmake ..
make
```
This will make `libJpacStyle.a` in the build directory which can be linked to other code to have access to the header files.

### jpacGraph1D
This object allows you to easily make one-dimensional plots according to the style and with minimal ROOT syntax.

Basic usage is:
```
// Initialize the object
jpacGraph1D* my_plotter = new jpacGraph1D();

// Add x and f(x) data in a vector and a string for the legend label
my_plotter->AddEntry(vector<double>, vector<double>, string);

// Plot to file
my_plotter->Plot(string);
```
You can add multiple curves (up to 10, because we only have 10 colors defined).

Additional customization can be set up with the previous functions before plotting:
```
// Manually place location of the legend with relative coordinate of the bottom left vertex x and y
my_plotter->SetLegend(double, double);

// Label (units) for x and y axes and upper and lower bounds
my_plotter->SetXaxis(string, double, double);
my_plotter->SetYaxis(string, double, double);
```
Axes labels are TLatex objects and thus follow the same syntax for mathematical symbols (see [doc](https://root.cern.ch/doc/master/classTLatex.html)).

### importStyle.C
Alternatively if you want to make the plots manually through ROOT, this macro imports the jpacStyle and jpacColors. Also adds a function `AddLogo()` which adds the collaboration logo in the upper right corner.
