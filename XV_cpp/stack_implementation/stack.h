// File: stack.h
#include <iostream>
using namespace std;

// Using Array of Characters
class Stack
{
private: // Implementation
    char *data_;
    int top_;

public: // Interface
    Stack();
    ~Stack();
    int empty();
    void push(char x);
    void pop();
    char top();
};

// Using Vector
// class Stack
// {
// private:
//     vector<char> data_;
//     int top_;

// public:
//     Stack();
//     ~Stack();
//     int empty();
//     void push(char x);
//     void pop();
//     char top();
// };