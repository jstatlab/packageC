#' Adaptative Kernel Regression Smoothing Bandwidth Estimation
#'
#' Model a kernel regression model smoother (KRS) based on a normal distribution
#' and bandwidth estimation.
#' @param y A vector (dbl)
#' @param x A vector (dbl)
#' @param x0 A vector (dbl)
#' @param lambda Bandwidth (dbl)
#'
#' @return A fitted model based on KRS method with bandwidth estimation
#' @examples
#' set.seed(998)
#' nobs <- 200
#' x <- runif(nobs)
#' y <- sin(4*pi*x^3) + rnorm(nobs, 0, 0.2)
#' plot(x, y)
#' x0 <- seq(0, 1, length.out = 1000)
#' fit1 <- mean_var_krs(y, x, x0, 0.01)
#' fit2 <- mean_var_krs(y, x, x0, 0.03)
#' fit3 <- mean_var_krs(y, x, x0, 0.06)
#' plot(x, y, col = "grey")
#' lines(x0, fit1, col = 2)
#' lines(x0, fit2, col = 4)
#' lines(x0, fit3, col = 1)
#' @export
mean_var_krs <- function(y, x, x0, lambda) {
  .Call(
    "mean_var_krs_c",
    as.double(y),
    as.double(x),
    as.double(x0),
    as.double(lambda)
  )
}
