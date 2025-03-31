# C++ 

<p align="center">
    <img src="https://github.com/alx-sch/42_CPP_00-04/blob/main/.assets/img/cpp_badge.png" alt="cpp_badge.png" />
</p>


## Table of Contents
<div id="top"></div>  
  
- [CPP_00](#cpp_00)
  - [Namespace](#namespaces)
  - [Stdio Streams](#stdio-streams)
  - [Classes and Instances](#classes-and-instances)
  - [Member Attributes and Member Functions](#member-attributes-and-member-functions)
  - [This Pointer](#this-pointer)
  - [Initialization List](#initialization-list)
 
---

## CPP_00:

### Namespaces   

A **namespace** is a way to group related declarations (such as variables, functions, and classes) to organize code and prevent name conflicts. Think of it as a "bag" that holds related entities, giving them a meaningful and scoped name.

**Example:**
```cpp
int g_var = 1;
int fct(void) {return 42;}

namespace Foo {
    int g_var = 2;
    int fct(void) {return 40;}
}

namespace Bar {
    int g_var = 3;
    int fct(void) {return 2;}
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
namespace Muf = Bar;
```

Now, `Muf` is an alias for `Bar`, and you can access `Bar`'s members using `Muf`.

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

**Example: Basic I/O in C++:**
```cpp
#include <iostream>

char    buff[512];

int main(void) {
    std::cout << "Hello world!" << std::endl;

    std::cout << "Input a word: ";
    std::cin >> buff;
    std::cout << "You entered: [" << buff << "]" << std::endl;

    return (0);
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

#ifndef EXAMPLE_HPP
# define EXAMPLE_HPP

class Example {
public:
    Example(void);   // Constructor (same name as the class)
    ~Example(void);  // Destructor (same name with '~' prefix)
};

#endif
```

- **Constructor** (`Example(void)`) is automatically called when an instance of the class is created.
- **Destructor** (`~Example(void)`) is called when an instance is destroyed.
- Unlike functions, constructors and destructors **do not have a return type**.

---

#### Defining the Class Methods:

Class methods in C++ are functions that are defined inside a class. They describe the behavior of the class and operate on its data.

```cpp
// Example.cpp

#include <iostream>
#include "Example.hpp"

Example::Example(void) {
    std::cout << "Constructor called" << std::endl;
}

Example::~Example(void) {
    std::cout << "Destructor called" << std::endl;
}
```

- The scope resolution operator (`::`) is used to define class methods outside the class declaration.
- The constructor is executed automatically when an instance is created.
- The destructor is executed automatically when an instance goes out of scope or is deleted.
  
---

#### Creating an Instance:

```cpp
// Main.cpp

#include "Example.hpp"

int main(void) {
    Sample    inst; // Constructor is called
    return (0); // Destructor is called when 'inst' goes out of scope
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

#ifndef EXAMPLE_HPP
# define EXAMPLE_HPP

class Example {
public:
    int foo;    // Declaration of member attribute (variable)
 
    Example(void);  // Constructor declaration
    ~Example(void); // Destructor declaration

    void bar(void); // Declaration of member function
};

#endif
```

```cpp
// Example.cpp

#include <iostream>
#include "Example.hpp"

// Constructor definition
Example::Example(void) {
    std::cout << "Constructor called" << std::endl;
}

// Destructor definition
Example::~Example(void) {
    std::cout << "Destructor called" << std::endl;
}

// Member function definition
void Example::bar(void) {
    std::cout << "Member function bar called" << std::endl;
}

```

```cpp
// Main.cpp

#include <iostream>
#include "Example.hpp"

int main(void) {
    Example inst;  // Creating an instance of Example (Constructor is called)

    inst.foo = 42; // Accessing member attribute 'foo'
    std::cout << "inst.foo: " << inst.foo << std::endl; // Printing 'foo'

    inst.bar(); // Calling member function 'bar'

    return (0);  // Destructor is called automatically when 'inst' goes out of scope
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

#ifndef EXAMPLE_HPP
# define EXAMPLE_HPP

class Example {
public:
    int foo;    // Declaration of member attribute (variable)
 
    Example(void);  // Constructor declaration
    ~Example(void); // Destructor declaration

    void bar(void); // Declaration of member function
};

#endif
```

```cpp
// Example.cpp

#include <iostream>
#include "Example.hpp"

// Constructor definition
Example::Example(void) {
    std::cout << "Constructor called" << std::endl;

    // Using 'this' to refer to the current object's member attribute
    this->foo = 42; 
    std::cout << "this->foo: " << this->foo << std::endl;

    // Calling the member function 'bar' using 'this'
    this->bar();
}

// Destructor definition
Example::~Example(void) {
    std::cout << "Destructor called" << std::endl;
}

// Member function definition
void Example::bar(void) {
    std::cout << "Member function bar called" << std::endl;
}
```

```cpp
// Main.cpp

#include "Example.hpp"

int main(void) {
    Example inst;  // Creating an instance of Example, which calls the constructor
    return (0);  // Destructor is called when 'inst' goes out of scope
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

#ifndef EXAMPLE_HPP
# define EXAMPLE_HPP

class Example {
public:
    int    a1;
    char   a2;
    float  a3;  
 
    Example(char p1, int p2, float p3);  // Constructor accepting parameters
    ~Example(void); 
};

#endif
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
Example::~Example(void) {
    std::cout << "Destructor called" << std::endl;
}
```

```cpp
// Main.cpp

#include "Example.hpp"

int main(void) {
    Example inst('A', 99, 42.42f);  // Creating an instance with valid values
    return (0); 
}
```

<div align="right">
  <b><a href="#top">↥ back to top</a></b>
</div>

---



comparison: (e.g. running test)

non-member

pointer's to member: not possible to have pointers to member functions


 classes, member functions, stdio streams, initialization lists, static, const
- CPP_01: Memory allocation, pointers to members, references, switch statement;
