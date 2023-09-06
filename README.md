# CPPBox

C++ box.

Playing with C++

to compile:

```
g++ -g -o file file.cpp
```

or

```
g++ file.cpp -o file
```

`-g` - option tells compiler to include debugging information in the generated executable.  
`-o` - option specifies the name of the output file. In this case, the output (the compiled executable) will be named my_program. If you don't provide the -o option, g++ will, by default, produce an output file named a.out on Unix-like systems or a.exe on Windows.

---

```
to run: ./filename
```

`cout` - console output  
`cin` - console input

`g++` - gnu compiler  
`-o` - the output file

`float` - 4 bytes // 7 decimal digits precision // less memory cost  
`double` - 8 bytes // 15 decimal digits precision //

`new` - allocate memory dynamically on the heap during runtime:

- `int *ptr = new int;` - variable - `delete ptr;`
- `int *arr = new int[10];` - array - `delete[] arr;`
