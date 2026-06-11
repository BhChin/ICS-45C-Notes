#include <iostream>
#include <string>
using namespace std;
//-------5.2------- literals
int literals() {
    //literal = value written directly in code
    //constant by definition

    //ex:
    double d { 5.4};
    int apple { 5};

    //literal suffixes:

    //integer suffixes:
    //5u  unsigned int
    //5L  long
    //5LL long long

    //floating point suffixes
    //5.0f float
    //5.0 double (default)

    //"hello"s std::string
    //"hello"sv std::string_view

    float f{4.1}; //warning: 4.1 is double -> conversion happens
    float f2{4.1};//cprrect

    //scientific notation:
    double a{6.02e23};

    //magic numbers (bad practice)
    //don't use random literals since its not clear
    //create a const variable with a name that tells the reader where it comes from

    return 0;
}

int constants_constexpr() {

    //runtime = happens during execution
    //compile-time = can happen before program runs

    const double x {1.2};
    const double y {3.4};
    const double z {x + y}; //may happen at compile time because we know the values of x and y already

    const double d {1.2};

    //constant expression
    5;
    1.2;
    5 + 6;

    //rules:
    //all parts must be known at compile time
    //if one part is not, it makes the whole thing not a constant expression

    //what can be used in constant expressions??
    //literals, operators with constant operands, const integral variables, constexpr variables and functions

    //constant expressions improve performance, makes things less error prone


    //-------5.6------- constexpr

    //const does not guarantee compile time

    //constexpr = must be compile time
    //initializer must be a constant expression
    //works with non-integral types
    constexpr double gravity{9.8};

    //best practice:
    //if value is known at compile-time:
    constexpr int size{10};

    //if value is only known at runtime
    string input{};
    cin >> input;
    const string name{input};





    return 0;

}

constexpr int cmax(int x, int y){
    if (x>y) {
        return x;
    }else {
        return y;
    }
}

//you can't initialize a constexpr variable iwth a function call unless the function is also constexpr

//------6.6------ conditional operator

void notes()
{
    // ------------------------------------------
    // CONDITIONAL OPERATOR BASICS
    // ------------------------------------------

    int x{ 5 };
    int y{ 7 };

    // if-else version
    int max1;
    if (x > y)
        max1 = x;
    else
        max1 = y;

    // ternary version
    int max2{ (x > y) ? x : y };

    // ------------------------------------------
    // RETURNS A VALUE (EXPRESSION)
    // ------------------------------------------

    int z{ (x > y) ? x : y };

    // usable in:
    // - initialization
    // - return statements
    // - function arguments
    // - output

    std::cout << ((x > y) ? x : y) << '\n';

    // ------------------------------------------
    // CONSTEXPR USAGE
    // ------------------------------------------

    constexpr bool big{ false };
    constexpr int size{ big ? 30 : 20 }; // compile-time

    // ------------------------------------------
    // PRECEDENCE (COMMON BUG)
    // ------------------------------------------

    int a{ 2 };
    int b{ 1 };

    // ❌ WRONG
    int wrong{ 10 - a > b ? a : b };

    // actually:
    // (10 - a) > b ? a : b

    // ✔ CORRECT
    int correct{ 10 - ((a > b) ? a : b) };

    // ------------------------------------------
    // ALWAYS PARENTHESIZE
    // ------------------------------------------

    int safe{ (a > b) ? a : b };
    std::cout << ((a > b) ? a : b);

    // ------------------------------------------
    // ANOTHER COMMON BUG
    // ------------------------------------------

    int n{ 2 };

    // ❌ WRONG
    std::cout << (n < 0) ? "negative" : "non-negative";

    // ✔ CORRECT
    std::cout << ((n < 0) ? "negative" : "non-negative");

    // ------------------------------------------
    // TYPE RULES
    // ------------------------------------------

    // ✔ same types
    int t1{ (true ? 1 : 2) };

    // ✔ convertible types
    double t2{ (false ? 1 : 2.2) };

    // ⚠ dangerous (signed vs unsigned)
    unsigned int t3{ (true ? -1 : 2u) };

    // ❌ ERROR (no common type)
    // auto bad = (true ? 5 : "hello");

    // ------------------------------------------
    // GOOD USE CASES
    // ------------------------------------------

    int m{ (x > y) ? x : y };

    std::cout << ((x > y) ? x : y);

    int result = (x > y) ? x : y;

    // ------------------------------------------
    // BAD USE (TOO COMPLEX)
    // ------------------------------------------

    // ❌ avoid nested messy expressions
    // int messy = cond1 ? (cond2 ? a : b) : (cond3 ? c : d);

    // use if-else instead for readability

    // ------------------------------------------
    // SUMMARY (MENTAL MODEL)
    // ------------------------------------------

    // condition ? value_if_true : value_if_false;

    // rules:
    // 1. always parenthesize in complex expressions
    // 2. types must match or convert
    // 3. use for simple logic only
}


//--------17.11------ c style string symbolic constants

int c_string() {

    //2 ways to create c style string symbolic constants:
    const char name[] = "Alex"; //c style string initialized with c style string literal
    const char* const color = "Orange"; //pointer to c style string literal

    //both have different memory allocation
    //case 1: ends up with 2 copies
    ///case 2: pointer are better
    //if there are two pointers that point to the same value, the program may turn it into one single value to save memory

    //
    return 0;
}

// ==========================================
// ALL NOTES (INCLUDING DYNAMIC MEMORY) IN ONE FUNCTION
// ==========================================

int dynamic()
{
    // ==========================================
    // CONDITIONAL OPERATOR (?:)
    // ==========================================

    int x{ 5 };
    int y{ 7 };

    int max{ (x > y) ? x : y };

    std::cout << ((x > y) ? x : y) << '\n';

    // constexpr usage
    constexpr bool big{ false };
    constexpr int size{ big ? 30 : 20 };

    // precedence issue
    int a{ 2 };
    int b{ 1 };

    int wrong{ 10 - a > b ? a : b };         // ❌ wrong
    int correct{ 10 - ((a > b) ? a : b) };   // ✔ correct

    // type rules
    int t1{ (true ? 1 : 2) };
    double t2{ (false ? 1 : 2.2) };

    // ==========================================
    // DYNAMIC MEMORY (new / delete)
    // ==========================================

    // allocate memory on heap
    int* ptr{ new int };     // allocate int
    *ptr = 7;                // use it

    // initialization
    int* ptr2{ new int{ 10 } };

    // ------------------------------------------
    // DELETE MEMORY
    // ------------------------------------------

    delete ptr;
    ptr = nullptr; // prevent dangling pointer

    delete ptr2;
    ptr2 = nullptr;

    // ------------------------------------------
    // DANGLING POINTER (BAD)
    // ------------------------------------------

    int* badPtr{ new int{ 5 } };
    delete badPtr;

    // badPtr is now dangling
    // *badPtr;        // ❌ undefined behavior
    // delete badPtr;  // ❌ undefined behavior

    badPtr = nullptr; // fix

    // ------------------------------------------
    // MULTIPLE POINTERS ISSUE
    // ------------------------------------------

    int* p1{ new int{ 3 } };
    int* p2{ p1 }; // both point to same memory

    delete p1;     // both now dangling
    p1 = nullptr;

    // p2 is still dangling ❌

    // ------------------------------------------
    // NULL POINTER BEHAVIOR
    // ------------------------------------------

    int* nullPtr{ nullptr };

    delete nullPtr; // ✔ safe (does nothing)

    if (!nullPtr)
    {
        nullPtr = new int{ 8 }; // allocate if needed
    }

    delete nullPtr;
    nullPtr = nullptr;

    // ------------------------------------------
    // MEMORY LEAK (VERY IMPORTANT)
    // ------------------------------------------

    int* leak{ new int{ 5 } };

    // leak = new int{ 10 }; // ❌ memory leak (lost original address)

    delete leak; // ✔ must delete before reassignment
    leak = new int{ 10 };

    delete leak;
    leak = nullptr;

    // ------------------------------------------
    // ANOTHER MEMORY LEAK CASE
    // ------------------------------------------

    int value{ 5 };
    int* ptr3{ new int{ 7 } };

    delete ptr3;       // free memory
    ptr3 = &value;     // safe reassignment

    // ------------------------------------------
    // NOTHROW VERSION OF NEW
    // ------------------------------------------

    int* safeAlloc{ new (std::nothrow) int{} };

    if (!safeAlloc)
    {
        std::cerr << "Allocation failed\n";
    }

    delete safeAlloc;
    safeAlloc = nullptr;

    // ==========================================
    // KEY TAKEAWAYS
    // ==========================================

    // - new → allocates memory (heap)
    // - delete → frees memory
    // - always delete what you new
    // - set pointer to nullptr after delete
    // - avoid multiple owners of same pointer
    // - avoid memory leaks

    return 0;
}

// ==========================================
// 19.2 — Dynamic Arrays (ONLY YOUR CONTENT)
// ==========================================

int dynamic_arrays()
{
    // ------------------------------------------
    // WHY DYNAMIC ARRAYS?
    // ------------------------------------------

    // Fixed arrays:
    // - size must be known at compile-time

    // Dynamic arrays:
    // - size can be decided at runtime

    std::size_t length{ 10 }; // could come from user

    // ------------------------------------------
    // ALLOCATE ARRAY (new[])
    // ------------------------------------------

    int* array{ new int[length]{} }; // allocate + zero initialize

    array[0] = 5;

    // ------------------------------------------
    // DEALLOCATE ARRAY (delete[])
    // ------------------------------------------

    delete[] array;

    // IMPORTANT:
    // use delete[] NOT delete

    // delete array; ❌ undefined behavior

    // ------------------------------------------
    // LARGE ALLOCATIONS POSSIBLE
    // ------------------------------------------

    // dynamic arrays come from heap (large memory)
    // can allocate very large arrays

    // ------------------------------------------
    // NO SIZE INFORMATION
    // ------------------------------------------

    // dynamic array behaves like pointer
    // does NOT know its length

    // sizeof(array) ❌ won't give array size

    // ------------------------------------------
    // INITIALIZATION
    // ------------------------------------------

    // zero initialization
    int* arr1{ new int[length]{} };

    // manual initialization (pre C++11 style)
    int* arr2{ new int[5] };
    arr2[0] = 9;
    arr2[1] = 7;
    arr2[2] = 5;
    arr2[3] = 3;
    arr2[4] = 1;

    // initializer list (C++11+)
    int* arr3{ new int[5]{ 9, 7, 5, 3, 1 } };

    // using auto
    auto* arr4{ new int[5]{ 9, 7, 5, 3, 1 } };

    // ------------------------------------------
    // RESIZING ARRAYS
    // ------------------------------------------

    // ❌ cannot resize directly

    // must:
    // 1. allocate new array
    // 2. copy values
    // 3. delete old array

    // error-prone → avoid

    // ------------------------------------------
    // RECOMMENDATION
    // ------------------------------------------

    // use std::vector instead of manual resizing

    // ------------------------------------------
    // CLEANUP (IMPORTANT)
    // ------------------------------------------

    delete[] arr1;
    delete[] arr2;
    delete[] arr3;
    delete[] arr4;

    // ------------------------------------------
    // KEY TAKEAWAYS
    // ------------------------------------------

    // new[] → allocate array
    // delete[] → free array
    // size decided at runtime
    // no built-in resize
    // behaves like pointer
}

// ==========================================
// 14.14 — Copy Constructor (ONLY YOUR CONTENT)
// ==========================================

int copy_constructor()
{
    // ------------------------------------------
    // WHAT IS A COPY CONSTRUCTOR?
    // ------------------------------------------

    // Used to initialize an object using another object of same type

    // Example:
    // Fraction fCopy{ f }; → calls copy constructor

    // ------------------------------------------
    // IMPLICIT COPY CONSTRUCTOR
    // ------------------------------------------

    // If you don’t write one → C++ provides one

    // It does:
    // memberwise copy

    // Example concept:
    // fCopy.m_numerator = f.m_numerator
    // fCopy.m_denominator = f.m_denominator

    // ------------------------------------------
    // DEFINING YOUR OWN
    // ------------------------------------------

    class Fraction
    {
    private:
        int m_numerator{ 0 };
        int m_denominator{ 1 };

    public:
        Fraction(int n=0, int d=1)
            : m_numerator{ n }, m_denominator{ d }
        {}

        // Copy constructor
        Fraction(const Fraction& other)
            : m_numerator{ other.m_numerator }
            , m_denominator{ other.m_denominator }
        {
            std::cout << "Copy constructor called\n";
        }
    };

    // ------------------------------------------
    // IMPORTANT RULE
    // ------------------------------------------

    // Parameter must be:
    // const reference

    // Fraction(const Fraction& other)

    // ------------------------------------------
    // BEST PRACTICE
    // ------------------------------------------

    // Copy constructor should ONLY copy
    // no side effects

    // Prefer implicit version unless needed

    // ------------------------------------------
    // WHEN IS IT CALLED?
    // ------------------------------------------

    // 1. Initialization
    // Fraction fCopy{ f };

    // 2. Pass by value
    // void func(Fraction f)

    // 3. Return by value

    // ------------------------------------------
    // PASS BY VALUE
    // ------------------------------------------

    void printFraction(Fraction f)
    {
        // copy constructor used here

    }

    // ------------------------------------------
    // RETURN BY VALUE
    // ------------------------------------------

    Fraction makeFraction()
    {
        Fraction f{ 1, 2 };
        return f; // copy constructor used
    }

    // ------------------------------------------
    // = DEFAULT
    // ------------------------------------------

    class A
    {
    public:
        A(const A&) = default; // use compiler version
    };

    // ------------------------------------------
    // = DELETE
    // ------------------------------------------

    class B
    {
    public:
        B(const B&) = delete; // prevent copying
    };

    // ------------------------------------------
    // KEY TAKEAWAYS
    // ------------------------------------------

    // - copy constructor copies objects
    // - compiler provides one by default
    // - uses memberwise copy
    // - called on pass/return by value
    // - use const reference parameter
}

// ==========================================
// 14.15 — Copy Elision (ONLY YOUR CONTENT)
// ==========================================

int copy_elision()
{
    // ------------------------------------------
    // TYPES OF INITIALIZATION
    // ------------------------------------------

    int a;        // default initialization
    int b = 5;    // copy initialization
    int c(6);     // direct initialization

    int d{ 7 };   // list initialization (preferred)
    int e = { 8 };
    int f{};      // value initialization

    // ------------------------------------------
    // SAME FOR CLASSES
    // ------------------------------------------

    class Foo
    {
    public:
        Foo() {}
        Foo(int x) {}
        Foo(const Foo&) {}
    };

    Foo f1;        // default
    Foo f2{};      // value init (preferred)

    Foo f3 = 3;    // copy init
    Foo f4(4);     // direct init
    Foo f5{ 5 };   // list init (preferred)

    Foo f7 = f3;   // copy constructor
    Foo f8(f3);    // copy constructor
    Foo f9{ f3 };  // copy constructor

    // ------------------------------------------
    // KEY DIFFERENCES
    // ------------------------------------------

    // 1. List init → no narrowing conversions
    // 2. Copy init → ignores explicit constructors
    // 3. List init → prefers list constructors

    // ------------------------------------------
    // UNNECESSARY COPY
    // ------------------------------------------

    class Something
    {
    public:
        Something(int x) {}
        Something(const Something&) {}
    };

    // This creates a temporary, then copies it:
    Something s{ Something{ 5 } };

    // Equivalent but better:
    Something s2{ 5 }; // avoids copy

    // ------------------------------------------
    // COPY ELISION
    // ------------------------------------------

    // Compiler optimization:
    // removes unnecessary copy constructor calls

    // So this:
    Something s3{ Something{ 5 } };

    // becomes:
    // Something s3{ 5 };

    // ------------------------------------------
    // IMPORTANT RULE
    // ------------------------------------------

    // Copy constructor MAY NOT be called
    // even if it looks like it should be

    // ------------------------------------------
    // WHY THIS MATTERS
    // ------------------------------------------

    // Copy constructors should NOT have side effects
    // because compiler might skip them

    // ------------------------------------------
    // PASS / RETURN BY VALUE
    // ------------------------------------------

    class Test
    {
    public:
        Test() = default;
        Test(const Test&) {}
    };

    Test rvo()
    {
        return Test{}; // may skip copy
    }

    Test nrvo()
    {
        Test t{};
        return t; // may skip copy
    }

    Test t1{ rvo() };   // copy may be elided
    Test t2{ nrvo() };  // copy may be elided

    // ------------------------------------------
    // C++17 CHANGE
    // ------------------------------------------

    // Some cases MUST elide copy (guaranteed)

    // ------------------------------------------
    // KEY TAKEAWAYS
    // ------------------------------------------

    // - Copy elision removes unnecessary copies
    // - Compiler may skip copy constructor
    // - Do not rely on copy constructor side effects
    // - Happens in initialization, return, pass-by-value
}


// ==========================================
// 21.12 — Assignment Operator (ONLY YOUR CONTENT)
// ==========================================

int assignment_operator()
{
    // ------------------------------------------
    // COPY CONSTRUCTOR vs ASSIGNMENT
    // ------------------------------------------

    // Copy constructor:
    // → used when creating a NEW object

    // Assignment operator:
    // → used when object ALREADY EXISTS

    // Example:
    // Fraction f2{ f1 }; → copy constructor
    // f2 = f1;           → assignment operator

    // ------------------------------------------
    // BASIC IMPLEMENTATION
    // ------------------------------------------

    class Fraction
    {
    private:
        int m_numerator{ 0 };
        int m_denominator{ 1 };

    public:
        Fraction(int n=0, int d=1)
            : m_numerator{ n }, m_denominator{ d }
        {}

        // assignment operator
        Fraction& operator=(const Fraction& other)
        {
            m_numerator = other.m_numerator;
            m_denominator = other.m_denominator;

            return *this; // important for chaining
        }
    };

    // ------------------------------------------
    // CHAINING
    // ------------------------------------------

    // f1 = f2 = f3;

    // works because operator= returns *this

    // ------------------------------------------
    // SELF-ASSIGNMENT
    // ------------------------------------------

    // f = f;

    // Usually harmless:
    // just copies values to themselves

    // ------------------------------------------
    // DANGEROUS CASE (DYNAMIC MEMORY)
    // ------------------------------------------

    class MyString
    {
    private:
        char* m_data{};
        int m_length{};

    public:
        MyString(const char* data = nullptr, int length = 0)
            : m_length{ length }
        {
            if (length)
            {
                m_data = new char[length];
                // copy omitted for brevity
            }
        }

        ~MyString()
        {
            delete[] m_data;
        }

        MyString& operator=(const MyString& str)
        {
            // ❌ PROBLEM: self-assignment can break this

            if (m_data)
                delete[] m_data;

            m_length = str.m_length;

            if (m_length)
                m_data = new char[m_length];

            // copying data here...

            return *this;
        }
    };

    // ------------------------------------------
    // WHY SELF-ASSIGNMENT IS BAD HERE
    // ------------------------------------------

    // If:
    // str and *this are same object

    // then:
    // delete[] m_data → deletes the data we need to copy

    // results:
    // copying garbage / undefined behavior

    // ------------------------------------------
    // FIX: SELF-ASSIGNMENT CHECK
    // ------------------------------------------

    class SafeString
    {
    private:
        char* m_data{};
        int m_length{};

    public:
        SafeString& operator=(const SafeString& str)
        {
            if (this == &str) // self-check
                return *this;

            if (m_data)
                delete[] m_data;

            m_length = str.m_length;

            if (m_length)
                m_data = new char[m_length];

            // copy data...

            return *this;
        }
    };

    // ------------------------------------------
    // IMPORTANT NOTES
    // ------------------------------------------

    // - self-assignment is rare but dangerous
    // - check is cheap (pointer comparison)
    // - good defensive programming

    // ------------------------------------------
    // WHEN YOU CAN SKIP CHECK
    // ------------------------------------------

    // If assignment is naturally safe:

    class Simple
    {
    private:
        int x{};

    public:
        Simple& operator=(const Simple& other)
        {
            x = other.x; // safe even if self-assign
            return *this;
        }
    };

    // ------------------------------------------
    // IMPLICIT OPERATOR=
    // ------------------------------------------

    // If you don’t define one:
    // compiler creates one

    // It does:
    // memberwise assignment

    // ------------------------------------------
    // = DELETE
    // ------------------------------------------

    class NoAssign
    {
    public:
        NoAssign& operator=(const NoAssign&) = delete;
    };

    // ------------------------------------------
    // KEY TAKEAWAYS
    // ------------------------------------------

    // - operator= copies into existing object
    // - must return *this
    // - handle self-assignment if needed
    // - compiler provides default version
}

// ==========================================
// 21.13 — Shallow vs Deep Copy (ONLY YOUR CONTENT)
// ==========================================

int copy()
{
    // ------------------------------------------
    // SHALLOW COPY (DEFAULT)
    // ------------------------------------------

    // C++ default:
    // - copy constructor
    // - assignment operator

    // do:
    // memberwise copy

    // Example (works fine):
    class Fraction
    {
    private:
        int m_numerator{ 0 };
        int m_denominator{ 1 };

    public:
        Fraction(int n=0, int d=1)
            : m_numerator{ n }, m_denominator{ d }
        {}
    };

    // integers → safe to copy

    // ------------------------------------------
    // PROBLEM WITH POINTERS
    // ------------------------------------------

    class MyString
    {
    private:
        char* m_data{};
        int m_length{};

    public:
        MyString(const char* source = "")
        {
            m_length = 0; // simplified
            m_data = new char[10]; // pretend allocation
        }

        ~MyString()
        {
            delete[] m_data;
        }
    };

    // Default shallow copy:
    // m_data = source.m_data

    // ❌ both objects point to SAME memory

    // ------------------------------------------
    // WHAT GOES WRONG
    // ------------------------------------------

    MyString hello{ "Hello" };

    {
        MyString copy{ hello }; // shallow copy
    } // copy destroyed → deletes memory

    // hello now has dangling pointer ❌

    // using hello → undefined behavior

    // ------------------------------------------
    // ROOT PROBLEM
    // ------------------------------------------

    // shallow copy copies POINTER
    // NOT the actual data

    // ------------------------------------------
    // DEEP COPY (FIX)
    // ------------------------------------------

    class SafeString
    {
    private:
        char* m_data{};
        int m_length{};

    public:
        void deepCopy(const SafeString& source)
        {
            delete[] m_data;

            m_length = source.m_length;

            if (source.m_data)
            {
                m_data = new char[m_length];

                for (int i{ 0 }; i < m_length; ++i)
                    m_data[i] = source.m_data[i];
            }
            else
            {
                m_data = nullptr;
            }
        }

        // copy constructor
        SafeString(const SafeString& source)
        {
            deepCopy(source);
        }

        // assignment operator
        SafeString& operator=(const SafeString& source)
        {
            if (this != &source)
            {
                deepCopy(source);
            }

            return *this;
        }

        ~SafeString()
        {
            delete[] m_data;
        }
    };

    // ------------------------------------------
    // KEY DIFFERENCE
    // ------------------------------------------

    // shallow copy:
    // → copies pointer (same memory)

    // deep copy:
    // → allocates new memory
    // → copies actual data

    // ------------------------------------------
    // IMPORTANT RULE
    // ------------------------------------------

    // If using dynamic memory:
    // must implement:
    // - destructor
    // - copy constructor
    // - assignment operator

    // (rule of three)

    // ------------------------------------------
    // BEST PRACTICE
    // ------------------------------------------

    // Avoid manual memory management

    // Use:
    // std::string
    // std::vector

    // They handle deep copy automatically

    // ------------------------------------------
    // KEY TAKEAWAYS
    // ------------------------------------------

    // - default copy = shallow copy
    // - shallow copy breaks with pointers
    // - deep copy fixes it
    // - use rule of three
}

// ==========================================
// 22.3 — Move Semantics (ONLY YOUR CONTENT)
// ==========================================

int move()
{
    // ------------------------------------------
    // RECAP: COPY SEMANTICS
    // ------------------------------------------

    // Copy constructor → new object
    // Copy assignment → existing object

    // Default:
    // → shallow copy (bad for dynamic memory)

    // Deep copy:
    // → expensive (alloc + copy)

    // ------------------------------------------
    // PROBLEM
    // ------------------------------------------

    // Copying creates:
    // - extra allocations
    // - extra destruction
    // - slow performance

    // ------------------------------------------
    // SOLUTION: MOVE SEMANTICS
    // ------------------------------------------

    // Instead of copying → TRANSFER ownership

    // ------------------------------------------
    // MOVE CONSTRUCTOR
    // ------------------------------------------

    class Example
    {
    private:
        int* m_ptr{};

    public:
        Example(int* ptr = nullptr)
            : m_ptr{ ptr }
        {}

        // move constructor
        Example(Example&& other) noexcept
            : m_ptr{ other.m_ptr }
        {
            other.m_ptr = nullptr; // prevent double delete
        }
    };

    // ------------------------------------------
    // MOVE ASSIGNMENT
    // ------------------------------------------

    class Example2
    {
    private:
        int* m_ptr{};

    public:
        Example2& operator=(Example2&& other) noexcept
        {
            if (this == &other)
                return *this;

            delete m_ptr;

            m_ptr = other.m_ptr;
            other.m_ptr = nullptr;

            return *this;
        }
    };

    // ------------------------------------------
    // KEY IDEA
    // ------------------------------------------

    // Copy:
    // → duplicate data

    // Move:
    // → steal pointer (cheap)

    // ------------------------------------------
    // WHEN MOVE IS USED
    // ------------------------------------------

    // When argument is rvalue (temporary)

    // Example:
    // obj = createObject(); // uses move

    // ------------------------------------------
    // WHY IT WORKS
    // ------------------------------------------

    // Temporary object will be destroyed anyway
    // → safe to steal its resources

    // ------------------------------------------
    // IMPORTANT RULE
    // ------------------------------------------

    // After move:
    // moved-from object must be valid

    // Usually:
    other.m_ptr = nullptr;

    // ------------------------------------------
    // PERFORMANCE BENEFIT
    // ------------------------------------------

    // Copy:
    // → allocate + copy data

    // Move:
    // → just pointer assignment

    // Much faster

    // ------------------------------------------
    // IMPLICIT MOVE
    // ------------------------------------------

    // Compiler creates move constructor/assignment if:
    // - no user-defined copy
    // - no destructor
    // - no move functions already

    // BUT:
    // pointers are copied (not moved) by default

    // ------------------------------------------
    // DISABLING COPY
    // ------------------------------------------

    class MoveOnly
    {
    public:
        MoveOnly(const MoveOnly&) = delete;
        MoveOnly& operator=(const MoveOnly&) = delete;
    };

    // ------------------------------------------
    // RULE OF FIVE
    // ------------------------------------------

    // If you define/delete one:
    // - destructor
    // - copy constructor
    // - copy assignment
    // - move constructor
    // - move assignment

    // → you should define/delete all

    // ------------------------------------------
    // KEY TAKEAWAYS
    // ------------------------------------------

    // - move = transfer ownership
    // - avoids expensive copies
    // - used with rvalues
    // - always leave source valid
}