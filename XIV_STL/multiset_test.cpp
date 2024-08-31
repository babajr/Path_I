#include <iostream>
#include <set>
using namespace std;

/*
Multisets are a type of associative containers similar to the set,
with the exception that multiple elements can have the same values
multiset <data_type> set_name;
*/

void multiset_explanination()
{
    multiset<int> st;

    st.insert(1); // {1}
    st.insert(2); // {1, 2}
    st.insert(1); // {1, 1, 2}

    cout << st.count(1) << endl; // 2
}

int main(void)
{
    multiset_explanination();
    return 0;
}