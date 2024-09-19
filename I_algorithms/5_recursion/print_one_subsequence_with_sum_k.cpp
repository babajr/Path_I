/*
Print only 1st Sq which sums to K
*/
#include <iostream>
#include <vector>

using namespace std;

bool print_subsequence_equal_to_sum(int idx, vector<int> &ds, int res_sum,
                                    int given_sum, int arr[], int size)
{
    if (idx == size)
    {
        // If condition is satisfied, return true.
        // Otherwise return false.
        if (res_sum == given_sum)
        {
            for (auto it : ds)
            {
                cout << it << " ";
            }

            cout << endl;
            return true;
        }

        return false;
    }

    // Pick the element.
    // If the subsequence found, return true. No need further recursive calls.
    ds.push_back(arr[idx]);
    res_sum += arr[idx];
    if (print_subsequence_equal_to_sum(idx + 1, ds, res_sum,
                                       given_sum, arr, size) == true)
        return true;

    // Do not the element.
    // If the subsequence found, return true. No need further recursive calls.
    res_sum -= arr[idx];
    ds.pop_back();
    if (print_subsequence_equal_to_sum(idx + 1, ds, res_sum, given_sum, arr, size) == true)
        return true;

    // return false if no subsequence found.
    return false;
}

int main()
{
    int arr[] = {1, 2, 1};
    // int arr[] = {1, 2, 3, 4, 5};
    int size = sizeof(arr) / sizeof(arr[0]);
    int given_sum = 5;

    vector<int> ds;

    // print_subsequence_equal_to_sum(idx, ds, res_sum, given_sum, arr, size);
    cout << print_subsequence_equal_to_sum(0, ds, 0, given_sum, arr, size) << endl;

    return 0;
}