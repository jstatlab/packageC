#include <Rcpp.h>
#include <numeric>
#include <boost/integer/common_factor_rt.hpp>
// [[Rcpp::plugins("cpp11")]]
// [[Rcpp::plugins("cpp17")]]
// [[Rcpp::depends(BH)]]

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
int boost_mdc (int& a, int& b) {
  return boost::integer::gcd(a, b);
}
