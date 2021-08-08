cmake_minimum_required(VERSION 3.21)

# set the project name
project(Rattle-compiler VERSION 1.2)

# specify the C standard
set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)
set(CMAKE_CXX_FLAGS_DEBUG "${CMAKE_CXX_FLAGS} -Wall -Wall -Werror -Wshadow -Wdouble-promotion -Wformat -Wformat -Wformat-overflow -Wformat-truncation -Wundef -fno-common -Wconversion -ffunction-sections -Wpadded -g3")

include_directories(${PROJECT_SOURCE_DIR})
include_directories("src/lib/data-types/Vector")

# add the executable
add_executable(rattle src/lib/utils/utils.cpp src/token.cpp src/lexer.cpp src/rattle.cpp
		src/main.cpp)

IF(CMAKE_BUILD_TYPE MATCHES DEBUG)
	enable_testing()
	add_test(NAME Concept COMMAND rattle ${PROJECT_SOURCE_DIR}/examples/concept.rattle)
	add_test(NAME Hello_world COMMAND rattle ${PROJECT_SOURCE_DIR}/examples/hello_world.rattle)
	add_test(NAME Fib COMMAND rattle ${PROJECT_SOURCE_DIR}/examples/fib.rattle)
ENDIF(CMAKE_BUILD_TYPE MATCHES DEBUG)
