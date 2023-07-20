#include <iostream>

using namespace std;

const volatile char& text = "weird"[0];
// const volatile int& number = 0;

// Create a function that instantiates type T
// passing the argument a to the appropriate constructor depending
// on if it is an lvalue or rvalue.
// Perfect forwarding preserves the expression's value category (lvalue vs rvalue)
// as it is passed through intermediary functions.
template <typename T, typename Arg>
T create(Arg&& a) {
    return T(std::forward<Arg>(a)); // outputs (by ref) (by rvalue ref)
    // return T(a); // outputs (by ref) (by ref) - not what we want!
}

// rvalues, generally, are expressions that evaluate to:
// - temporary objects
// - objects without names
// - objects without addresses
// rvalues can only appear on the right hand side of assignment operator

// lvalues have both a name and an address
// they can appear on the left or right hand side of assignment operator
// See: https://www.justsoftwaresolutions.co.uk/cplusplus/core-c++-lvalues-and-rvalues.html

class Inspector {
    public:
        Inspector(const int& id)
            : id(id) {
            cout << "primary (by ref): " << id << endl;
        }

        Inspector(int&& id)
            : id(id) {
            cout << "primary (by rvalue ref): " << id << endl;
        }

    friend ostream& operator<<(ostream& os, const Inspector& inspector);
    
    private:
        int id;
};

ostream& operator<<(ostream& os, const Inspector& inspector) {
    return os << inspector.id;
}

int main(int argc, char* argv[]) {

    // lvalues
    auto five = 5;
    auto myFive = create<Inspector>(five);
    cout << "myFive: " << myFive << endl;

    // rvalues
    auto myFive2 = create<Inspector>(5);
    cout << "myFive2: " << myFive2 << endl;

    auto myTen = create<Inspector>(five + five); // (lvalue + lvalue) is an rvalue
    cout << "myTen: " << myTen << endl;

    cout << text << endl;

    return 0;
}