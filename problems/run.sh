
rm ./build/solution
cmake -S . -B build
cmake --build build
./build/solution
