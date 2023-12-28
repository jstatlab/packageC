#define R_NO_REMAP
#include <R.h>
#include <Rinternals.h>
#include <Rmath.h>
#include <stdlib.h>

SEXP mean_var_krs_c (SEXP y_, SEXP x_, SEXP x0_, SEXP lambda_) {

  // C objects to match with SEXP parameters
  double *y, *x, *x0, lambda;
  int n, n0;
  double *mu, *out, *w, *res, num, denom, mean_w = 0.0;

  // R objects
  SEXP mu_, out_, w_, res_;

  // Casting R objects
  x_  = PROTECT(Rf_coerceVector(x_, REALSXP));
  y_  = PROTECT(Rf_coerceVector(y_, REALSXP));
  x0_ = PROTECT(Rf_coerceVector(x0_, REALSXP));

  // R -> C (scalars)
  lambda = REAL(lambda_)[0];

  // Lengths
  n = Rf_length(x_);
  n0 = Rf_length(x0_);

  // Allocating R objects
  mu_  = PROTECT(Rf_allocVector(REALSXP, n));
  out_ = PROTECT(Rf_allocVector(REALSXP, n0));
  w_   = PROTECT(Rf_allocVector(REALSXP, n0));
  res_ = PROTECT(Rf_allocVector(REALSXP, n));

  // R -> C (vectors)
  mu = REAL(mu_);
  out = REAL(out_);
  w = REAL(w_);
  res = REAL(res_);
  x = REAL(x_);
  y = REAL(y_);
  x0 = REAL(x0_);

  for (int i = 0; i < n; ++i) {
    num = 0.0;
    denom = 0.0;
    for (int j = 0; j < n; ++j) {
      num += dnorm4(x[j], x[i], lambda, 0) * y[j];
      denom += dnorm4(x[j], x[i], lambda, 0);
    }
    mu[i] = num / denom;
    res[i] = ((y[i] - mu[i]) >= 0) ? (y[i] - mu[i]) : (mu[i] - y[i]);
  }

  for (int i = 0; i < n0; ++i) {
    num = 0.0;
    denom = 0.0;
    for (int j = 0; j < n; ++j) {
      num += dnorm4(x[j], x0[i], lambda, 0) * res[j];
      denom += dnorm4(x[j], x0[i], lambda, 0);
    }
    // lambda_hat[i] = num / denom;
    w[i] = denom / num;
    mean_w += w[i];
  }

  mean_w /= n0;
  for(int i = 0; i < n0; ++i) {
    w[i] /= mean_w;
  }

  for (int i = 0; i < n0; ++i) {
    num = 0.0;
    denom = 0.0;
    for (int j = 0; j < n; ++j) {
      num += dnorm4(x[j], x0[i], lambda * w[i], 0) * y[j];
      denom += dnorm4(x[j], x0[i], lambda * w[i], 0);
    }
    out[i] = num / denom;
  }
  UNPROTECT(7);

  return out_;
}
