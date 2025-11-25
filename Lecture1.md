# **C++ for Python Developers: Lab 1 Exercises (Codespaces Edition)**

**Objective:** Use GitHub Codespaces to instantly get a C++ environment, write your first program, and understand the "compile-link-run" cycle.

## **Part 1: Environment Setup (The 5-Minute Task)**

Instead of installing software, we'll use a cloud-based environment.

1. **Launch Your Codespace:**  
   * Go to [github.com/codespaces](https://github.com/codespaces).  
   * Look for the "Blank" template (it's often at the top under "Quickstart templates").  
   * Click "Use this template". This will create a new, private coding environment for you and open it in your browser. It's a full version of VS Code, running on a Linux machine in the cloud.  
2. **Verify Your Installation:**  
   * Once your Codespace loads, a terminal should automatically open at the bottom. If not, open one (Ctrl+ ` or View > Terminal).  
   * Type the following command and press Enter:
     ```bash
     g++ --version
     ```
   * You should see a message showing the g++ version (e.g., g++ (Ubuntu ...) ...). This confirms your C++ compiler is ready to go.  
3. **Check for the VS Code Extension:**  
   * Click the Extensions tab (the four squares icon on the left).  
   * Search for "C/C++". You'll likely see that the "C/C++ Extension Pack" from Microsoft is already installed. If not, install it.

That's it! Your environment is set up.

## **Part 2: Exercise 1 - "Hello, World!"**

This exercise mirrors the code from the lecture.

1. In the VS Code file explorer on the left, create a new folder for your course work (e.g., right-click in the blank space and choose New Folder... named `cpp_course`).  
2. Right-click your new `cpp_course` folder and select New File....  
3. Name the new file `hello.cpp`.  
4. Type or paste the following code into your file:
```cpp
// This is a preprocessor directive. It's like 'import' in Python.
#include <iostream>

// This is the main function. Every C++ program starts running here.
int main() {
    // std::cout is the object we use to print to the console.
    // << is the "stream insertion" operator.
    std::cout << "Hello, C++ World!";

    // return 0 tells the operating system that the program ran successfully.
    return 0;
}
```

6. **Save the file.** (It might auto-save). You've now *written* a C++ program. But you can't *run* it... yet.

## **Part 3: Exercise 2 - The Compile-Link-Run Cycle**

This is the most important exercise. We will compile and run your program manually to understand the process.

1. **Navigate to Your Folder:** In your terminal, you first need to move *into* the folder you created. Type:
   ```bash
   cd cpp_course
   ```

3. **Compile Your Code:** In the terminal, type the following command and press Enter:
   ```bash
   g++ -o hello hello.cpp
   ```

   * `g++` is the command to call the compiler.
   * `-o hello` tells the compiler to create an **o**utput file named hello.
   * `hello.cpp` is the **i**nput source file we want to compile.  
5. **Look at Your Files:**  
   * In the VS Code file explorer on the left, look inside your `cpp_course` folder (or type `ls` in the terminal). You will now see **two** files:  
     * `hello.cpp` (your source code)  
     * `hello` - This is your new **executable program**!  
6. **Run Your Program:** In the terminal, type the following:
   ```bash
   ./hello
   ```

   * `./` tells the terminal to look for the program in the "current directory."
   * You should see `Hello, C++ World!` printed to your console.

### **Python Contrast (Discussion)**

Think about what you just did. To run a Python script, you would just:

1. Create `hello.py` with `print("Hello, Python World!")`  
2. Run `python3 hello.py`

Notice the C++ process has an explicit **compile step** (`g++ ...`) that creates a *new file*, and a separate **run step** (`./hello`) that doesn't even mention g++ or .cpp. You are running the compiled machine code directly.

## **Part 4: Exercise 3 - Meeting the Compiler**

Let's see what happens when we make mistakes. The compiler is your (very strict) first line of defense.

### **4.1: The Syntax Error**

1. Go back to `hello.cpp`.  
2. Delete the semicolon (;) at the end of the std::cout line.  
3. Save the file.  
4. Go to your terminal and try to compile the program again:
   ```bash
   g++ -o hello hello.cpp
   ```

6. **Observe the Error:** The compiler will stop and print an error message. It will say something like error: expected ';' before 'return'. It tells you *exactly* what's wrong and on what line.  
7. This is a **compile-time error**. Your program *was not created*. The old hello executable (if it existed) is still there, unchanged.

### **4.2: The Type Error**

1. Fix the semicolon.  
2. Now, try to do something that's easy in Python but makes no sense in C++. Change the std::cout line to this:
   ```cpp
   std::cout << "My favorite number is: " + 5;
   ```

4. Save the file and try to compile: `g++ -o hello hello.cpp`  
5. **Observe the Error:** You'll get a much more complex error, like `no match for 'operator+' (operand types are 'const char*' and 'int')`.  
   * This is the compiler telling you: "I don't know how to add an integer (5) to a text string literal."

### **Python Contrast (Runtime vs. Compile-Time)**

1. Create a new file `bad.py` in your `cpp_course` folder.  
2. Type this code: `print("My favorite number is: " + 5)`  
3. Save it and run it: `python3 bad.py`  
4. The program **runs**, and *then* it **crashes** with a TypeError. This is a **runtime error**.

**Reflection:** C++ *prevented* you from even *creating* a broken program. Python let you run it, and it failed "live." This is the "Temporal Error Shift" from the lecture.

## **Part 5: Exercise 4 - Your First Modification**

1. Fix your `hello.cpp` file. To print a string and a number, the C++ way is to "stream" them one after another:  
   ```cpp
   std::cout << "My favorite number is: " << 5;
   ```

2. Compile (`g++ -o hello hello.cpp`) and run (`./hello`) to make sure it works.  
3. **Your Task:** Modify the program to:  
   * Print "Hello, C++ World!" on the *first* line.  
   * Print your name on the *second* line.  
   * Print your favorite Python module on the *third* line.

**Hint:** To make a new line, you can stream `std::endl` (which stands for "end line") or use the newline character `\n` inside a string.
   ```cpp
   std::cout << "This is line 1" << std::endl;
   std::cout << "This is line 2\nThis is line 3\n";
   ```

4. **Common Pitfall:** After you change your `.cpp` file, what happens if you just run `./hello`? You'll see your *old* program! Remember: you **must re-compile** every time you make a change to your source code.  
   1. Save file.  
   2. `g++ -o hello hello.cpp` (re-compile)  
   3. `./hello` (run the *new* program)

## **Bonus Challenge: Using Namespaces**

Tired of typing `std::` everywhere? You can tell C++ you're "using" that namespace.

1. Add this line *after* `#include <iostream>` but *before* `int main()`:  
   ```cpp
   using namespace std;
   ```

2. Now, you can remove `std::` from your code:  
   ```cpp
   cout << "Hello, much cleaner!" << endl;
   ```

3. Compile and run. It should work perfectly.

**Food for thought:** This is very convenient (like Python's `from math import *`), but it's often considered bad practice in large projects as it can cause name collisions. For our small programs, it's fine.
