set(Sources
  main.cpp
  Utils/Utils.cpp
  Boards/Boards.cpp
)

set(Headers
  Utils/Utils.hpp
  Boards/Boards.hpp
)

add_library(mainTests STATIC ${Sources} ${Headers})

add_executable(Battleship ${Sources} ${Headers})

