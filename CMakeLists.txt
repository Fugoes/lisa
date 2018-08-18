cmake_minimum_required(VERSION 3.10)
project(lisa)

set(CMAKE_CXX_STANDARD 17)

add_executable(lisa main.cpp
        src/LToken.cpp src/LToken.h
        src/LLexer.cpp src/LLexer.h
        src/LNode.cpp src/LNode.h src/LNodeType.h
        src/LParser.cpp src/LParser.h)
