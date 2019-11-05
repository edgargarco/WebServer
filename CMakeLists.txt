cmake_minimum_required(VERSION 3.15)
project(MongooseWebServer)

set(CMAKE_CXX_STANDARD 14)
#add_executable(MongooseWebServer cmake-build-debug/src/mongoose.c cmake-build-debug/src/mongoose.h cmake-build-debug/src/main.cpp cmake-build-debug/mongoose/Server.h cmake-build-debug/mongoose/WebController.h  cmake-build-debug/src/hello.cpp)
add_executable(MongooseWebServer cmake-build-debug/src/mongoose.c cmake-build-debug/src/mongoose.h cmake-build-debug/src/main.cpp cmake-build-debug/src/main.cpp)