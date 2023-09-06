#include <iostream>
char str[20] = "Hi, there!";

int main()
{
    char *p = &str[4];
    std::cout << *p++;
    std::cout << p;
    return 0;
}