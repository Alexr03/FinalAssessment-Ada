cmake_minimum_required(VERSION 3.15)
project(StringManipulation)

set(CMAKE_CXX_STANDARD 11)

add_executable(StringManipulation main.cpp Menu.cpp Menu.h Utilities/InputUtilities.cpp Utilities/InputUtilities.h Utilities/StringUtilities.cpp Utilities/StringUtilities.h AnagramSolver.cpp AnagramSolver.h)