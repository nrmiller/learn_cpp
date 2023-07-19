#include <iostream>

using namespace std;

int main(int argc, char* argv[]) {

    int number = 1;
    number++;
    cout << "Number is " << number << endl; // Number is 2

    const double account = 10.0;
    //account += 1.0; // error #137: expression must be a modifiable lvalue

    char* text1 = "Hello world?"; // warning: ISO C++11 does not allow conversion from string literal to 'char *'
    //text1[0] = 'J'; // undefined behavior due to modifying a const char[] (the literal is const)

    // This is because string literals are const char[]
    cout << "Type of string literal is: " << typeid("Hello world?").name() << endl;
    char nonConstant[] = { "Hello world?" };
    cout << "Type of nonConstant is: " << typeid(nonConstant).name() << endl;
    // On Apple clang 14.0.0, the types of the constant/non-constant arrays match, this may be
    // different on other C++ implementations.

    // Arrays are mutable!, the intializers copy the string literal
    char text2[] = { "Hello world?" };
    text2[0] = 'J';
    cout << "Text2 is \"" << text2 << "\"" << endl;

    char text3[] { "Hello world!" }; // Preferred: uniform initializer syntax since C++11
    cout << "Text3 is \"" << text3 << "\"" << endl;

    char text4[] = "Hello world!";
    text4[0] = 'J';
    cout << "Text4 is \"" << text4 << "\"" << endl;

    // This array is not mutable!
    const char text5[] { "Hello world!" }; // FYI: array is sized to 13 (12 plus 1 for the null-terminator)
    // text5[0] = 'J'; // error #137: expression must be a modifiable lvalue

    cout << typeid(text5).name() << endl; // A13_c --> 13 element array of chars
    cout << typeid(text5[0]).name() << endl; // c --> char
    cout << "Types are " << (is_same<const char[13], decltype(text5)>() ? "same" : "different") << endl; // same
    cout << "Types are " << (is_same<char[13], decltype(text5)>() ? "same" : "different") << endl; // different

    // char* pText5 = text5; // error #44: a value of type "const char *" cannot be used to initialize an entity of type  "char *"

    return 0;
}