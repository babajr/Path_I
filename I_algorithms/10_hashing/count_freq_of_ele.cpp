/*
Count frequency of each element in the array.

Given an array, we have found the number of occurrences of each element in the
array.

Input: arr[] = {10,5,10,15,10,5};
Output:
        10  3
        5  2
        15  1
*/
#include <iostream>
#include <map>
using namespace std;

/*
Brute Force
*/
void count_freq(int arr[], int size)
{
    int *visited = (int *)calloc((size + 1), sizeof(int));

    for (int i = 0; i < size; i++)
    {
        if (visited[i] == 1)
        {
            continue;
        }

        int cnt = 1;
        for (int j = i + 1; j < size; j++)
        {
            if (arr[i] == arr[j])
            {
                visited[j] = 1;
                cnt++;
            }
        }

        cout << arr[i] << " : " << cnt << endl;
    }
}

/*
Using Map (Unordered MAP)
*/
void count_freq_eff(int arr[], int size)
{
    unordered_map<int, int> map;

    // Update the map with key : value
    for (int i = 0; i < size; i++)
        map[arr[i]]++;

    // Print
    for (auto x : map)
        cout << x.first << " : " << x.second << endl;
}

int main(void)
{
    int arr[] = {10, 5, 10, 15, 10, 5};
    int size = sizeof(arr) / sizeof(arr[0]);

    count_freq(arr, size);
    count_freq_eff(arr, size);

    return 0;
}