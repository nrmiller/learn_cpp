#include <iostream>

using namespace std;

int main(int argc, char* argv[]) {

    const char* pToConst = "Hello World";

    cout << "Pointer to constant char: \"" << pToConst
        << "\", length=" << strlen(pToConst)
        << endl;

    const char* anotherString = "Goodbye";
    pToConst = anotherString; // legal reassignment since the pointer itself is not constant

    cout << pToConst << endl;

    // pToConst[0] = 'J'; // error #137: expression must be a modifiable lvalue

    char mutableArray[] { "Mutable" };
    char* const constPToC = mutableArray;

    // constPToC = anotherString; // error #137: expression must be a modifiable lvalue
    constPToC[0] = 'J';

    cout << constPToC << endl;

    const char* const constPToConstC { "Fully Immutable" };
    // constPToConstC = anotherString; // error #137: expression must be a modifiable lvalue
    // constPToConstC[0] = 'J';

    cout << constPToConstC << endl;

    return 0;
}
