cmake_minimum_required(VERSION 3.29)
project(Caso_final)

set(CMAKE_CXX_STANDARD 14)

add_executable(Caso_final
    main.cpp
    Modules/DBModule.h
    Modules/MathModule.h
    Modules/Module.h
    Modules/ModuleManager.h
)
