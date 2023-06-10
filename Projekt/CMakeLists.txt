cmake_minimum_required(VERSION 3.25)
project(Test)

set(CMAKE_CXX_STANDARD 17)

add_executable(Test main.cpp Course.cpp Material.cpp Lecturer.cpp Student.cpp System.cpp User.cpp VideoConference.cpp)