#include <iostream>
#include <string>
#include <string_view>
#include "main.hpp"
using namespace std;

//------- 24.1: Introduction to inheritance -------//
int inheritance(){

    // Inheritance allows us to create a new class that is based on an existing class. 
    // Useful for code reuse and to create a hierarchical relationship between classes.
    // For example, we can have class Fruit which has members like color and taste
    // Then we can have classes like Apple and Banana that inherit from Fruit
    // While also having its own unique members and functions.
  
    return 0;
    
}

//------- 24.2: Basic inheritance in C++ -------//

class Person{

    public: 
        std::string m_name {};
        int m_age {};

        Person(std::string_view name = "", int age = 0) : m_name(name), m_age(age) {}

        const std::string& getName() const { return m_name; }
        int getAge() const {return m_age; }
};

class BaseballPlayer : public Person{

    public:
        double m_battingAverage {};
        int m_homeRunes{};

        BaseballPlayer(double battingAverage = 0.0, int homeRuns = 0)
         : m_battingAverage(battingAverage), m_homeRunes(homeRuns) {}

};

int basicInheritance(){

    // Parent Class or Base Class or Super Class: The class that is being inherited from
    // Child Class or Derived Class or Sub Class: The class that is inheriting from the parent class

    BaseballPlayer player1{};
    player1.m_name = "Babe Ruth";
    cout << player1.getName() << endl;

    //Derived classes can access public and protected members of the base class, but not private members.

    return 0;
    
}

//------- 24.3: Order of construction of derived classes -------//

int orderOfConstruction(){

    // Derived Classes don't copy the members of the base class
    // Instead, they are part base class and part derived class.
    // When we create an object of the derived class, the base class
    // constructor is called first to initialize the base class part
    // of the object, and then the derived class constructor

    // The order of construction follows the hierarchy of inheritance
    // If we have classes A, B, C, and D where A inherits from B, B inherits from C
    // and C inherits from D, then the order of construction will be D, C, B, A.
    return 0;
}

//------- 24.4: Constructors and initialization of derived classes -------//

class Base{

    public: 
        int m_id {};

        Base(int id = 0) : m_id {id}
        {
        }

        int getId() const { return m_id; }
};

class Derived : public Base{

    public:
        double m_cost{};

        Derived(double cost = 0.0, int id = 0) : Base(id), m_cost(cost)
        {
        }

        double getCost() const { return m_cost; }
};



int constructorsAndInitializationOfDerivedClasses(){
    
    //How do we initialize the members of base class when we create
    //an object of the derived class?

    //Call the constructor of the Base Class in the constructor of the Derived Class

    return 0;
}

//------- 24.5: Inheritance and access specifiers -------//

class Base2{
    public: 
        int m_public {}; // accessed by anyone
    protected:
        int m_protected {}; //accessed by Base2 members, friends, and derived classes
    private:
        int m_private {}; //accessedonly by Base2 members and friends
};

class Derived2 : public Base2{
    public:
        Derived2(){
            m_public = 1; // OK
            m_protected = 2; // OK
            // m_private = 3; // Error: private members are not accessible in derived classes
        }
};
class Pub: public Base2{}; // Inherit from Base Publicly
class Pro: protected Base2{}; // Inherit from Base Protectedly
class Pri: private Base2{}; // Inherit from Base Privately
class Def: Base2{}; // Inherit from Base Privately (default)
int inheritanceAndAccessSpecifiers(){

    // Access specifiers (public, protected, private) determine the accessibility of members of a class.
    // When we inherit from a base class, we can specify the access level of the inherited members in the derived class.
    // Derived classes can access public and protected members of the base class, but not private members.
    // The default access level for inheritance is private.
    // Protected members of the base class are accessible in the derived class, but not outside the class hierarchy.

    // Inheritance can also be specified as public, protected, or private.
    // This determines the access level of the inherited members in the derived class.

    // Public Inheritance: The public and protected members of the base class become
    // public and protected members of the derived class, respectively. Private members of the base class are not accessible in the derived class.

    // Protected Inheritance: The public and protected members of the base class become
    // protected members of the derived class. Private members of the base class are not accessible in the derived class.

    // Private Inheritance: The public and protected members of the base class become
    // private members of the derived class. Private members of the base class are not accessible in the derived class.


    return 0;
    
}

//------- 24.6: Adding new functionality to a derived class -------//
// Derived classes members and functions aren't accessible to Base Class objects


//------- 24.7: Callng inherited functions and overriding behavior -------//

class Base3
{
public:
    Base3() { }

    void identify() const { std::cout << "Base::identify()\n"; }

    friend std::ostream& operator<<(std::ostream& out, const Base3& b)
    {
        out << "In Base\n";
        return out;
    }
};

class Derived3: public Base3
{
public:
    Derived3() { }

    void identify() const
    {
        std::cout << "Derived::identify()\n";
        Base3::identify(); // note call to Base::identify() here
    }

    friend std::ostream& operator<<(std::ostream& out, const Derived3& d)
    {
        out << "In Derived\n";

        //operators aren't actually part of the base class so scope resolution operator won't work
        //so we need to use static_cast

        out << static_cast<const Base3&>(d); // call the Base operator<< function
        return out;
    }
};

int overridingInheritanceBehavior(){
    // Derived Classes with the same function name as its base classes can override the behavior of the base class function.
    //The compiler selects the best matching function from the most-derived classes
    //It will start with the derived class and work its way up the inheritance hierarchy until it finds a match for the function call.

    //But sometimes we don't want to override the behavior of the base class function completely
    //We might want to call the base class function and then add some additional functionality
    // We can do this by using the scope resolution operator (::) to call the base class function from the derived class function.

    //imagine we have a base class and a derived class
    //base class have two print functions that take int and double
    //derived class has a print function that takes a double
    //if we call print with an int argument on the derived class object, it will call the derived class print function
    //but if we didn't want that
    //we can use the using Base::print; statement in the derived class to bring the base class print
    // functions into the scope of the derived class

    return 0;
}

//------- 25.1: Points and references to the base classes of derived objects -------//

class Base4
{
protected:
    int m_value {};

public:
    Base4(int value)
        : m_value{ value }
    {
    }

    std::string_view getName() const { return "Base4"; }
    int getValue() const { return m_value; }
};

class Derived4: public Base4
{
public:
    Derived4(int value)
        : Base4{ value }
    {
    }

    std::string_view getName() const { return "Derived"; }
    int getValueDoubled() const { return m_value * 2; }
};

int pointersAndReferencesToBaseClasses(){

    Derived4 derived {5};
    Base4* pBase = &derived; // pointer to base class
    Base4& rBase = derived;  // reference to base class
    
    std::cout << "derived is a " << derived.getName() << " and has value " << derived.getValue() << '\n';

    std::cout << "rBase is a " << rBase.getName() << " and has value " << rBase.getValue() << '\n';
    std::cout << "pBase is a " << pBase->getName() << " and has value " << pBase->getValue() << '\n';
    //These calls the Base4 versions of getName() and getValue()
    // Because it only has access to the Base4 part of the object, not the Derived4 part of the object.

    return 0;
    
}

//------- 25.2: Virtual Functions and polymorphism -------//

class Base5{
public:
    virtual std::string_view getName() const { return "Base5"; } // note addition of virtual keyword
};

class Derived5: public Base5{
public:
    virtual std::string_view getName() const { return "Derived5"; }
};

// identifier "add" has two forms
int add(int a, int b) {
    return a + b;
}

double add(double a, double b) {
    return a + b;
}

int virtualFunctionsAndPolymorphism(){

    // Virtual Function = member function that resolves to the most-derived version of the function
    // For the actual type of the object being referenced or pointed to

    Derived5 derived {};
    Base5& rBase{ derived };
    std::cout << "rBase is a " << rBase.getName() << '\n'; 
    // calls Derived5::getName() because getName() is a virtual function and rBase is referencing a Derived5 object

    // Polymorphism = ability of an entity to have multiple forms
    // Compile-time polymorphism = resolved by compiler: function overloading and operator overloading
    // Run-time polymorphism = resolved at runtime: virtual functions

    //identifier "add" has two forms

    //downsides: inefficient compared to regular functions, 
    // compiler has to allocate an extra pointer for each object of a class with virtual functions

    return 0;
    
}

//------- 25.7: Pure virtual functions, abstract base classes, and interface classes -------//

int pureVirtualFunctions(){

    // Virtual functions have a body while pure don't



    return 0;
}

// ------- 25.10: Dyanmic Casting -------//

int dynamicCasting(){

    // Dynamic Casting = safely cast a pointer or reference to a base class to a pointer or reference to a derived class
    // Only works if the base class has at least one virtual function (usually the destructor)
    // If the cast is successful, it returns a pointer or reference to the derived class
    // If the cast fails, it returns nullptr for pointers and throws an exception for references

    return 0;
    
}