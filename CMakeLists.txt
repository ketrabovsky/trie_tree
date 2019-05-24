cmake_minimum_required(VERSION 3.7)

project(program)

set(CMAKE_BINARY_DIR bin)
set(CMAKE_POSITION_INDEPENDENT_CODE ON)
set (CMAKE_CXX_STANDARD 11)

add_subdirectory(googletest)

set(Headers
	Trie_tree.h
	Json.hpp
	fileReader.hpp
	Board.hpp
)

set(Sources
	main.cpp
	Trie_tree.cpp
	Json.cpp
	fileReader.cpp
	Board.cpp
)

enable_testing()

add_library(program STATIC ${Sources} ${Headers})

add_subdirectory(test)

add_executable(programBinary ${Sources} ${Headers})
