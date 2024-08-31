#include <iostream>
using namespace std;

void pair_explaination()
{
    pair<int, int> p_int = {10, 20};
    cout << p_int.first << " " << p_int.second << endl;

    // Nested Pair
    pair<int, pair<int, int>> pp_int = {1, {2, 3}};
    cout << pp_int.first << " " << pp_int.second.first << " " << pp_int.second.second << endl;

    // Array of Pairs
    pair<int, int> arr[] = {{5, 6},
                            {7, 8}};
    cout << arr[0].first << endl;
}

int main(void)
{
    pair_explaination();
    return 0;
}
