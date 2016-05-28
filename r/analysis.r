setwd("C:/dev/arduino/campusparty/logs")

plotSensorData <- function(filename, title) {
  temp <- read.csv(filename)
  par(mfrow=c(2,1),oma=c(0,0,2,0))
  plot(temp[,1],type="h")
  plot(temp[,2],type="h")
  title(title, outer=T)

}