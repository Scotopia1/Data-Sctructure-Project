cmake_minimum_required (VERSION 3.30)
project (untitled2)

set (CMAKE_CXX_STANDARD 20)

add_executable (untitled2 main.cpp
                DynamicArrayList.cpp
                DynamicArrayList.h
                FileHandler.cpp
                FileHandler.h
                MenuItem.cpp
                MenuItem.h
                Order.cpp
                Order.h
                Queue.cpp
                Queue.h
                README.md
                Stack.cpp
                Stack.h
                menu.txt)
