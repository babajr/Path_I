/****************************************************************************
File name: merge_two_sorted_arrays.cpp

Author: babajr
*****************************************************************************/

/*
Efficiently merging two sorted arrays.
Input: ar1[] = {10};
       ar2[] = {2, 3};
Output: ar1[] = {2}
        ar2[] = {3, 10}

Input: ar1[] = {1, 5, 9, 10, 15, 20};
       ar2[] = {2, 3, 8, 13};
Output: ar1[] = {1, 2, 3, 5, 8, 9}
        ar2[] = {10, 13, 15, 20}

*/

#include <bits/stdc++.h>
#include <iostream>
#include <algorithm>

using namespace std;

void printArray(int arr[], int size)
{
    for (int i = 0; i < size; ++i)
        cout << arr[i] << " ";
    cout << "\n";
}

/* Approach 1: With extra space. Brute Force.
TC: O(nlogn) assuming Merge / Quick Sort is used.
SC: O(n)
*/
/*
void mergeArray(int arr1[], int arr2[], int sizeArr1, int sizeArr2)
{
    int sizeArr3 = sizeArr1 + sizeArr2;
    int arr3[sizeArr3] = {0};

    // copy elements from arr1 to arr3.
    for(int i = 0; i < sizeArr1; ++i)
    {
        arr3[i] = arr1[i];
    }

    // copy elements from arr2 to arr3.
    for(int j = 0; j < sizeArr2; ++j)
    {
        arr3[j + sizeArr1] = arr2[j];
    }

    // sort arr3
    sort(arr3, arr3 + sizeArr3);

    // Now copy elements from arr3 to arr1 as well as arr2.
    for(int k = 0; k < sizeArr1; ++k)
        arr1[k] = arr3[k];
    for(int l = 0; l < sizeArr2; ++l)
        arr2[l] = arr3[l + sizeArr1];
}
*/

/* Approach 2:
IDEA:
We will traverse the first array and compare it with the first element of the second array.
If the first element of the second array is smaller than the first array then we will swap and then sort the second array.

Algo:
1. First, we have to traverse array1 and then compare it with the first element of array2.
If it is less than array1 then we swap both.

2. After swapping we are going to sort the array2 again so that the smallest element of the array2
comes at the first position and we can again swap with the array1

3. To sort the array2 we will store the first element of array2 in a variable and left shift all the element and store
the first element in array2 in the last.

TC: O(nm)
SC: O(1)
*/

void mergeArray(int arr1[], int arr2[], int sizeArr1, int sizeArr2)
{
    // Traverse arr1
    for (int i = 0; i < sizeArr1; ++i)
    {
        // Check if element at arr1[i] is greater than element at arr2[0].
        if (arr1[i] > arr2[0])
        {
            // swap the elements
            int temp = arr1[i];
            arr1[i] = arr2[0];
            arr2[0] = temp;

            // sort the arr2 in order to again swap the elements with arr1.
            int first_ele = arr2[0];
            int k;

            // We will store the first_ele of arr2 and left shift all the element and store
            // the first_ele in arr2[k-1]
            for (k = 1; k < sizeArr2 && arr2[k] < first_ele; ++k)
            {
                // if(arr2[k] < first_ele)
                arr2[k - 1] = arr2[k];
            }
            arr2[k - 1] = first_ele;
        }
    }
}

/*
Apporach 3: Without using any extra space

Intuition:
If we merge the given array, one thing we can assure is that arr1[] will contain all the
smaller elements and arr2[] will contain all the bigger elements.
This is the logic we will use. Using the 2 pointers, we will swap the bigger elements of
arr1[] with the smaller elements of arr2[] until the minimum of arr2[] becomes greater or
equal to the maximum of arr1[].

-- We will declare two pointers i.e. left and right.
   The left pointer will point to the last index of the arr1[]
   (i.e. Basically the maximum element of the array).
   The right pointer will point to the first index of the arr2[]
   (i.e. Basically the minimum element of the array).
-- Now, the left pointer will move toward index 0 and the right pointer will move
   towards the index m-1.
   While moving the two pointers we will face 2 different cases like the following:
   -- If arr1[left] > arr2[right]: In this case, we will swap the elements and move the pointers
      to the next positions.
   -- If arr1[left] <= arr2[right]: In this case, we will stop moving the pointers as arr1[] and arr2[]
      are containing correct elements.
-- Thus, after step 2, arr1[] will contain all smaller elements and arr2[] will contain
   all bigger elements.
   Finally, we will sort the two arrays.
*/
void mergeArray_optimal(int arr1[], int arr2[], int sizeArr1, int sizeArr2)
{
    int left = sizeArr1 - 1;
    int right = 0;

    // Swap the elements until arr1[left] is smaller than arr2[right]:
    while (left >= 0 && right < sizeArr2)
    {
        if (arr1[left] > arr2[right])
        {
            swap(arr1[left], arr2[right]);
            left--, right++;
        }
        else
        {
            break;
        }
    }

    // Sort arr1[] and arr2[] individually:
    sort(arr1, arr1 + sizeArr1);
    sort(arr2, arr2 + sizeArr2);
}

/*Approach 4: GAP method. OPTIMUM SOLUTION.
IDEA:
We start comparing elements that are far from each other rather than adjacent.
For every pass, we calculate the gap and compare the elements towards the right of the gap.
Every pass, the gap reduces to the ceiling value of dividing by 2

First example:
a1[] = {3 27 38 43},
a2[] = {9 10 82}
Start with
gap =  ceiling of n/2 = 4
[This gap is for whole merged array]
3 27 38 43   9 10 82
3 27 38 43   9 10 82
3 10 38 43   9 27 82

gap = 2:
3 10 38 43   9 27 82
3 10 38 43   9 27 82
3 10 38 43   9 27 82
3 10 9 43   38 27 82
3 10 9 27   38 43 82

gap = 1:
3 10 9 27   38 43 82
3 10 9 27   38 43 82
3 9 10 27   38 43 82
3 9 10 27   38 43 82
3 9 10 27   38 43 82
3 9 10 27   38 43 82
Output : 3 9 10 27 38 43 82

*/
// void mergeArray(int arr1[], int arr2[], int sizeArr1, int sizeArr2)
// {

// }

int main()
{
    int arr1[] = {1, 5, 9, 10, 15, 20};
    int arr2[] = {2, 3, 8, 13};

    int sizeArr1 = sizeof(arr1) / sizeof(arr1[0]);
    int sizeArr2 = sizeof(arr2) / sizeof(arr2[0]);

    cout << "original arrays" << endl;
    printArray(arr1, sizeArr1);
    printArray(arr2, sizeArr2);

    // mergeArray(arr1, arr2, sizeArr1, sizeArr2);
    // cout << "Sorted arrays" << endl;
    // printArray(arr1, sizeArr1);
    // printArray(arr2, sizeArr2);

    mergeArray_optimal(arr1, arr2, sizeArr1, sizeArr2);
    cout << "Sorted arrays" << endl;
    printArray(arr1, sizeArr1);
    printArray(arr2, sizeArr2);

    return 0;
}
