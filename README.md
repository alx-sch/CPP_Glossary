# C++ Glossary

<p align="center">
    <img src="https://github.com/alx-sch/42_CPP_00-04/blob/main/.assets/img/cpp_badge.png" alt="cpp_badge.png" />
</p>


## Table of Contents
<div id="top"></div>  
  
- [Namespaces](#namespaces)
- [Stdio Streams](#stdio-streams)
- [Classes and Instances](#classes-and-instances)
- [Member Attributes and Member Functions](#member-attributes-and-member-functions)
- [This Pointer](#this-pointer)
- [Initialization List](#initialization-list)
- [Const](#const)
- [Visibility (public/private)](#visibility-privatepublic)
- [Class vs Struct](#class-vs-struct)
- [Static](#static)
- [Pointers to Class Members](#pointers-to-class-members)
- [Memory Allocation](#memory-allocation)
- [References](#reference)
 
---

## CPP_00:

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

---

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

---

#### Scope Resolution Operator (`::`):  

The `::` operator is used to access elements within a namespace. For example:

```cpp
Foo::g_var   // Accesses the 'g_var' defined in the 'Foo' namespace
::g_var      // Accesses the global 'g_var' (outside any namespace); same as using 'g_var' 
```

---

#### Standard Namespace:

The `std` namespace is the default namespace for the C++ Standard Library. It contains commonly used components like `iostream`, `string`, etc.

```cpp
std::cout << "Hello, world!" << std::endl;
```

For more details, check out: [cplusplus.com - Namespaces](https://cplusplus.com/doc/oldtutorial/namespaces/)

<div align="right">
  <b><a href="#top">↥ back to top</a></b>
</div>

---

### Stdio Streams

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

---

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
  
---

#### Creating an Instance:

```cpp
// Main.cpp

#include "Example.hpp"

int main() {
    Sample    inst; // Constructor is called
    return 0; // Destructor is called when 'inst' goes out of scope
}
```

---

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

### Member Attributes and Member Functions

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

### Initialization List

In C++, when a constructor is called, the class's member variables need to be initialized. While you can assign values inside the constructor body (as done [above](#this-pointer)), using an initialization list is often more efficient and sometimes necessary.  

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
    int    getSecret() {return _secret;}    // Public function (part of the interface)
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
- These pointers are useful when implementing things like callback mechanisms, or selecting behavior at runtime based on a table of member function pointers.

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

### References

In C++ there are references, which are an alias for an existing variable (like a pointer that is const and alway unreferenced) 

```cpp
int     a = 10;
int&    ref = a;  // ref is now an alias for a

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

