/*
Print all Sq which sums to K
*/
#include <iostream>
#include <vector>

using namespace std;

void print_subsequence_equal_to_sum(int idx, vector<int> &ds, int res_sum,
                                    int given_sum, int arr[], int size)
{
    if (idx == size)
    {
        if (res_sum == given_sum)
        {
            for (auto it : ds)
            {
                cout << it << " ";
            }

            cout << endl;
        }

        return;
    }

    ds.push_back(arr[idx]);
    res_sum += arr[idx];
    print_subsequence_equal_to_sum(idx + 1, ds, res_sum, given_sum, arr, size);

    res_sum -= arr[idx];
    ds.pop_back();
    print_subsequence_equal_to_sum(idx + 1, ds, res_sum, given_sum, arr, size);
}

int main()
{
    int arr[] = {1, 2, 1};
    // int arr[] = {1, 2, 3, 4, 5};
    int size = sizeof(arr) / sizeof(arr[0]);
    int given_sum = 2;

    vector<int> ds;

    // print_subsequence_equal_to_sum(idx, ds, res_sum, given_sum, arr, size);
    print_subsequence_equal_to_sum(0, ds, 0, given_sum, arr, size);

    return 0;
}