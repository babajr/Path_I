#include <iostream>
#include <unordered_set>
using namespace std;

/*
An unordered_set is an unordered associative container implemented using a
hash table where keys are hashed into indices of a hash table so that the
insertion is always randomized.

All operations on the unordered_set take constant time O(1) on an average
which can go up to linear time O(n) in the
worst case which depends on the internally used hash function,
but practically they perform very well and generally provide a constant time
lookup operation.

The unordered_set can contain a key of any type – predefined or user-defined
data structure but all the keys must be unique.

unordered_set<data_type> name;
*/

void unordered_set_explanination()
{
    // declaring set for storing string data-type
    unordered_set<string> stringSet;

    // inserting various string, same string will be stored
    // once in set

    stringSet.insert("code");
    stringSet.insert("in");
    stringSet.insert("c++");
    stringSet.insert("is");
    stringSet.insert("fast");

    string key = "slow";

    // find returns end iterator if key is not found,
    // else it returns iterator to that key

    if (stringSet.find(key) == stringSet.end()) // not found
        cout << key << " not found" << endl
             << endl;
    else
        cout << "Found " << key << endl
             << endl;

    key = "c++";
    if (stringSet.find(key) == stringSet.end()) // Found
        cout << key << " not found\n";
    else
        cout << "Found " << key << endl;

    // now iterating over whole set and printing its content
    // here string printed in random manner
    cout << "\nAll elements : ";
    unordered_set<string>::iterator itr;
    for (itr = stringSet.begin(); itr != stringSet.end(); itr++)
        cout << (*itr) << endl;

    // for each loop
    for (auto iter1 : stringSet)
    {
        cout << (iter1) << endl;
    }
}

int main(void)
{
    unordered_set_explanination();
    return 0;
}