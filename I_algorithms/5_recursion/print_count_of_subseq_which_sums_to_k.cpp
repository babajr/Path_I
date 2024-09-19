/*
Print the count of Sq which sums to K
*/
#include <iostream>
#include <vector>

using namespace std;

int print_count_of_subsequence_equal_to_sum(int idx, vector<int> &ds, int res_sum,
                                            int given_sum, int arr[], int size)
{
    if (res_sum > given_sum)
        return 0;

    if (idx == size)
    {
        // If condition is satisfied, return true.
        // Otherwise return false.
        if (res_sum == given_sum)
        {
            // for (auto it : ds)
            // {
            //     cout << it << " ";
            // }

            // cout << endl;
            return 1;
        }

        return 0;
    }

    // Pick the element.
    // If the subsequence found, return true. No need further recursive calls.
    ds.push_back(arr[idx]);
    res_sum += arr[idx];
    int left = print_count_of_subsequence_equal_to_sum(idx + 1, ds, res_sum,
                                                       given_sum, arr, size);

    // Do not the element.
    // If the subsequence found, return true. No need further recursive calls.
    res_sum -= arr[idx];
    ds.pop_back();
    int right = print_count_of_subsequence_equal_to_sum(idx + 1, ds, res_sum,
                                                        given_sum, arr, size);

    // return false if no subsequence found.
    return (left + right);
}

int main()
{
    int arr[] = {1, 2, 1, 1};
    // int arr[] = {1, 2, 3, 4, 5};
    int size = sizeof(arr) / sizeof(arr[0]);
    int given_sum = 2;

    vector<int> ds;

    // print_subsequence_equal_to_sum(idx, ds, res_sum, given_sum, arr, size);
    cout << print_count_of_subsequence_equal_to_sum(0, ds, 0, given_sum, arr, size) << endl;

    return 0;
}