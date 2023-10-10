# CPPBox

Playing with C++

[multi-threading course](https://github.com/JamesRaynard/Multithreading-Cpp-Course)  
[keywords](https://en.cppreference.com/w/cpp/keyword)  
[CPP reference](https://en.cppreference.com/w/)

1. Books
2. Videos
3. Leetcode
4. Projects

-----

## VSCode Setup:

1. Command palate: C++ then compiler path to g++ and C++ standard C++17
2. terminal: configure default build task C++ g++ active build
3. Add to tasks.json

- "-Wall" and "-std=C++17"

to compile:

```
g++ -g -o file file.cpp
```

or

```
g++ file.cpp -o file
```

---

`-g` - tells compiler to include debugging information in generated executable.  
`-o` - specifies name of output file. If no -o option, g++ will, by default, produce an output file named a.out on Unix-like systems or a.exe on Windows.

---

```
to run: ./filename
```
---
# Statements and Operators
---
# Program Flow
---
# OOP
---
# Operator Overloading
---
# Inheritance
---
# Polymorphism
 enables objects of different types through a uniform interface, enhancing flexibility and scalability of the code.

Static Polymorphism vs. Compile-Time Polymorphism   
Dynamic Polymorphism - Run-Time Polymorphism   

- Concrete class
- Abstract class



---
# Smart Pointers
- C++11
- object class templates
- point to heap and automatically call delete
- include `memory header file`
- can't do pointer arithmetic
- C++14 `make_unique`
- `use_count` and `make_shared` in C++11
- wrapped raw pointers

`RAII` - "Resource Acquisition Is Initialization" - tie resource management (like memory or file handles) to object lifetime: open a file, allocate memory, aquire a lock. Smart pointers are example pf RAII classes.

- `unique_ptr`
  - has sole ownership of an object; cannot be two unique_ptr's owning the same object.
  - cannot be copied or assigned
  - can have custom deleters
  - can only be moved

- `shared_ptr` 
  - common heap storage
  - can be copied or assigned
  - can be moved

- `weak_ptr`
  - does not affect reference count of the object it points to.
  - helps resolve memory leaks caused by `circular references` among std::shared_ptr objects.
  - are thread-safe.

- `custom deleters`
  - useful when working with APIs that provide their own memory management functions,
  - can't use make_shared or make_unique
  - used to manage resources other than memory, such as file handles, sockets, and more
  - Lambda expressions are commonly used for custom deleters because they allow you to define the deletion strategy inline where the smart pointer is defined.

---
# Exception Handling
---
# IO Streams
---
# STL
---
# Lambda expressions
---
# Multithreading and Concurrency
---
# Notes

- `strace` - system call trace -  find failed system calls in a program
- monolithic kernel better performance 
- `context switching` - process where the state of a process is saved and the state of another process is loaded. It allows a single CPU to be shared by multiple processes by saving and loading their respective states so that execution can be resumed from where it was halted.
- TTT - Time To Trade
- ACID


---


# Definitions

`cout` - console output -- insertion operator <<  
`cin` - console input -- extraction operator >>

`#` - is a preprocessor directive

`g++` - gnu compiler  
`-o` - the output file

`float` - 4 bytes // 7 decimal digits precision // less memory cost  
`double` - 8 bytes // 15 decimal digits precision //

`list initialization syntax` - int age {21};  
`sizeof (int)` - #include <climits> // #inlcude <cfloat>  
`sizeof (double)` returns byte size

`mutex` - (mutual exclusion) a synchronization primitive that enforces limits on access to a shared resource within multiple threads of execution.

- crucial for ensuring the correctness and efficiency of multithreaded applications
- usleep (common in POSIX systems) pauses thread: std::this_thread::sleep_for
- https://github.com/portfoliocourses/c-example-code/tree/main/mutex

`new` - allocate memory dynamically on the heap during runtime:

- `int *ptr = new int;` - variable - `delete ptr;`
- `int *arr = new int[10];` - array - `delete[] arr;`

---

static_cast<type>()  
`boolalpha` - boolean 0 = false  
Short-circuit evaluation  
sequence selection iteration  
Function overloading  
Conditional operator cout << num << “is ” << (num %2 == 0 ? “even” : “odd” ) << end;  
size_t  
Static local variable values retain value between calls  
Formal parameters  
Volatile  
Actual parameters: pass by value: default manner in which passing parameters to functions  
Function templates  
Stack frame/activation record  
Nullptr started in C++11  
Sentinel  
include guard - only process once // or pragma once
constructor initialization list and delegation
shallow copy -  and invalid data   
deep copy - copy data to pointer (incurs overhead)    
move constructor (move semantics) C++ 11 (L value and R value) - && more efficient than copying (steals or pilfers the data)   
return value optimization   

---

* Avoiding Heap Allocations: Use stack memory or pre-allocated memory pools to avoid dynamic memory allocations during critical paths.
* Inlining: Understand compiler optimizations like inlining and when it's beneficial.
* Cache Optimization: Familiarize yourself with cache hierarchies and how to write cache-friendly code.

valgrind

Copy Constructor: A copy constructor initializes an object using another object of the same type. It's particularly useful when you need a deep copy or want to control how objects of a class are copied.

The stack is for automatic storage duration, typically for local variables. It has a LIFO (last in, first out) nature, is of limited size, and has automatic memory management. The heap is for dynamic storage duration, managed using new and delete (or malloc and free in C). It's larger but requires manual memory management.


std::move vs std::copy: std::move is used for moving resources (like from one object to another), while std::copy is for copying contents between two places.

Sockets:
* Sockets provide an interface for programming networks at the transport layer of the internet protocol suite. They can be created using a combination of an IP address and a port number. Programming with sockets involves understanding various socket APIs for creating, binding, listening, sending, and receiving data.

TCP/UDP:
    * These are transport layer protocols in the internet protocol suite.
    * TCP (Transmission Control Protocol): It is a connection-oriented protocol, ensuring that data sent from one end reaches the other end in the correct order and without errors. It's reliable but might have overhead due to its error-checking mechanisms.
    * UDP (User Datagram Protocol): It is a simpler, connectionless protocol. Messages (datagrams) are sent without establishing a connection and without error-checking, making it faster but less reliable than TCP.

RDMA (Remote Direct Memory Access):
* RDMA allows direct memory access from the memory of one computer to that of another without involving either one's operating system. This is beneficial for HFT as it reduces latency in network communications.
* It's a technology that permits high-throughput, low-latency networking, which is used in supercomputing and financial applications.

enum without initialization implicit initialization // enum `is/a` type // switch statements   
`enum enum-name : enumerator type {};`     

`uint_fast32` - defined in the <cstdint> - the fastest unsigned integer type with a width of at least 32 bits.
