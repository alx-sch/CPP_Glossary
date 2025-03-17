# C++ 

<p align="center">
    <img src="https://github.com/alx-sch/42_CPP_00-04/blob/main/.assets/img/cpp_badge.png" alt="cpp_badge.png" />
</p>

## CPP 00:

### Namespaces   

A **namespace** is a way to group related declarations (such as variables, functions, and classes) to organize code and prevent name conflicts. Think of it as a "bag" that holds related entities, giving them a meaningful and scoped name.

**Example:**
```cpp
int g_var = 1;
int fct( void ) { return 42; }

namespace Foo {
    int g_var = 2;
    int fct( void ) { return 40; }
}

namespace Bar {
    int g_var = 3;
    int fct( void ) { return 2; }
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
::g_var      // Accesses the global 'g_var' (outside any namespace)
```

---

#### Standard Namespace:

The `std` namespace is the default namespace for the C++ Standard Library. It contains commonly used components like `iostream`, `string`, etc.

```cpp
std::cout << "Hello, world!" << std::endl;
```

---






stdio streams: standard input / output + error output   

class and instances: object-oriented programming   

member attribute and member function, method: member function   

instance variable: -> this   

list initialization: create   

constants   

encapsulation: private + public    

class vs struct

acessor: access / update private attributes

comparison: (e.g. running test)

non-member

pointer's to member: not possible to have pointers to member functions


 classes, member functions, stdio streams, initialization lists, static, const
- CPP_01: Memory allocation, pointers to members, references, switch statement;
