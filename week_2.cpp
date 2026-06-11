//------------9.1-----------: Testing your Code

//-------------2.1------------ Header files

//to add functions from another file, you need to create a header file
//create the function in the other file
//declare it in the header file (not definition aka the body)
//#include "file.name" in the main file
//avoid including cpp files because it can cause name collisions

//-----------5.1------------- constant variables

//constant: a value that isn't changed during the program's execution

//named constants: constant values that have an identifier
//literal constants constant values that don't have an identifier

//constants help prevent accidentally changing the value of a constants
//optimizes program by not being able to assume a value won't change
//reduces complexity of program

const double gravity = 9.8; //more conventional
// or
int const sidesInSquare = 4;

//constants must be initialized to a value when you define them
//programmers often name constants with a "k" at the start or uppercase every letter

//object like macros
#define GRAVITY 9.8

//harder to debug than constants, all subsequent calls are replaced by the macro


//-----------6.4-------------: increment/decrement operators
//++x = increment x then return x
//x++ copy x, increment x, return copy

#include <iostream>
using namespace std;

int week_2() {

    int x = 5;
    int y = {++x}; //x is incremented to 6, x is evaluated to value 6, 6 is assigned to y

    // if it was x++, a copy of x is made, x is incremented to 6, copy of x is evaluated to value 5 and is assigned to y

    cout << x << " " << y << endl;


    return 0;
}

//--------------10.8------------: Type deduction using auto keyword

double d {5.0}; //this is redundant, d is declared as double, 5.0 is already a double. "auto" removes this duplication

auto b {5.0}; //double
auto i { 1 + 2}; //int
auto x { i }; //int


const auto c { 5 }; //const int
constexpr auto f { 5 }; //constexpr int

auto k { c }; //int (const removed)
//const doesn't carry over so you must rewrite it

//benefits of auto:

//1. cleaner, more readable
//prevents accidental uninitialized variables

int o;
//auto o; would error because it can't deduce a type for o

//downsides:
//hides type information

//--------------12.1----------- Compound Types:

//compound type: a type made by combining other types

//-----------12.2----------- Value Categories:

//Expression = something that produces a value
//Expressions have 2 properties:
//1. Type of value it produces
//2. category of the value: is it an lvalue or rvalue

//lvalue = something with a location (a variable)
//rvalue = temporary value (no location)

//lvalue:

int apple = 5;

//types of lvalues: modifiable, non-modifiable (const)

//rvalue:
//5
//x+1
//return5()

//assignment rule:
//x = 5  // VALID
//5 = x //ERROR

//left side must be an lvalue, right side must be a rvalue

//++x; is lvalue -> modifies and returns the variable
//x++; is rvalue -> returns old value

//string literals are lvalues -> "Hello"

//-------------12.3----------- Lvalue references:

//reference = another name for an existing variable

int hello(){

    int orange = 5;
    int& ref = orange; //int& = reference to int, & != address operator

//references must be initialized, can only refer to lvalues, can't bind to const
//can't make an existing reference, rereference a differen't variable

    int banana = 10;
    ref = banana; //this does NOT mean that the reference, references banana. This is equivalent to orange = banana
    //this means that orange will now equal 10.


    return 0;
}

//references aren't objects

//-------------12.4------------- Lvalue references const:

//you can't reference a const because you can modify a const variable through the reference
//however, you can create a const reference
//const referrence: can reference, but cant modify

const int poop = 5;
const int& ref = poop;

int yolo = 8;
const int& ref2 = yolo; //can't modify through ref2, can modify through yolo

//const references can bind to lvalues, const lvalues, rvalues
//normal references can't bind to rvalues

//const converts what ever value its set to, to its original type declaration
//if the const = 5, but the const reference type is double, it will turn the 5 into 5.0
//same with strings

//-----------12.5----------: pass by lvalue references:

void printValue(int y) {
    std::cout << y;
}

int happy = 5;
//printValue(happy);

//when printValue is called, happy is copied into y, function uses copy, copy is destroyed
//for small types like int, its inexpensive, but for big types such as std::string, it is EXPENSIVE

void printValue(std::string& y) {
    std::cout << y;
}

std::string yo {"Hello"};
//printValue(yo);  y is an alias of x, no copy is made


//pass by referrence allows us to change the value of an argument

void addOne(int y) {
    ++y; //modifies the copy of x, not the actual object x
}

void addOne2(int& y) {
    ++y; //modifies the actual object x
}

//pass by reference only accepts modifiable lvalue arguments

//-------------12.6-------------: pass by const lvalue reference
//a reference parameter const makes sure the function doesn't change the value being referenced
//a reference to const can bind to modifiable lvalues, non-modifiable lvalues, and rvalues

//------------14.2------------: intro to classes

//struct members are public by default
//class members are private by default
//you can modify this behavior using private and public keywords

class Employee {
public:
    int m_id {}; //"m_" is used to specify the classes member variables
    int m_age {};
    double m_wage {};

};

void printEmployee(const Employee& employee) {
    std::cout << employee.m_id << std::endl;
}

int classTest() {
    Employee jim {4,10,21};
    printEmployee(jim);
    return 0;
}

//----------14.3---------- member functions:

//member functions = functions that belong to a class type

//quiz:
struct IntPair {
    int int1 {};
    int int2 {};

    void print() {
        std::cout << "Pair(" << int1 << ", " << int2 << ")" << std::endl;
    }



};


//----------14.4--------- const objects

//objects can be made const
const IntPair obj1 {1,2};
//can't be modified after creation
//const objects can ONLY call const member functions
//void print() const{

//const member functions can't modifiy member variables and can't call non-const member functions

//-----------14.5--------- public and private m embers and access specifiers:

//public = can be accessed inside and outside the class
//private = can be accessed ONLY inside the class

class Date2 {
public:
    void print();

private:
    int m_day;
};

//structs are public by default
//class are private by default

//use structs for simple data

//-------------14.9------------- constructors:

class Foo {
private:
    int m_x {};
    int m_y {};

public:
    Foo(int x, int y) {
        cout << "Constructed" << endl;

    }

    void print() {
        cout << m_x << " " << m_y;
    }
};

Foo foo {6,7};
//foo.print(); prints 0 0 because constructors didn't assign values to members

//constructors do not create an object, they initialize it

//the constructor must match class name, have no return type, usually public

//----------------14.10-------------- constructir member intializer lists:

//need a way to initialize members

class Foo2 {
private:
    int m_x {};
    int m_y {};

public:
    Foo2(int x, int y)
        : m_x { x }, m_y { y } //IMPORANT
    {
        ;
    }

};

//: -> starts initiaizer list
//m_x { x } -> initializes member
//comma seperated

//execution order:
//order is based on class definition, not list order
//m_x is first regardless of list order because it was defined first in the member list


//-------------15.2----------- class and header files

//as your class gets bigger, it cna get messy
//one way to help is you can seperate the constructor definition

#include <iostream>

// class Date2
// {
// private:
//     int m_year{};
//     int m_month{};
//     int m_day{};
//
// public:
//     Date2(int year, int month, int day); // constructor declaration
//
//     void print() const; // print function declaration
//
//     int getYear() const { return m_year; }
//     int getMonth() const { return m_month; }
//     int getDay() const  { return m_day; }
// };
//
// Date2::Date(int year, int month, int day) // constructor definition
//     : m_year{ year }
// , m_month{ month }
// , m_day{ day }
// {
// }
//
// void Date2::print() const // print function definition
// {
//     std::cout << "Date(" << m_year << ", " << m_month << ", " << m_day << ")\n";
// };
//
//
// const Date2 d2{ 2015, 10, 14 };
// d2.print();


