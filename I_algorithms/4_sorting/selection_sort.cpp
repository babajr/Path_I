#include <iostream>

using namespace std;

/*
Selection Sort:
Select the minimum element from the array and move it to the starting of the array.

TC (worst) = O(n2)
TC (best) = O(n2)

Outer Loop: i = 0 to (n-2)
Inner Loop: j = i to (n-1)


arr: 13, 46, 24, 52, 20, 9
     0    1   2   3   4  5
step1: Traverse array from 0 to 5 index and find min element
       Swap min with the 0th index
9, 46, 24, 52, 20, 13

step2: Traverse array from 1 to 5 index and find min element
       Swap min with the 1st index
9, 13, 24, 52, 20, 46

step3: Traverse array from 2 to 5 index and find min element
       Swap min with the 2nd index
9, 13, 20, 52, 24, 46

step4: Traverse array from 3 to 5 index and find min element
       Swap min with the 3rd index
9, 13, 20, 24, 52, 46

step5: Traverse array from 4 to 5 index and find min element
       Swap min with the 4th index
9, 13, 20, 24, 46, 52

===> Array is SORTED
*/

void selection_sort(int arr[], int size)
{
    for (int i = 0; i < (size - 1); i++)
    {
        int min_index = i;
        for (int j = i + 1; j < size; j++)
        {
            if (arr[j] < arr[min_index])
            {
                min_index = j;
            }
        }
        // Swap the Element at min_index to i
        int temp = arr[min_index];
        arr[min_index] = arr[i];
        arr[i] = temp;
    }
}

void print_array(int arr[], int size)
{
    for (int i = 0; i < size; i++)
    {
        cout << arr[i] << " ";
    }

    cout << endl;
}

int main(void)
{
    int arr[] = {13, 46, 24, 52, 20, 9};
    int size = sizeof(arr) / sizeof(arr[0]);
    print_array(arr, size);

    selection_sort(arr, size);
    print_array(arr, size);

    return 0;
}