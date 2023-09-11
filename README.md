# CPPBox

Playing with C++

[multi-threading course](https://github.com/JamesRaynard/Multithreading-Cpp-Course)   
[keywords](https://en.cppreference.com/w/cpp/keyword)   


VSCode Setup:
1. Command palate: C++ then compiler path to g++ and C++ standard C++17   
2. terminal: configure default build task C++ g++ active build   
3. Add to tasks.json
 - "-Wall" and "-std=C++17"   

----
  
to compile:

```
g++ -g -o file file.cpp
```

or

```
g++ file.cpp -o file
```

----

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
`sizeof (int)` - #include <climits>  // #inlcude <cfloat>   
`sizeof (double)` returns byte size   

`mutex` - (mutual exclusion) a synchronization primitive that enforces limits on access to a shared resource within multiple threads of execution.
 - crucial for ensuring the correctness and efficiency of multithreaded applications
 - usleep (common in POSIX systems) pauses thread: std::this_thread::sleep_for
 - https://github.com/portfoliocourses/c-example-code/tree/main/mutex   

`new` - allocate memory dynamically on the heap during runtime:

- `int *ptr = new int;` - variable - `delete ptr;`
- `int *arr = new int[10];` - array - `delete[] arr;`
