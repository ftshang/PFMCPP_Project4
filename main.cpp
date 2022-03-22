/*
 Project 4 - Part 2 / 9
 Video: Chapter 3 Part 6

 Create a branch named Part2

New/This/Pointers/References conclusion

    Build/Run often with this task to make sure you're not breaking the code with each step.
    I recommend committing after you get each step working so you can revert to a working version easily if needed.
 
 0) in the blank space below, declare/define an empty struct named 'A' on a single Line. 
     on the lines below it, write a struct named 'HeapA' that correctly shows how to own an instance of 'A' 
         on the heap without leaking, without using smart pointers. 
 */

// Instruction 0
struct A {};

struct HeapA 
{
    // Member Variables
    A* aPtr = nullptr;

    // Constructor
    HeapA() : aPtr{new A()}
    {}

    // Destructor
    ~HeapA()
    {
        delete aPtr;
    }
};


 /*
 1) Edit your 3 structs so that they own a heap-allocated primitive type without using smart pointers named 'value'
         IntType should own a heap-allocated int, for example.
 
 2) give it a constructor that takes the appropriate primitive
    this argument will initialize the owned primitive's value.
         i.e. if you're owning an int on the heap, your ctor argument will initialize that heap-allocated int's value.
 
 3) modify those add/subtract/divide/multiply member functions from chapter 2 on it
         a) make them modify the owned numeric type
         b) set them up so they can be chained together.
             i.e.
             DoubleType dt(3.5);
             dt.add(3.0).multiply(-2.5).divide(7.2); //an example of chaining
 
 4) write add/subtract/divide/multiply member functions for each type that take your 3 UDTs
        These are in addition to your member functions that take primitives
        for example, IntType::divide(const DoubleType& dt);
        These functions should return the result of calling the function that takes the primitive.
        This technique of having multiple functions with the same name and different function arguments is known as 'function overloading' or 'overloaded functions'.
        This topic will be covered in Chapter 4 Part 7.
     
 5) Don't let your heap-allocated owned type leak!
 
 6) replace your main() with the main() below.
    It has some intentional mistakes that you need to fix to match the expected output
    i.e. don't forget to dereference your pointers to get the value they hold.

 7) click the [run] button.  Clear up any errors or warnings as best you can.
 */

/*
your program should generate the following output EXACTLY.
This includes the warnings.
Use a service like https://www.diffchecker.com/diff to compare your output. 
you'll learn to solve the conversion warnings in the next project part.

18 warnings generated.
FloatType add result=4
FloatType subtract result=2
FloatType multiply result=4
FloatType divide result=0.25

DoubleType add result=4
DoubleType subtract result=2
DoubleType multiply result=4
DoubleType divide result=0.8

IntType add result=4
IntType subtract result=2
IntType multiply result=4
IntType divide result=1

Chain calculation = 590
New value of ft = (ft + 3.0f) * 1.5f / 5.0f = 0.975
---------------------

Initial value of dt: 0.8
Initial value of it: 590
Use of function concatenation (mixed type arguments) 
New value of dt = (dt * it) / 5.0f + ft = 95.375
---------------------

Intercept division by 0 
New value of it = it / 0 = error: integer division by zero is an error and will crash the program!
590
New value of ft = ft / 0 = warning: floating point division by zero!
inf
New value of dt = dt / 0 = warning: floating point division by zero!
inf
---------------------

good to go!


/*
 MAKE SURE YOU ARE NOT ON THE MASTER BRANCH

 Commit your changes by clicking on the Source Control panel on the left, entering a message, and click [Commit and push].
 
 If you didn't already: 
    Make a pull request after you make your first commit
    pin the pull request link and this repl.it link to our DM thread in a single message.

 send me a DM to review your pull request when the project is ready for review.

 Wait for my code review.
 */


#include <iostream>

// Forward declarations
struct DoubleType;
struct IntType;

struct FloatType
{
    // Instruction 3
    FloatType& add( float rhs );
    FloatType& subtract( float rhs );
    FloatType& multiply( float rhs );
    FloatType& divide( float rhs );

    // Heap-Allocated Float (Instruction 1)
    float* fltPtr = new float;
    float& value = *fltPtr;

    // Constructor (Instruction 2)
    FloatType(float fValue)
    {
        *fltPtr = fValue;
    }

    // Additional Member Functions (Instruction 4)
    FloatType& add(const FloatType& flt);
    FloatType& add(const DoubleType& dbl);
    FloatType& add(const IntType& it);

    FloatType& subtract(const FloatType& flt);
    FloatType& subtract(const DoubleType& dbl);
    FloatType& subtract(const IntType& it);

    FloatType& multiply(const FloatType& flt);
    FloatType& multiply(const DoubleType& dbl);
    FloatType& multiply(const IntType& it);

    FloatType& divide(const FloatType& flt);
    FloatType& divide(const DoubleType& dbl);
    FloatType& divide(const IntType& it);
};

struct DoubleType
{
    // Instruction 3
    DoubleType& add( double rhs );
    DoubleType& subtract( double rhs );
    DoubleType& multiply( double rhs );
    DoubleType& divide( double rhs );

    // Heap-Allocated Double (Instruction 1)
    double* dblPtr = new double;
    double& value = *dblPtr;

    // Constructor (Instruction 2)
    DoubleType(double dValue)
    {
        *dblPtr = dValue;
    }

    // Instruction 4
    DoubleType& add(const FloatType& flt);
    DoubleType& add(const DoubleType& dbl);
    DoubleType& add(const IntType& it);

    DoubleType& subtract(const FloatType& flt);
    DoubleType& subtract(const DoubleType& dbl);
    DoubleType& subtract(const IntType& it);

    DoubleType& multiply(const FloatType& flt);
    DoubleType& multiply(const DoubleType& dbl);
    DoubleType& multiply(const IntType& it);

    DoubleType& divide(const FloatType& flt);
    DoubleType& divide(const DoubleType& dbl);
    DoubleType& divide(const IntType& it);
};

struct IntType
{
    // Instruction 3
    IntType& add(int rhs);
    IntType& subtract(int rhs);
    IntType& multiply(int rhs);
    IntType& divide(int rhs);

    // Heap-Allocated Int (Instruction 1)
    int* intPtr = new int;
    int& value = *intPtr;

    // Constructor (Instruction 2)
    IntType(int iValue)
    {
        *intPtr = iValue;
    }

    // Instruction 4
    IntType& add(const FloatType& flt);
    IntType& add(const DoubleType& dbl);
    IntType& add(const IntType& it);

    IntType& subtract(const FloatType& flt);
    IntType& subtract(const DoubleType& dbl);
    IntType& subtract(const IntType& it);

    IntType& multiply(const FloatType& flt);
    IntType& multiply(const DoubleType& dbl);
    IntType& multiply(const IntType& it);

    IntType& divide(const FloatType& flt);
    IntType& divide(const DoubleType& dbl);
    IntType& divide(const IntType& it);
};

FloatType& FloatType::add(const FloatType& flt)
{
    return add(flt.value);
}

FloatType& FloatType::add(const DoubleType& dbl)
{
    return add(dbl.value);
}

FloatType& FloatType::add(const IntType& it)
{
    return add(it.value);
}

FloatType& FloatType::subtract(const FloatType& flt)
{
    return subtract(flt.value);
}

FloatType& FloatType::subtract(const DoubleType& dbl)
{
    return subtract(dbl.value);
}

FloatType& FloatType::subtract(const IntType& it)
{
    return subtract(it.value);
}

FloatType& FloatType::multiply(const FloatType& flt)
{
    return multiply(flt.value);
}

FloatType& FloatType::multiply(const DoubleType& dbl)
{
    return multiply(dbl.value);
}

FloatType& FloatType::multiply(const IntType& it)
{
    return multiply(it.value);
}

FloatType& FloatType::divide(const FloatType& flt)
{
    return divide(flt.value);
}

FloatType& FloatType::divide(const DoubleType& dbl)
{
    return divide(dbl.value);
}

FloatType& FloatType::divide(const IntType& it)
{
    return divide(it.value);
}

FloatType& FloatType::add(float rhs)
{
    *fltPtr += rhs;

    return *this;
}

FloatType& FloatType::subtract(float rhs)
{
    *fltPtr -= rhs;
    return *this;
}

FloatType& FloatType::multiply(float rhs)
{
    *fltPtr *= rhs;
    return *this;
}

FloatType& FloatType::divide(float rhs)
{
    if ( rhs == 0.f )
        std::cout << "\nwarning, floating point division by zero returns 'inf' !" << std::endl;
    
    *fltPtr /= rhs;
    return *this;
}

DoubleType& DoubleType::add(const FloatType& flt)
{
    return add(flt.value);
}

DoubleType& DoubleType::add(const DoubleType& dbl)
{
    return add(dbl.value);
}

DoubleType& DoubleType::add(const IntType& it)
{
    return add(it.value);
}

DoubleType& DoubleType::subtract(const FloatType& flt)
{
    return subtract(flt.value);
}

DoubleType& DoubleType::subtract(const DoubleType& dbl)
{
    return subtract(dbl.value);
}

DoubleType& DoubleType::subtract(const IntType& it)
{
    return subtract(it.value);
}

DoubleType& DoubleType::multiply(const FloatType& flt)

{
    return multiply(flt.value);
}

DoubleType& DoubleType::multiply(const DoubleType& dbl)
{
    return multiply(dbl.value);
}

DoubleType& DoubleType::multiply(const IntType& it)
{
    return multiply(it.value);
}

DoubleType& DoubleType::divide(const DoubleType& dbl)
{
    return divide(dbl.value);
}

DoubleType& DoubleType::divide(const FloatType& flt)
{
    return divide(flt.value);
}

DoubleType& DoubleType::divide(const IntType& it)
{
    return divide(it.value);
}

DoubleType& DoubleType::add(double rhs)
{
    *dblPtr += rhs;
    return *this;
}

DoubleType& DoubleType::subtract(double rhs)
{
    *dblPtr -= rhs;
    return *this;
}

DoubleType& DoubleType::multiply(double rhs)
{
    *dblPtr *= rhs;
    return *this;
}

DoubleType& DoubleType::divide(double rhs)
{
    if ( rhs == 0.0 )
        std::cout << "\nwarning, floating point division by zero returns 'inf' !" << std::endl;

    *dblPtr /= rhs;
    return *this;
}

IntType& IntType::add(const FloatType& flt)
{
    return add(flt.value);
}

IntType& IntType::add(const DoubleType& dbl)
{
    return add(dbl.value);
}

IntType& IntType::add(const IntType& it)
{
    return add(it.value);
}

IntType& IntType::subtract(const FloatType& flt)
{
    return subtract(flt.value);
}

IntType& IntType::subtract(const DoubleType& dbl)
{
    return subtract(dbl.value);
}

IntType& IntType::subtract(const IntType& it)
{
    return subtract(it.value);
}

IntType& IntType::multiply(const FloatType& flt)
{
    return multiply(flt.value);
}

IntType& IntType::multiply(const DoubleType& dbl)
{
    return multiply(dbl.value);
}

IntType& IntType::multiply(const IntType& it)
{
    return multiply(it.value);
}

IntType& IntType::divide(const FloatType& flt)
{
    return divide(flt.value);
}

IntType& IntType::divide(const DoubleType& dbl)
{
    return divide(dbl.value);
}

IntType& IntType::divide(const IntType& it)
{
    return divide(it.value);
}

IntType& IntType::add(int rhs)
{
    *intPtr += rhs;
    return *this;
}

IntType& IntType::subtract(int rhs)
{
    *intPtr -= rhs;
    return *this;
}

IntType& IntType::multiply(int rhs)
{
    *intPtr *= rhs;
    return *this;
}

IntType& IntType::divide(int rhs)
{
    if (rhs == 0)
    {
        std::cout << "error, integer division by zero will crash the program!" << std::endl;
    }
    else 
    {
        *intPtr /= rhs;
    }
    
    return *this;
}

int main() 
{   
    //testing instruction 0
    HeapA heapA; 

    //assign heap primitives
    FloatType ft ( 2.0f );
    DoubleType dt ( 2 );
    IntType it ( 2 ) ;

    std::cout << "FloatType add result=" << ft.add( 2.0f ).value << std::endl;
    std::cout << "FloatType subtract result=" << ft.subtract( 2.0f ).value << std::endl;
    std::cout << "FloatType multiply result=" << ft.multiply( 2.0f ).value << std::endl;
    std::cout << "FloatType divide result=" << ft.divide( 16.0f).value << std::endl << std::endl;

    std::cout << "DoubleType add result=" << dt.add(2.0).value << std::endl;
    std::cout << "DoubleType subtract result=" << dt.subtract(2.0).value << std::endl;
    std::cout << "DoubleType multiply result=" << dt.multiply(2.0).value << std::endl;
    std::cout << "DoubleType divide result=" << dt.divide(5.f).value << std::endl << std::endl;

    std::cout << "IntType add result=" << it.add(2).value << std::endl;
    std::cout << "IntType subtract result=" << it.subtract(2).value << std::endl;
    std::cout << "IntType multiply result=" << it.multiply(2).value << std::endl;
    std::cout << "IntType divide result=" << it.divide(3).value << std::endl << std::endl;
    std::cout << "Chain calculation = " << (it.multiply(1000).divide(2).subtract(10).add(100)).value << std::endl;

        // FloatType object instanciation and method tests
    // --------
    std::cout << "New value of ft = (ft + 3.0f) * 1.5f / 5.0f = " << ft.add( 3.0f ).multiply(1.5f).divide(5.0f).value << std::endl;
       
    std::cout << "---------------------\n" << std::endl; 
    
    // DoubleType/IntType object instanciation and method tests
    // --------
    std::cout << "Initial value of dt: " << dt.value << std::endl;
    std::cout << "Initial value of it: " << it.value << std::endl;
    // --------
    std::cout << "Use of function concatenation (mixed type arguments) " << std::endl;
    std::cout << "New value of dt = (dt * it) / 5.0f + ft = " << (dt.multiply(it).divide(5.0f).add(ft).value) << std::endl;

    std::cout << "---------------------\n" << std::endl; 
    
    // Intercept division by 0
    // --------
    std::cout << "Intercept division by 0 " << std::endl;
    std::cout << "New value of it = it / 0 = " << it.divide(0).value << std::endl;
    std::cout << "New value of ft = ft / 0 = " << ft.divide(0).value << std::endl;
    std::cout << "New value of dt = dt / 0 = " << dt.divide(0).value << std::endl;

    std::cout << "---------------------\n" << std::endl; 

    std::cout << "good to go!\n";

    return 0;
}



// int main() 
// {
//     FloatType ft;
//     std::cout << "result of ft.add(): " << ft.add( 123.456f, 432.1f) << std::endl;
//     std::cout << "result of ft.subtract(): " << ft.subtract( 123.456f, 432.1f) << std::endl;
//     std::cout << "result of ft.multiply(): " << ft.multiply( 123.456f, 432.1f) << std::endl;
//     std::cout << "result of ft.divide(): " << ft.divide( 123.456f, 432.1f) << std::endl;

//     std::cout << "result of ft.add(): " << ft.add( 4444.56f, 0.0f)  << std::endl;
//     std::cout << "result of ft.subtract(): " << ft.subtract( 4444.56f, 0.0f) << std::endl;
//     std::cout << "result of ft.multiply(): " << ft.multiply( 4444.56f, 0.0f) << std::endl;
//     std::cout << "result of ft.divide(): " << ft.divide( 4444.56f, 0.0f) << std::endl;

//     DoubleType db;
//     std::cout << "result of db.add(): " << db.add( 123.456, 432.1) << std::endl;
//     std::cout << "result of db.subtract(): " << db.subtract( 123.456, 432.1) << std::endl;
//     std::cout << "result of db.multiply(): " << db.multiply( 123.456, 432.1) << std::endl;
//     std::cout << "result of db.divide(): " << db.divide( 123.456, 432.1) << std::endl;

//     std::cout << "result of db.add(): " << db.add( 123.456, 0.0) << std::endl;
//     std::cout << "result of db.subtract(): " << db.subtract( 123.456, 0.0) << std::endl;
//     std::cout << "result of db.multiply(): " << db.multiply( 123.456, 0.0) << std::endl;
//     std::cout << "result of db.divide(): " << db.divide( 123.456, 0.0) << std::endl;

//     IntType i;
//     std::cout << "result of i.add(): " << i.add( 10, 20) << std::endl;
//     std::cout << "result of i.subtract(): " << i.subtract( 10, 20) << std::endl;
//     std::cout << "result of i.multiply(): " << i.multiply( 10, 20) << std::endl;
//     std::cout << "result of i.divide(): " << i.divide( 10, 20) << std::endl;

//     std::cout << "result of i.add(): " << i.add( 10, 0) << std::endl;
//     std::cout << "result of i.subtract(): " << i.subtract( 10, 0) << std::endl;
//     std::cout << "result of i.multiply(): " << i.multiply( 10, 0) << std::endl;
//     std::cout << "result of i.divide(): " << i.divide( 10, 0) << std::endl;

//     std::cout << "good to go!" << std::endl;
// }
