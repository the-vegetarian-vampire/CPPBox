#include <iostream>
#include <vector>

using namespace std;

int main()
{

    vector<int> vec1{10, 20, 30, 40, 50, 60};
    vector<int> vec2{10, 20, 30, 40, 50, 60};

    cout << vec1.at(0) << endl;
    cout << vec2.at(0) << endl;

    vec1.push_back(70);

    cout << vec1.at(6) << endl;
    cout << vec1.size() << endl;

    cout << vec2.size() << endl;
    vec2.pop_back();
    cout << vec2.size() << endl;

    return 0;
}