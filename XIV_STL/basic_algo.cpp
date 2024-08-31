#include <iostream>
#include <vector>
using namespace std;

/*

*/

void print_arr(vector<int> v)
{
    for (auto it : v)
    {
        cout << it << " ";
    }

    cout << endl;
}

bool comp(pair<int, int> p1, pair<int, int> p2)
{
    if (p1.second < p2.second)
        return true;
    if (p1.second > p2.second)
        return false;

    // if they are same
    if (p1.first > p2.first)
        return true;
    else
        return false;
}

void algo_explanination()
{
    // VECTOR
    vector<int> arr = {5, 1, 4, 2, 3};

    // Original array
    print_arr(arr);

    // sort vector in ascending order
    sort(arr.begin(), arr.end()); // arr.end() points to next to last element
    print_arr(arr);

    pair<int, int> a[] = {{4, 1},
                          {2, 1},
                          {1, 2}};
    int size = sizeof(a) / sizeof(a[0]);
    // Sort array of pairs in certain way: Example, sort according to second element:
    // If second element is same, then sort it according to first element but
    // in desceding order.
    // ARRAY
    sort(a, a + size, comp); // {{1, 2}, {2, 1}, {4, 1}}
    for (auto it : a)
    {
        cout << it.first << ":" << it.second << " ";
    }
    cout << endl;

    int arr1[] = {1, 2, 3, 5, 4};
    int n = sizeof(arr1) / sizeof(arr1[0]);
    sort(arr1, arr1 + 2);

    // sort array in asceding order
    sort(arr1, arr1 + n); // arr.end() points to next to last element
    print_arr(arr);

    cout << "Max Element in an Array: " << *max_element(arr1, arr1 + n) << endl;
}

void count_numberof_ones(int n)
{
    int number_of_ones = __builtin_popcount(n);
    cout << number_of_ones << endl;
}

void print_all_next_permutation(string s)
{
    cout << "Next permutations: \n";

    do
    {
        cout << s << endl;
    } while (next_permutation(s.begin(), s.end()));
}

int main(void)
{
    algo_explanination();
    // count_numberof_ones(6); // 3
    print_all_next_permutation("123");
    return 0;
}