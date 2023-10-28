#include <iostream>
#include <thread>
#include <map>
#include <string>
#include <chrono>

using namespace std::chrono_literals;

void WeatherForcast(std::map<std::string, int> &forecastMap) // pass by reference
{
    while (true)
    {
        for (auto &item : forecastMap) // use reference
        {
            item.second++;
            std::cout << item.first << " - " << item.second << "\n";
        }
        std::this_thread::sleep_for(1500ms);
    }
}

int main()
{
    std::map<std::string, int> forecastMap = {
        {"New York", 80},
        {"London", 60},
        {"Paris", 72},
        {"Beijing", 77}};

    std::thread bgWorker(WeatherForcast, std::ref(forecastMap)); // pass map as reference to thread

    bgWorker.join(); // Join the thread to let it finish. Alternatively, you can use bgWorker.detach();

    return 0;
}
