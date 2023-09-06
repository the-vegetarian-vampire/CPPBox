#include <iostream>

bool isPrime(int num)
{
    if (num <= 1)
        return false;
    if (num <= 3)
        return true;

    // Check for divisibility by 2 and 3
    if (num % 2 == 0 || num % 3 == 0)
        return false;

    int i = 5;
    while (i * i <= num)
    {
        if (num % i == 0 || num % (i + 2) == 0)
            return false;
        i += 6;
    }

    return true;
}

int main()
{
    int number;

    do
    {
        std::cout << "Enter a number between 1 and 100: ";
        std::cin >> number;

        if (number < 1 || number > 100)
        {
            std::cout << "Pick a number between 1-100" << std::endl;
        }
    } while (number < 1 || number > 100);

    if (isPrime(number))
    {
        std::cout << number << " is a prime number." << std::endl;
    }
    else
    {
        std::cout << number << " is not a prime number." << std::endl;
    }

    return 0;
}
