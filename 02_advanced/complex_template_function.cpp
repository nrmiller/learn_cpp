#include <stdlib.h>
#include <cstdint>
#include <iostream>

typedef uint32_t tw_size_t;

template <size_t nlen>
constexpr tw_size_t read(char*(&aryval)[nlen]);

tw_size_t read(char* buf, size_t len) {
    std::cout << len << std::endl;
    return len; // read everything
}

template <typename T, size_t nlen>
constexpr tw_size_t read(T(&aryval)[nlen]) {
    std::cout << "aryval[" << nlen << "]" << std::endl;
    if constexpr (std::is_standard_layout_v<T>) {
        return read(reinterpret_cast<char*>(aryval), sizeof(T) * nlen);
    }
}

class A {
    uint32_t i;
};

class B : A {
    uint32_t j;
};

int main(int argc, char* argv[]) {

    char array[512];
    
    // Reads up to 512 bytes and stores into array
    //
    read<char, 512>(array);

    // Compiles OK - template parameters can be inferred
    //
    read(array);

    // Reads up to 8192 (2048 x 4) bytes into the array
    //
    uint32_t aryOfInt[2048];
    read(aryOfInt);

    // Compiles OK - A is a standard layout type.
    // Reads up to 40 bytes into the array
    //
    A aryOfA[10];
    read<A, 10>(aryOfA);

    // Fails to Compile - B is not a standard layout type!
    // error C4716: 'read<B,10>': must return a value
    //
    // B aryOfB[10];
    // read<B, 10>(aryOfB);

    return 0;
}