#' Simulation of the likelihood
#'
#' @param logr log of r param (dbl)
#' @param n Number of steps (int)
#' @param nsim Simulation's number (int)
#' @param sigma_true The true sigma value (dbl)
#'
#' @return The likelihood (dbl)
#' @export
simulate_likelihood <- function(logr, n, nsim, sigma_true) {
  r <- exp(logr)
  s1 <- numeric(nsim)
  s2 <- numeric(nsim)
  y0 <- stats::runif(nsim, 1, 10)

  for(i in 1:nsim) {
    ysim <- ricker_simulation(n, nburn, r, y0[i]) *
      exp(stats::rnorm(n, 0, sigma_true))
    s1[i] <- mean(ysim)
    s2[i] <- stats::sd(ysim)
  }

  out <- stats::dnorm(mean(ysim), mean(s1), stats::sd(s1), log = TRUE) +
    stats::dnorm(mean(ysim), mean(s2), stats::sd(s2), log = TRUE)

  return(out)
}

