#include <iostream>
#include <vector>
#include <ctime>


void swap (std::vector<int>& array, int a, int b) // swap elements in vector
{
    int temp = array[a];
    array [a] = array[b];
    array[b] = temp;
}
int Partition (std::vector<int>& array, int minElement, int maxElement)  // get pivot index
{
    int i = minElement-1;    // i iterator 
    int pivot = array[maxElement]; 
    for(size_t j = minElement; j < maxElement; j++) 
    {
        if (array[j] < pivot)
        {
            i++;
            swap(array,i,j); //swap i and j elements
        }
    }
    swap(array,i+1,maxElement); //swap i+1 element and last elem
    return i+1;
}
void QuickSort(std::vector<int>& array, int minElement, int maxElement)
{
    if (minElement < maxElement)
    {
         int pivotIndex =  Partition(array,minElement,maxElement); // get pivotIndex
         QuickSort (array, minElement, pivotIndex-1 ); // start sort in left part
         QuickSort (array, pivotIndex+1, maxElement); // start sort in right part

    }
}

int main()
{
    srand(time(NULL));
    std::vector <int> array;
    for(size_t i = 0; i < 15; i++)
    {
        array.push_back(rand()%99+1);
    }
    for(auto i:array)
    {
        std::cout << " " << i;
    }
    
   QuickSort(array,0,array.size()-1);
   std::cout <<std::endl;
   std::cout << "After Quick Sort: " << std::endl;
    for(auto i:array)
    {
        std::cout << " " << i;
    }
   
}