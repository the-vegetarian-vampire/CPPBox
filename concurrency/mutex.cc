#include <iostream>
#include <thread>
#include <mutex>
using namespace std;

mutex carMutex;

void driveCar(string driverName)
{
    // lock_guard<mutex> carLock(carMutex);

    unique_lock<mutex> carLock(carMutex);
    cout << driverName << "is driving..." << endl;
    this_thread::sleep_for(chrono::seconds(2));
    cout << driverName << " is done driving!" << endl;
    carLock.unlock();
}

int main()
{
    thread t1(driveCar, "Alice");
    thread t2(driveCar, "Bob");

    t1.join();
    t2.join();

    cin.get();
}