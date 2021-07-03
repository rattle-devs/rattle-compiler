cmake_minimum_required(VERSION 3.10)

# set the project name
project(Tpython VERSION 1.1)

# specify the C standard
#set(CMAKE_C_STANDARD 17)
set(CMAKE_C_STANDARD_REQUIRED ON)
set(CMAKE_C_EXTENSIONS OFF)
set(CMAKE_BUILD_TYPE DEBUG)
set(CMAKE_C_FLAGS_DEBUG "${CMAKE_CXX_FLAGS} -std=c17 -Wall -Wall -Werror -Wshadow -Wdouble-promotion -Wformat -Wformat -Wformat-overflow -Wformat-truncation -Wundef -fno-common -Wconversion -ffunction-sections -Wpadded -g3")


include_directories(${PROJECT_SOURCE_DIR})

# add the executable
add_executable(Main src/lib/vector.c src/lib/utils.c src/token.c src/lexer.c src/tpython.c
	src/main.c)

