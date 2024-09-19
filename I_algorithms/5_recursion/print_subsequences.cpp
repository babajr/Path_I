/*
Input: array = {1, 2, 3}
Output:   // this space denotes null element.
         1
         1 2
         1 2 3
         1 3
         2
         2 3
         3
Explanation: These are all the subsets that can be formed using the array.
*/

#include <iostream>
#include <vector>

using namespace std;

/*
Using Recursion:
TC: O(2^n) * n
SC: O(n)
*/
void print_subsequence(int idx, vector<int> &vt, int arr[], int n)
{
    // Base Condition. If idx reaches end of array, print the subsequence.
    // If size of vector becomes 0, print {}
    if (idx == n)
    {
        for (auto it : vt)
        {
            cout << it << " ";
        }

        if (vt.size() == 0)
        {
            cout << "{}";
        }

        cout << endl;
        return;
    }

    // Pick the particular index into the subsequence.
    vt.push_back(arr[idx]);
    print_subsequence(idx + 1, vt, arr, n);

    // Do not pick particular index into the subsequence
    vt.pop_back();
    print_subsequence(idx + 1, vt, arr, n);
}

int main(void)
{
    int arr[] = {1, 2, 3};
    int size = sizeof(arr) / sizeof(arr[0]);
    vector<int> vect;

    print_subsequence(0, vect, arr, size);

    return 0;
}
