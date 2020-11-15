set(Sources
  main.cpp
)

set(Headers
)

add_library(mainTests STATIC ${Sources} ${Headers})

add_executable(Battleship ${Sources} ${Headers})

