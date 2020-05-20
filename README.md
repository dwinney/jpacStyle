# jpacStyle
<p align="center">
  <img width="350" src="./doc/JPAClogo.png">
</p>

Library for making plots in C++/[ROOT](https://root.cern/) for the JPAC Collaboration.

Compile the library with the following command:
```bash
mkdir build
cd build
cmake ..
make
```
This will make `libJpacStyle.a` in the build directory which can be added to `$PATH` for access to the header files.

Alternatively, clone this repo into the working directory of the project you intend to link (or add it as a `git submodule`) and add the following lines to `CMakeList.txt`:
```cmake
# BUILD THE PLOTTING LIBRARY
include_directories("jpacStyle/include")
include_directories("jpacStyle/src")
file(GLOB_RECURSE PLOTINC "jpacStyle/include/*.hpp")
file(GLOB_RECURSE PLOTSRC "jpacStyle/src/*.cpp")
add_library( JpacStyle ${PLOTINC} ${PLOTSRC} )
```
then link to any executable with
```cmake
target_link_libraries( $MY_EXE JpacStyle)
```
For a full example of this see [vector_photoproduction](https://github.com/dwinney/vector_photoproduction). For questions email: *dwinney@iu.edu*.

### jpacGraph1D
This object allows you to easily make one-dimensional plots according to the style and with minimal ROOT syntax.

Basic usage is:
```cpp
// Initialize the object
jpacGraph1D* my_1Dplotter = new jpacGraph1D();

// Add x and f(x) data in a vector and a string for the legend label
my_1Dplotter->AddEntry(std::vector<double> x, std::vector<double> fx, std::string legendTitle);

// Plot to file
my_1Dplotter->Plot(std::string filename);
```
You can add multiple curves (up to 10, because we only have 10 colors defined).

<p align="center">
  <img width="500" src="./doc/colors1.png">
  <img width="500" src="./doc/colors2.png">
</p>

Additional customization can be set up with the previous functions before plotting:
```cpp
// Manually place location of the legend with relative coordinate of the bottom left vertex x and y
my_1Dplotter->SetLegend(double xCord, double yCord);

// Or disable the Legend entirely with
my_1Dplotter->SetLegend(false);

// Add axis labels
my_1Dplotter->SetXaxis(std::string xLabel);
my_1Dplotter->SetYaxis(std::string yLabel);

// The above will set the range of the plot based on the first
// Entry added. To manually fix the range use optional parameters:
my_1Dplotter->SetXaxis(std::string xLabel, double xMin, double xMax);
my_1Dplotter->SetYaxis(std::string yLabel, double yMin, double yMax);
```
Axes labels are TLatex objects and thus follow the same syntax for mathematical symbols (see [doc](https://root.cern.ch/doc/master/classTLatex.html)). For an example script using this object see [bessel.cpp](./examples/bessel.cpp).

<p align="center">
  <img width="500" src="./doc/bessel.png">
</p>

### jpacGraph1Dc
This is operates nearly identical to the above but allows for plotting complex valued function defined on the real line. All the functions available in `jpacGraph1D` are present here except all with the possibility of accepting complex vectors when adding entries:
```cpp
jpacGraph1Dc* my_1Dcplotter = new jpacGraph1Dc();

// Adding complex-valued entry
my_1Dcplotter->AddEntry(std::vector<double> x, std::vector<complex<double>> fx, std::string legendTitle);

// There are now 2 y-axes for the real and imaginary parts
// These are independently customizable with:
my_2Dplotter->SetYRealaxis(std::string yLabel, double yMin, double yMax);
my_2Dplotter->SetYImagaxis(std::string yLabel, double yMin, double yMax);
```
Output is the Real and Imaginary parts plotted seperately in the same file (See [hankel.cpp](./examples/hankel.cpp)).

<p align="center">
  <img width="500" src="./doc/hankel.png">
</p>

### jpacGraph2D
This object allows yo uto make two-dimensional plots according to JPAC color scheme with minimal ROOT interfacing.

Basic usage is even easier than above since only one function is plottable at once:
```cpp
// Initialize
jpacGraph2D* my_2Dplotter = new jpacGraph2D();

// Add in the x, y, and z data as vectors
my_2Dplotter->AddData(std::vector<double> x, std::vector<double> y, std::vector<double>) z;

// Plot to file
my_2Dplotter->Plot(string filename);
```
As above, additional customization of the axes is available through:
```c++
// Axis label, minimum and maximum values
my_2Dplotter->SetXaxis(std::string xLabel, double xMin, double xMax);
my_2Dplotter->SetYaxis(std::string yLabel, double yMin, double yMax);
```
See the example executable [2dgaussian.cpp](./examples/2dgaussian.cpp).

<p align="center">
  <img width="500" src="./doc/2dgaussian.png">
</p>


### importStyle.C
Alternatively if you want to make the plots manually through ROOT, this macro imports the jpacStyle and jpacColors. Also adds a function `AddLogo()` which adds the collaboration logo in the upper right corner.
Simply load when opening ROOT:
```bash
root -l importStyle.C
```
