
#include <string>
#include <iostream>
#include <vector>

using namespace std;


int main(int argc, char* argv[]) {

    vector<string> msg{"Hello", "C++", "World", "from", "VS Code", "and the C++ Extension!"};
    for (const string &word : msg) {
        cout << word << " ";
    }

    cout << endl;

    return 0;
}