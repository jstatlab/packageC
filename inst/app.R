library(shiny)

run_app <- function() {
  shinyApp(
    ui = fluidPage(
      sidebarLayout(
        sidebarPanel(
          wellPanel(
            sliderInput(
              inputId = "n",
              label = "Size",
              min = 100,
              max = 100000,
              value = 1000,
              step = 1
            )
          ),
          wellPanel(
            sliderInput(
              inputId = "smooth",
              label = "Smooth",
              min = 0,
              max = 0.99,
              value = 0.8,
              step = 0.01
            )
          )
        ),

        mainPanel(
          plotOutput(outputId = "plot")
        )
      )
    ),

    server = function(input, output, session) {
      output$plot <- renderPlot({
        y <- cumsum(rnorm(n = input$n))
        plot(y, col = "gray80")
        lines(exp_smooth(y, input$smooth), col = "red")
      })
    }
  )
}
