cmake_minimum_required(VERSION 3.15)
project(guess_game)

set(CMAKE_CXX_STANDARD 17)

include(FetchContent)
FetchContent_Declare(ftxui
  GIT_REPOSITORY https://github.com/ArthurSonzogni/FTXUI.git
  GIT_TAG main
)
FetchContent_MakeAvailable(ftxui)

add_executable(guess_game main.cpp)
target_link_libraries(guess_game
  PRIVATE ftxui::screen
  PRIVATE ftxui::dom
  PRIVATE ftxui::component
)