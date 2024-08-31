/*
Given an integer n, return all divisors of n.

Input: n = 12
Output: [1, 2, 3, 4, 6, 12]
*/

#include <iostream>
#include <vector>
using namespace std;

/*
Brute Force
*/
int *print_divisor(int n, int &size)
{
    int *divisors = new int[n];
    int count = 0;

    for (int i = 1; i <= n; i++)
    {
        if (n % i == 0)
        {
            divisors[count++] = i;
        }
    }

    size = count;

    return divisors;
}

/*
Efficient approach
*/

vector<int> print_divisor_eff(int n)
{
    vector<int> div;

    for (int i = 1; i <= sqrt(n); ++i)
    {
        if (n % i == 0)
        {
            div.push_back(i);

            if (i != n / i)
            {
                div.push_back(n / i);
            }
        }
    }

    return div;
}

void print_arr(int arr[], int size)
{
    for (int i = 0; i < size; i++)
    {
        cout << arr[i] << " ";
    }

    cout << endl;
}

int main()
{
    int number = 12;
    int size;

    int *div = print_divisor(number, size);
    print_arr(div, size);
    delete[] div;

    vector<int> div_res;
    div_res = print_divisor_eff(number);

    for (auto it : div_res)
    {
        cout << it << " ";
    }
    cout << endl;

    return 0;
}
