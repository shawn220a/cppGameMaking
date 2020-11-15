set(Sources
  main.cpp
  Utils/Utils.cpp
)

set(Headers
  Utils/Utils.hpp
)

add_library(mainTests STATIC ${Sources} ${Headers})

add_executable(Battleship ${Sources} ${Headers})

