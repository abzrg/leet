# BUILD TOOLS

## scan-build

https://clang-analyzer.llvm.org/scan-build.html

## clang-sanitizers

https://developers.redhat.com/blog/2021/05/05/memory-error-checking-in-c-and-c-comparing-sanitizers-and-valgrind

https://medium.com/swlh/finding-memory-leaks-in-c-de1aa8c5f0fb
https://dr-rost.medium.com/detect-memory-leaks-on-macos-4cf257529aa

Both GCC (GNU Compiler Collection) and Clang (LLVM Compiler) support a variety of sanitizers for detecting different types of programming errors.

Some of the commonly supported sanitizers for GCC and Clang include:

**GCC (GNU Compiler Collection):**

1. **AddressSanitizer (ASan)**: Detects memory corruption errors, such as buffer overflows and use-after-free (`-fsanitize=address`).

2. **UndefinedBehaviorSanitizer (UBSan)**: Helps catch undefined behavior in C/C++ code, such as type-related issues (`-fsanitize=undefined`).

3. **MemorySanitizer (MSan)**: Focuses on detecting uninitialized memory reads (`-fsanitize=memory`).

4. **ThreadSanitizer (TSan)**: Detects data races and other threading-related issues (`-fsanitize=thread` ).

5. **LeakSanitizer (LSan)**: Identifies memory leaks in your code (`-fsanitize=leak`).

**Clang (LLVM Compiler):**

1. **AddressSanitizer (ASan)**: Similar to GCC's ASan, it detects memory corruption errors (`-fsanitize=address`).

2. **UndefinedBehaviorSanitizer (UBSan)**: Identical to GCC's UBSan, it helps find undefined behavior in C/C++ code (`-fsanitize=undefined`).

3. **MemorySanitizer (MSan)**: Comparable to GCC's MSan, it detects uninitialized memory reads (`-fsanitize=memory`).

4. **ThreadSanitizer (TSan)**: Also similar to GCC's TSan, it detects data races and threading issues (`-fsanitize=thread`).

5. **LeakSanitizer (LSan)**: Similar to GCC's LSan, it identifies memory leaks (`-fsanitize=leak`).

6. **Control-Flow Integrity (CFI)**: Detects and mitigates control-flow hijacking attacks (`-fsanitize=cfi`).

7. **DataFlowSanitizer (DFSan)**: Focuses on detecting taint and data flow vulnerabilities (`-fsanitize=dataflow`).

8. **SafeStack**: Provides protection against stack-based buffer overflow attacks (`-fsanitize=safestack`).

9. **AddressSanitizer with HWASan**: A specialized variant of ASan for detecting hardware-assisted memory bugs (`-fsanitize=address`).

Please note that the availability and compatibility of these sanitizers can vary depending on the compiler version and the target platform.

The compiler flags for enabling specific sanitizers can vary depending on whether you are using GCC or Clang, and which sanitizer you want to enable. Here are some common flags for enabling sanitizers with both compilers:


## Most used Sanitizers

### 1. LeakSanitizer (LSan):

LeakSanitizer (LSan) is a memory leak detector. It is used to identify memory leaks in your C/C++ programs. Memory leaks occur when a program allocates memory (e.g., with `malloc` or `new`) but fails to release it (e.g., with `free` or `delete`), causing the program to consume more and more memory over time.

LeakSanitizer works by tracking memory allocations and detecting memory that has not been freed when the program exits. It then reports the location in your code where the leaked memory was allocated. This helps developers find and fix memory leaks, preventing excessive memory consumption and potential performance issues.

### 2. AddressSanitizer (ASan):

AddressSanitizer (ASan) is a runtime memory error detector. It is primarily used to find memory corruption bugs, including:

- Buffer overflows: When you write past the end of an array.
- Use-after-free: When you access memory that has been freed.
- Double-free: When you attempt to free memory that has already been freed.
- Memory leaks: ASan can also detect some types of memory leaks, although LeakSanitizer is more specialized for this purpose.

ASan instruments your code at runtime, adding checks and metadata to each memory allocation. When a memory error is detected, ASan reports the location of the error, including the file and line number. This makes it easier to identify and fix memory-related issues in your code.

### 3. UndefinedBehaviorSanitizer (UBSan):

UndefinedBehaviorSanitizer (UBSan) is used to catch undefined behavior in C/C++ code. Undefined behavior refers to actions in your code that are not well-defined by the C/C++ standards. These actions can lead to unpredictable program behavior and security vulnerabilities.

UBSan helps identify various types of undefined behavior, including:

- Dereferencing null or invalid pointers.
- Signed integer overflow or underflow.
- Shift operations with invalid shift counts.
- Using uninitialized variables.
- Type-related issues, such as type mismatches in function calls.

When UBSan detects undefined behavior, it reports the problem, including the location in your code where it occurred. Fixing these issues is essential for writing safe and reliable C/C++ programs.

### 4. MemorySanitizer (MSan):

- **Purpose:** MemorySanitizer is designed to detect and report the use of uninitialized memory in your C/C++ programs.
- **How it Works:** MSan instruments the code to track the flow of values in memory and detects when uninitialized memory is used. It does this by associating a "shadow" memory region with each byte of your program's addressable memory, and it checks for discrepancies between the program's regular memory and the shadow memory.
- **Common Use Case:** Identifying and fixing bugs where your program reads uninitialized memory, which can lead to unpredictable and potentially incorrect behavior.



---


# Strings

## `strtok(token, delimiter)`


`strtok` modifies the string it operates on, replacing delimiter characters with `NULL`s.


```c
token = strtok(str, " ");

while (token != NULL) {
    // do some stuff with token
    token = strtok(NULL, " ")
}

// ~~~ strtok_r

// - One can use multiple delimiter (":,")
// - ,, or :: will not produce an empty token
// - overwrites input string (*str) and input pointer (str)
while ((token = strtok_r(str, ":,", &str))) {
    // do your stuff
}

// ~~~ strsep

// - One can use multiple delimiter (":,")
// - ,, or :: will produce an empty token
// - overwrites input string (*str) and input pointer (str)
while ((token = strsep(&str, ":,"))) {
    // do your stuff
}
```

Read more: https://stackoverflow.com/a/7219504/13041067
