#include <iostream>
#include <utility> // Required for std::pair

int main()
{
    // Creating a pair of int and string
    std::pair<int, std::string> pair1;

    // Assigning values to the pair
    pair1.first = 1;        // First element of the pair (int)
    pair1.second = "Apple"; // Second element of the pair (string)

    // Displaying the values of the first pair
    std::cout << "Pair1: " << pair1.first << ", " << pair1.second << std::endl;

    // Creating and initializing a pair using make_pair
    std::pair<int, std::string> pair2 = std::make_pair(2, "Banana");

    // Displaying the values of the second pair
    std::cout << "Pair2: " << pair2.first << ", " << pair2.second << std::endl;

    // Creating a pair of double and char
    std::pair<double, char> pair3(3.14, 'C');

    // Displaying the values of the third pair
    std::cout << "Pair3: " << pair3.first << ", " << pair3.second << std::endl;

    return 0;
}
