cmake_minimum_required(VERSION 3.0.0)

set(This DemoTests)

set(Sources
  DemoTests.cpp
)

add_executable(${This} ${Sources})
target_link_libraries(${This} PUBLIC
  gtest_main
  mainTests
)

add_test(
  NAME ${This}
  COMMAND ${This}
)