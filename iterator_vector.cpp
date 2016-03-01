#include <iostream>
#include <vector>
using namespace std;

int main(int argc, const char *argv[])
{
    vector<int> v;

    v.push_back(10);
    v.push_back(20);
    v.push_back(30);
    v.push_back(40);

    // Using iterator
    for (vector<int>::iterator i = v.begin(), e = v.end(); i != e; ++i) {
        cout << *i << endl;
    }
    // Using reverse iterator
    cout << "Reverse iterator..." << endl;
    for (vector<int>::reverse_iterator i = v.rbegin(), e = v.rend(); i != e; ++i) {
        cout << *i << endl;
    }
    cout << endl;
    return 0;
}