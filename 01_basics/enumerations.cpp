#include <iostream>

using std::cout, std::endl;

enum Color { red = 1, green = 2, blue = 3, yellow, orange, purple };

enum class Day {
    sunday,
    monday,
    tuesday,
    wednesday,
    thursday,
    friday,
    saturday,
};

int main(int argc, char* argv[]) {

    // plan enumerations are basic
    // they can hold integer values
    // and have no ability for finding the runtime type
    // they are type compatible with any integer (or other plain enums)
    Color c {};
    cout << c << endl; // 0

    c = Color::red;
    c = red;
    cout << c << endl; // 1


    // enum classes are preferred:
    // they have rtti
    // they are type compatible only within the enum
    // :: scoping is required
    Day day = Day::wednesday;
    cout << typeid(day).name() << endl;

    day = Day::monday;
    cout << typeid(day).name() << endl;

    return 0;
}
