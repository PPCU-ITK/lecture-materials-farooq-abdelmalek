# **Lecture 11 Exercises: Copy Semantics & Memory Management**

## **Overview**

These exercises are designed to reinforce the concepts of Deep vs. Shallow copying, the Rule of Three, and the modern Rule of Zero.

**Environment:** These are standard C++ files. You can compile them in your Codespace terminal using g++.

## **Exercise 1: The Crash Investigation**

**File:** `01_crash_investigation.cpp`

**Objective:** Witness a "Double Free" error firsthand and fix it using a Copy Constructor.

1. Compile and Run:
   ```bash
   g++ 01_crash_investigation.cpp -o ex1
   ./ex1
   ```
   *Observation:* The program should crash (Segfault) or report a "double free or corruption" error.

2. **Analyze:** Look at the UnsafeBuffer class. It manages a raw pointer but uses the *default* copy constructor (shallow copy).  
3. **Fix:** Implement a custom **Copy Constructor** that performs a **Deep Copy**.  
   * Allocate new memory for the new object.  
   * Copy the *data* from the source, not the address.

## **Exercise 2: Implementing The Rule of Three**

**File:** `02_rule_of_three.cpp`

**Objective:** Implement a complete class that safely manages a dynamic array.

1. Open `02_rule_of_three.cpp`.  
2. The DynamicArray class has a constructor, but mimics a "resource leak" and unsafe copying.  
3. **Task A (Destructor):** Implement the destructor to free the memory.  
4. **Task B (Copy Constructor):** Implement deep copying.  
5. **Task C (Copy Assignment):** Implement the assignment operator `operator=`.  
   * *Hint:* Remember to free existing memory before allocating new memory!  
6. Run the tests in `main()` to verify your implementation.

## **Exercise 3: The Self-Assignment Trap**

**File:** `03_assignment_operator.cpp`

**Objective:** Handle the edge case where an object is assigned to itself (`a = a`).

1. **Compile and Run:**
   ```bash
   g++ 03_assignment_operator.cpp -o ex3
   ./ex3
   ```

2. The program attempts `p1 = p1`.  
3. **Debug:** Explain why the current implementation corrupts the data during self-assignment. (Hint: We delete the old data before we copy... but if source and destination are the same, we just deleted our source!).  
4. **Fix:** Add a **Self-Assignment Check** at the very top of the assignment operator.

## **Exercise 4: The Rule of Zero (Refactoring)**

**File:** `04_rule_of_zero.cpp`

**Objective:** Stop managing memory manually. Refactor a legacy class to use `std::unique_ptr`.

1. Open `04_rule_of_zero.cpp`.  
2. The LegacyLogger class is currently using raw pointers and requires the Rule of Three (which is currently missing, making it unsafe).  
3. **Refactor:**
   * Change `int* logData` to `std::unique_ptr<int> logData`.  
   * Update the constructor to use `std::make_unique`.  
   * **Delete** the Destructor, Copy Constructor, and Copy Assignment Operator entirely.  
4. **Verify:** Attempt to copy the object in `main()`.  
   * *Note:* It should fail to compile! `unique_ptr` disables copying automatically.  
   * Update `main()` to `std::move` the logger or simply show that the compiler prevents the safety violation.