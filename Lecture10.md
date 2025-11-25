# **Lecture 10: Classes & Lifecycle - Programming Exercises**

These exercises are designed to practice the transition from Python-style OOP to C++ classes, focusing on encapsulation, memory management, and the object lifecycle.

## **How to Run**

If you are using a Codespace or terminal, compile each file using g++:

```bash
g++ -o ex1 ex1_basics.cpp
./ex1
```

## **Exercise 1: The Class Blueprint (RPG Character)**

Topic: Basic Class Syntax & Public/Private  
Goal: Convert a Python concept into a C++ class.

1. Open `ex1_basics.cpp`.  
2. Define a class named `RPGCharacter`.  
3. It should have **private** member variables for `name` (string) and `health` (int).  
4. It should have a **public** constructor that accepts a name and initial health.  
5. Add a public method `take_damage(int amount)` that reduces health.  
6. Add a public method `is_alive()` that returns true if `health > 0`.

## **Exercise 2: The Gatekeeper (Encapsulation)**

Topic: Invariants & Getters/Setters  
Goal: Use private to enforce logic rules (invariants) that would be impossible in Python.

1. Open `ex2_encapsulation.cpp`.  
2. Complete the `Thermometer` class.  
3. The internal temperature (`m_celsius`) must be **private**.  
4. Implement `set_temperature(double c)`. **Crucial:** This method must reject any temperature below absolute zero (-273.15). If the user tries to set a lower value, print an error and do not update the variable.  
5. Implement `get_fahrenheit()` which converts the internal Celsius to Fahrenheit (`C * 9/5 + 32`) and returns it.

## **Exercise 3: The Immutable (Initializer Lists)**

Topic: Member Initializer Lists & const  
Goal: Initialize a constant member variable, which is impossible without an initializer list.

1. Open `ex3_initializers.cpp`.  
2. Create a class `Planet`.  
3. It must have a `const double gravity` member variable.  
4. Try to assign `gravity` inside the constructor body (like Python). Observe the compiler error.  
5. Fix it by using a **Member Initializer List** (`: gravity(g)`).

## **Exercise 4: The Lifecycle (Destructors)**

Topic: Scope & Deterministic Destruction  
Goal: Visualize exactly when objects die.

1. Open `ex4_lifecycle.cpp`.  
2. The `LoudObject` class prints "Born" in its constructor.  
3. Implement the **Destructor** `~LoudObject()` to print "Died".  
4. In `main()`, create explicitly nested scopes using `{ }`.  
5. Place objects inside different scopes and run the program to predict the order of "Born" and "Died" messages.

## **Exercise 5: The Wrapper (RAII)**

Topic: RAII & Manual Memory Management  
Goal: Create a safe wrapper around a dangerous raw pointer.

1. Open `ex5_raii.cpp`.  
2. The class `HeapWrapper` manages a raw integer pointer (`int* m_ptr`).  
3. In the **Constructor**: Allocate memory using `new int` and store the value.  
4. In the **Destructor**: Release memory using `delete`.  
5. Run the program with Valgrind (if available) or observe the print statements to ensure every allocation has a matching deletion automatically.