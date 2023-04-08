/****************************************************************************
File name: largest_subarray_sum.cpp

Author: babajr
*****************************************************************************/


/*
Find the largest possible subarray sum in a given array.

Input: {1,2,-3,4,1}
Output: 5
*/


#include<bits/stdc++.h>
using namespace std;

/*
Brute Force Approach.
Calculate sum of all possible subarrays. Return maximum sum.
*/
int largestSubarrSum(int arr[], int size)
{
    int maximum_sum = INT_MIN;

    for(int i = 0; i < size; i++)
    {
        int subarr_sum = 0;

        for(int j = i; j < size; j++)
        {
            subarr_sum += arr[j];
            maximum_sum = max(maximum_sum, subarr_sum);
        }
    }

    return maximum_sum;
}


int main(void)
{
    int arr[] = {-2, 1, -3, -4, 0};
    // int arr[] = {1,2,3,-4,5};
    int size = sizeof(arr) / sizeof(arr[0]);

    int largest_sum = largestSubarrSum(arr, size);
    cout << largest_sum << endl;

    return 0;
}
