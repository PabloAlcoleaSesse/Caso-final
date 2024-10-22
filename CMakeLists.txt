cmake_minimum_required(VERSION 3.29)
project(Caso_final)

set(CMAKE_CXX_STANDARD 14)

add_executable(Caso_final
    main.cpp
"Framework/ColorManager.h"
"Framework/EventManager.h"
"Framework/FileManager.h")
