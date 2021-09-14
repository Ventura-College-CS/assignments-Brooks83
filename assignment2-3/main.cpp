#include <iostream>
#include <algorithm>
#include <random>


const int array_size = 10;

// Generate random numbers and store to dynamic memory.
// Pass reference of pointer to all fxns to prevent different memory addresses.
void makeNumbers(double *&ptr)
{
    for (int i = 0; i<array_size; i++)
        *(ptr+i) = (((double)rand())/rand()) * 100;
}


// Sort numbers - increasing 
void sortNumbers(double *&ptr)
{
    double temp;
    for(int i = 0; i<array_size; i++)
	{
		for(int j = i+1; j<array_size; j++)
		{
			if(*(ptr+i) > *(ptr+j))
			{
				temp = *(ptr+i);
				*(ptr+i) = *(ptr+j);
				*(ptr+j) = temp;
			}
		}
	}
}


void printNumbers(double *&ptr)
{
    for (int i = 0; i<array_size; i++)
        std::cout << *(ptr+i) << " ";
}


void deleteNumbers(double *&array_ptr)
{
    delete[] array_ptr;
    //array_ptr = nullptr;
}


int main()
{
    double *array_ptr;
    array_ptr = new double [array_size];     // Pointer to array.
    
    makeNumbers(array_ptr);
    sortNumbers(array_ptr);
    printNumbers(array_ptr);
    deleteNumbers(array_ptr);

    std::cout << "complete";

    return 0;
}