cmake_minimum_required(VERSION 3.17)
project(Caso_final)

set(CMAKE_CXX_STANDARD 14)

add_executable(Caso_final
    main.cpp
        "Language/type.h"
        "Language/environment.h"
        "Language/parser.h"
        "Language/evaluator.h"
        "Language/main.cpp"
        Modules/Module.h
        Modules/MathModule.h
        Modules/DBModule.h
        Modules/ModuleManager.h
        Modules/main.cpp
)
