#include <iostream>
#include <algorithm>
#include <random>




// Generate random numbers and store to dynamic memory.
// Pass reference of pointer to all fxns to prevent different memory addresses.
void makeNumbers(double *&ptr, const int array_size)
{
    for (int i = 0; i<array_size; i++)
        *(ptr+i) = (((double)rand())/rand()) * 100;
}


// Sort numbers - increasing
void sortNumbers(double *&ptr, const int array_size)
{
    std::sort(ptr, ptr+array_size);
}


void printNumbers(double *&ptr, const int array_size)
{
    for (int i = 0; i<array_size; i++)
        std::cout << i << ": " << *(ptr+i) << " ";
}


void deleteNumbers(double *&array_ptr)
{
    delete[] array_ptr;
    //array_ptr = nullptr;
}


int main()
{
    const int array_size = 10;
    double *array_ptr = new double [array_size];     // Pointer to array.
    
    makeNumbers(array_ptr, array_size);
    sortNumbers(array_ptr, array_size);
    printNumbers(array_ptr, array_size);
    deleteNumbers(array_ptr);   

    return 0;
}