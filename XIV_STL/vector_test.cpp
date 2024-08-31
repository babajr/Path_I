#include <iostream>
#include <vector>
using namespace std;

/*
Vectors in STL are basically dynamic arrays that have the ability to
change size whenever elements are added or deleted from them.
*/

void vector_explaination_1()
{
    vector<int> v;

    for (int i = 0; i < 10; i++)
    {
        v.push_back(i);
    }

    cout << "the elements in the vector: ";
    for (auto it = v.begin(); it != v.end(); it++)
        cout << *it << " ";

    cout << "\nThe front element of the vector: " << v.front();
    cout << "\nThe last element of the vector: " << v.back();
    cout << "\nThe size of the vector: " << v.size();
    cout << "\nDeleting element from the end: " << v[v.size() - 1];
    v.pop_back();

    cout << "\nPrinting the vector after removing the last element:" << endl;
    for (int i = 0; i < v.size(); i++)
        cout << v[i] << " ";

    cout << "\nInserting 5 at the beginning:" << endl;
    v.insert(v.begin(), 5);
    cout << "The first element is: " << v[0] << endl;
    cout << "Erasing the first element" << endl;
    v.erase(v.begin());
    cout << "Now the first element is: " << v[0] << endl;

    if (v.empty())
        cout << "\nvector is empty";
    else
        cout << "\nvector is not empty" << endl;

    cout << "Capacity: " << v.capacity() << endl;
    cout << "Max Size: " << v.max_size() << endl;

    v.clear();
    cout << "Size of the vector after clearing the vector:" << v.size();
}

void vector_explanination()
{
    vector<int> v;

    // push_back() and emplace_back() do the same operation.
    // emplace_back() is faster.
    v.push_back(1);
    v.emplace_back(2);

    vector<int> v1(5);    // 0 0 0 0 0
    vector<int> v2(5, 1); // 1 1 1 1 1
    vector<int> v2_cp(v2);

    // Iterator declaration/definition
    vector<int>::iterator it = v2.begin();

    // Use of iterator to iterate over the vector
    // begin() will point to zeroth element in the vector.
    // end() will point to the next to last element in the vector.
    // for (; it != v2.end(); it++)
    // {
    //     cout << *it << " ";
    // }
    // cout << endl;

    for (auto iter = v2.begin(); iter != v2.end(); iter++)
    {
        cout << *iter << " ";
    }
    cout << endl;

    // for each loop
    // for (auto it : v2)
    // {
    //     cout << it << " ";
    // }
    // cout << endl;

    // erase() --> delete element from the vector
    // insert() --> insert element in the vector
    v2.insert(v2.begin(), 2);
    for (auto iter = v2.begin(); iter != v2.end(); iter++)
    {
        cout << *iter << " ";
    }
    cout << endl;

    v2.erase(v2.begin());
    for (auto iter = v2.begin(); iter != v2.end(); iter++)
    {
        cout << *iter << " ";
    }
    cout << endl;
}

int main(void)
{
    vector_explanination();
    // vector_explaination_1();
    return 0;
}