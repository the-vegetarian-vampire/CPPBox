# CPPBox

Playing with C++

[multi-threading course](https://github.com/JamesRaynard/Multithreading-Cpp-Course)  
[keywords](https://en.cppreference.com/w/cpp/keyword)  
[CPP reference](https://en.cppreference.com/w/)

1. Books
2. Videos
3. Leetcode
4. Projects

VSCode Setup:

1. Command palate: C++ then compiler path to g++ and C++ standard C++17
2. terminal: configure default build task C++ g++ active build
3. Add to tasks.json

- "-Wall" and "-std=C++17"

---

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
`-o` - specifies name of the output file. In this case, the output (the compiled executable) will be named my_program. If you don't provide the -o option, g++ will, by default, produce an output file named a.out on Unix-like systems or a.exe on Windows.

---

```
to run: ./filename
```

---

Definitions

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
Polymorphism  
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

RAII: Stands for "Resource Acquisition Is Initialization". It's a principle in C++ where you tie resource management (like memory or file handles) to object lifetime.

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

Operator overloading 
