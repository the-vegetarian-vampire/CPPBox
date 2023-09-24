#include <iostream>

int main()
{
    int num1, num2;

    // Input two numbers
    std::cout << "Enter two numbers:" << std::endl;
    std::cin >> num1 >> num2;

    // Check if the numbers are the same
    if (num1 == num2)
    {
        std::cout << "Both numbers are the same: " << num1 << std::endl;
    }
    else
    {
        int largest = (num1 > num2) ? num1 : num2;
        int smallest = (num1 < num2) ? num1 : num2;

        std::cout << "Largest: " << largest << std::endl;
        std::cout << "Smallest: " << smallest << std::endl;
    }

    return 0;
}
