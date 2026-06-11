
//------- 23.6: Container Classes -------//

int containerClasses()
{
    // A container class is a class that holds and organizes multiple instances of another type
    // Container classes provide a way to store and manage collections of objects.
    // They provide member functions to add, remove, and access the elements in the container.
    // Provides extra functionality. std::array is preferred over C-style arrays

    // Value Container = stores copies of the objects it holds. 
    // Reference Container = stores references or pointers to the objects it holds
    // Typically holds only one type of data


    return 0;
}

//------- 23.7: std::initializer_list -------//

int initializerList(){
    // std::initializer_list = a lightweight proxy object that provides access to an array of objects of a specified type
    // It is used to allow functions and constructors to accept a variable number of arguments of the same type, using a convenient syntax.

    // The std::initializer_list class template is defined in the <initializer_list> header and has the following member functions:
    // size() = returns the number of elements in the initializer list
    // begin() = returns a pointer to the first element in the initializer list
    // end() = returns a pointer to one past the last element in the initializer list
}

// ------- 9.6: assert and static-assert -------//

#include <cassert>
#include <cmath>

double calculateTimeUntilObjectHitsGround(double initialHeight, double gravity)
{
  assert(gravity > 0.0); // The object won't reach the ground unless there is positive gravity.

  if (initialHeight <= 0.0)
  {
    // The object is already on the ground. Or buried.
    return 0.0;
  }

  return std::sqrt((2.0 * initialHeight) / gravity);
}

int assertAndStaticAssert(){
    // assert = a macro that evaluates an expression and terminates the program if the expression is false
    // static_assert = a compile-time assertion that checks a condition at compile time and generates 
    // a compile-time error if the condition is false

    // std::cout << "Took " << calculateTimeUntilObjectHitsGround(100.0, -9.8) << " second(s)\n";
    // this will cause an assertion failure because gravity is negative, which is not valid for this function

    // its important to be descriptive with the assertion message to help identify the cause of the failure
    // Example:
    // assert(found && "Car could not be found in database");

    
    // --- static assert ---
    //static_assert(condition, diagnostic_message)
    
    // prefer static assert over assert because it catches errors at 
    // compile time rather than runtime, which can help prevent bugs 
    // and improve the overall reliability of the code.


  return 0;

}

// ------- 22.1 smart pointers and move semantics -------//

#include <iostream>

template<typename T>
class Auto_ptr1{
    T* m_ptr;
public:
    Auto_ptr1(T* ptr = nullptr) : m_ptr(ptr) {}
    ~Auto_ptr1() { delete m_ptr; }

    T& operator*() { return *m_ptr; }
    T* operator->() { return m_ptr; }

    Auto_ptr1(Auto_ptr1& a){
        m_ptr = a.m_ptr; // transfer ownership of the resource
        a.m_ptr = nullptr; // set the original pointer to null to prevent double deletion
    }

    Auto_ptr1& operator=(Auto_ptr1& a){
        if (this != &a) { // check for self-assignment
            delete m_ptr; // delete the current resource
            m_ptr = a.m_ptr; // transfer ownership of the resource
            a.m_ptr = nullptr; // set the original pointer to null to prevent double deletion
        }
        return *this;
    }
};
   
int smartPointersAndMoveSemantics(){
    
    // The problem with ptrs is that you must deallocate the ptr
    // It's easy to forget and when you return or throw an exception, the program
    // will exit before you have a chance to deallocate the ptr

    // Classes contain destructors that automatically get executed when an object goes out of scope
    // Smart Pointers = a class that mimics the behavior of a regular pointer but also provides automatic memory management

    Auto_ptr1<int> ptr{ new int{5} }; 
    // allocation of memory but no explicit delete needed

    // one problem with this is it doesn't support copy semantics, so you can't copy an Auto_ptr1 object
    // Auto_ptr1<int> ptr2 = ptr; // can error because of double deletes

    // we can fix this using move semantics, which allows us to transfer ownership of the resource
    // from one object to another without copying the resource itself

    return 0;
}

// ------- 22.5 std::unique_ptr -------//

#include <memory>
#include <iostream>
#include <utility>

class Resource{
public:
    Resource(){
        std::cout << "Resource acquired\n";
    }

    ~Resource(){
        std::cout << "Resource destroyed\n";
    }

    void hello() const{
        std::cout << "Hello\n";
    }
};

void useResource(const Resource* res){
    if (res){
        res->hello();
    }
}

std::unique_ptr<Resource> createResource(){
    return std::make_unique<Resource>();
}

int uniquePtr(){

    // std::unique_ptr = a smart pointer that automatically deletes
    // the dynamically allocated object when the unique_ptr goes out of scope

    // should be used when ONLY ONE object owns the resource

    // lives in memory header


    // --- basic usage ---

    std::unique_ptr<Resource> ptr{ new Resource() };

    // Resource automatically destroyed when ptr goes out of scope
    // no manual delete needed


    // --- preferred syntax ---

    auto ptr2{ std::make_unique<Resource>() };

    // preferred over using new directly
    // cleaner and safer


    // --- copy semantics disabled ---

    auto a{ std::make_unique<Resource>() };

    // auto b{ a }; // ERROR
    // unique_ptr cannot be copied because two objects
    // cannot own the same resource


    // --- move semantics ---

    auto b{ std::move(a) };

    // ownership transferred from a -> b

    // after move:
    // a becomes nullptr
    // b owns the Resource


    // --- checking for null ---

    if (b){
        std::cout << "b owns resource\n";
    }

    if (!a){
        std::cout << "a is null\n";
    }


    // --- accessing the object ---

    b->hello();

    (*b).hello();

    // -> accesses member functions like normal ptr
    // * dereferences the object


    // --- get() ---

    Resource* raw{ b.get() };

    // get() returns raw ptr WITHOUT transferring ownership

    raw->hello();


    // --- passing to functions ---

    useResource(b.get());

    // function uses object but does NOT take ownership


    // --- returning unique_ptr from function ---

    auto ptr3{ createResource() };

    // safe because ownership transfers correctly


    // --- arrays ---

    auto arr{ std::make_unique<int[]>(5) };

    arr[0] = 10;


    // --- common mistakes ---

    // BAD:
    // manually deleting object owned by unique_ptr

    // delete b.get();

    // unique_ptr will try deleting it again later
    // causes undefined behavior


    // BAD:
    // multiple unique_ptrs owning same raw ptr

    // Resource* temp{ new Resource() };

    // std::unique_ptr<Resource> x{ temp };
    // std::unique_ptr<Resource> y{ temp };

    // both x and y will try deleting temp
    // causes double delete


    return 0;
}

// ------- 22.6 std::shared_ptr -------//

#include <memory>
#include <iostream>

class Resource{
public:
    Resource(){
        std::cout << "Resource acquired\n";
    }

    ~Resource(){
        std::cout << "Resource destroyed\n";
    }

    void hello() const{
        std::cout << "Hello\n";
    }
};

int sharedPtr(){

    // std::shared_ptr = a smart pointer that allows
    // MULTIPLE objects to share ownership of the same resource

    // resource is destroyed only when the LAST shared_ptr
    // owning the resource goes out of scope

    // lives in memory header


    // --- basic usage ---

    auto ptr1{ std::make_shared<Resource>() };

    {
        auto ptr2{ ptr1 };

        // ptr1 and ptr2 both own same Resource

        std::cout << "Inside block\n";

    } // ptr2 destroyed here
      // Resource NOT destroyed because ptr1 still owns it


    std::cout << "Outside block\n";

    // Resource destroyed when ptr1 goes out of scope


    // --- reference counting ---

    auto a{ std::make_shared<Resource>() };

    std::cout << a.use_count() << '\n'; // 1

    auto b{ a };

    std::cout << a.use_count() << '\n'; // 2
    std::cout << b.use_count() << '\n'; // 2

    // both point to same control block


    // --- accessing object ---

    a->hello();

    (*a).hello();


    // --- checking for null ---

    if (a){
        std::cout << "a owns resource\n";
    }


    // --- get() ---

    Resource* raw{ a.get() };

    raw->hello();

    // get() returns raw ptr WITHOUT transferring ownership


    // --- BAD EXAMPLE ---

    Resource* temp{ new Resource() };

    std::shared_ptr<Resource> x{ temp };

    // std::shared_ptr<Resource> y{ temp };

    // BAD:
    // x and y would have separate control blocks
    // both think they are sole owner
    // causes double delete


    // --- CORRECT WAY ---

    auto p1{ std::make_shared<Resource>() };

    auto p2{ p1 };

    // p1 and p2 share same control block
    // safe shared ownership


    // --- unique_ptr -> shared_ptr ---

    auto unique{ std::make_unique<Resource>() };

    std::shared_ptr<Resource> shared{ std::move(unique) };

    // ownership transferred from unique_ptr -> shared_ptr


    return 0;
}

int test(){
    int x = 5;
    auto f = [x]() {
        x++;
        std::cout << x;
    }

}