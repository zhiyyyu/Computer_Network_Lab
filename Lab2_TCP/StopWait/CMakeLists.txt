cmake_minimum_required(VERSION 3.10)

project(StopWait)

add_definitions(-std=c++11)
set(CMAKE_CXX FLAGS -fexec-charset=GBK)

include_directories(
        include
)

add_executable(StopWait
        src/StopWait.cpp
        src/StopWaitRdtReceiver.cpp
        src/StopWaitRdtSender.cpp
        src/GBNRdtSender.cpp
        src/GBNRdtReceiver.cpp
        )

set(EXECUTABLE_OUTPUT_PATH ${PROJECT_SOURCE_DIR}/bin)

target_link_libraries(StopWait
        -lnetsim
        )