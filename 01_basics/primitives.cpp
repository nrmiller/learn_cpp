#include <iostream>

using namespace std;

int main(int argc, char* argv[]) {

    bool isComplete = false;
    cout << "isComplete: " << boolalpha << isComplete << noboolalpha << " (size = " << sizeof(isComplete) << ")" << endl;

    int number = 0;
    cout << "sizeof(number) = " << sizeof(number) << ", sizeof(int) = " << sizeof(int) << endl;

    cout << "sizeof(char) = " << sizeof(char) << endl;
    cout << "sizeof(int) = " << sizeof(int) << endl;

    // short == short int
    cout << "sizeof(short) = " << sizeof(short) << endl;
    cout << "sizeof(short int) = " << sizeof(short int) << endl;

    // long == long int
    cout << "sizeof(long) = " << sizeof(long) << endl;
    cout << "sizeof(long int) = " << sizeof(long int) << endl;
    
    cout << "sizeof(float) = " << sizeof(float) << endl;
    cout << "sizeof(double) = " << sizeof(double) << endl;
    cout << "sizeof(long double) = " << sizeof(long double) << endl;

    cout << "sizeof(wchar_t) = " << sizeof(wchar_t) << endl;

    const wchar_t* str = L"Hello world!\n";
    wprintf(str);

    const char16_t* str1 = u"Hello world!\n";
    const char32_t* str2 = U"Hello world!\n";

    return 0;
}