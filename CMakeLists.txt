cmake_minimum_required(VERSION 3.7)
project(ImageFiltersAndDFT)

find_package(OpenCV REQUIRED)
include_directories(${OpenCV_INCLUDE_DIRS})

set(CMAKE_CXX_STANDARD 14)

set(SOURCE_FILES main.cpp BoxFilter.cpp BoxFilter.h GaussianFilter.cpp GaussianFilter.h Gaussian2D_ZeroMeanDiagonalCov.cpp Gaussian2D_ZeroMeanDiagonalCov.h MedianFilter.cpp MedianFilter.h MyUtilityOpenCV.h MyUtilityOpenCV.cpp BilateralFilter.cpp BilateralFilter.h Gaussian1D_ZeroMean.cpp Gaussian1D_ZeroMean.h)
add_executable(ImageFiltersAndDFT ${SOURCE_FILES})

target_link_libraries(ImageFiltersAndDFT ${OpenCV_LIBS} )