cmake_minimum_required(VERSION 3.10)

# set the project name
project(Tpython VERSION 1.1)


message("${CMAKE_C_COMPILER_VERSION}")

# specify the C standard
set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)
set(CMAKE_BUILD_TYPE DEBUG)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall -Wall -Werror -Wshadow -Wdouble-promotion -Wformat -Wformat -Wformat-overflow -Wformat-truncation -Wundef -fno-common -Wconversion -ffunction-sections -Wpadded -g3")
#set(CMAKE_CXX_FLAGS_DEBUG "${CMAKE_C_FLAGS_DEBUG} 
#-Wall -Wextra -Werror -Wshadow -Wdouble-promotion -Wformat -Wformat -Wformat-overflow -Wformat-truncation 
#-Wundef -fno-common -Wconversion -ffunction-sections -Wpadded -g3")

# add the executable
add_executable(Main src/main.cpp)

