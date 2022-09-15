#include <iostream>
#include <vector>
#include <ctime>


void swap (std::vector<int>& array, int a, int b)
{
    int temp = array[a];
    array [a] = array[b];
    array[b] = temp;
}
int Partition (std::vector<int>& array, int minElement, int maxElement)
{
    int i = minElement-1;
    int pivot = array[maxElement];
    for(size_t j = minElement; j < maxElement; j++)
    {
        if (array[j] < pivot)
        {
            i++;
            swap(array,i,j);
        }
    }
    swap(array,i+1,maxElement);
    return i+1;
}
void QuickSort(std::vector<int>& array, int minElement, int maxElement)
{
    if (minElement < maxElement)
    {
         int pivotIndex =  Partition(array,minElement,maxElement);
         QuickSort (array, minElement, pivotIndex-1 );
         QuickSort (array, pivotIndex+1, maxElement);

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