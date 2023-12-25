#define R_NO_REMAP
#include <R.h>
#include <Rinternals.h>

// source: https://mfasiolo.github.io/sc2-2019/rcpp/1_r_internals/
// https://stackoverflow.com/questions/42313373/r-cmd-check-note-found-no-calls-to-r-registerroutines-r-usedynamicsymbols
// Sys.setenv(PATH = paste(Sys.getenv("PATH"), "C:/rtools40", "C:/rtools40/mingw64/bin", sep = ";"))

SEXP exp_smooth_c (SEXP y_, SEXP a_) {

  // C objects
  int n;
  double *y, *ys;
  double a;

  // R object
  SEXP ys_;

  y_ = PROTECT(Rf_coerceVector(y_, REALSXP));
  n = Rf_length(y_);
  ys_ = PROTECT(Rf_allocVector(REALSXP, n));

  // Initilize C objects
  a = REAL(a_)[0];    // R -> C:  a_ -> a
  y = REAL(y_);       // R -> C:  y_ -> y
  ys = REAL(ys_);     // R -> C: ys_ -> ys

  ys[0] = y[0];
  for (int i = 1 ; i < n ; ++i) {
    ys[i] = a * ys[i-1] + (1-a) * y[i];
  }

  UNPROTECT(2);

  return ys_;
}
