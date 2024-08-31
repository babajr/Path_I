#include <iostream>
#include <set>
using namespace std;

/*
Sets are a type of associative container in which each element has to be unique because
the value of the element identifies it.
The values are stored in a specific sorted order i.e. either ascending or descending.

set <data_type> set_name;
*/

void set_explanination()
{
    set<int> st;

    st.insert(1); // {1} --> log(n)
    st.insert(2); // {1, 2}
    st.insert(1); // {1, 2}
    st.insert(3); // {1, 2, 3}
    st.insert(4); // {1, 2, 3, 4}

    // st.erase(4); // delete 4 --> log(n)

    for (auto iter : st)
    {
        cout << iter << " ";
    }

    cout << endl;

    // --> log(n)
    auto it = st.find(5); // if element is not found, it will return st.end().
    cout << *it << endl;

    int cnt = st.count(1); // returns 1 if element is presetn, returns 0 if not present.
    cout << cnt << endl;
}

int main(void)
{
    set_explanination();
    return 0;
}