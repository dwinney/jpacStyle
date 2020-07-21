// Misc utilities i have found useful to have
//
// Author:       Daniel Winney (2020)
// Affiliation:  Joint Physics Analysis Center (JPAC)
// Email:        dwinney@iu.edu
// -----------------------------------------------------------------------------

#ifndef _JPAC_UTILS_
#define _JPAC_UTILS_

#include <fstream>
#include <iostream>
#include <vector>
#include <complex>
#include <string>
#include <iomanip>
#include <tuple>
#include <array>
#include <functional>

// -----------------------------------------------------------------------------
// Super simple string functions to facilitate bolding and italics
std::string ROOT_italics(std::string in);
std::string ROOT_bold(std::string in);
std::string ROOT_bold_italics(std:: string in);

// Utilities to separate the real and imaginary parts into separate vectors
std::vector<double> vec_real(std::vector<std::complex<double>> fx);
std::vector<double> vec_imag(std::vector<std::complex<double>> fx);

// Parse an input vector of the form "[a:b]"
void y_range(std::string input, double * output);

//-----------------------------------------------------------------------------
// Functions for evaluating a function into vectors

// take in a lambda and output a vector
std::array<std::vector<double>, 2> vec_fill(int N, std::function<double(double)> f, double min, double max, bool DEBUG = false);

// complex version of the above
std::tuple<std::vector<double>, std::vector<std::complex<double>>> vec_fillc(int N, std::function<std::complex<double>(double)> f, double min, double max, bool DEBUG = false);

//-----------------------------------------------------------------------------
// Functions for printing to file

// Output a vector to a file
void vec_print(std::vector<double> x, std::vector<double> fx, std::string filename);

// Take in an ASCII file with two columns, x and f(x). Import values to an array of vectors
std::array<std::vector<double>, 2> vec_read_file(std::string file_path);

#endif