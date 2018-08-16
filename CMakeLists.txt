cmake_minimum_required(VERSION 3.10)
project(lisa)

set(CMAKE_CXX_STANDARD 17)

add_executable(lisa main.cpp src/LLexer.cpp src/LLexer.h src/LToken.cpp src/LToken.h src/LParser.cpp src/LParser.h src/LNodeType.h)
