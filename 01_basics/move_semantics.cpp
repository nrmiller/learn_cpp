
#include <iostream>

using namespace std;

class String {
    public:
        String(const char* string) {
            cout << "Primary Constructor" << endl;
            length = strlen(string) + 1;
            data = new char[length];
            memcpy(data, string, length);
        }

        String(const String& other) {
            cout << "Copied" << endl;

            length = other.length;
            data = new char[length];
            memcpy(data, other.data, length);
        }

        String& operator=(const String& other) {
            cout << "Copy Assignment" << endl;

            if (this == &other) {
                cout << "Cancelled" << endl;
                return *this; 
            }

            length = other.length;
            data = new char[length];
            memcpy(data, other.data, length);

            return *this;
        }

        String(String&& other) {
            cout << "Moved" << endl;

            length = other.length;
            data = other.data;

            other.length = 0;
            other.data = nullptr; // prevent the old String from deleting the memory
        }

        String& operator=(String&& other) {
            cout << "Move Assignment" << endl;

            if (this == &other) {
                cout << "Cancelled" << endl;
                return *this; 
            }

            delete[] data;

            length = other.length;
            data = other.data;

            other.length = 0;
            other.data = nullptr; // prevent the old String from deleting hte memory   

            return *this;
        }

        ~String() {
            cout << "Destroyed" << endl;

            delete[] data;
        }

        // Note the trailing const.
        // This communicates that the current instance is not modified during the
        // body of the function.
        // Also, it avoids a commutativity problem. Generally (a==b) should yield the same
        // result (b==a), including preconditions, postconditions, and invaraints.
        // By defining only one argument as a const, C++ compiler generates a warning because
        // its possible that (a==b) != (b==a)
        bool operator==(const String& other) const {
            if (length != other.length)
                return false;

            char* otherIterator = other.data;
            for (char* iterator = data; *iterator;) {
                if (*iterator != *otherIterator)
                    return false;

                iterator++;
                otherIterator++;
            }

            return true;
        }

    // If << is overridden for ostream, allow it to access private members of String
    friend ostream& operator<<(ostream& os, const String& str);
    friend ostream& operator<<(ostream& os, const String&& str);

    private:
        char* data;
        int length;
};

ostream& operator<<(ostream& os, const String& string) {
    return os << "[lvalue] " << string.data;
}
ostream& operator<<(ostream& os, const String&& string) {
    return os << "[rvalue] " << string.data;
}

int main(int argc, char* argv[]) {

    String text("literal");

    String text2 { text }; // uniform initializer to call copy constructor

    cout << "text: " << text << endl;
    cout << "text2: " << text2 << endl;

    String text3 = (String&&)text; // calls the move constructor

    // cout << "text: " << text << endl; // EXC_BAD_ACCESS (because text has been moved)
    cout << "text3: " << text3 << endl;

    String text4 = std::move(text3); // calls the move constructor
    cout << "text4: " << text4 << endl;

    String text5 { std::move(text4) }; // calls the move constructor
    cout << "text5: " << text5 << endl;

    cout << String("<-- check the expression type") << endl;

    String src = "Hello";
    String dst = src; // copy src to dst
    cout << "src: " << src << endl;
    cout << "dst: " << dst << endl;

    // Move Assignment only gets called when moving to an already existing variable
    dst = std::move("Goodbye");
    cout << "dst: " << dst << endl;

    // Move into itself should not wipe the data.
    dst = std::move(dst);
    cout << "dst: " << dst << endl;

    auto copy = String("value");
    copy = dst;
    cout << "dst: " << dst << endl;

    // Copy into itself should not create new memory
    copy = copy;
    cout << "dst: " << dst << endl;

    cout << "Objects are identical? " << std::boolalpha << (&copy == &dst) << std::noboolalpha << endl;

    auto hello = String("hello");
    cout << "(\"" << copy << "\" == \"" << dst << "\")? " << std::boolalpha << (copy == dst) << std::noboolalpha << endl;
    cout << "(\"" << copy << "\" == \"" << hello << "\")? " << std::boolalpha << (copy == hello) << std::noboolalpha << endl;

    return 0;
}