/****************************************************************************
File name: insertion_sort.cpp

Author: babajr
*****************************************************************************/

#include <iostream>
#include <cassert>
using namespace std;

/*
Helper API to swap the numbers.
*/
void swap(int *first, int *second)
{
    int temp = *first;
    *first = *second;
    *second = temp;
}

/*
Insertion Sort:
Takes an element and places it at correct position.

TC (worst): O(n2)
TC (best): O(n)

Idea is similar to the playing cards.
i.e. insert the card in its correct position in the sorted part of the array.
*/
// void insertion_sort(int arr[], int size)
// {
//     for (int i = 1; i < size; i++) // skipping 0th element,
//                                    // as single element is always sorted.
//     {
//         int value = arr[i];
//         int prev = i - 1;

//         // logic to find the correct position to insert the element.
//         while (prev >= 0 && arr[prev] > value)
//         {
//             arr[prev + 1] = arr[prev];
//             prev = prev - 1;
//         }

//         arr[prev + 1] = value;
//     }
// }

void insertion_sort(int arr[], int size)
{
    for (int i = 0; i <= (size - 1); i++)
    {
        int j = i;
        // logic to find the correct position to insert the element.
        while (j > 0 && arr[j - 1] > arr[j])
        {
            int temp = arr[j - 1];
            arr[j - 1] = arr[j];
            arr[j] = temp;
            j--;
        }
    }
}

/*
Helper API to print the array.
*/
void print_arr(int arr[], int size)
{
    for (int i = 0; i < size; i++)
        printf("%d ", arr[i]);

    printf("\n");
}

int main(void)
{
    int arr[] = {1, 4, 5, 2, 3, 6};
    // int arr[] = {1,2,3,4,5,6};
    int size = sizeof(arr) / sizeof(arr[0]);

    printf("Original Array: \n");
    print_arr(arr, size);

    insertion_sort(arr, size);
    printf("Sorted Array: \n");
    print_arr(arr, size);
}
