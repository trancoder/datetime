cmake_minimum_required(VERSION 3.0)
project(BoostAsioExample)

# Set C++ standard
set(CMAKE_CXX_STANDARD 11)

# Add your application files
add_executable(getEpoch getEpoch.cpp)
add_executable(todayDate todayDate.cpp)

