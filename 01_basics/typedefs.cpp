#include <iostream>

using namespace std;

// Simple typedef
typedef int number;

// typedef-named struct
typedef struct {
    int x;
    int y;
} Point, *pPoint;

using Vector2 = Point;

// overload << to easily print the Point
ostream& operator<<(ostream& os, const Point& point) {
    return os << "(" << point.x << ", " << point.y << ")";
}

int main(int argc, char* argv[]) {

    auto num = number(3);

    // Initializes the struct to be zeroed
    auto point = Point{};
    cout << "point: " << point << endl;

    Point p2; // uninitialized - x & y refer to undefined memory
    cout << "p2: " << p2 << endl;

    // Also initialized
    Point p3{};
    cout << "p3: " << p3 << endl;

    // Fully defined
    auto p4 = Point{};
    p4.x = 1;
    p4.y = 4;
    cout << "p4: " << p4 << endl;

    // Use the pointer typedef-name
    const pPoint pointerToPoint = &point;
    pointerToPoint->x = 10;
    pointerToPoint->y = 20;
    cout << "point: " << point << endl;

    auto vec = Vector2{};
    vec.x = 3;
    vec.y = 3;
    cout << "vector: " << vec << endl;

    return 0;
}