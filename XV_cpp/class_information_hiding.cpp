#include <iostream>
using namespace std;

/*
Stack using array of characters.
Data Members: Private
Methods: Public
*/

class Stack
{
private:
    char *data_;
    int top_;

    // Using Vector
    // vector<char> data_;
    // int top_;

public:
    // Initialization
    Stack() : data_(new char[100]), top_(-1) {}

    // Using Vector
    // Stack() : top_(-1) {data_.resize(100);}

    // De-Initialization
    ~Stack() { delete[] data_; }

    // Using Vector
    // ~Stack() {}

    int empty() { return (top_ == -1); }

    void push(char x) { data_[++top_] = x; }

    void pop() { --top_; }

    char top() { return data_[top_]; }
};

int main()
{
    Stack s;
    char str[10] = "ABCDE";

    for (int i = 0; i < 5; ++i)
        s.push(str[i]);

    // Reverse string/array using Stack
    while (!s.empty())
    {
        cout << s.top();
        s.pop();
    }
    cout << endl;

    return 0;
}