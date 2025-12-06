cmake -S . -B build -DSDL_SHARED=ON -DSDL_STATIC=OFF -DCMAKE_BUILD_TYPE=Debug

cd build

cmake --build . -j 4
