#include <iostream>
using namespace std;

int main()
{
    double distance;
    double lightspeed;
    double delay;
    double delay_in_min;

    distance = 34000000.0;
    lightspeed = 186000.0;

    delay = distance / lightspeed;
    cout << "Time delay when talking to Mars: " << delay << " seconds.\n";

    delay_in_min = delay / 60.0;

    cout << "This is " << delay_in_min << "minutes.";

    return 0;
}
