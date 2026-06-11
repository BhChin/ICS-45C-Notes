#include <iostream>
#include <string>
using namespace std;

//--------------5.7---------------- std::string
int standard_string() {

    //While C-style strings are fine to use, they are hard to work with
    //It is better to use std::string instead.

    string x {};
    x = "John";

    //std::string can handle strings at different lengths

    cout << "Enter your full name: ";
    string name{};
    cin >> name; // this won't work as expected since std::cin breaks on whitespace

    cout << "Enter your favorite color: ";
    string color{};
    cin >> color;

    cout << "Your name is " << name << " and your favorite color is " << color << endl;
    //if you were to put the enter the name John Doe, it won't work
    //Doe is left in cin waiting to be extracted
    // It would print "Your name is John and your favorite color is Doe"


    getline(std::cin >> std::ws, name);
    //getline fixes this. Requires 2 parameters: std::cin and string variable
    //std::ws tells std::cin to ignore leading whitespace

    cout << name.length() << endl; //length of a string

    //initializing std::string is expensive
    //DON'T pass std::string by value because as a function parameter, a copy of the string is expensive


    //literals
    //double quoted string literals are C-style strings by default

    std::cout << "goo\n"s; //s suffix is a std::string literal

    //constexpr std::string will generate an error

    return 0;
}

//------------12.12------------- Return by reference and address:
const std::string& getProgramName() {
    static const std::string s_programName {"Calculator"}; //static duration, destroyed at end of program
    return s_programName;;
}

const std::string& getProgramName2() {
    const std::string s_programName {"Calculator"}; //reference is left dangling (references an object that is destroyed)
    return s_programName;; //returning a literal also will be destroyed

}

int reference() {

    //passing std::string as an argument is expensive because a copy of it is made first
    //its better to return by reference

    //example is up top

    //object being returned by reference must exist after the function returns

    //don't return non-const static local variables by reference
    //not using const will cause multiple calls to a function to reference the same value

    return 0;
}

//-----------14.11------------ default constructor and argument:
int default_c_and_a(){

    //default constructor: a constructor that can be called with no arguments
    class Foo {
    public:
        Foo() {
            cout << "constructed" << endl;
        }
    };

    Foo foo{}; //value initialization. preferred, safe, consistent
    Foo foo2; //default initialization

    //constructors with default arguments

    class Foo2 {
    public:
        Foo2(int x = 0, int y = 0) {
            ;
        }
    };

    Foo2 a{}; // (0,0)
    Foo2 b{6,7}; //(6,7)
    //if all parameters have defaults, the constructor is a default constructor

    //only one default constructor allowed
    //if Foo were to have multiple constructors, Foo f{} would be ambiguous

    //implicit default constructor: if no constuctors defined, one is created automatically
    //equivalent to Foo() {}

    //explicit default constructor: = default
    // Foo() = default;
    //prefer = default over empty {} constructor

    class User {
    public:
        User() {}
    };

    class Default {
    public:
        Default() = default;
    };

    User user{}; // not zero initialized
    Default def{}; //zero initialized

    //Default is safer (0 initialized). User may contain garbage

    //summary:

    //Foo() -> default constuctor
    //Foo(int x = 0) -> default constructor
    //Foo() = default -> best practice
    //Foo foo{} -> safest initialization

    return 0;
}

//--------17.7--------- C-style arrays:

int cArrays() {

    int testScore[30] {}; //c-tyle array containing 30 value-initialized int elements
    //must be length 1 atleast

    //array length must be const
    //out of bounds index will result in undefined behavior

    //can't use auto on initializing arrays

    const int prime1[5] {2,3,5,7,11}; //defined to be length 5 but is redundant
    const int prime2[] {2,3,5,7,11}; //since you want 5 numbers, you don't need to specific its length. it will do it automatically

    //defining arrays as const or constexpr makes it so the list isn't mutable

    //sizeof() to find the size of an object or type in bytes
    //size of an array is dependent on how many elements
    //if you have an array of 5 4byte ints, it will be a 20 byte list

    std::cout << std::ssize(prime1) << '\n'; //returns signed integral value 5

    //array assignment is invalid
    //prime1 = {1,2,3,4,5} doesn't work




    return 0;
}

//------------17.8------------ C style array decay

int decay() {

    //c had 2 problems
    //copying large arrays is expensive like when passing a large array as an argument to a function
    //no way to pass arrays of different sizes to the same function

    //array decays into pointers that point to its first element (but can still access every element)when used in expressions

    int arr[5] {1,2,3,4,5};
    auto ptr = arr; //ptr is int*

    //arrays are not pointers
    //become pointers when used
    //array length information is lost during decay

    //void func(int arr[1000]) = void func(int* arr)
    //you are passing address, not copying the array
    //works with any size array
    //this is because arrays of different sizes ultimately decay to int*

    //array indexing = pointer indexing
    //arr[2] = *(arr + 2)
    //ptr[2] = arr[2]

    //preferred function parameter syntax:
    //void func(const int arr[])
    //or
    //void func (const int* arr) //equivalent but not as preferred

    //do not decay in: sizeof(arr), typeid(arr), &arr, passed by reference





    return 0;
}

//-----------17.9------------ pointer arithmetic and subscripting

int pointer() {

    int arr[5]{10, 20, 30, 40, 50};
    int* ptr = arr; //ptr points to first element but isn't stuck

    //pointers represent the address
    //ptr + 1 returns the address of the object next in line
    //ptr - 1 returns the address of the object previously in line

    cout << *(ptr + 1) << endl; //prints 20
    // ptr[n] == *(ptr + n)

    int* ptr2 = &arr[3]; //position is relative

    cout << *(ptr2 + 1) << endl;
    cout << *(ptr2 - 1) << endl;

    //you can loop through a pointer
    const int* begin = arr;        // &arr[0]
    const int* end{ arr + std::size(arr) };    // one-past-the-end

    for (; begin != end; ++begin)
    {
        cout << *begin << " ";  // access current element
    }
    cout << endl;

    return 0;

}

//------------17.10------------ C style strings
#include <cstring>
int cStrings() {

    //C strings are C arrays whose element type is char or const char
    char str1[8] {}; //an array of 8 char
    const char str2[] {"string"}; //an array of 7 char
    //1 extra character for implicit null terminator
    //better to let the initializer auto calculate length

    //c style strings are fixed-size arrays so if you need user input, just make the size really large like 255

    //you can't assign values to a c style string but you can change specific elements using []

    //use std::size() or std::ssize() to get the length of a string as an array
    //doesn't return the length of the string but the length of the array (length of string + null terminator)
    //doesn't work on pointers

    std::cout << strlen(str2) << endl; //prints length 6
    const char *ptr {str2};
    std::cout << strlen(ptr) <<endl;//prints length 6




    return 0;
}


//--------operator overloading-------:

int overload() {

    int x = 3;
    int y = 4;
    //x + y is actually the call to the function operator+(x,y)

    class Mystring {
    public:
        Mystring(string s){}
    };

    Mystring string1 {"Hello"};
    Mystring string2 {" World"};
    //adding string1 + string2 doesn't work for program defined types
    //to bypass this, we need to write an overloaded function to tell the compiler how the + should work for this type

    //you can overload almost any existing operator
    //you can only overload operators that exist

    //at least one of the operands in an overloaded operator must be a user defined type
    //ex: operator+(int, Mystring) but not operator+(int, double)




    return 0;

}

//------------21.4------------- overloading << and >>

class Point {
private:
    double m_x{};
    double m_y{};
    double m_z{};
public:
    Point(double x = 0.0, double y = 0.0, double z = 0.0) : m_x {x}, m_y{y}, m_z{z}{}

    friend std::ostream& operator<< (std::ostream& out, const Point& p); //overloaded function for cout looks like this
    friend std::istream& operator>>(std::istream& in, Point& p);

    double getX() const {return m_x;}
    double getY() const {return m_y;}
    double getZ() const {return m_z;}

};

//overload cout
std::ostream& operator<< (std::ostream& out, const Point& p) {
    out << "Point(" << p.getX() << ", " << p.getY() << ", "  << p.getZ() << ")"  << endl;

    return out;
    //std::cout << p << "\n" allows chaining
    //cout << p == operator(cout, p)
}

//overload cin
std::istream& operator>> (std::istream& in, Point& p) {

    //basic
    //in >> p.m_x >> p.m_y >> p.m_z;
    //return in;
    //partial input = broken object
    //input: 4.0b 5.6 7.2
    //results x = 4.0, y = 0 (fail), z = unchanged

    //transactional
    //double x{}, y{}, z{};

    //if (in >> x >> y >> z) //only if all suceed
      //  p = Point({x,y,z});

    //return in;


    //alternative

    double x {}, y{}, z{};
    in >> x >> y >> z;
    p = in ? Point{x,y,z}: Point{}; //default if fail

    return in;

}

int overload_cin_cout() {

    //---------problem--------
    //printing objects is annoying


    Point p{5,6,7};

    cout << "Point(" << p.getX() << ", " << p.getY() << ", "  << p.getZ() << ")"  << endl; //tedious and long
    //or create a print function but you can't chain with cout

    //the goal is to do std::cout << p
    //friend std::ostream& operator << (std::ostream& out, const Point& point);


    return 0;
}
//--------------21.5------------- overloading operators using member functions
class Cents
{
private:
    int m_cents {};

public:
    Cents(int cents)
        : m_cents { cents } { }

    // Overload Cents + int
    Cents operator+(int value) const; //Cents::operator+ instead of friend operator+

    int getCents() const { return m_cents; }
};

// note: this function is a member function!
// the cents parameter in the friend version is now the implicit *this parameter
Cents Cents::operator+ (int value) const
{
    return Cents { m_cents + value };
}

int member() {

    //overloading using member functions rules:
    //1. overloaded operator must be added as a member function of the left operand
    //2. the left operand becomes the implicit *this object
    //3. all other operands become function parameters

    //when to use member:
    // = (assignment)
    // [] indexing
    // () function call
    // -> member access


    return 0;
}

//-------------28.6------------ file i/o
#include <fstream>

int file() {

    //file i/o works like cin and cout but you must open files yourself

    //--------file output-------
    std::ofstream outf{"poop.txt"};

    //if we can't open the file
    if (!outf) {
        std::cerr << "can't be open for writing"; //prints error and exit
        return 1;
    }

    //write lines into file
    outf << "line 1\n";
    outf << "line2" << endl;



    //------file input------

    std::ifstream inf { "Poop.txt"};

    if (!inf) {
        std::cerr << "Can't be opened for reading\n";
        return 1;
    }

    std::string strInput{};
    while (inf >> strInput) {
        std::cout <<strInput <<endl; //reads out contents of file but breaks on white space if we were to add a sentence
    }

    //to read sentences use getline()

    //replace the while statement
    //while(std::getline(inf, strInput))
    //std::cout << strInput << endl;

    return 0;
}