/*
Given an array of size N. Find the highest and lowest frequency element.

Input: array[] = {10,5,10,15,10,5};
Output: 10 15
Explanation:
The frequency of 10 is 3, i.e. the highest
and the frequency of 15 is 1 i.e. the lowest.
*/
#include <iostream>
#include <map>
using namespace std;

/*
Brute Force
*/
void count_freq(int arr[], int size)
{
    vector<bool> visited(size, false);

    int max_freq = 0;
    int min_freq = size;
    int max_ele = 0;
    int min_ele = 0;

    for (int i = 0; i < size; i++)
    {
        // skip this element if it is already processed
        if (visited[i] == true)
            continue;

        int count = 1;
        for (int j = i + 1; j < size; j++)
        {
            if (arr[j] == arr[i])
            {
                visited[j] = true;
                count++;
            }
        }

        if (count > max_freq)
        {
            max_ele = arr[i];
            max_freq = count;
        }

        if (count < min_freq)
        {
            min_ele = arr[i];
            min_freq = count;
        }
    }

    cout << "The highest frequency element is: " << max_ele << "\n";
    cout << "The lowest frequency element is: " << min_ele << "\n";
}

/*
Using Map (Unordered MAP)
*/
void count_freq_eff(int arr[], int size)
{
    unordered_map<int, int> map;
    int max_freq = 0;
    int max_ele = 0;
    int min_freq = size;
    int min_ele = 0;

    // Update the map with key : value
    for (int i = 0; i < size; i++)
        map[arr[i]]++;

    // Print
    for (auto it : map)
    {
        int count = it.second;
        int element = it.first;

        if (count > max_freq)
        {
            max_freq = count;
            max_ele = element;
        }

        if (count < min_freq)
        {
            min_freq = count;
            min_ele = element;
        }
    }

    cout << "The highest frequency element is: " << max_ele << "\n";
    cout << "The lowest frequency element is: " << min_ele << "\n";
}

int main(void)
{
    int arr[] = {10, 5, 10, 15, 10, 5};
    int size = sizeof(arr) / sizeof(arr[0]);

    count_freq(arr, size);
    count_freq_eff(arr, size);

    return 0;
}