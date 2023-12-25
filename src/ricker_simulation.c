#define R_NO_REMAP
#include <R.h>
#include <Rinternals.h>
#include <Rmath.h>

// https://mfasiolo.github.io/sc2-2019/rcpp/2_exercises/
SEXP ricker_simulation_c (SEXP n_, SEXP nburn_, SEXP r_, SEXP y0_) {

  // C objects
  double *y, yt, r;
  int n, nburn, y0;

  // R object to be returned
  SEXP y_;

  n = INTEGER(n_)[0];
  nburn = INTEGER(nburn_)[0];
  r = REAL(r_)[0];
  y0 = INTEGER(y0_)[0];

  y_ = PROTECT(Rf_allocVector(REALSXP, n));
  y  = REAL(y_);

  yt = y0;

  // Burn in phase
  if (nburn > 0) {
    for (int i = 0 ; i < nburn; ++i) {
      yt = r * yt * exp(-yt);
    }
  }

  // Simulating and storing
  for (int i = 0; i < n ; ++i) {
    yt = r * yt * exp(-yt);
    y[i] = yt;
  }

  UNPROTECT(1);

  return y_;
}
