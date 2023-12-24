
#' Smooth a time series
#'
#' @description
#' A function to smooth a time series
#'
#' @param y Time series to be smoothed
#' @param a Smooth parameter
#'
#' @return A time series smoothed from `y`
#' @export
exp_smooth <- function(y, a) {
  .Call(
    "exp_smooth_c",
    as.double(y),
    as.double(a)
  )
}
