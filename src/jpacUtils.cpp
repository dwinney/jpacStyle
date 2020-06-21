// Misc utilities i have found useful to have
//
// Author:       Daniel Winney (2020)
// Affiliation:  Joint Physics Analysis Center (JPAC)
// Email:        dwinney@iu.edu
// -----------------------------------------------------------------------------

#include "jpacUtils.hpp"

// -----------------------------------------------------------------------------
// Functions to italicize and bold
std::string ROOT_italics(std::string in)
{
  return "#font[12]{" + in + "}";
};

std::string ROOT_bold(std::string in)
{
  return "#font[22]{" + in + "}";
};

std::string ROOT_bold_italics(std::string in)
{
  return "#font[32]{" + in + "}";
};

// -----------------------------------------------------------------------------
// Function to parse a string to specify y range at command line
// input of the form : "[y1:y2]"
void y_range(std::string input, double * output)
{
  std::string delimiter = ":";
  size_t pos = input.find(delimiter);

  std::string y1, y2;
  y1 = input.substr(1, pos);
  y2 = input.substr(pos + 1, input.length() - 1);

  output[0] = std::stod(y1);
  output[1] = std::stod(y2);
};

// Utility functions that take in a vector of complex<doubles> and return vector<double>s of the same size
// containing only the real or imaginary parts.
//-----------------------------------------------------------------------------
std::vector<double> vec_real(std::vector<std::complex<double>> fx)
{
  std::vector<double> result;
  for (int i = 0; i < fx.size(); i++)
  {
    result.push_back(real(fx[i]));
  }

  // Quick Error check
  if (result.size() != fx.size())
  {
    std::cout << "vec_real: ERROR Output and Input vector sizes dont match. Quitting... \n";
    std::exit(1);
  }

  return result;
};

std::vector<double> vec_imag(std::vector<std::complex<double>> fx)
{
  std::vector<double> result;
  for (int i = 0; i < fx.size(); i++)
  {
    result.push_back(imag(fx[i]));
  }

  // Quick Error check
  if (result.size() != fx.size())
  {
    std::cout << "vec_imag: ERROR Output and Input vector sizes dont match. Quitting... \n";
    std::exit(1);
  }

  return result;
};

std::array<std::vector<double>, 2> vec_fill(int N, std::function<double(double)> f, double min, double max, bool DEBUG)
{
  std::vector<double> fx, x;
  for (int i = 0; i <= N; i++)
  {
    double xi = min + double(i) * (max - min) / double(N);
    x.push_back(xi);

    double fxi = f(xi);
    fx.push_back(fxi);

    if (DEBUG == true)
    {
      std::cout << std::left << std::setw(5) << i;
      std::cout << std::setw(15) << xi;
      std::cout << std::setw(15) << fxi << std::endl;
    }
  }

  return {x, fx};
};

std::tuple<std::vector<double>, std::vector<std::complex<double>>> vec_fillc(int N, std::function<std::complex<double>(double)> f, double min, double max)
{
  std::vector<double> x;
  std::vector<std::complex<double>> fx;
  for (int i = 0; i <= N; i++)
  {
    double xi = min + double(i) * (max - min) / double(N);
    x.push_back(xi);

    std::complex<double> fxi = f(xi);
    fx.push_back(fxi);
  }

  return std::make_tuple(x, fx);
};
