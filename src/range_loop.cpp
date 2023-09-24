#include <iostream>
#include <vector>
using namespace std;

int main()
{

    vector<int> vec{1, 3, 5, 15, 16, 17, 18, 19, 20, 21, 25, 26, 27, 30, 50, 55, 56, 58, 100, 200, 300, 400, 500, 600, 700};

    int count{};

    for (auto v : vec)
    {
        if (v % 3 == 0 || v % 5 == 0)
            count += 1;
    }
    cout << "Count of numbers divisible by 3 or 5: " << count << endl;

    return 0;
}