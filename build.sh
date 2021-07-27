export BUILD_TYPE="PRODUCTION"
cmake -B ./Build -DCMAKE_BUILD_TYPE=$BUILD_TYPE
cmake --build ./Build --config $BUILD_TYPE
cd Build/
ctest -C $BUILD_TYPE
