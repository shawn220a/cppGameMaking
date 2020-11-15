set(Sources
  main.cpp
  Utils/Utils.cpp
  Boards/Boards.cpp
  Players/Players.cpp
  Ships/Ships.cpp
)

set(Headers
  Utils/Utils.hpp
  Boards/Boards.hpp
  Players/Players.hpp
  Ships/Ships.hpp
)

add_library(mainTests STATIC ${Sources} ${Headers})

add_executable(Battleship ${Sources} ${Headers})
