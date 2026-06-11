#include <cassert>
#include <algorithm>
#include <array>
#include <functional>
#include <iostream>
#include <string_view>

// ------- 11.6: Function Templates -------//

/*
  Notes:

  - Function templates let us write one definition that works for many types.
  - A template uses placeholder types (type template parameters) instead of concrete types.
  - The compiler instantiates actual functions from the template when it is used.
  - This avoids repeated overloads with the same implementation.
  - Templates can support types that did not exist when the template was written.
*/

template <typename T>
T maxValue(T x, T y)
{
    return (x < y) ? y : x;
}

/*
  - Here, T is a placeholder type that is deduced when maxValue is called.
  - The same template can generate maxValue<int>, maxValue<double>, maxValue<char>, etc.
  - "typename" and "class" are equivalent in template parameter declarations.
  - Use simple names like T, U, V for trivial type parameters.
  - Use descriptive names like Allocator when the type has a specific role.
*/

int functionTemplates()
{
    int i1 = 3;
    int i2 = 7;
    double d1 = 2.5;
    double d2 = 4.1;

    std::cout << "maxValue(" << i1 << ", " << i2 << ") = " << maxValue(i1, i2) << '\n';
    std::cout << "maxValue(" << d1 << ", " << d2 << ") = " << maxValue(d1, d2) << '\n';

    // Explicit template arguments are optional in this case.
    auto maxInt = maxValue<int>(i1, i2);
    auto maxDouble = maxValue<double>(d1, d2);

    std::cout << "maxValue<int>(...) = " << maxInt << '\n';
    std::cout << "maxValue<double>(...) = " << maxDouble << '\n';

    return 0;
}

// ------- 11.7: Function template instantiation -------//

/*
  Notes:

  - Function templates are not functions themselves; they generate functions when used.
  - The process of creating a concrete function from a template is called instantiation.
  - Explicit template arguments look like max<int>(1, 2).
  - Template argument deduction lets the compiler infer the type from the arguments.
  - max<>(1, 2) considers only template overloads; max(1, 2) also considers non-template overloads.
  - If a matching non-template function exists, it is preferred over an equally viable template instantiation.
  - Templates are instantiated only when they are used. Unused templates do not generate code.
  - If a template is instantiated with a type that does not support the required operations,
    the resulting instantiated function can fail to compile.
*/

template <typename T>
T maxInst(T x, T y)
{
    std::cout << "called maxInst<T>(...)\n";
    return (x < y) ? y : x;
}

int maxInst(int x, int y)
{
    std::cout << "called non-template maxInst(int, int)\n";
    return (x < y) ? y : x;
}

int functionTemplateInstantiation()
{
    std::cout << maxInst<int>(1, 2) << '\n'; // explicit template instantiation
    std::cout << maxInst<>(4, 3) << '\n';    // template argument deduction, template-only overload resolution
    std::cout << maxInst(1, 2) << '\n';      // non-template overload is preferred
    std::cout << maxInst(1.2, 2.3) << '\n';  // deduced as maxInst<double>(double, double)

    return 0;
}

// ------- 26.1: Template classes -------//

/*
  Notes:

  - Template classes generalize classes to work with many data types.
  - The only substantive difference between IntArray and DoubleArray is the element type.
  - A class template uses a type template parameter like template <typename T>.
  - Member functions defined outside the class still need their own template declaration.
  - Array<T> is the templated class name; Array without arguments would refer to a non-template class.
  - Template classes are ideal for container classes because they avoid duplicated code.
  - Template code must be visible to the compiler when the template is instantiated,
    which is why class templates are usually defined entirely in header files.
*/

template <typename T>
class Array
{
private:
    int m_length{};
    T* m_data{};

public:
    Array(int length)
    {
        assert(length > 0);
        m_data = new T[length]{};
        m_length = length;
    }

    Array(const Array&) = delete;
    Array& operator=(const Array&) = delete;

    ~Array()
    {
        delete[] m_data;
    }

    void erase()
    {
        delete[] m_data;
        m_data = nullptr;
        m_length = 0;
    }

    T& operator[](int index);
    int getLength() const { return m_length; }
};

template <typename T>
T& Array<T>::operator[](int index)
{
    assert(index >= 0 && index < m_length);
    return m_data[index];
}

int templateClassExample()
{
    const int length = 5;

    Array<int> intArray(length);
    Array<double> doubleArray(length);

    for (int i = 0; i < length; ++i)
    {
        intArray[i] = i;
        doubleArray[i] = i + 0.5;
    }

    for (int i = length - 1; i >= 0; --i)
    {
        std::cout << intArray[i] << '\t' << doubleArray[i] << '\n';
    }

    return 0;
}

// ------- 26.2: Template non-type parameters -------//

/*
  Notes:

  - Template non-type parameters are compile-time values, not types.
  - They can be integral values, enums, pointers/references, nullptr_t, and since C++20, floating point values.
  - Non-type parameters must be constexpr values.
  - std::array<int, 5> is an example of a template class with both a type parameter and a non-type parameter.
  - Non-type parameters can be used to make compile-time fixed-size containers.
*/

template <typename T, int size>
class StaticArray
{
private:
    T m_array[size]{};

public:
    T* getArray();

    T& operator[](int index)
    {
        assert(index >= 0 && index < size);
        return m_array[index];
    }
};

template <typename T, int size>
T* StaticArray<T, size>::getArray()
{
    return m_array;
}

int templateNonTypeParameterExample()
{
    StaticArray<int, 12> intArray;
    for (int i = 0; i < 12; ++i)
        intArray[i] = i;

    for (int i = 11; i >= 0; --i)
        std::cout << intArray[i] << ' ';
    std::cout << '\n';

    StaticArray<double, 4> doubleArray;
    for (int i = 0; i < 4; ++i)
        doubleArray[i] = 4.4 + 0.1 * i;

    for (int i = 0; i < 4; ++i)
        std::cout << doubleArray[i] << ' ';
    std::cout << '\n';

    return 0;
}

// ------- 20.6: Introduction to lambdas (anonymous functions) -------//

/*
  Notes:

  - Lambdas are anonymous callable objects that can be defined inside a function.
  - Syntax: [capture](parameters) -> returnType { statements; }
  - Capture clause, parameters, and return type are all optional in simple cases.
  - Lambdas without captures can convert to function pointers.
  - Use auto to store lambdas and to keep the actual lambda type hidden.
  - Generic lambdas use auto parameters and behave like templates.
  - Lambda return types are deduced unless explicitly specified.
  - C++17+ allows constexpr lambdas when the body is constexpr.
*/

void repeat1(int repetitions, const std::function<void(int)>& fn)
{
    for (int i{ 0 }; i < repetitions; ++i)
        fn(i);
}

template <typename T>
void repeat2(int repetitions, const T& fn)
{
    for (int i{ 0 }; i < repetitions; ++i)
        fn(i);
}

template <typename F>
void repeat3(int repetitions, const F& fn)
{
    for (int i{ 0 }; i < repetitions; ++i)
        fn(i);
}

void repeat4(int repetitions, void (*fn)(int))
{
    for (int i{ 0 }; i < repetitions; ++i)
        fn(i);
}

int lambdaIntroductionExample()
{
    constexpr std::array<std::string_view, 4> arr{ "apple", "banana", "walnut", "lemon" };

    auto found = std::find_if(arr.begin(), arr.end(),
                              [](std::string_view str)
                              {
                                  return str.find("nut") != std::string_view::npos;
                              });

    if (found == arr.end())
    {
        std::cout << "No nuts\n";
    }
    else
    {
        std::cout << "Found " << *found << '\n';
    }

    auto isEven = [](int i)
    {
        return (i % 2) == 0;
    };

    std::array<int, 5> values{ 1, 2, 3, 4, 5 };
    std::cout << std::boolalpha << std::all_of(values.begin(), values.end(), isEven) << '\n';

    auto addNumbers3 = [](double a, double b)
    {
        return a + b;
    };

    std::cout << addNumbers3(5, 6) << '\n';

    auto lambda = [](int i)
    {
        std::cout << i << '\n';
    };

    repeat1(3, lambda);
    repeat2(3, lambda);
    repeat3(3, lambda);
    repeat4(3, lambda);

    auto genericPrint = [](auto value)
    {
        static int callCount{ 0 };
        std::cout << callCount++ << ": " << value << '\n';
    };

    genericPrint("hello");
    genericPrint("world");
    genericPrint(1);
    genericPrint(2);
    genericPrint("ding dong");

    return 0;
}


int& hi(){
    int x = 5;
    return x;
}

int main(){
    int x = hi();
}