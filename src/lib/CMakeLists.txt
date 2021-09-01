add_subdirectory(utils)
add_library (libs null.cpp)
target_link_libraries(libs PUBLIC Utils)