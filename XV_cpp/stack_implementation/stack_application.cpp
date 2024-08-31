#include "stack.h"

int main()
{
    Stack s; // Object creation
    char str[10] = "ABCDE";

    for (int i = 0; i < 5; ++i)
        s.push(str[i]); // Push into the Stack

    // Reverse the string/array using Stack
    while (!s.empty())
    {
        cout << s.top();
        s.pop();
    }
    cout << endl;

    return 0;
}