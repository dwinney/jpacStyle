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
jpacGraph1D* my_1Dplotter = new jpacGraph1D();

// Add x and f(x) data in a vector and a string for the legend label
my_1Dplotter->AddEntry(vector<double>, vector<double>, string);

// Plot to file
my_1Dplotter->Plot(string);
```
You can add multiple curves (up to 10, because we only have 10 colors defined).

Additional customization can be set up with the previous functions before plotting:
```
// Manually place location of the legend with relative coordinate of the bottom left vertex x and y
my_1Dplotter->SetLegend(double, double);

// Label (units) for x and y axes and upper and lower bounds
my_1Dplotter->SetXaxis(string, double, double);
my_1Dplotter->SetYaxis(string, double, double);
```
Axes labels are TLatex objects and thus follow the same syntax for mathematical symbols (see [doc](https://root.cern.ch/doc/master/classTLatex.html)).

### jpacGraph2D
This object allows yo uto make two-dimensional plots according to JPAC color scheme with minimal ROOT interfacing.

Basic usage is even easier than above since only one function is plottable at once:
```
// Initialize
jpacGraph2D* my_2Dplotter = new jpacGraph2D();

// Add in the x, y, and z data as vectors
my_2Dplotter->AddData(vector<double>, vector<double>, vector<double>);

// Plot to file
my_2Dplotter->Plot(string);
```
As above, additional customization of the axes is available through:
```
// Axis label, minimum and maximum values
my_2Dplotter->SetXaxis(string, double, double);
my_2Dplotter->SetYaxis(string, double, double);
```
### importStyle.C
Alternatively if you want to make the plots manually through ROOT, this macro imports the jpacStyle and jpacColors. Also adds a function `AddLogo()` which adds the collaboration logo in the upper right corner.
Simply load when opening ROOT:
```
root -l importStyle.C
```
