cmake_minimum_required(VERSION 3.29)
project(MEPHI_LABBbs)

set(CMAKE_CXX_STANDARD 14)

include_directories(.)


add_executable(MEPHI_LABBbs
    ArraySequence.h
    DinamicArray.h
    exeption.h
    ImmutableArraySequence.h
    ImmutableListSequence.h
    LinkedList.h
    ListSequence.h
 #   main.cpp
    Sequence.h
    tests.cpp
    #UI.cpp
    #UI.h)
)
target_link_libraries(MEPHI_LABBbs PRIVATE gtest ${wxWidgets_LIBRARIES})