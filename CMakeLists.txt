cmake_minimum_required(VERSION 3.5)

project(VGTU_Practical_3)
add_definitions(-W -Wall -Wextra -Wfatal-errors -Wpedantic -ansi -g)
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_INCLUDE_CURRENT_DIR ON)
set(THREADS_PREFER_PTHREAD_FLAG ON)
include(${CMAKE_BINARY_DIR}/conanbuildinfo.cmake)
conan_basic_setup()

set(SFML_STATIC_LIBRARIES FALSE)
find_package(SFML 2.5.1 REQUIRED COMPONENTS audio graphics window system)

#
# Errors Sources & Inc
#

set(ERRORS_INC
    ./Sources/Errors/
)

set(ERRORS_SRC
    ./Sources/Errors/IError.cpp
    ./Sources/Errors/Errors.cpp
)

#
# Engine Sources & Inc
#

set(ENGINE_INC    
  ./Sources/Engine/Window/
  ./Sources/Engine/Event/
  ./Sources/Engine/Shape/
  ./Sources/Engine/Shape/RectangleShape/
  ./Sources/Engine/Shape/CircleShape/
  ./Sources/Engine/Shape/RoundedRectangleShape/
  ./Sources/Engine/Shape/RoundedRectangleShape/SfmlOverload/
  ./Sources/Engine/Text/
  ./Sources/Engine/Button/
  ./Sources/Engine/Button/RectangleShapeButton/
  ./Sources/Engine/Button/RoundedRectangleShapeButton/
)

set(ENGINE_SRC    
    ./Sources/Engine/Window/Window.cpp
    ./Sources/Engine/Event/Event.cpp
    ./Sources/Engine/Shape/RectangleShape/RectangleShape.cpp
    ./Sources/Engine/Shape/CircleShape/CircleShape.cpp
    ./Sources/Engine/Shape/RoundedRectangleShape/RoundedRectangleShape.cpp
    ./Sources/Engine/Shape/RoundedRectangleShape/SfmlOverload/SfmlRoundedRectangleShape.cpp
    ./Sources/Engine/Text/Text.cpp
    ./Sources/Engine/Button/RectangleShapeButton/RectangleShapeButton.cpp
    ./Sources/Engine/Button/RoundedRectangleShapeButton/RoundedRectangleShapeButton.cpp
)

#
# Project Sources & Inc
#

set(GAME_INC
    ./Sources/Core/
    ./Sources/Collections/
)

set(GAME_SRC
    ./Sources/Main/Main.cpp
    ./Sources/Core/Core.cpp
    ./Sources/Collections/Collections.cpp
)

add_executable(VGTU_Practical_3 ${ERRORS_SRC} ${ENGINE_SRC} ${SHARED_SRC} ${GAME_SRC})
target_include_directories(VGTU_Practical_3 PUBLIC ${ERRORS_INC} ${ENGINE_INC} ${SHARED_INC} ${GAME_INC})
if(SFML_FOUND)
  target_include_directories(VGTU_Practical_3 PUBLIC ${SFML_INCLUDE_DIRS})
  target_link_libraries(VGTU_Practical_3 PUBLIC ${SFML_LIBRARIES} ${SFML_DEPENDENCIES} sfml-graphics sfml-audio sfml-window sfml-system)
endif()
