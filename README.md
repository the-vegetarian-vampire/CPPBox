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
- clang
- VC++
- gcc


# Statements and Operators
Universal initiliazation   
- `int x{7};`
- `int x{7.7} - is ok` narrowing conversion


preprocessor directives

---
# Program Flow
---
# Pointers and References


- nullptr C++11  


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
schools of thought: 
  1. only used for exceptional situations where prevents program from continuing
  2. never be used   

- throw
- try { code that may throw an exception }
- catch (exception ex) { code to handle } // catch(...) - catch all
  -  best practice to throw by value and catch by reference
  -  don't throw exceptions from destructor

`exception` - object or primitive type    
`cerr` - standard error stream   
`clog` - log stream for logging   
`stack unwinding` - an exception is thrown, and control is transferred from the point of the throw statement to the handler; 

`fail soft` - system is designed to continue operating even in the event of a failure or error, albeit in a potentially degraded state; useful in systems where total failure would have significant negative impacts, and some level of functionality is preferable to none

STL C++17 heirarchy
- `std::exception`
- `noexcept` keyword
- `what()` - virtual function


---
# IO Streams
streams - an abstract interface to input and output operations; represent data as a sequence of bytes and allow you to perform operations like reading and writing without needing to know the details of the underlying device or medium
- iostream - input/output 
- fstream - formatted input/output for file streams
- iomanip - for manipulators


### Manipulators - overloading insertion operator
    - Boolean: boolalpha, noboolalpha
    - Integer: dec, hex, oct, showbase
    - Floating point: fixed, scientific
    - endl, flush, skipws (ws = whitespace), noskipws, setfill
    - showpos
    - setf (is a method call)

`cout` - console output -- insertion operator <<     
`cin` - console input -- extraction operator >>   

```
int num {255}

// std::cout << std::showbase;// and << std::uppercase
std::cout << std::dec << num << stdLL << std::endl;
std::cout << std::hex << num << stdLL << std::endl;
std::cout << std::oct << num << stdLL << std::endl;

255
ff // or 0xff
377 // or 3077
```

flush the stream - 
redirecting i/o - 

### Precision
- std::setprecision(*n*)
if not within precision range will display sci-notation

---
# STL
- has ~60 algorithms 

- Vector: direct element access and insertion and deletion at back in `constant time`. 
  - emplace_back
  - shrink_to_fit
  - back_inserter // for copy if
  - 

## Macros
Defined using the #define directive in the preprocessor.   
Need to be careful.   
- #define PI 3.14159
- #define SQUARE(x) ((x) * (x))
- #define MAX(a, b) ((a) > (b) ? (a) : (b))
```
#ifdef DEBUG
#define DEBUG_PRINT(...) fprintf(stderr, __VA_ARGS__)
#else
#define DEBUG_PRINT(...) // No action
#endif
```

## Templates
A template is a blueprint; creating functions and classes that work with any data type, promoting code reuse and type safety.
`template <typename T>`
  - T is a placeholder for a type
  - Template instantiations are determined at compile-time. 
  - may need operator overloading
Template classee.

## Containers
[STL Containers](https://en.cppreference.com/w/cpp/container)
- container - an object that stores other objects (the elements) and that provides various methods to access and manipulate them
  1. Sequence Containers
  2. Associative Containers
  3. Unordered Associative Containers

`generic programming` - (type-agnostic) software components are designed to work with different data types without requiring changes to achieve type-specific behavior; allows a function or a class to work with any data type.   
`metaprogramming` - code that generates or manipulates other code. It's about programs that reason about, or modify, other programs or themselves, often at compile-time.   

---
# Lambda expressions
- "Closures" or anonymous functions
- defined inline
- [] - the capture block
- `[] (int arg){ return 2 * arg};`
- can "capture" a local variable

different in C++11/14/17

`stateful`
`stateless`



---
# Multithreading and Concurrency

### Concurrency
- two activities at the same time
- hardware concurrency // CPU chips "cores" // hardware threads
- simultaneous users // separation of concerns
- processor bigger and clock frequency but electrons can move through silicon so fast 
- multithread: server throughput child and server in same process // access to each others data
- adds complexity - bug likeliness - and may not result in faster programs

Challenges:
- race conditions, deadlocks, and resource contention

- `parallelism` - multiple programs at the `same time` (amount of cores (and clock speed operations)) 
- `threading` - hang, different timing
- `process` an independent program in execution, with its own memory space, while a thread is the smallest executable unit of a process, sharing the process's memory space. Multithreading allows concurrent execution of two or more threads, which can be achieved through time slicing (sharing the CPU time between all running threads) or true parallel execution (in multi-core processors).

### Threaded Program Structure
- `#include thread`
- entry point function: `main` executes one thread
- `std::thread` - similar to Boost threads
- C14 - Read/Write blocks
- C17 - standard algorithms execute in parallel
- C20 - joining threads // thread cancellation // Coroutines, semaphores, latches and barriers

Lambda expressions for threads is convenient   

- Constructor starts execution   
- Parent thread will continue its own execution   
- By default the destructor calls `std::terminate`   but join() function is a blocking call
- Joining the thread

----------
# C++11   
- best random generator - std::19937
- should be declared static 
- Array class `std::array` - more efficient than a vector if the size is fixed and known


----------
# C++14 
  - using namespace std::literals;
  - 2s
  - 20ms
  - 50us

`auto` - gives underlying type // compiler deduces // typical in `range for loop`

---
# Notes

- `strace` - system call trace -  find failed system calls in a program
- monolithic kernel better performance 
- `context switching` - process where the state of a process is saved and the state of another process is loaded. It allows a single CPU to be shared by multiple processes by saving and loading their respective states so that execution can be resumed from where it was halted.
- TTT - Time To Trade
- `ACID` set of rules to make sure databases work reliably
  - Atomicity: All parts of a transaction succeed or none of them do. Think of it like buying a soda: if the machine doesn't drop the soda, you don't lose your money.
  - Consistency: Transactions always take the database from one correct state to another. Imagine a puzzle; after you place a piece, the picture still makes sense.
  - Isolation: Multiple transactions happening at the same time won't mess up each other. Like multiple people drawing on different parts of a whiteboard without interfering with one another.
  - Durability: Once a transaction is done, it's permanent, even if there's a power cut. It's like writing something in a book; once it's written, it stays there.
- nan = not a number
- Std::move casts the argument to an r value 

- std::chrono // namespace sc = std::chrono
  - sc::seconds
  - sc::miliseconds
  - microseconds

----
# Definitions


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

`new` - allocates memory dynamically on the heap during runtime:

- `int *ptr = new int;` - variable - `delete ptr;`
- `int *arr = new int[10];` - array - `delete[] arr;`

---

static_cast<type>()  
`boolalpha` - boolean 0 = false  
Short-circuit evaluation  
sequence selection iteration  
Conditional operator cout << num << “is ” << (num %2 == 0 ? “even” : “odd” ) << end;  
size_t  
Static local variable values retain value between calls  
Formal parameters  
Volatile  
Actual parameters: pass by value: default manner in which passing parameters to functions  
Function templates  
Stack frame/activation record  
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
