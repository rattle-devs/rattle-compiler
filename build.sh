export BUILD_TYPE="DEBUG"
cmake -B ./build -DCMAKE_BUILD_TYPE=$BUILD_TYPE
cmake --build ./build --config $BUILD_TYPE
cd build/
ctest -C $BUILD_TYPE
