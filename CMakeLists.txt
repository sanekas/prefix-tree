cmake_minimum_required(VERSION 3.12)
project(prefix_tree)

set(CMAKE_CXX_STANDARD 14)

add_executable(prefix_tree PrefixTree.cpp PrefixTree.h NodeArray.h)