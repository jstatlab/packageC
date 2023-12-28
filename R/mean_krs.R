#' Adaptative Kernel Regression Smoothing
#'
#' Model a kernel regression model moother (KRS) based on a normal distribution.
#' @param y A vector (dbl)
#' @param x A vector (dbl)
#' @param x0 A vector (dbl)
#' @param lambda Bandwidth (dbl)
#'
#' @return A fitted model based on KRS method
#' @examples
#' set.seed(998)
#' nobs <- 200
#' x <- runif(nobs)
#' y <- sin(4*pi*x^3) + rnorm(nobs, 0, 0.2)
#' plot(x, y)
#' x0 <- seq(0, 1, length.out = 1000)
#' fit1 <- mean_krs(y, x, x0, 0.06)
#' fit2 <- mean_krs(y, x, x0, 0.02)
#' plot(x, y, col = "grey")
#' lines(x0, fit1, col = 2)
#' lines(x0, fit2, col = 4)
#'
#' @export
mean_krs <- function(y, x, x0, lambda) {
  .Call(
    "mean_krs_c",
    as.double(y),
    as.double(x),
    as.double(x0),
    as.double(lambda)
  )
}
