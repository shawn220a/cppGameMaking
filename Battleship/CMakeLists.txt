cmake_minimum_required(VERSION 3.0.0)
project(Battleship VERSION 0.1.0)

enable_testing()

# Add google test to lib folder and uncomment testing comments
#add_subdirectory(lib/googletest)

add_subdirectory(src) # Change project name in src directory

# add_subdirectory(test)