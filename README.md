# CPPBox

Playing with C++    
[CPP Reference](https://en.cppreference.com/w/)
  - [Keywords](https://en.cppreference.com/w/cpp/keyword)  
  - [Awesome-cpp](https://github.com/fffaraz/awesome-cpp)
  - [Portfolio Courses](https://www.youtube.com/@PortfolioCourses)
  - [Code Beauty](https://www.youtube.com/@CodeBeauty)
  - [The Cherno](https://www.youtube.com/@TheCherno)
  - [CPP Con](https://www.youtube.com/@CppCon/featured)

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
- `-g` - tells compiler to include debugging information in generated executable.  
- `-o` - specifies name of output file; if no -o option, g++ will produce an output file named a.out on Unix systems

to compile:

```cpp
g++ -g -o file file.cpp
```

or

```cpp
g++ file.cpp -o file
```
---

```cpp
to run: ./filename
```
---
- clang
- VC++
- gcc

# Statements and Operators
~90 keywords

Universal initiliazation   
- `int x{7};`
- `int x{7.7}` - is ok; narrowing conversion

`#` - is a preprocessor directive
`g++` - gnu compiler  

- `short` - typically 2-byte integer.
- `int` - typically 4-byte integer.
- `long` - typically 4 bytes (can be 8 bytes on some platforms).
- `long long` - (from C++11): 8 bytes.
- `float` - 4 bytes // 7 decimal digits precision // less memory cost  
- `double` - 8 bytes // 15 decimal digits precision //
- `long double` - 8 to 16 bytes (varies by platform)


`list initialization syntax` - int age {21};  
`sizeof (int)` - #include <climits> // #inlcude <cfloat>  
`sizeof (double)` returns byte size

Derived Types
- **Pointers**: Address of a variable, e.g., `int*`.
- **Arrays**: Collection of same type, e.g., `int arr[10]`.
- **References**: Alias for a variable, e.g., `int&`.

User-defined Types
- **Class**: Custom data type with members.
- **Structure (`struct`)**: Data grouping.
- **Union**: Variables sharing memory.
- **Enumeration (`enum`)**: Named integer constants.
  - enum without initialization implicit initialization // enum `is/a` type // switch statements
  - `enum enum-name : enumerator type {};`     

`volatile` - tells the compiler a variable can change unexpectedly. This prevents compiler optimizations on that variable. Common uses include hardware registers in embedded systems and variables changed by external components or threads. However, it doesn't ensure thread-safety or atomicity.    

`endl` - flushes the buffer which takes more time than `\n`

`Conditional operator` - cout << num << “is ” << (num %2 == 0 ? “even” : “odd” ) << end;     
`Short-circuit evaluation` - the behavior of logical operators like && and || where the second operand is not evaluated if the first operand determines the result.

Sequence, selection, iteration: Basic control structures: (like if, switch). Iteration: Loops (for, while, do-while).

---
# Program Flow

---
# Pointers and References
- nullptr C++11  


---
# OOP
Rule of Three - if a class needs a custom implementation for any one of the following: 
  1. destructor
  2. copy constructor
  3. copy assignment operator, then it likely needs custom implementations for all three.
   - C++11, `Rule of Five` - two more functions were introduced: 
  - 4. move constructor
  - 5. move assignment operator. 
  - If any of these five operations is custom-defined, the others should be considered too.

- shallow copy: Copying the object's members directly, often leading to problems with shared pointers and dynamic memory.
- deep copy: Creating a copy of the object and the objects it refers to. It's more involved but avoids issues associated with shared resources.

```cpp
class Example {
    int x;
public:
    Example(int value) : x(value) {}  // initialization list
};
```

---
# Overloading
Function Overloading; defining multiple functions with the same name but with a different number or type of parameters.
```
void foo(int a) { }
void foo(double b) { }
```

### Operator Overloading
[CodeBeauty video](https://www.youtube.com/watch?si=Pj2FnZlNXhbMSjlx&v=BnMnozsSPmw&feature=youtu.be)

### Virtual Functions
Overriding

---
# Inheritance
---
# Polymorphism
 Polymorphism - enables objects of different types through a uniform interface, enhancing flexibility and scalability of the code.

Static Polymorphism vs. Compile-Time Polymorphism   
Dynamic Polymorphism - Run-Time Polymorphism   

- base class
- derived class

- Concrete class
- Abstract class

---
# Smart Pointers
- C++11 `use_count` and `make_shared`
- object class templates
- point to heap and automatically call delete
- include `memory header file`
- can't do pointer arithmetic
- C++14 `make_unique`
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
- fstream - formatted input/output for file streams (reading//opening//closing a file etc)
  - std::ios::in
- iomanip - for manipulators

### Manipulators - overloading insertion operator
    - Boolean: boolalpha, noboolalpha
    - Integer: dec, hex, oct, showbase
    - Floating point: fixed, scientific
    - endl, flush, skipws (ws = whitespace), noskipws, setfill
    - showpos
    - setf (is a method call)
    - setw - set the width of the field for the next output operation

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

flush the stream - forcing buffered data to be written immediately to the output stream or device
  - excessive flushing can impact performance, especially when dealing with large volumes of data. Buffering is employed to improve I/O efficiency, and flushing too frequently can slow down your program.

redirecting i/o - 
std::istringstream - 

### Precision
- std::setprecision(*n*)
if not within precision range will display sci-notation

---
# STL
- has ~60 algorithms 
- to use and compare user-defined Classes in the STL, the == and < operators must be overloaded

- Vector: direct element access and insertion and deletion at back in `constant time`. 
  - emplace_back
  - shrink_to_fit
  - back_inserter // for copy if

- Deque
  - double ended queue
  - insertion and removal O(n)
  - non contiguous memory (linked list of vectors)

- Maps
  - std::map
  - unordered_map
  - Multimap
  - unordered_multipmap

`# include numeric`
  - std::iota

The std::transform function applies a given function to a range and stores the result in another range, which may be the same as the first range.

 `ACE` (Adaptive Communication Environment): suited for systems that require real-time communication, such as telecom systems, games, and certain financial systems.
  - Reactor, Proactor, and Acceptor-Connector.

 `Boost` - linear algebra, pseudorandom number generation, multithreading, image processing, regular expressions, and unit testing   
  - `boost::asio` (for asynchronous I/O), `boost::mpl` (metaprogramming library), and `boost::graph` (graph algorithms and data structures).


## Macros
Defined using the #define directive in the preprocessor. // preprocessor directives  
Need to be careful.   
- #define PI 3.14159
- #define SQUARE(x) ((x) * (x))
- #define MAX(a, b) ((a) > (b) ? (a) : (b))
```cpp
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
```cpp
template <typename T>
T add(T a, T b) {
    return a + b;
}
```

## Containers
[STL Containers](https://en.cppreference.com/w/cpp/container)
- container - an object that stores other objects (the elements) and that provides various methods to access and manipulate them
  1. Sequence Containers
  2. Associative Containers
  3. Unordered Associative Containers

`Container adapter` - class that uses an underlying container class to provide a specific interface or behavior, thereby "adapting" the behavior of the underlying container.

`generic programming` - (type-agnostic) software components are designed to work with different data types without requiring changes to achieve type-specific behavior; allows a function or a class to work with any data type.   

`metaprogramming` - code that generates or manipulates other code. It's about programs that reason about, or modify, other programs or themselves, often at compile-time.   

---
# Lambda expressions
Different in C++11/14/17
- "Closures" or anonymous functions
- defined inline
- [] - the capture block
- `[] (int arg){ return 2 * arg};`
- can "capture" a local variable
- lambdas replace function objects
- easier to test/debug/read
- the compiler creates a closure object // generates unnamed function objects under the hood
- operator()
- `predicate lambda` - takes any num of arguments and returns a boolean value

```cpp
[]() -> return_type specifiers { };

[]() { std:: cout << "Hi"; };
[](int x) { std:: cout << "Hi"; };

auto L = [] () {std::cout << "x";};
L(10); // displays 10
L(100); // displays 100
```

```cpp
int num1 {10};
float num2 {20.5};

auto L = [auto x] {std:cout << x;};

L(num1);
L(num2);

```

`stateless` - empty capture lists
`stateful` - captures information from enviornment
  - `mutable` -  allows you to modify the captured variables that were captured by value, overriding the default const behavior.
  - [=] default capture by value (depricated in C++20)
  - [&] defauly capture by reference
  - [this] default capture this object by reference (preferred usage)

---
# Multithreading and Concurrency
1. [Concurrency In Action](https://www.bogotobogo.com/cplusplus/files/CplusplusConcurrencyInAction_PracticalMultithreading.pdf)
2. [Multi-threading Course Files](https://github.com/JamesRaynard/Multithreading-Cpp-Course)  
3. [CPP-Con video](https://www.youtube.com/watch?v=A7sVFJLJM-A&t=366s)

### Concurrency
- two activities at the same time
- hardware concurrency // CPU chips "cores" // hardware threads
- simultaneous users // `separation of concerns`
- processor bigger and clock frequency but electrons can move through silicon so fast 
- multithread: server throughput child and server in same process // access to each others data
- adds complexity - bug likeliness - and may not result in faster programs

### Synchronization Issues
1. Different threads execute on different cores
2. They may share data
- race conditions, deadlocks, and resource contention
- Each thread requires stack space 
- Kernel // OS system can slow 
- Separation of concerns 

- `parallelism` - multiple programs at the `same time` (amount of cores (and clock speed operations)) 
- `threading` - hang, different timing
- `process` an independent program in execution, with its own memory space, while a thread is the smallest executable unit of a process, sharing the process's memory space. Multithreading allows concurrent execution of two or more threads, which can be achieved through time slicing (sharing the CPU time between all running threads) or true parallel execution (in multi-core processors).

### Threaded Program Structure
Writing safe multithreaded programs is difficult.
- `#include thread`
- entry point function: `main` executes one thread
- `std::thread` - similar to Boost threads
- C14 - Read/Write blocks
- C17 - standard algorithms execute in parallel
- C20 - joining threads // thread cancellation // Coroutines, semaphores, latches and barriers // std::jthread calls join internaally

Lambda expressions for threads is convenient   

- Constructor starts execution   
- Parent thread will continue its own execution   
- By default the destructor calls `std::terminate` but `join()` function is a blocking call
- Joining the thread
- time slicing - each process is given a small period (or "slice") of CPU time.
  - premptive `task switching` -  OS can forcibly interrupt a currently running process to give another process a turn to use the CPU
  - `context switching` - process where the state of a process is saved and the state of another process is loaded. It allows a single CPU to be shared by multiple processes by saving and loading their respective states so that execution can be resumed from where it was halted.
  - data race - two or more threads access same memory location; one thread is modifying it
  - `critical` section: must only be executed one thread at a time

In finance, often have a `dedicated processor core` and a `thread for each stock ticker` so it guarantees the code which manages each ticker is always running, always available, and never has to be context switched.   

### Thread Class
Thread class is move only; objects cannot be copied; move transfers ownership. Returning a thread object, the compiler will automatically move it. 
```
`native_handle()` - 
`std::this_thread::get_id()` -   
`thr.get_id()` -   
`std::this_thread::sleep_for()` - 
`detach()`
<atomic>
Std::atomic<bool>
Std::atomic_flag
Store 
Load 
exchange()
Fetch_add()
<future>
std::package_task
Std::promise
Std::async
Spin lock
TLS Thread Local Storage
Wait_for()
Wait_until()
```

### Mutex Class
`mutex` - (mutual exclusion object) a synchronization primitive that enforces limits on access to a shared resource within multiple threads of execution (a kind of policeman or doorman; protecting shared data)
  - Code Beauty [video explanation](https://www.youtube.com/watch?si=LLZ45YZFTbiuuJYR&v=-Qa1RqmXKG0&feature=youtu.be)
  - `include <mutex>`
  - two states: locked or unlocked
  - hold lock for the shortest time
  - lock()
  - try_lock()
  - unlock()
- 

```
std::lock_guard   
std::unique_lock   
std::timed_mutex
std::shared_mutex
```

- std::chronos // namespace sc = std::chrono // C++11
  - sc::seconds
  - sc::miliseconds
  - microseconds

- crucial for ensuring the correctness and efficiency of multithreaded applications
- usleep (common in POSIX systems) pauses thread: std::this_thread::sleep_for
- https://github.com/portfoliocourses/c-example-code/tree/main/mutex

std::ref

### Thread Pools
To minimize overhead of thread creation and destruction, especially when tasks are short-lived but frequent. Creating and destroying threads for each task can be resource-intensive and slow. By reusing threads that are already alive, a thread pool can significantly improve performance.
- Fixed size of container thread objects
- std::thread::hardware_concurrency()
- Queue of task function objects
- easy scaling

```cpp
#include <iostream>
#include <thread>

void function1(char symbol) {
  for(int i =0; i < 50; ++i)
    std::cout << symbol;
}

void function2(){
  for (int i = 0; i < 50; ++i)
    std::cout << "-";
}

int main()
{
  std::thread worker1(function1, 'o');
  std::thread worker2(function2);

  worker1.join();
  worker2.join();

    return 0;
}
```

# Parallelism
- Task Parallelism
- Fork and join
- Data Parallelism
- Pipelining
- Graph Parallelism

Algorithms
- std::find
- std::find_if()
- std::accumulate
- std::reduce()
- std::inclusive_scan

----------
# C++11   
- best random generator - std::19937
- should be declared static 
- array class `std::array` - more efficient than a vector if the size is fixed and known
- move constructor (move semantics)(L value and R value) - && more efficient than copying (steals or pilfers the data)   
- data race - two or more threads access same memory location
- `constexpr` indicates that the value of a variable, or the result of a function, is a compile-time constant. Functions and variables declared with constexpr are evaluated at compile time whenever possible.

----------
# C++14 
  - using namespace std::literals;
  - 2s
  - 20ms
  - 50us

`auto` - gives underlying type // compiler deduces // typical in `range for loop` and lambdas

---
# Notes

- `strace` - system call trace -  find failed system calls in a program
- monolithic kernel better performance
- TTT - Time To Trade
- `ACID` set of rules to make sure databases work reliably
  - Atomicity: All parts of a transaction succeed or none of them do. Think of it like buying a soda: if the machine doesn't drop the soda, you don't lose your money.
  - Consistency: Transactions always take the database from one correct state to another. Imagine a puzzle; after you place a piece, the picture still makes sense.
  - Isolation: Multiple transactions happening at the same time won't mess up each other. Like multiple people drawing on different parts of a whiteboard without interfering with one another.
  - Durability: Once a transaction is done, it's permanent, even if there's a power cut. It's like writing something in a book; once it's written, it stays there.


`Perfect forwarding` - refers to the ability to forward arguments of a function to another function, preserving the "lvalue/rvalue-ness" and the type of each argument.

- nan = not a number
- Std::move casts the argument to an r value 

----
# Definitions
`pod` - plain old data.

`new` - allocates memory dynamically on the heap during runtime:

- `int *ptr = new int;` - variable - `delete ptr;`
- `int *arr = new int[10];` - array - `delete[] arr;`

`Sentinel` - value indicating the end of a data structure, like a null-terminated string in C.

------
# Cache 
  - `cache` - french for hidden; static RAM, modern days on same CPU chip
  - cache controller
  - cache lines - data transferred (64 bytes)
  - L1 (Level 1) Cache:
    - Location: Located on the CPU chip itself.
    - Size: Smallest among the cache levels, typically ranging from 16KB to 64KB per core
    - Speed: Fastest access time.
    - Purpose: Designed to cover the vast majority of the typical application’s working set. L1 cache is usually split into two parts: instruction cache (for CPU instructions) and data cache (for data).
  - L2 (Level 2) Cache:
    - Location: Also on the CPU chip but might be shared among several cores.
    - Size: Larger than L1, typically in the range of 128KB to 512KB per core, but can be larger.
    - Speed: Slower than L1 but faster than L3.
    - Purpose: Acts as a buffer between the fast L1 cache and the larger, slower L3 cache or main memory. It captures data and instructions that are not immediately found in L1.
  - L3 (Level 3) Cache:
    - Location: On the CPU chip and typically shared among all cores.
    - Size: Even larger, ranging from 1MB to upwards of 50MB for some high-end server processors.
    - Speed: Slower than L2 but faster than main RAM.
    - Purpose: Provides a backup to L1 and L2 for data and instructions, reducing the number of times the CPU needs to go to the slower main memory. Not all CPUs have L3 cache; it's more common on multi-core processors.
  - In addition to these, there are L4 caches in some architectures, but they're less common. This cache might be located on the CPU die or on a separate chip and can serve as a bridge between the L3 cache and main RAM, especially in systems with integrated graphics.

* Cache Optimization: Familiarize yourself with cache hierarchies and how to write cache-friendly code.

---
# Time 
| Unit          | Abbreviation | Description                     | Relation to Seconds                |
|---------------|--------------|---------------------------------|------------------------------------|
| Second        | s            | Base unit of time               | 1 second                           |
| Millisecond   | ms           | 1/1,000th of a second           | 1,000 milliseconds = 1 second      |
| Microsecond   | µs           | 1/1,000,000th of a second       | 1,000,000 microseconds = 1 second  |
| Nanosecond    | ns           | 1/1,000,000,000th of a second   | 1,000,000,000 nanoseconds = 1 second |

1. Hard real-time: Missing a deadline is catastrophic. Examples include flight control systems and pacemakers.
2. Soft real-time: Missing a deadline is undesirable but not catastrophic. Examples include video streaming and online gaming.
3. Firm real-time: It's useless to complete the task after the deadline. The missed deadlines won't result in a catastrophe but there's no point in completing the task late. For example, data packets in a live conference.

`Jitter` - variability in latency. In real-time systems, it's crucial not just to ensure low latency, but consistent latency.   

---

static_cast<type>()  
size_t  
Static local variable values - retain value between calls  
Formal parameters // Actual parameters

pass by value: default manner in which passing parameters to functions  
Stack frame/activation record    
include guard - only process once // or pragma once

shallow copy -  and invalid data   
deep copy - copy data to pointer (incurs overhead) 

Return value optimization (RVO): A compiler optimization that avoids extra copy or move operations when returning a value from a function.

---

* Avoiding Heap Allocations: Use stack memory or pre-allocated memory pools to avoid dynamic memory allocations during critical paths.
* Inlining: Understand compiler optimizations like inlining and when it's beneficial.

valgrind

Copy Constructor: A copy constructor initializes an object using another object of the same type. It's particularly useful when you need a deep copy or want to control how objects of a class are copied.

-----
# Stack vs. Heap
  1. Stack - for automatic storage duration, typically for local variables; LIFO (last in, first out) nature, is of limited size, and has automatic memory management. 
  2. Heap - for dynamic storage duration, managed using `new` and `delete` (or malloc and free in C); larger but requires manual memory management.

---
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

A delimiter is a character or sequence of characters used to separate distinct regions or elements in data. It marks boundaries between different items.
  - In CSV files: , separates values.
  - In programming: ; separates statements.
  - In string parsing: a space might separate words.
  - In JSON: { and } delimit objects; [ and ] delimit arrays.

`uint_fast32` - defined in the <cstdint> - the fastest unsigned integer type with a width of at least 32 bits.

----
# Structure Layout
```cpp
// 1. Preprocessor Directive; iincludes header files
#include <iostream>

// 2. Global Variables and Constants
// Generally discouraged due to potential issues, side effects and maintainability
// Variable is accessible from any function in this file.
int globalVar = 10;

// 3. Function Prototypes
// This declares the function printMessage so it can be used before it's defined.
void printMessage();

// 4. (No Classes/Structs/Unions/Enumerations in this example, but they would go here.)

// 5. Function Definitions and the main Function
// Main function is the entry point of a C++ program.
int main() {
    // Using the Standard Library's cout function to print to the console.
    std::cout << "Hello, World!" << std::endl;

    // Calling the previously declared function.
    printMessage();

    // The return value of the main function is returned to the operating system.
    // A return value of 0 typically indicates successful execution.
    return 0;
}

// Definition of the printMessage function.
void printMessage() {
    std::cout << "This is a message." << std::endl;
}

// 6. (No Namespace Declarations in this example, but custom namespaces would be defined here.)
```