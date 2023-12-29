#include <Rcpp.h>
#include <numeric>
#include <boost/integer/common_factor_rt.hpp>

using namespace Rcpp;

//' Maximo Divisor Comum
//'
//' @param a Um valor (int)
//' @param b Umm valor (int)
//' @return O MDC entre `a` e `b`
//' @useDynLib packageC, .registration = TRUE
//' @importFrom Rcpp evalCpp
//' @export
// [[Rcpp::export]]
int rcpp_mdc (int& a, int& b) {
  return std::gcd(a, b);
}
