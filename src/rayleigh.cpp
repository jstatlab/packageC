#include <RcppArmadillo.h>

//' @title Rayleigh's Probability Density Function
//'
//' @description
//' Function to calculate the Rayleigh probability density function
//'
//' @param `x` Value to return its density
//' @param `sigma` The variance associated
//' @return The probability density function of `x`
//' @export
// [[Rcpp::depends(RcppArmadilho)]]
// [[Rcpp::export]]
double f_rayleigh(double x, double sigma) {
  double y = 0;
  if (sigma <= 0.0) {
    throw std::range_error("Inadmissible value");
  }
  y = (x / pow(sigma, 2)) * exp(-pow(x, 2) / 2 * pow(sigma, 2));
  return(y);
}
