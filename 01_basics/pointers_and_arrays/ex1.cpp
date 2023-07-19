#include <iostream>
#include <type_traits>

// #include <cstdlib>
// #include <memory>
#include <cxxabi.h>

using namespace std;

std::string demangle(const char* name) {

    int status = -4; // some arbitrary value to eliminate the compiler warning

    // enable c++11 by passing the flag -std=c++11 to g++
    std::unique_ptr<char, void(*)(void*)> res {
        abi::__cxa_demangle(name, NULL, NULL, &status),
        std::free
    };

    return (status==0) ? res.get() : name ;
}

int main(int argc, char* argv[]) {


    // create an array of char*
    char const* pArray[2];

    pArray[0] = "Hello?";
    pArray[1] = "World?";
    pArray[2] = "Problem";

    // cout << "Size: " << size_t(char* [2]) << endl;
    cout << pArray[0] << endl;
    cout << pArray[1] << endl;
    cout << pArray[2] << endl;


    cout << "typeid(pArray)? " << typeid(pArray).name() << " (" << demangle(typeid(pArray).name()) << ")" << endl;
    cout << "typeid(pArray[0])? " << typeid(pArray[0]).name() << " (" << demangle(typeid(pArray[0]).name()) << ")" << endl;
    cout << "typeid(pArray[0][0])? " << typeid(pArray[0][0]).name() << " (" << demangle(typeid(pArray[0][0]).name()) << ")" << endl;

    cout << "char* [2] == pArray? " << (is_same<char* [2], decltype(pArray)>::value ? "Yes" : "No") << endl;
    cout << "char* == pArray[0]? " << (is_same<char*, decltype((pArray[0]))>::value ? "Yes" : "No") << endl;

    double a = 0;
    cout << "double == a? " << (is_same<double, decltype(a)>::value ? "Yes" : "No") << endl;
    cout << "int == a? " << (is_same<int, decltype(a)>::value ? "Yes" : "No") << endl;

    return 0;
}