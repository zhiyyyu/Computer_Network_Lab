# CMakeList.txt: Lab1 的 CMake 项目，在此处包括源代码并定义
# 项目特定的逻辑。
#
cmake_minimum_required (VERSION 3.8)

project ("Lab1")

include_directories(inc)
include_directories(inc/json)

link_directories(${PROJECT_SOURCE_DIR}/lib)
link_libraries(jsoncpp_static)

add_executable (Lab1
	Lab1.cpp
	src/Config.cpp
	src/Winsock.cpp
	src/Server.cpp)

target_link_libraries(Lab1
	-lwsock32
	-lpthread
	jsoncpp_static
)
