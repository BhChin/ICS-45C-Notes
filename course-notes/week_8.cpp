#include <iostream>
#include <vector>
#include <list>
#include <deque>
#include <array>
#include <set>
#include <map>
#include <algorithm>
// ------- 21.1: The Standard Library -------//
/*
  Notes:

  - The C++ Standard Library provides a collection of classes and functions for common programming tasks.
  - It includes containers (e.g., std::vector, std::list), algorithms (e.g., std::sort, std::find),
  - and utilities (e.g., std::pair, std::tuple).
  - The library is designed to be efficient and flexible, allowing developers to write high-performance code.
  - It promotes code reuse and helps avoid reinventing the wheel for common data structures and algorithms.
*/

// ------- 21.2: STL containers overview -------//

// STL contains many different container classes
// Fall into 3 categories: sequence containers, associative containers, container adapters

// -- Sequence Containers --:
// maintain the ordering of elements in the container
// can choose where to insert your elememt by positioning
// Examples: std::vector, std::list, std::deque, std::array, std::forward_list, std::basic_string

// Vector: dynamic array that can resize itself automatically when elements are added or removed

int vector(){
    std::vector<int> vect;
    for(int count = 0; count < 6; ++count)
        vect.push_back(10 - count); //insert at end of array

    for(int index = 0; index < vect.size(); ++index)
        std::cout << vect[index] << ' ';

    std::cout << '\n';

    return 0;

    //Result: 10 9 8 7 6 5
}

int deque(){
    
    std::deque<int> deq;
    for(int count = 0; count < 3; ++count){
        deq.push_back(count); //insert at end of array
        deq.push_front(10 - count); //insert at front of array
    }

    for(int index = 0; index < deq.size(); ++index)
        std::cout << deq[index] << ' ';

    std::cout << '\n';

    return 0;

    //Result: 8 9 10 0 1 2
}

// list: doubly linked list where each element in the container contains pointers
// to the previous and next element in the list

// -- Associative Containers --:

// automatically sorts their inputs when inserted into container
// comparison defaults to operator<
// Examples: set, multiset, map, multimap

// set: unique elements, no duplicates, sorted by values
// multiset: set but duplicates allowed
// map: key/vlue pairs, unique keys, sorted by keys
// multimap: map but duplicates allowed

// -- Container Adapters --:
// Example: stack, queue, priority queue


// ------- 21.3: STL iterators overview -------//

// Iterator: an object that can traverse a container class without exposing the underlying structure of the container
// Best visualized as a pointer to a given element in the container

// Operators: *, ++,--, ==, !=, =
// * dereferences the iterator to access the element it points to

// 4 basic member functions: begin(), end(), cbegin(), cend()
// cbegin() and cend() return const iterators that cannot be used to modify the container's elements
// end() returns an iterator that points to one past the last element in the container, not a valid element

// all containers provide container::iterator and container::const_iterator

int iterVector()
{
    std::vector<int> vect;
    for (int count=0; count < 6; ++count)
        vect.push_back(count);

    std::vector<int>::const_iterator it; // declare a read-only iterator
    it = vect.cbegin(); // assign it to the start of the vector
    while (it != vect.cend()) // while it hasn't reach the end
    {
        std::cout << *it << ' '; // print the value of the element it points to
        ++it; // and iterate to the next element
    }

    std::cout << '\n';
}

int iterList()
{

    std::list<int> li;
    for (int count=0; count < 6; ++count)
        li.push_back(count);

    std::list<int>::const_iterator it; // declare an iterator
    it = li.cbegin(); // assign it to the start of the list
    while (it != li.cend()) // while it hasn't reach the end
    {
        std::cout << *it << ' '; // print the value of the element it points to
        ++it; // and iterate to the next element
    }

    std::cout << '\n';
}

int iterSet()
{
    std::set<int> myset;
    myset.insert(7);
    myset.insert(2);
    myset.insert(-6);
    myset.insert(8);
    myset.insert(1);
    myset.insert(-4);

    std::set<int>::const_iterator it; // declare an iterator
    it = myset.cbegin(); // assign it to the start of the set
    while (it != myset.cend()) // while it hasn't reach the end
    {
        std::cout << *it << ' '; // print the value of the element it points to
        ++it; // and iterate to the next element
    }

    std::cout << '\n';
}

int iterMap()
{
	std::map<int, std::string> mymap;
	mymap.insert(std::make_pair(4, "apple"));
	mymap.insert(std::make_pair(2, "orange"));
	mymap.insert(std::make_pair(1, "banana"));
	mymap.insert(std::make_pair(3, "grapes"));
	mymap.insert(std::make_pair(6, "mango"));
	mymap.insert(std::make_pair(5, "peach"));

	auto it{ mymap.cbegin() }; // declare a const iterator and assign to start of vector
	while (it != mymap.cend()) // while it hasn't reach the end
	{
		std::cout << it->first << '=' << it->second << ' '; // print the value of the element it points to
		++it; // and iterate to the next element
	}

	std::cout << '\n';
}

// ------- 21.4: STL algorithms overview -------//

// STL algorithms: a collection of functions that operate on a range of elements defined by iterators
// Examples: std::min_element, std::max_element, std::find, std::sort, std::reverse
// These take begin and end iterators as arguments to specify the range of elements to operate on

// ------- 28.1: Input and Output (I/O) streams -------//

// stream: sequence of bytes accessed sequentially
// istream: input stream, used for reading data from a source (e.g., keyboard, file)
// ostream: output stream, used for writing data to a destination (e.g., console,
// iostream: input/output stream, can be used for both reading and writing

// cin: standard input stream, used for reading data from the keyboard
// cout: standard output stream, used for writing data to the console
// cerr: standard error stream, unbuffered
// clog: standard error stream, buffered

// unbuffered is handled immediately, buffered is stored in a temporary location and written out as a block

// ------- 28.2: Input with stream -------//

// std::setw(n): sets the width of the next input field to n characters
// user can't enter more than n characters and the extra characters will be left in the input buffer

// extraction skips whitespace
// std::cin.get(ch): does not discard whitespace

