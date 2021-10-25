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
        )

add_executable(GBN
        src/GBN.cpp
        src/GBNRdtSender.cpp
        src/GBNRdtReceiver.cpp
        )

add_executable(SR
        src/SR.cpp
        src/SRRdtReceiver.cpp
        src/SRRdtSender.cpp)

set(EXECUTABLE_OUTPUT_PATH ${PROJECT_SOURCE_DIR}/bin)

target_link_libraries(StopWait
        -lnetsim
        )

target_link_libraries(GBN
        -lnetsim
        )

target_link_libraries(SR
        -lnetsim
        )