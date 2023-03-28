cmake_minimum_required(VERSION 3.0.0)
project(main VERSION 0.1.0)

enable_testing()

include(FetchContent)

FetchContent_Declare(
  googletest
  GIT_REPOSITORY https://github.com/google/googletest.git
  GIT_TAG        MASTER
)

FetchContent_Declare(
  PDCurses
  GIT_REPOSITORY https://github.com/wmcbrine/PDCurses.git
  GIT_TAG        MASTER
)

FetchContent_MakeAvailable(googletest PDCurses)

# find_path(PDC_INCLUDES curses.h)
# find_library(PDC_LIBS pdcurses REQUIRED)

# target_include_directories(${PROJECT} PRIVATE ${PDC_INCLUDES})
# target_link_libraries(${PROJECT} PRIVATE ${PDC_LIBS})

add_subdirectory(src) # Change project name in src directory
add_subdirectory(test)