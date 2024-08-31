#include <iostream>
#include <vector>
using namespace std;

class Construct
{
private:
    int data;
    int *ptr;

public:
    // default constructor
    Construct()
    {
        cout << " I am in default constructor" << endl;
        data = 0;
        ptr = new int;
        *ptr = 21;
    }
    // parameterised constructor
    Construct(int input)
    {
        cout << " I am in a parameterised constructor" << endl;
        data = input;
        ptr = new int;
        *ptr = 23;
    }

    // copy constructor
    // reference is used to avoid looping
    // const is used to avoid modification in original obj
    Construct(const Construct &temp)
    {
        cout << "I am in a copy constructor" << endl;
        this->data = temp.data;
        this->ptr = new int;
        this->ptr = temp.ptr;
    }

    // assign operator
    Construct &operator=(const Construct &temp)
    {
        cout << "I am in a assign operator" << endl;
        data = temp.data;
        this->ptr = new int;
        this->ptr = temp.ptr;
        return *this;
        // returning reference to avoid chaining problem
        // eg obj1=(obj2=obj3)=obj6
    }

    // move constructor
    // for concept https://www.youtube.com/watch?v=JAOZjf4KneY
    Construct(Construct &&temp) // rvalue reference.
    {
        cout << " I am in move constructor" << endl;
        this->data = temp.data;
        this->ptr = temp.ptr;
        temp.ptr = NULL;
    }
};

int main()
{
    vector<Construct> v1;
    // v1.push_back(Construct());//default & move constructor
    // (bcz its moving the reference/temporary obj);
    Construct a1;
    Construct a2 = a1; // copy constructor
    // v1.push_back(a1);//copy constructor(bcz it copying actual object)
    v1.push_back(move(a2)); // move constructor gets called
    Construct a3;           // default constructor
    a3 = a1;                // assign operator;
    Construct a5(move(a1)); // move constructor;

    return 0;
}