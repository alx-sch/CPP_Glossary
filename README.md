## C++ Glossary

<p align="center">
    <img src="https://github.com/alx-sch/42_CPP_00-04/blob/main/.assets/cpp_badge.png" alt="cpp_badge.png" />
</p>

[cplusplus.com](https://cplusplus.com/) is a great resource for all things C++.   
Most of the entries in this glossary are based on or adapted from those found there.

The object-oriented programming principles featured in this glossary are covered throughout the exercise modules:

- **C++ Module 00**: Classes, member functions, stdio streams
- **C++ Module 01**: Memory Management, pointers to members
- **C++ Module 02**: Function and operator overloading
- **C++ Module 03**: Inheritance
- **C++ Module 04**: Subtype polymorphism, abstract classes
- **C++ Module 05**: Exceptions
- **C++ Module 06**: Casting
- **C++ Module 07**: Templates
- **C++ Module 08**: STL containers, STL Algorithms
- **C++ Module 09**: Programs using STL containers (esp. Ford-Johnson algorithm)

---

## Table of Contents
<div id="top"></div>  
  
- [Namespaces](#namespaces)
- [I/O Streams](#io-streams)
- [File Streams](#file-streams)
- [Classes and Instances](#classes-and-instances)
- [Class Members](#class-members)
- [This Pointer](#this-pointer)
- [Pointers to Class Members](#pointers-to-class-members)
- [References](#references)
- [Initialization List](#initialization-list)
- [Const](#const)
- [Static](#static)
- [Visibility (public/private)](#visibility-privatepublic)
- [Class vs Struct](#class-vs-struct)
- [Memory Allocation](#memory-allocation)
- [Overloading](#overloading)
- [Inheritance](#inheritance)
- [Abstract Classes](#abstract-classes)
- [Exceptions](#exceptions)
- [Casting](#casting)
- [Templates](#templates)
- [STL Containers](#stl-containers)
- [STL Algorithms](#stl-algorithms)
- [Ford-Johnson Algorithm](#ford-johnson-algorithm)
 
---

### Namespaces   

A **namespace** is a way to group related declarations (such as variables, functions, and classes) to organize code and prevent name conflicts. Think of it as a "bag" that holds related entities, giving them a meaningful and scoped name.

**Example:**
```cpp
int g_var = 1;
int fct(void) { return 42; }

namespace Foo {
    int g_var = 2;
    int fct(void) { return 40; }
}

namespace Bar {
    int g_var = 3;
    int fct(void) { return 2; }
}
```

In the example above, the global variable `g_var` and function `fct` are defined in different namespaces (`Foo` and `Bar`). This allows multiple definitions of the same name without conflict.

**Key Points:**

- Namespaces allow you to split your code into logical components and avoid name collisions.
- You can have variables or functions with the same name in different namespaces.

#### Namespace Aliasing:    

You can create an alias for an existing namespace to shorten its reference:

```cpp
namespace VeeeeryLongName {
    int var = 3;
    int fct(void) { return 42; }
}

namespace Muf = VeeeeryLongName;
```

Now, `Muf` is an alias for `VeeeeryLongName`, and you can access `VeeeeryLongName`'s members using `Muf`.

#### Scope Resolution Operator (`::`):  

The `::` operator is used to access elements within a namespace. For example:

```cpp
Foo::g_var   // Accesses the 'g_var' defined in the 'Foo' namespace
::g_var      // Accesses the global 'g_var' (outside any namespace); same as using 'g_var' 
```

#### Standard Namespace:

The `std` namespace is the default namespace for the C++ Standard Library. It contains commonly used components like `iostream`, `string`, etc.

```cpp
std::cout << "Hello, world!" << std::endl;
```

If you include the line `using namespace std;` at the beginning of your code, you no longer need to prefix standard library components with `std::`:
```cpp
using namespace std;

cout << "Hello, world!" << endl;
```

For more details, check out: [cplusplus.com - Namespaces](https://cplusplus.com/doc/oldtutorial/namespaces/)

<div align="right">
  <b><a href="#top">↥ back to top</a></b>
</div>

---

### I/O Streams

C++ provides a more convenient way to handle input and output compared to C. In C, functions like `write` and `read` are used for I/O manipulation, often requiring manual file descriptor handling and buffer management.

In C++, there is no need to set up file descriptors or manage buffers manually: Standard streams like `cin` and `cout` handle this for you. The language introduces two operators, `>>` and `<<`, to facilitate data flow.

**Basic I/O in C++:**
```cpp
#include <iostream>

char    buff[512];

int main() {
    std::cout << "Hello world!" << std::endl;

    std::cout << "Input a word: ";
    std::cin >> buff;
    std::cout << "You entered: [" << buff << "]" << std::endl;

    return 0;
}
```

**Key Differences from C:**
- No need to manually set up file descriptors or buffers.
- Uses `cin` (standard input) and `cout` (standard output) instead of `scanf` and `printf`.
- The `<<` operator is used for output, and `>>` is used for input.

For more details, check out the official C++ documentation: [cplusplus.com - I/O Stream](https://cplusplus.com/reference/iostream/)

<div align="right">
  <b><a href="#top">↥ back to top</a></b>
</div>

---

### File Streams

File streams in C++ are used to read from and write to files. They are part of the `<fstream>` header.
Classes for for reading, writing, and read/write streams are `ifstream`, `ofstream`, and `fstream`, respectively.

**Reading from a File**
```cpp
#include <iostream>
#include <fstream>

int main() {
    std::ifstream    inFile("example.txt");  // Open the file for reading
    std::string      line;  // String to store each line read from the file

    // Check if the file was successfully opened
    if (inFile.is_open()) {
        // Read the file line by line until the end of the file
        while (std::getline(inFile, line)) {
            std::cout << line << std::endl;  // Output the line to the terminal
        }
        inFile.close();  // Close the file after reading
    } else {
        std::cout << "Unable to open file\n";
    }

    return 0;
}
```

**Writing to a File**
```cpp
#include <iostream>
#include <fstream>

int main() {
    std::ofstream    outFile("example.txt");  // Open the file for writing

     // Check if the file was successfully opened
    if (outFile.is_open()) {
        outFile << "Hello, world!\n";  // Write text to the file
        outFile << "Writing to files in C++.\n";  // Write another line
        outFile.close();  // Close the file after writing
    } else {
        std::cout << "Unable to open file";
    }

    return 0;
}
```

**File Modes**
You can open files in different modes using flags like:

- `ios::in` – read (default for `ofstream` and `fstream`)
- `ios::out` – write (default for `ifstream` and `fstream`)
- `ios::app` – append
- `ios::trunc` – truncate
- `ios::binary` – binary mode

Example:
```cpp
fstream file("data.bin", ios::in | ios::out | ios::binary);
```

**Best Practices**
- Always check if a file is open before reading or writing.
- Close files after use to free up resources.
- Use `getline()` for line-by-line reading, and `>>` for formatted extraction (e.g., reading integers or floating-point numbers).

For more details, see the [C++ File I/O tutorial on cplusplus.com](https://cplusplus.com/doc/tutorial/files/).

<div align="right">
<b><a href="#top">↥ back to top</a></b>
</div>

---

### Classes and Instances

In C++, objects are instances of **classes**. A class defines a blueprint for creating objects, encapsulating both data and behavior.

#### Declaring a Class:

```cpp
// Example.hpp

#pragma once

class Example {
public:
    Example();   // Constructor (same name as the class)
    ~Example();  // Destructor (same name with '~' prefix)
};
```

- **Constructor** (`Example()`) is automatically called when an instance of the class is created.
- **Destructor** (`~Example()`) is automatically called when an instance is destroyed or goes out of scope.
- Unlike functions, constructors and destructors **do not have a return type**.
- You don't *need* to explicitly define a constructor or destructor — the compiler automatically provides default ones. However, if you want to initialize member variables or define custom behavior when an object is created or destroyed, you should provide your own.

#### Defining Class Methods:

Class methods in C++ are functions defined inside a class. They describe the behavior of the class and operate on its data.

```cpp
// Example.cpp

#include <iostream>
#include "Example.hpp"

Example::Example() {
    std::cout << "Constructor called" << std::endl;
}

Example::~Example() {
    std::cout << "Destructor called" << std::endl;
}
```

- The scope resolution operator (`::`) is used to define class methods outside the class declaration.

#### Creating an Instance:

```cpp
// Main.cpp

#include "Example.hpp"

int main() {
    Sample    inst; // Constructor is called
    return 0; // Destructor is called when 'inst' goes out of scope
}
```

#### Key Takeaways:
- Classes encapsulate data and behavior.
- Constructors initialize objects when they are created.
- Destructors handle cleanup when objects are destroyed.
- Instance creation automatically triggers the constructor and destructor.

For more details, refer to: [cplusplus.com - Classes](https://cplusplus.com/doc/tutorial/classes/)

<div align="right">
  <b><a href="#top">↥ back to top</a></b>
</div>

---

### Class Members

In C++, a **member attribute** is simply a variable that belongs to a class and is associated with an instance of the class. These attributes are used to store data specific to the class objects. Similarly, **member functions** are functions that belong to a class and operate on its data (attributes). These functions can be used to modify or access member attributes and carry out specific actions.

```cpp
// Example.hpp

#pragma once

class Example {
public:
    int foo;    // Declaration of member attribute (variable)
 
    Example();  // Constructor declaration
    ~Example(); // Destructor declaration

    void bar(); // Declaration of member function
};
```

```cpp
// Example.cpp

#include <iostream>
#include "Example.hpp"

// Constructor definition
Example::Example() {
    std::cout << "Constructor called" << std::endl;
}

// Destructor definition
Example::~Example() {
    std::cout << "Destructor called" << std::endl;
}

// Member function definition
void Example::bar() {
    std::cout << "Member function bar called" << std::endl;
}
```

```cpp
// Main.cpp

#include <iostream>
#include "Example.hpp"

int main() {
    Example inst;  // Creating an instance of Example (Constructor is called)

    inst.foo = 42; // Accessing member attribute 'foo'
    std::cout << "inst.foo: " << inst.foo << std::endl; // Printing 'foo'

    inst.bar(); // Calling member function 'bar'

    return 0;  // Destructor is called automatically when 'inst' goes out of scope
}
```

For more details, refer to: [cplusplus.com - Class Member Functions](https://www.tutorialspoint.com/cplusplus/cpp_class_member_functions.htm)

<div align="right">
  <b><a href="#top">↥ back to top</a></b>
</div>

--- 

### This Pointer

In C++, the `this` pointer refers to the current instance of the class. It is an implicit pointer passed to all non-static member functions, which allows those functions to access and modify the data members of the object they belong to.

Using `this` is often unnecessary when there's no name conflict, but it becomes useful when a local variable or function parameter has the same name as a member attribute.

```cpp
// Example.hpp

#pragma once

class Example {
public:
    int foo;    // Declaration of member attribute (variable)
 
    Example();  // Constructor declaration
    ~Example(); // Destructor declaration

    void bar(); // Declaration of member function
};
```

```cpp
// Example.cpp

#include <iostream>
#include "Example.hpp"

// Constructor definition
Example::Example() {
    std::cout << "Constructor called" << std::endl;

    // Using 'this' to refer to the current object's member attribute
    this->foo = 42; 
    std::cout << "this->foo: " << this->foo << std::endl;

    // Calling the member function 'bar' using 'this'
    this->bar();
}

// Destructor definition
Example::~Example() {
    std::cout << "Destructor called" << std::endl;
}

// Member function definition
void Example::bar() {
    std::cout << "Member function bar called" << std::endl;
}
```

```cpp
// Main.cpp

#include "Example.hpp"

int main() {
    Example inst;  // Creating an instance of Example, which calls the constructor
    return 0;  // Destructor is called when 'inst' goes out of scope
}
```

The output will be the same as the [previous example](#member-attributes-and-member-functions), showing the constructor and destructor messages as well as the `bar()` function call.

<div align="right">
  <b><a href="#top">↥ back to top</a></b>
</div>

---

### Pointers to Class Members

C++ allows pointers not just to regular variables and functions, but also to class members. These are special pointers because they don't point to memory directly, but instead require an object to be used.

```cpp
class Example {
public:
    int    foo;

    void    sayHi() const;
};
```
Using Pointers to Members:
```cpp
int main() {
    Example    inst;
    Example*   instPtr = &inst;

    // Pointer to member variable of type `int`
    int Example::*ptr = nullptr;

    // Pointer to member function that is `const` and returns `void`
    void (Example::*f_ptr)() const; // <- Note parentheses

    // Assign the member pointer
    ptr = &Example::foo;

    // Access member variable via instance
    inst.*ptr = 21;

    // Access member variable via pointer to instance
    instPtr->*ptr = 42;

    // Assign member function pointer
    f_ptr = &Example::sayHi;

    // Call member function via instance
    (inst.*f_ptr)();

    // Call member function via pointer to instance
    (instPtr->*f_ptr)();

    return 0;
}
```
**Notes**
- Use `.*` with objects and `->*` with pointers to objects.
- Parentheses are required when calling member functions via pointers to avoid syntax ambiguity.
- Pointers to class members are useful when you want to choose which function to call while your program is running, like picking from a list. They are also handy for things like callbacks, where a function needs to be called later.

<div align="right">
<b><a href="#top">↥ back to top</a></b>
</div>

---

### References

In C++ there are references, which are an alias for an existing variable (like a pointer that is const and alway unreferenced) 

```cpp
int     a = 10;
int     &ref = a; // ref is now an alias for a

ref = 20;         // modifies a, since ref refers to a

std::cout << a;   // prints 20
```

#### References vs Pointers
| Feature             | Reference         | Pointer            |
|---------------------|-------------------|--------------------|
| Can be reassigned   | ❌ No              | ✅ Yes             |
| Can be null         | ❌ No              | ✅ Yes             |
| Must be initialized | ✅ Yes             | ❌ No              |
| Syntax              | `int& x = y;`      | `int* x = &y;`     |
| Dereferencing       | Implicit (`x`)     | Explicit (`*x`)    |

References are often preferred when you want to:
- Avoid copying large objects
- Guarantee that something valid is being referred to
- Keep syntax clean (no `*` or `->` needed)

<div align="right">
<b><a href="#top">↥ back to top</a></b>
</div>

---

### Initialization List

In C++, when a constructor is called, the class's member variables need to be initialized. While you can assign values inside the constructor body (as done [here](#this-pointer)), using an initialization list is often more efficient and sometimes necessary.  

An **initialization list** allows you to initialize member variables before entering the constructor body. This is particularly useful when  
1. Initializing **const** members (since they cannot be assigned later).
2. Initializing **reference** members (as references must be assigned at construction).
3. Ensuring **efficient initialization** by directly initializing members instead of using assignment inside the constructor body, which may involve extra operations.

Here’s how it works:
```cpp
// Example.hpp

#pragma once

class Example {
public:
    int    a1;
    char   a2;
    float  a3;  
 
    Example(char p1, int p2, float p3);  // Constructor accepting parameters
    ~Example(); 
};
```

```cpp
// Example.cpp

#include <iostream>
#include "Example.hpp"

// Constructor definition
Example::Example(char p1, int p2, float p3) : a1(p2), a2(p1), a3(p3) { // Initalization list 
    std::cout << "Constructor called" << std::endl;
    std::cout << "this->a1: " << this->a1 << std::endl;
    std::cout << "this->a2: " << this->a2 << std::endl;
    std::cout << "this->a3: " << this->a3 << std::endl;
}

// Destructor definition
Example::~Example() {
    std::cout << "Destructor called" << std::endl;
}
```

```cpp
// Main.cpp

#include "Example.hpp"

int main() {
    Example inst('A', 99, 42.42f);  // Creating an instance with valid values
    return 0; 
}
```

<div align="right">
  <b><a href="#top">↥ back to top</a></b>
</div>

---

### Const

The `const` keyword tells the compiler (and readers) that something should not be modified.
You can use it for variables, functions, and pointers. It’s useful for writing safer code and avoiding accidental changes.

```cpp
class Example {
private:
    int            a;
    const float    pi;  // Can be initialized here...

public:
    Example(float value) : _pi(value) {}  // ...or via constructor initializer lists

    int getA() const {return a;}  // This function promises not to modify the object

    // Pointer variations:
    const int*         p1;  // Pointer to const int (can't change the value)
    int* const         p2;  // Const pointer to int (can't change the pointer)
    const int* const   p3;  // Const pointer to const int (can't change either)
};
```

<div align="right">
  <b><a href="#top">↥ back to top</a></b>
</div>

---

### Static

```cpp
class Example {
public:
    static int count;        // Shared by all instances (class-level)
    static void sayHi();     // Can be called without an object: Example::sayHi();
    int value;               // Normal instance member
};
```
- `static` data members belong to the class, not each object.
- `static` member functions can’t access non-static members (no `this` pointer)
- You must define static members outside the class (unless also `const`): int `Example::count = 0;`

Use `static` for shared state or utility functions that don’t depend on a specific object.

<div align="right">
  <b><a href="#top">↥ back to top</a></b>
</div>

---

### Visibility (private/public)

C++ classes use access specifiers to control visibility. These determine what parts of your code can access the members of a class.

The two most common are:
- `private`: only accessible inside the class
- `public`: accessible from outside the class

```cpp
class Example {
private:
    int    _secret;     // Convention: private members often start with an underscore
    void   _hide() {}   // Used internally by the class

public:
    int    value;       // Public variable (can be accessed from outside)
    int    getSecret() {return _secret;}    // Public function
};
```

`private`:
- Default for class members (if you don’t specify).
- Only accessible from **within** the class.
- Useful for internal data or helper functions.

`public`:
- Accessible from **outside** the class.
- Use for functions or data you want other code to interact with.

Keep members `private` and provide `public` functions to interact with them (like getters/setters).

<div align="right">
  <b><a href="#top">↥ back to top</a></b>
</div>

---

### Class vs Struct

In C++, `class` and `struct` are functionally the same, except for the default visibility:
- `class`: members are `private` by default
- `struct`: members are `public` by default

```cpp
class MyClass {
    int x;       // private by default
};

struct MyStruct {
    int x;       // public by default
};
```

<div align="right">
  <b><a href="#top">↥ back to top</a></b>
</div>

---

### Memory Allocation

While you can use `malloc` and `free` in C++ as in C, this can cause issues with objects since their constructors and destructors won’t be called.   
The safe way to allocate and deallocate memory in C++ is by using `new` and `delete`:
```cpp
int main() {
   Person    bob("bob");               // Stack allocation (automatically destroyed)
   Person    *jim = new Person("jim"); // Heap allocation (manual deletion required)

   int       *arr = new int[5];        // Use `new[]` to allocate arrays

   delete    jim;                      // Free memory for single object
   delete[]  arr;                      // Use `delete[]` for arrays

   return 0;
}
```

---

### Overloading
Overloading (or ad-hoc polymorphism) allows multiple functions or operators to have the same name but different parameters and behaviors.   

#### Function Overloading

Function overloading means writing multiple functions with the same name but with different numbers of parameters or parameter types.   
The compiler picks the right version based on what you pass in.

Example:
```cpp
#include <iostream>

void my_print(int i) {
    std::cout << "Integer: " << i << std::endl;
}

void my_print(double d) {
    std::cout << "Double: " << d << std::endl;
}

void my_print(const std::string& s) {
    std::cout << "String: " << s << std::endl;
}

int main() {
    my_print(10);          // Calls my_print(int)
    my_print(3.14);        // Calls my_print(double)
    my_print("Hello");     // Calls my_print(const std::string&)
}
```

#### Operator Overloading

C++ also allows operator overloading, where you redefine the meaning of built-in operators (like `+`, `<<`, `==`) for your custom types.   

Example: Addition of points:
```cpp
#include <iostream>

struct Point {
    int x, y;

    Point(int x, int y) : x(x), y(y) {}

    // Overloading the '+' operator for adding two Points
    Point operator+(const Point &other) const {
        return Point(x + other.x, y + other.y); // or: `return Point(this->x + other.x, this->y + other.y);`
    }

    // Overloading the '=' operator for assigning one Point to another
    Point &operator=(const Point &other) {
        if (this != &other) {  // Check for self-assignment
            x = other.x;
            y = other.y;
        }
        return *this;  // Return *this to allow chained assignments (`a = b = c;`, right-to-left evaluation)
    }
};

int main() {
    Point a(1, 2);
    Point b(3, 4);

    Point c = a + b;  // Calls `operator+`
    std::cout << c.x << ", " << c.y << std::endl; // Prints '4, 6'

    Point d(0, 0);
    d = c;  // Calls `operator=`, assigns c to d
    std::cout << d.x << ", " << d.y << std::endl;  // Prints '4, 6'
}
```

**Breaking down `Point operator+(const Point& other) const`:**
| Part                  | Meaning                                                |
|------------------------|--------------------------------------------------------|
| `Point`                | Return type: a new `Point` will be returned.            |
| `operator+`            | Special function name for overloading `+`.              |
| `(const Point &other)` | Takes another `Point` as a const reference (safe and fast). |
| `const` (at end)       | Guarantees that `this` won't be changed.                |

For comparison, `operator=` works similarly to `operator+`, but instead of creating a new `Point`, it modifies the existing current object (`*this` returning `Point&`).

**What happens when you write `a + b`?**
- `a` becomes `this` inside `operator+`.
- `b` becomes the `other` parameter.
- C++ treats `a + b` like: `a.operator+(b)`.

**What happens when you write `d = c`?**
- The `operator=` is called on `d`, with `c` as the argument, just like `d.operator=(c)`.
- Inside `operator=`, the values of `c` (the `x` and `y` of `Point c`) are copied into `d`.
- The assignment operator checks for self-assignment (e.g., `d = d`), ensuring the object isn't assigned to itself.
- After the assignment, `d` holds the same values as `c`.

<div align="right">
<b><a href="#top">↥ back to top</a></b>
</div>

---

### Inheritance

Inheritance allows one class to acquire the properties (data members) and behaviors (member functions) of another class. 

**Basic Syntax:**
```cpp
#include <iostream>

class Animal { // Base class
protected:
    int legs;

public:
    Animal(int numLegs) : legs(numLegs) {}
    virtual ~Animal {}   // Base class deconstructor should be virtual,
                         // especially when dealing with pointers to dynamically allocated objects.

    void eat() { std::cout << "Eats!\n" }
    void run() { std::cout << "Runs!\n" }
};

class Cat : public Animal { // Derived class
public:
    Cat() : Animal(4) {}  // Call base class constructor

    void run() { std::cout << "Jumps!\n" } // Overwrite inherited behavior
};
```

**Access Specifiers in Inheritance:**

| Specifier   | Access in Child Class | Access Outside |
|-------------|------------------------|----------------|
| `public`    | ✅ Yes                 | ✅ Yes         |
| `protected` | ✅ Yes                 | ❌ No          |
| `private`   | ❌ No                  | ❌ No          |

- Constructors of base classes are called **first**.
- Destructors are called in **reverse order** (child first, then base).
- **Private inheritance** is possible, but it is usually not useful because it hides the base class's functionality, making it harder to access and extend. It is useful in situations where you want to implement "**has-a**" relationships rather than "**is-a**" relationships.

#### Multiple Inheritance

You can inherit from more than one base class:
```cpp
class Carnivore {
protected:
    bool    eatsMeat = true;
};

class Cat : public Animal, public Carnivore {
    // Can access members from both Animal and Carnivore
};
```
Caution: Be mindful of name conflicts and ambiguous inheritance, such as when a variable name in the base class is redefined in the derived class. This shadowing can lead to unexpected behavior and confusion. You can use the compiler flag `-Wshadow` to identify situations where shadowing occurs.

#### Diamond Inheritance

**The Problem:**
```cpp
class Animal { /* ... */ };

class Mammal : public Animal { /* ... */ };
class Feline : public Animal { /* ... */ };

class Cat : public Mammal, public Feline { /* ... */ };  // Two Animal copies!
```

**The Solution: Use `virtual` inheritance**
```cpp
class Animal {
protected:
    int legs;

public:
    Animal(int numLegs) : legs(numLegs) {}
    virtual ~Animal() {} 
};

class Mammal : virtual public Animal { // Virtual inheritance prevents duplicate Animal subobjects
protected:
    bool    liveBirth = true;

public:
    Mammal() : Animal(4) {}

    void identification() { std::cout << "I'm a mammal!\n" }
};

class Feline : virtual public Animal { // Virtual inheritance prevents duplicate Animal subobjects
protected:
    bool    whiskers = true;

public:
    Feline() : Animal(4) {}

    void identification() { std::cout << "I'm a feline!\n" }
};

class Cat : public Mammal, public Feline {
public:
    Cat() : Animal(4), Mammal(), Feline() {}

    using Feline::identification() // Selects Feline's version to resolve ambiguity
};
```

**`virtual` Keyword in Inheritance:**
- Ensures that only one instance of the base class exists in the inheritance chain.
- Requires the **most derived class** to call constructors in **order of inheritance** (base first).

<div align="right">
  <b><a href="#top">↥ back to top</a></b>
</div>

---

### Subtyping Polymorphism

Subtyping polymorphism enables a pointer or reference to a base class to refer to objects of derived classes. The actual function called is determined at runtime using virtual functions.

```cpp
#include <iostream>

class Base {
public:
    void    sayHello() {
        std::cout << "Base says hello (non-virtual)\n";
    }

    virtual void greet() {
        std::cout << "Base greets you (virtual)\n";
    }
};

class Derived : public Base {
public:
    void sayHello() {
        std::cout << "Derived says hello (non-virtual)\n";
    }

    void greet() {
        std::cout << "Derived greets you (virtual)\n";
    }
};

int main() {
    Derived    d;
    Base*      ptr = &d;  // Base pointer pointing to Derived object

    ptr->sayHello(); // Non-virtual → Base::sayHello() is called
    ptr->greet();    // Virtual → Derived::greet() is called

    return 0;
}
```

<div align="right">
  <b><a href="#top">↥ back to top</a></b>
</div>

---

### Abstract Classes

An abstract class in C++ is a class that contains at least one pure virtual function. You cannot instantiate an abstract class directly.   

An interface in C++ is a special kind of abstract class that contains only pure virtual functions and no data members. It defines a contract that derived classes must fulfill.   

Pure virtual functions act as placeholders for behavior that must be implemented by any concrete (non-abstract) derived class.

```cpp
#include <iostream>

class ABase {
public:
    virtual void say() = 0;   // pure virtual: Makes the class abstract
    virtual ~ABase() {}       // virtual destructor: Deleting derived objects through a base pointer works correctly.
};

class Derived : public ABase {
public:
    void say() {              // Derived classes must implement pure virtual functions to be instantiable
        std::cout << "Hello hello!\n";
    }
};

```

---

### Exceptions

Exceptions let you handle errors and unexpected situations in a clean way without crashing your program.

**Throwing exceptions**

You "throw" an exception when something goes wrong:

```cpp
throw std::runtime_error("Something went wrong!");
```

You can throw:
- Built-in types (`throw 42;`) (not recommended as this lacks context).
- Standard exceptions (`std::runtime_error`, `std::invalid_argument`, etc.).
- Your own custom exception classes.

**Catching Exceptions**

You use `try`/`catch` to handle exceptions:

```cpp
#include <iostream>
#include <stdexcept>

int main() {
    try {
        throw std::runtime_error("Failure!");
    } catch (const std::exception& e) {
        std::cout << "Caught exception: " << e.what() << std::endl;
    }

    return 0;
}
```

- The `what()` method returns a description of the error.
- You should throw an exception by value (passing an exception object), which makes a copy of the exception.
- You should catch exceptions by reference, e.g., `const std::exception& e`; use `const` to avoid accidentally modifying the exception object.
- You can catch anything with a generic catch block (`catch (...)`), but it's best to catch specific exception types when possible.
- It's good practice to let exceptions bubble up so they can be handled at a higher level where more context is available, rather than forcing them to be caught and handled locally. If no one catches the exception, the program terminates.

**Defining Your Own Exception Class**

Define your own exception class by inheriting from `std::exception`.

```cpp
#include <exception>
#include <string>

class MyError : public std::exception {
    std::string message;
public:
    MyError(const std::string& msg) : message(msg) {}

    const char* what() const throw() { // Override the what() function from std::exception
        return message.c_str();
    }
};
```

- `what()` returns a `const char*`.
- `throw()` means that it doesn’t throw exceptions itself (`noexcept` is used in modern C++ instead).
- You can also define exceptions within classes to keep things organized (nested custom exceptions).

<div align="right">
  <b><a href="#top">↥ back to top</a></b>
</div>

---

### Casting

C-style casting (```(type) expression```) works in C++ as well but can be potentially unsafe and ambiguous.

**-> Type Promotion (Implicit Casting)**

Promotion Hierarchy:  

```cpp
bool < char < short < int < unsigned int < long < float < double < long double
```

Example:  

```cpp
char c = 10;
int i = c + 1; // c is promoted to int
```

- Happens automatically
- Safe, but can cause loss of precision (when demoting, e.g. `float` to `int`).

**-> Reinterpretation Cast**

Implicit reinterpretation:

```cpp
float a = 3.14f;
void* p = &a; // implicit reinterpretation (safe)
```

Explicit reinterpretation:

```cpp
void* p = (void*)&a; // explicit reinterpretation
int* i = (int*)p;     // reinterpret float as int (dangerous)
```

Reinterpreting `float*` as `int*` changes how the bits are read. The actual value may become meaningless.

**-> Demotion**

```cpp
void* d = &a;     // a is float
int* e = d;       // ❌ implicit demotion not allowed
```

```cpp
int* e = (int*)d; // ✅ allowed, but dangerous; must be explicit
```

**-> Object-Oriented Casts (Upcast & Downcast)**

```cpp
class Parent {};
class Child1 : public Parent {};
class Child2 : public Parent {};
```

Upcast (Safe):

```cpp
Child1 a;
Parent* p = &a; // implicit upcast from Child1 to Parent (safe)
```

Downcast (Needs explicit cast):

```cpp
Child1* c = (Child1*)p; // C-style (unsafe)
Child2* d = static_cast<Child2*>(p); // static_cast (dangerous if types unrelated)
```

**-> static_cast**

- Compile-time
- Between related types (inheritance, arithmetic types)

```cpp
float f = 3.14;
int i = static_cast<int>(f);
```

**-> dynamic_cast**

- Runtime checked
- For polymorphic base classes
- Requires virtual function in base

```cpp
Parent* p = new Child1; 
Child1* c = dynamic_cast<Child1*>(p); // OK
Child2* d = dynamic_cast<Child2*>(p); // nullptr (safe)

try {
  Child2& ref = dynamic_cast<Child2&>(*p); // throws std::bad_cast
} catch (std::bad_cast&) {
  // handle error
}
```

**-> reinterpret_cast**

- Reinterpret memory
- Used with raw pointers

```cpp
void* buffer = malloc(4);
int* i = reinterpret_cast<int*>(buffer);
```

Use for low-level operations only (e.g. networks, serialization).

**-> const_cast**

- Add/remove `const` or `volatile`

```cpp
int a = 42;
const int* p = &a;
int* q = const_cast<int*>(p); // now mutable
```

**⚠️ Note:** The need for const_cast often signals a design issue. If you find yourself using it, consider whether const correctness is being violated elsewhere in your code. Ideally, you shouldn't need it in well-structured code.

**-> `explicit` Keyword in Constructors**

Prevents implicit conversions.

```cpp
class A {};
class B {};

class C {
public:
  C(const A&) {}
  explicit C(const B&) {}
};

void f(const C&) {}

int main() {
  f(A()); // OK
  // f(B()); // ❌ Error: explicit required
  f(C(B())); // ✅ Explicitly constructed
}
```

A constructor with one parameter can act as an implicit converter.   
To prevent accidental or unintended conversions, including assignment-style initialization, `explicit` is used:


```cpp
class C {
public:
  explicit C(int x) {}
};

int main() {
  C c = 42;  // ❌ Error — implicit conversion not allowed
  C c(42);   // ✅ OK — direct initialization
}
```

Using `explicit` is good practice to avoid surprises when a class is constructible from a single value.


**-> Summary**

| Cast Type         | Time | Use Case                          |
|------------------|------------------|-----------------------------------|
| C-Style          |  Compile-time     | Avoid in modern C++               |
| static_cast      |  Compile-time     | Arithmetic, related types         |
| dynamic_cast     | Runtime          | Polymorphic downcasting           |
| reinterpret_cast |  Compile-time     | Low-level memory reinterpretation |
| const_cast       |  Compile-time     | Add/remove const/volatile         |

<div align="right">
  <b><a href="#top">↥ back to top</a></b>
</div>

---

### Templates

Templates allow to write generic code that works with any data type. You can think of a template as a "recipe" that the compiler uses to generate type-specific versions of your code.

There are:
- Function templates → Generic functions
- Class templates → Generic classes/structs

**Function Templates**

```cpp
template<typename T>
T max(T a, T b)
{
    return (a > b) ? a : b;
}

int main()
{
    int i = max(3, 7);         // T = int
    double d = max(2.5, 4.8);  // T = double
    char c = max('a', 'z');    // T = char
}
```

**Class Templates**

```cpp
template<typename T>
class Box
{
    T _value;
public:
    Box(T val) : _value(val) {}
    T get() const { return _value; }
};
 
int main()
{
    Box<int> intBox(42);
    Box<std::string> strBox("Hello");

    std::cout << intBox.get() << std::endl;
    std::cout << strBox.get() << std::endl;
}
```

**Templates with Default Types**

You can provide a default type for a template parameter:

```cpp
template<typename T = int>
class DefaultBox
{
    T _value;
public:
    DefaultBox(T val) : _value(val) {}
    T get() const { return _value; }
};

int main()
{
    DefaultBox<> box1(123);         // T defaults to int
    DefaultBox<double> box2(3.14);  // T = double

    std::cout << box1.get() << std::endl;
    std::cout << box2.get() << std::endl;
}
```

**Template Specializations**

Sometimes you want to provide a custom implementation for a specific type. This is called template specialization.

```cpp
template<typename T>
class Printer
{
public:
    void print(T value)
    {
        std::cout << "General: " << value << std::endl;
    }
};

// Specialization for bool
template<>
class Printer<bool>
{
public:
    void print(bool value)
    {
        std::cout << "Boolean: " << (value ? "true" : "false") << std::endl;
    }
};

int main()
{
    Printer<int> p1;
    Printer<bool> p2;

    p1.print(42);
    p2.print(true);
}
```

**`.tpp` Files (Template Implementation Files)**

**Problem:** You cannot put template definitions in `.cpp` files because templates are compiled when instantiated.

**Solution:** Use `.tpp` files:

- Put template class declaration in `.hpp`
- Put template function implementations in `.tpp`
- Include `.tpp` at the bottom of `.hpp`
- It’s common to have both `.tpp` and `.hpp` files in the same `include/` folder.

**Box.hpp**

```cpp
#ifndef BOX_HPP
# define BOX_HPP

# include <iostream>

template<typename T>
class Box
{
    T _value;
public:
    Box(T val);
    T get() const;
};

# include "Box.tpp" // include implementation here

#endif
```

**Box.tpp**

```cpp
template<typename T>
Box<T>::Box(T val) : _value(val) {}

template<typename T>
T Box<T>::get() const
{
    return _value;
}
```

**main.cpp**

```cpp
#include "../include/Box.hpp"

int main()
{
    Box<int> b(5);
    std::cout << b.get() << std::endl;
}
```

**Why `.tpp`?**
It is not required to name it `.tpp` — some people use `.inl` or just put the functions in the `.hpp`.
But using `.tpp` helps keep declarations and definitions separated.

<div align="right">
  <b><a href="#top">↥ back to top</a></b>
</div>

---

### STL Containers

The Standard Template Library (STL) in C++ provides several generic containers that simplify the management of data structures. Below is an overview of key STL containers (`list`, `vector`, `map`), their operations, and iterator concepts.  

You can find more details about STL containers at [https://cplusplus.com/reference/stl](https://cplusplus.com/reference/stl/?kw=stl).

1. **`std::list`**          
    A `std::list` is a **doubly linked list**, allowing efficient insertions and deletions from both ends and the middle.

   Declaration:
    ```cpp
    #include <list>
    std::list<int> myList;
    ```

    Common Operations:
   
    | Function           | Description                   | Example                   |
    |--------------------|-------------------------------|---------------------------|
    | `push_back(val)`   | Add element to the end         | `myList.push_back(10);`   |
    | `push_front(val)`  | Add element to the front       | `myList.push_front(5);`   |
    | `pop_back()`       | Remove the last element        | `myList.pop_back();`      |
    | `pop_front()`      | Remove the first element       | `myList.pop_front();`     |
    | `insert(pos, val)` | Insert before iterator `pos`   | `myList.insert(it, 7);`   |
    | `erase(pos)`       | Remove element at iterator `pos` | `myList.erase(it);`     |
    | `remove(val)`      | Remove all elements equal to `val` | `myList.remove(42);`   |
    | `clear()`          | Remove all elements            | `myList.clear();`         |
    | `sort()`           | Sort the list                  | `myList.sort();`          |
    | `reverse()`        | Reverse the list               | `myList.reverse();`       |
    | `unique()`         | Remove consecutive duplicates  | `myList.unique();`        |
    | `splice(pos, other)` | Move elements from other list  | `myList.splice(it, other);` |
    | `merge(other)`     | Merge two sorted lists         | `myList.merge(other);`    |

    Access:

    | Function          | Description              |
    |-------------------|--------------------------|
    | `front()`         | Access first element      |
    | `back()`          | Access last element       |
    | `size()`          | Number of elements        |
    | `empty()`         | Check if empty            |

   
2. **`std::vector`**

    A `std::vector` is a **dynamic array**, offering fast random access and automatic resizing.

    Declaration:
    ```cpp
    #include <vector>
    std::vector<int> myVector;
    ```

    Common Operations:
   
    | Function           | Description                   | Example                  |
    |--------------------|-------------------------------|--------------------------|
    | `push_back(val)`   | Add element to the **end**     | `myVector.push_back(10);`|
    | `pop_back()`       | Remove last element            | `myVector.pop_back();`   |
    | `insert(pos, val)` | Insert before position         | `myVector.insert(it, 7);`|
    | `erase(pos)`       | Remove element at position     | `myVector.erase(it);`    |
    | `resize(n)`        | Resize the vector              | `myVector.resize(5);`    |
    | `clear()`          | Remove all elements            | `myVector.clear();`      |

    Access:

    | Function           | Description                    |
    |--------------------|--------------------------------|
    | `operator[]`       | Random access by index          |
    | `at(index)`        | Bounds-checked access           |
    | `front()`          | First element                  |
    | `back()`           | Last element                   |
    | `size()`           | Number of elements             |
    | `capacity()`       | Current storage capacity       |
    | `empty()`          | Check if empty                 |
   
3. **`std::map`**
   
    A  `std::map ` is an **ordered associative container** storing key-value pairs, sorted by keys.

    Declaration:
    ```cpp
    #include <map>
    std::map<std::string, int> myMap;
    ```

    Common Operations:
   
    | Function          | Description                | Example                      |
    |-------------------|----------------------------|------------------------------|
    | `insert({k,v})`   | Insert key-value pair       | `myMap.insert({"a", 1});`     |
    | `erase(key)`      | Remove element by key       | `myMap.erase("a");`           |
    | `clear()`         | Remove all elements         | `myMap.clear();`              |
    | `find(key)`       | Find element by key         | `std::map<std::string, int>::iterator it = myMap.find("a");`  |

    Access:

    | Function          | Description                  |
    |-------------------|------------------------------|
    | `operator[]`      | Access or insert element      |
    | `at(key)`         | Access with bounds checking   |
    | `size()`          | Number of elements            |
    | `empty()`         | Check if empty                |

   

   A `std::list` is a doubly linked list, allowing efficient insertions and deletions from both ends and from the middle.

4. **Iterators**

    Iterators are objects that **point to elements inside containers**, allowing traversal.

    Iterator Types:

    | Iterator Type           | Description                        | Access         |
    |------------------------|-----------------------------------|----------------|
    | `iterator`             | Read/write access                  | Read & modify  |
    | `const_iterator`       | Read-only access                  | Read only      |
    | `reverse_iterator`     | Reverse traversal, read/write    | Read & modify  |
    | `const_reverse_iterator`| Reverse traversal, read-only      | Read only      |


    Begin/End Functions:

    | Function      | Returns                          | Description                     |
    |---------------|---------------------------------|---------------------------------|
    | `begin()`     | `iterator`                      | Iterator to first element       |
    | `end()`       | `iterator`                      | Iterator past the last element  |
    | `cbegin()`    | `const_iterator`                | Const iterator to first element |
    | `cend()`      | `const_iterator`                | Const iterator past last element|
    | `rbegin()`    | `reverse_iterator`              | Reverse iterator to last element|
    | `rend()`      | `reverse_iterator`              | Reverse iterator before first   |
    | `crbegin()`   | `const_reverse_iterator`        | Const reverse iterator last element |
    | `crend()`     | `const_reverse_iterator`        | Const reverse iterator before first |

    Notes:

    - `begin()` and `end()` let you loop forward.
    - `rbegin()` and `rend()` let you loop backward.
    - `const_` versions provide **read-only** access, preventing modification.
    - Containers declared `const` only allow const iterators.
  
**Example: Looping through a list with iterators**

```cpp
#include <iostream>
#include <list>

std::list<int> myList = {10, 20, 30};

// Forward loop
for (std::list<int>::iterator it = myList.begin(); it != myList.end(); ++it) {
    std::cout << *it << " ";  // Output: 10 20 30
}
std::cout << std::endl;

// Read-only loop with const_iterator
for (std::list<int>::const_iterator cit = myList.cbegin(); cit != myList.cend(); ++cit) {
    std::cout << *cit << " ";  // Output: 10 20 30
}
std::cout << std::endl;

// Reverse loop
for (std::list<int>::reverse_iterator rit = myList.rbegin(); rit != myList.rend(); ++rit) {
    std::cout << *rit << " ";  // Output: 30 20 10
}
std::cout << std::endl;

return 0;
}
```

<div align="right">
  <b><a href="#top">↥ back to top</a></b>
</div>

---

### STL Algorithms

The STL provides a useful set of algorithms in the `<algorithms>` header. These functions operate on ranges defined by iterators and allow for easy manipulation of data stored in containers such as `list`, `vector`, and `map`. 

All `<algorithms>` functions are listed here: [https://cplusplus.com/reference/algorithm/](https://cplusplus.com/reference/algorithm/)

1. **Understanding Ranges and Iterators**

   STL algorithms do no act directly on containers but on iterator ranges. A range is typically specified using a pair of iterators, such as `begin()` and `end()`:

   ```cpp
   std::vector<int> v = {1, 3, 1};
   std::sort(v.begin(), v.end());
   ```

   Here, `sort` processes the range `[v.begin(), v.end()]`.
   
2. **Categories pf Algorithms**
    
    **Modifying Algorithms**
   
    | Function   | Description                            | Example                                      |
    |------------|----------------------------------------|----------------------------------------------|
    | `copy`     | Copies elements to another range       | `std::copy(a.begin(), a.end(), b.begin());`  |
    | `fill`     | Assigns a value across a range         | `std::fill(v.begin(), v.end(), 0);`          |
    | `replace`  | Replaces specific values               | `std::replace(v.begin(), v.end(), 1, 99);`   |
    | `sort`     | Sorts elements in ascending order      | `std::sort(v.begin(), v.end());`             |
    | `reverse`  | Reverses the order of elements         | `std::reverse(v.begin(), v.end());`          |
    

    **Searching Algorithms**    

    | Function         | Description                                 | Example                                        |
    |------------------|---------------------------------------------|------------------------------------------------|
    | `find`           | Finds the first occurrence of a value       | `std::find(v.begin(), v.end(), 5);`            |
    | `find_if`        | Finds the first element matching a condition| `std::find_if(v.begin(), v.end(), pred);`      |
    | `count`          | Counts occurrences of a value               | `std::count(v.begin(), v.end(), 3);`           |
    | `binary_search`  | Checks existence in sorted range            | `std::binary_search(v.begin(), v.end(), 2);`   |


    **Comparison Algorithms**

    | Function                  | Description                                  | Example                                          |
    |---------------------------|----------------------------------------------|--------------------------------------------------|
    | `equal`                   | Compares if two ranges are element-wise equal| `std::equal(a.begin(), a.end(), b.begin());`     |
    | `lexicographical_compare` | Compares two ranges like dictionary order    | `std::lexicographical_compare(...)`              |


    **Removal Algorithms**

    | Function   | Description                                             | Example                                     |
    |------------|---------------------------------------------------------|---------------------------------------------|
    | `remove`   | Removes elements logically (does not resize container)  | `std::remove(v.begin(), v.end(), 2);`       |
    | `unique`   | Removes consecutive duplicates                          | `std::unique(v.begin(), v.end());`          |

   These do not actually shrink the container. Use erase to do that:
   ```cpp
   v.erase(std::remove(v.begin(), v.end(), 2), v.end());
   ```
   
3. **Best Practices**
    
    - Some algorithms require specific iterator types (e.g., `sort` needs random-access iterators).
    - Use lambdas for concise custom logic in algorithms.
    - Combine algorithms for clean, efficient patterns (e.g., `unique` + `erase`).
      
4. **Example: Finding and Replacing**

    ```cpp
    // Using C++98 Standard

    #include <vector>
    #include <algorithm>
    #include <iostream>

    void print_int(int x) {
        std::cout << x << " ";
    }
    
    int main() {
        std::vector<int> v;
    
        v.push_back(1);
        v.push_back(2);
        v.push_back(3);
        v.push_back(2);
        v.push_back(4);

        // Find the first occurrence of 2
        std::vector<int>::iterator it = std::find(v.begin(), v.end(), 2);
        if (it != v.end())
            std::cout << "Found: " << *it << "\n";
    
        // Replace all 2s with 9s
        std::replace(v.begin(), v.end(), 2, 9);

        // Print elements with std::for_each and a function
        std::for_each(v.begin(), v.end(), print_int);
        std::cout << std::endl;
        // Output: 1 9 3 9 4
    }
    ```

<div align="right">
<b><a href="#top">↥ back to top</a></b>
</div>

---

### Ford-Johnson Algorithm 


XXX

<div align="right">
  <b><a href="#top">↥ back to top</a></b>
</div>

---
