/*
A static data member:
-- is associated with class not with object.
-- is shared by all the objects of a class
-- needs to be defined outside the class scope
   (in addition to the declaration within the class scope) to avoid linker error
-- must be initialized in a source file
-- is constructed before main() starts and destructed after main() ends
-- can be private / public type
-- can be accessed:
   -- with the class-name followed by the scope resolution operator (::)
   -- as a member of any object of the class

eg.
class MyClass {
    static int x; // Declaration
    ..
    ..
};

int Myclass::x = 0; // Definition


A static member function:
-- does not have this pointer – not associated with any object
-- cannot access non-static data members
-- cannot invoke non-static member functions
-- is needed to read / write static data members
-- may initialize static data members even before any object creation
-- cannot co-exist with a non-static version of the same function
-- cannot be declared as const
*/