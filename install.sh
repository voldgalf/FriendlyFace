cmake -S . -B build -DSDL_SHARED=ON -DSDL_STATIC=OFF

cd build

cmake --build . -j 4
