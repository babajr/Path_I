#include <iostream>
#include <map>
using namespace std;

/*
Map:
====
Maps are associative containers that store elements in a mapped fashion.
Each element has a key value and a mapped value. No two mapped values can have the same
key values. --> Keys are unique, but values can be duplicate.
Map stores keys in sorted order.

// Key and values can be of any datatype.
map<int, int> m1;
map<pair<int, int>, int> m2;
map<int, pair<int, int>> m3;

Multimap:
========
Similar to Map except it can store multiple keys (duplicate keys)

Unordered Map:
=============
unordered_map is an associated container that stores elements formed by the combination
of a key value and a mapped value.
The key value is used to uniquely identify the element and the mapped value is the content
associated with the key.
Both key and value can be of any type predefined or user-defined. In simple terms,
an unordered_map is like a data structure of dictionary type that stores elements in itself.
It contains successive pairs (key, value), which allows fast retrieval of an individual
element based on its unique key.

Keys can be stored in randomized manner.
*/

void map_explanination()
{
    // map definition
    map<int, int> m1;            // Key: int, value: int
    map<pair<int, int>, int> m2; // Key: pair, value: int
    map<int, pair<int, int>> m3; // Key: int, value: pair
    map<string, int> m4;         // Key: string, value: int

    // adding elements to the map
    m1[1] = 10;
    m1.insert({2, 20});
    m1.insert({3, 20});
    m1.insert({4, 30});

    cout << m1[1] << " " << m1[4] << endl;

    // printing
    for (auto it : m1)
    {
        cout << it.first << ":" << it.second << endl;
    }

    // find()
    auto itr1 = m1.find(3);
    cout << itr1->second << endl;

    for (auto itr = m1.find(2); itr != m1.end(); itr++)
    {
        cout << itr->first << " --> " << itr->second << endl;
    }
}

int main(void)
{
    map_explanination();
    return 0;
}