cmake_minimum_required(VERSION 3.0.0)

set(This main)

set(Sources
  main.cpp
  CursesUtils.cpp
)

set(Headers
  CursesUtils.hpp
)

add_library(mainTests STATIC ${Sources} ${Headers})

add_executable(${This} ${Sources} ${Headers})