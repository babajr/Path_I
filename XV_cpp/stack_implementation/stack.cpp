#include "stack.h"

// File: Stack.cpp
// Implementation : Using Array of Characters

Stack::Stack() : data_(new char[100]), top_(-1) {}

Stack::~Stack() { delete[] data_; }

int Stack::empty() { return (top_ == -1); }

void Stack::push(char x) { data_[++top_] = x; }

void Stack::pop() { --top_; }

char Stack::top() { return data_[top_]; }

// Using Vectore
// Stack::Stack() : top_(-1) {data_.resize(100);}

// Stack::~Stack() {}

// int Stack::empty() { return (top_ == -1);}

// void Stack::push(char x) { data_[++top_] = x;}

// void Stack::pop() { --top_; }

// char Stack::top() { return data_[top_];}