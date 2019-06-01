cmake_minimum_required(VERSION 3.6)
project(Card)

set(CMAKE_CXX_STANDARD 11)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall -std=c++0x")

# 引入子目录
ADD_SUBDIRECTORY(MonteCarlo)
ADD_SUBDIRECTORY(Test)
ADD_SUBDIRECTORY(SameProbability)
ADD_SUBDIRECTORY(DynamicPogramming)