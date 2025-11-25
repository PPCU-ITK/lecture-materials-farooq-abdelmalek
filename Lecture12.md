# **Lecture 12 Exercises: Polymorphism & Error Handling**

## **Environment Setup**

These exercises are designed to run in GitHub Codespaces or any standard Linux environment with g++.  
To compile any exercise, use the command:  
```bash
g++ -o app exN_filename.cpp
./app
```

## **Exercise 1: The Overloaded Printer**

Topic: Static Polymorphism (Function Overloading)  
File: `ex1_overload.cpp`  
Goal:  
The main function attempts to call `print_data` with three different types: `int`, `std::string`, and `double`. Currently, only the `int` version exists.  
**Task:**

1. Add two new overloads for `print_data`:  
   * One that accepts `const std::string&`.  
   * One that accepts `double`.  
2. Run the code. Notice how the compiler decides which function to call at compile time.

## **Exercise 2: The Generic Accumulator**

Topic: Static Polymorphism (Templates)  
File: `ex2_template.cpp`  
Goal:  
We want a single function `add_values` that can add two integers, two doubles, or concatenate two strings. Instead of writing three functions, write one Template.  
**Task:**

1. Replace the specific `add_values` function with a `template <typename T>`.  
2. Ensure it returns type `T` and takes two arguments of type `T`.  
3. Observe how it handles `std::string` concatenation automatically (because `std::string` overloads the `+` operator!).

## **Exercise 3: The RPG Party (The "Virtual" Bug)**

Topic: Runtime Polymorphism (Virtual Functions)  
File: `ex3_rpg.cpp`  
Goal:  
We have a `Character` base class and two derived classes: `Warrior` and `Mage`. We have a `std::vector<Character*>` representing a party.  
The Problem:  
When iterating through the party and calling `attack()`, everyone just says "Generic Attack!" instead of their specific class attack.  
**Task:**

1. Run the code and observe the incorrect output.  
2. Fix it by making the `attack()` method virtual in the base class.  
3. Add the `override` keyword to the derived classes for safety.

## **Exercise 4: The Shape Interface**

Topic: Abstract Classes (Pure Virtual Functions)  
File: `ex4_shapes.cpp`  
Goal:  
We want to enforce a contract: Any class that claims to be a `Shape` must implement a method to calculate its `area()`.  
**Task:**

1. Modify the `Shape` class to make `area()` a **Pure Virtual Function** (`= 0`).  
2. Implement the `area()` logic in `Rectangle` (`width * height`) and `Circle` (`3.14 * radius * radius`).  
3. Uncomment the lines in `main` to test your classes.  
4. Try to instantiate a `Shape` directly and see the compiler error (this verifies it is Abstract).

## **Exercise 5: Safe Division (Exceptions vs. UB)**

Topic: Error Handling  
File: `ex5_safe_math.cpp`  
Goal:  
The provided code performs division. Passing `0` currently crashes the program or causes Undefined Behavior (UB). We want to handle this gracefully using C++ exceptions.  
**Task:**

1. Modify the `safe_divide` function. Check if denominator is `0`.  
2. If it is `0`, throw a `std::runtime_error` with a helpful message.  
3. In `main`, wrap the function calls in a `try...catch` block.  
4. Catch `std::exception` and print the error message using `.what()`.