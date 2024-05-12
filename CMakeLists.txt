cmake_minimum_required(VERSION 3.0)
project(simplePlot)

add_executable(firstPlot firstPlot.cpp)

add_subdirectory(matplotplusplus)

target_link_libraries(firstPlot PUBLIC matplot)
