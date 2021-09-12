#include <iostream>


int main() 
{
    const int n = 10;
    double numbers[n] = {10.0, 15.2, 21.2, 10.5, 11.3, 12.5, 13.8, 14.7, 19.8, 20.0};
    double *ptr;

    //  The pointer points to the address of 'numbers' which is also the first element in 'numbers'
    ptr = numbers;
    for (int i = 0; i < n; i++)
        std::cout << "Element: " << i << " | Address: " << ptr+i << " | Value: " << *(ptr+i) << std::endl;
}