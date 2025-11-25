# **C++ Lecture 2: Type System Exercises**

The goal here is to get a feel for the C++ static type system, especially coming from a language like Python.

## **Your Goal**

Your task is to work through each `exerciseN_*.cpp` file. Read the comments (starting with `//`) inside each file. They will tell you what to do.

**Many of these exercises are "broken" on purpose!** The goal is to see the compiler error, understand it, and then fix the code.

## **How to Use Codespaces**

You have a full computer here. You'll use the terminal to compile and run your code.

### **1. How to Compile**

To turn your C++ code (a `.cpp` file) into a runnable program, you use a compiler. We'll use `g++`.

In the terminal, type:

```bash
g++ exercise1_typing.cpp -o exercise1
```

* `g++` is the compiler program.
* `exercise1_typing.cpp` is the input file (your code).
* `-o exercise1` means "create an output file named `exercise1`".

If this command succeeds without any red text, it worked! You've created a program.

If you get **errors** (and you will!), read them! They are the C++ compiler trying to help you. `"error: cannot assign..."` is a classic!

### **2. How to Run**

Once it compiles successfully, you can run your new program:

```bash
./exercise1
```

* `./` just means "in this current folder".

### **3. Repeat for Each Exercise**

Repeat these steps for each exercise file.

# For exercise 2:

```bash
g++ exercise2_auto.cpp -o exercise2
./exercise2
```

# For exercise 3:

```bash
g++ exercise3_constants.cpp -o exercise3
./exercise3
```

# ...and so on.

Good luck, and don't be afraid of the error messages!