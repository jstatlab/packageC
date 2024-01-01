#include <packagec_arma.h>

//' @title Generate Random Wishart Distribution
//' @description Creates a random wishart distribution when given degrees of freedom and a sigma matrix.
//' @param df An \code{int}, which gives the degrees of freedom of the Wishart (df > 0).
//' @param S An \code{matrix} with dimensions m x m that provides Sigma, the covariance matrix.
//' @return A \code{matrix} that is a Wishart distribution, aka the sample covariance matrix of a Multivariate Normal Distribution.
//' @seealso \code{\link{riwishart}}
//' @useDynLib packageC, .registration = TRUE
//' @importFrom Rcpp evalCpp
//' @export
// [[Rcpp::export]]
arma::mat rwishart (unsigned int df, const arma::mat& S) {
  // Dimension of returned Wishart
  unsigned int m = S.n_rows;

  // Z composition:
  // sqrt chisqs on diagonal
  // random normals bellow diagonal
  // misc above diagonal
  arma::mat Z(m, m);

  // Fill the diagonal
  for (unsigned int i = 0; i < m; ++i) {
    Z(i,i) = sqrt(R::rchisq(df - i));
  }

  // Fill the lower matrix with random guesses
  for (unsigned int j = 0; j < m; ++j) {
    for (unsigned int i = j+1; i < m; ++i) {
      Z(i,j) = R::rnorm(0, 1);
    }
  }

  // Lower triangle * chol decomp
  arma::mat C = arma::trimatl(Z).t() * arma::chol(S);

  return C.t()*C;
}

//' @title Generate Random Inverse Wishart Distribution
//' @description Creates a random inverse wishart distribution when given degrees of freedom and a sigma matrix.
//' @param df An \code{int} that represents the degrees of freedom (df > 0).
//' @param S A \code{matrix} with dimensions m x m that provides Sigma, the covariance matrix.
//' @return A \code{matrix} that is an inverse wishart distribution.
//' @seealso \code{\link{rwishart}}
//' @useDynLib packageC, .registration = TRUE
//' @importFrom Rcpp evalCpp
//' @export
// [[Rcpp::export]]
arma::mat riwishart (unsigned int df, const arma::mat S) {
  return rwishart(df, S.i()).i();
}

