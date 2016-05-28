plotSensorData <- function(filename) {
  temp <- read.csv("logs-011522-good-1-sensor.log")
  par(mfrow=c(2,1),oma=c(0,0,2,0))
  plot(temp[,1],type="h")
  plot(temp[,2],type="h")
  title("1 good", outer=T)

}