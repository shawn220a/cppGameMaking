set(Sources
  main.cpp
  Utils.hpp
)

set(Headers
  Utils.hpp
)

add_library(mainTests STATIC ${Sources} ${Headers})

add_executable(Battleship ${Sources} ${Headers})

