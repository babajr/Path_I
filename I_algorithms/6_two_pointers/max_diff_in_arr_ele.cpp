#include <bits/stdc++.h>
using namespace std;

/*
https://www.enjoyalgorithms.com/blog/maximum-difference-between-two-elements
*/

int maximum_difference_bf(int arr[], int size)
{
    int max_diff = 0;

    for (int i = 0; i < size - 1; i++)
    {
        for (int j = i + 1; j < size; j++)
        {
            if (arr[j] > arr[i])
            {
                max_diff = max(max_diff, arr[j] - arr[i]);
            }
        }
    }

    return max_diff;
}

int maximum_difference_eff(int arr[], int size)
{
    int min_ele = arr[0];
    int max_diff = 0;

    for (int i = 1; i < size; i++)
    {
        if ((arr[i] - min_ele) > max_diff)
            max_diff = arr[i] - min_ele;

        if (arr[i] < min_ele)
            min_ele = arr[i];
    }

    return max_diff;
}

int main(void)
{
    int arr[] = {8, 4, 9, 5, 3, 7};
    int size = sizeof(arr) / sizeof(arr[0]);

    printf("%d\n", maximum_difference_bf(arr, size));
    printf("%d\n", maximum_difference_eff(arr, size));

    return 0;
}