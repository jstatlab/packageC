#' Ricker Simulation Based on Ricker Model
#'
#' @description
#' A function to model population dynamics based on Ricker model
#'
#' @param n Is the total number of time steps to be stored (int)
#' @param nburn Is the initial number of simulations to be discarded before the following iterations (int)
#' @param r Is the growth rate (dbl)
#' @param y0 Is the initial population size (int)
#'
#' @return A tragetory from those parameters
#' @examples
#' nburn <- 100
#' n <- 50
#'
#' y0_true <- 1
#' sig_true <- 0.1
#' r_true <- 10
#'
#' Ntrue <- ricker_simulation(n = n, nburn = nburn, r = r_true, y0 = y0_true)
#' yobs <- Ntrue * exp(rnorm(n, 0, sig_true))
#'
#' plot(yobs, type = 'b')
#' @export
ricker_simulation <- function(n, nburn, r, y0) {
  .Call(
    "ricker_simulation_c",
    as.integer(n),
    as.integer(nburn),
    as.double(r),
    as.integer(y0)
  )
}
