//---------------1.1----------------

//statements: type of instruction that causes the program to perform some action
//most statements end in a semicolon

//function: collection of statements that get executed sequentially
//every C++ program must have a "main" function
//name of a function is called an "identifier"

#include <iostream>

int week_1() {

    std::cout << "Hello World!" << '\n';



    //include indicates that we want to use contents of the "iostream" library
    //we need it to use "std::cout"

    //---------------1.2----------------

    //comments
    /* multi
     * lined
     * comment
     * /

    /* multi lined comment /* comment */ // "*/"
    //multi lined comments can't be nested


    //---------------1.3----------------

    //intro to objects and variables
    //value/datavalue: single piece of data
    //numbers: 5 or -6.7
    //characters: must be single quoted 'H' or '&'
    //text: doubled quoted "Hello" or "H". must contain 0 or more characters


    std::cout << 5 << '\n';
    std::cout << 'H'<< '\n';
    std::cout << "Hello"<< '\n';
    std::cout << "Hello World"<< '\n';

    //RAM: Random Access Memory
    //C++ accesses memory through an object
    //object represents a region of storage that can hold a value
    //object with a name is called a variable

    int x; //variable named x of type int
    double width; //variable named width of type double

    int a;
    int b;

    int c,d; //int c, int d; is a compiler error

    int e; int f;

    int g; double h;

    //---------------1.4----------------

    //variable assignment and initialization

    int apple;
    apple = 5;

    std::cout << apple;

    apple = 7; //changes value

    std::cout << apple;

    //other ways of initializing

    int orange { 7 };
    int banana = 10;
    int grape ( 6 );
    int watermelon {};

    int hi; //default-initialization leaves the variable with no indeterminate value
    int hello = 5; //copy initialization
    int hey ( 5 ); //direct initialization
    int yo {1}; // list initialization
    int whatsup = {6}; ///copy list initialization

    //can't list initialize a double (doesn't allow narrowing conversion)

    //some compliers will error if you have an unused variable
    //to fix

    [[maybe_unused]] double pi {3.14159265358};


    //---------------1.5----------------

    //#include <iostream> gives access to std::cout and std::cin

    std::cout << "Hello World";
    int p {5};

    std::cout << "p is " << p;

    //new lines

    //without newline

    std::cout << "Alex";
    std::cout << "Hi"; //prints AlexHi

    //option 1: std::endl

    std::cout << "Hello" << std::endl;
    //flushes buffer but is slow

    //option 2: '\n' preferred

    std::cout << "Hi\n";
    //doesn't flush buffer

    //output is not immediate, goes into buffer first then prints
    //flushing = sending buffer to screen

    //flushing happens when buffer fills, program ends, or std::endl is used

    //input: std::cin
    //uses >>

    int poop {};
    std::cin >> poop;

    int k {}, l {};

    std::cin >> k >> l;
    //input: 5 6
    //k = 5, l = 6

    //summary:

    //std::cout << value; //output
    //std::cin >> value; //input

    //cout << -> goes OUT
    //cin >> -> goes IN

    //input buffering:



    //---------------1.6----------------

    //Initialized = given value at definition
    int test{1};

    //Assigned = given value later
    int exam{};
    exam = 2;

    //Uninitialized = no known value
    int z;
    //C++ does not have some default value and just assigns it to some int in the memory
    //Printing it out could be a random number

    //---------------1.7----------------

    //common keywords

    //---------------1.9----------------

    //literals and operators

    //literals are like variables expect their value can't be changed

    std::cout << 5 << '\n'; //prints the value of a literal

    int smile {5};

    std::cout << smile << '\n' ;

    //operands

    std::cout << 3 + 4 << '\n'; //prints 7

    //+,-, *,/

    std::cout << (smile = 7) << '\n'; //changes the value of smile to 7 and prints out 7


    //---------------1.11----------------

    //make a program the takes an integer input
    //prints out double that integer


    int number{};

    std::cout << "Enter an integer: ";
    std::cin >> number;

    std::cout << "Double that number is: " << number * 2;


    //---------------2.1----------------: Introduction to Functions

    //----Nomenclature-----:
    //returnType functionName(){body}

    //always put functions above the main function
    //IMPORTANT: you can't create a function in the main function

    //---------------2.2----------------: Function return values

    //---------------2.3----------------: Void Functions

    //---------------2.4----------------: Function Parameters

    //same as python expect you have to specify the parameter's types

    //---------------2.5----------------: Local Scope

    //legit same thing as python




    //doesn't return any value

    //nomenclature:

    //void functionName{body}





    //---------in-lecture-----------

    //----data types

    // int: -1, 0, 1
    // char: 'A', 'Z', '0'
    // bool: false, true
    // string: "X", "Hello"
    // double: 0.0, 1.0, 1.5, -1.333
    // arrays: {2,4,5,6,7}, {"A", "B"}

    //----operators
    // int: =, ==, +, -, *, /
    //float: =, +. -, *, /
    //bool logical: &&, ||, !
    //string: =, +, +=, ==, [], iterator
    //arrays: L[3], iterator

    //no negative index

    //highest to lowest precendence
    //++ -+ - (unary)
    //* / %
    //+ - = += -= *= /= %=











    return 0;
}