cmake_minimum_required(VERSION 3.6)
project(M_Extraction)

set(CMAKE_CXX_STANDARD 14)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall -std=c++0x")

# 引入子目录
ADD_SUBDIRECTORY(MonteCarlo)
ADD_SUBDIRECTORY(SameProbability)
ADD_SUBDIRECTORY(DynamicPogramming)
ADD_SUBDIRECTORY(FFT)