cmake_minimum_required(VERSION 3.10)

project(StudentuValdymas VERSION 1.0)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED True)

set(SOURCE_FILES
    main.cpp
    studentas.cpp
    studentas.h
    failai.cpp
    failai.h
    mylib.cpp
    mylib.h
    skaidymas.cpp
    skaidymas.h
)

add_executable(studentu_valdymas ${SOURCE_FILES})

install(TARGETS studentu_valdymas DESTINATION bin)
