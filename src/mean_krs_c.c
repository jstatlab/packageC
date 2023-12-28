#define R_NO_REMAP
#include <R.h>
#include <Rinternals.h>
#include <Rmath.h>
// #include <stdlib.h>

// https://mfasiolo.github.io/sc2-2019/rcpp/2_exercises/

SEXP mean_krs_c(SEXP y_, SEXP x_, SEXP x0_, SEXP lambda_) {

  // C objects
  double *x, *x0, *y, *out;
  double lambda, num, denom;
  int n, n0;

  // R objects
  SEXP out_;

  // R -> C
  y_ = PROTECT(Rf_coerceVector(y_, REALSXP));

  x_ = PROTECT(Rf_coerceVector(x_, REALSXP));
  n = Rf_length(x_);

  x0_ = PROTECT(Rf_coerceVector(x0_, REALSXP));
  n0 = Rf_length(x0_);

  out_ = PROTECT(Rf_allocVector(REALSXP, n0));

  lambda = REAL(lambda_)[0];
  x = REAL(x_);
  x0 = REAL(x0_);
  y = REAL(y_);
  out = REAL(out_);

  for (int i = 0; i < n0; ++i) {
    num = 0.0;
    denom = 0.0;
    for (int j = 0; j < n; ++j) {
      num += dnorm4(x[j], x0[i], lambda, 0) * y[j];
      denom += dnorm4(x[j], x0[i], lambda, 0);
    }
    out[i] = num / denom;
  }

  UNPROTECT(4);

  return out_;
}


