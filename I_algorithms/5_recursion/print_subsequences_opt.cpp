/*
Given a string, find all the possible subsequences of the string.

Input: str = "abc"
Output: a
        ab
        abc
        ac
        b
        bc
        c
*/

#include <iostream>
#include <vector>
using namespace std;

/*
1. Bit Manipulation:
TC = O(2^n * n)
SC = O(1)
*/
vector<string> all_possible_strings(string str)
{
    int n = str.length();
    vector<string> res;

    // Traverse string from 0 to 2^(n)-1.
    // Check for every number if their bit is set or not.
    // If the bit is set add that character to your subsequence.
    for (int num = 0; num < (1 << n); num++)
    {
        string subseq = "";
        for (int i = 0; i < n; i++)
        {
            // check if the ith bit is set or not
            if (num & (1 << i))
            {
                subseq += str[i];
            }
        }
        if (subseq.length() > 0)
        {
            res.push_back(subseq);
        }
    }

    sort(res.begin(), res.end());

    return res;
}

/*
2. Backtracking (Recursion):
TC = O(2^n)
SC = O(n)
*/
void all_possible_strings_rec(int idx, string s, string &res)
{
    if (idx == s.length())
    {
        cout << res << " ";
        return;
    }

    // picking
    res = res + s[idx];
    all_possible_strings_rec(idx + 1, s, res);

    // poping out while backtracking
    res.pop_back();
    all_possible_strings_rec(idx + 1, s, res);
}

int main()
{
    string str = "abc";
    vector<string> res = all_possible_strings(str);

    // printint all the subsequence.
    cout << "All possible subsequences are " << endl;
    for (auto it : res)
    {
        cout << it << " ";
    }

    cout << endl;

    // Pass starting index as 0
    string output = "";
    // all_possible_strings_rec(start_idx, original_str, output_str);
    all_possible_strings_rec(0, str, output);

    return 0;
}