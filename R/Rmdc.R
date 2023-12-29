#' Maximo Divisor Comum
#'
#' @param a Um valor (int)
#' @param b Um valor (int)
#'
#' @return The mdc entre a e b
#' @export
r_mdc <- function(a, b) {
  if (a == b)
    b
  else
    r_mdc(b %% a, a)
}
