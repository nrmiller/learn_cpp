#include <iostream>

using namespace std;


template <typename T>
void print(T value)
{
    std::cout << value << std::endl;
}

template <typename T, int iterations>
void printMany(T value)
{
    for (int i = 0; i < iterations; i++)
    {
        print(value);
    }
}

int main(int argc, char* argv[]) {

    // Using the same print function, print different types of data:
    //
    print<int>(3);
    print<const char*>("Hello");
    print<float>(3.14159f);

    // Template parameter types can be inferred for function templates when the parameter type
    // can be deduced from the function arguments:
    //
    print(3);
    print("Hello");
    print(3.14159f);

    // Templates also support non-type parameters:
    //
    printMany<const char*, 3>("This is a warning!");
}