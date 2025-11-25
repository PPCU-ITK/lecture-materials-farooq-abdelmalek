# **Lecture 3: Pointers & Memory - Exercises**

**Objective:** These exercises are designed to break your "Python mental model" and get comfortable with direct memory access. You will practice declaring pointers, finding addresses, and dereferencing them to read/write values.

**Environment:** These files are ready to run in Codespaces. Open the terminal and compile each file using g++.

## **Exercise 1: The Mailbox (Basics)**

**File:** `01_basics.cpp`

**Goal:** Differentiate between the "House" (Variable), the "GPS Coordinate" (Address), and the "Mailbox" (Pointer).

1. Open `01_basics.cpp`.  
2. Follow the TODO comments to:  
   * Print the memory address of `secret_number`.  
   * Create a pointer variable.  
   * Use the pointer to change `secret_number` to 999 without touching the original variable name.  
3. **Compile & Run:**  
   ```bash
   g++ 01_basics.cpp -o basics
   ./basics
   ```

## **Exercise 2: The Puppeteer (Pass-by-Pointer)**

**File:** `02_modify.cpp`

**Goal:** Understand how to modify a variable living in main() from a different function.

In Python, integers are immutable. In C++, we can reach into memory and change them.

1. Open `02_modify.cpp`.  
2. Implement the `tripler` function. It should take a pointer to an integer and multiply the original value by 3.  
3. **Compile & Run:**  
   ```bash
   g++ 02_modify.cpp -o modify
   ./modify
   ```

## **Exercise 3: The Classic Swap**

**File:** `03_swap.cpp`

**Goal:** Implement the fundamental pattern for swapping two values using pointers.

1. Open `03_swap.cpp`.  
2. The main function has two variables, apple and orange.  
3. Write a function `swap_fruit` that takes two pointers.  
4. Use a temporary variable inside the function to swap their values.  
5. **Compile & Run:**  
   ```bash
   g++ 03_swap.cpp -o swap
   ./swap
   ```

## **Exercise 4: Danger Zone (Null Safety)**

**File:** `04_safety.cpp`

**Goal:** Identify and fix a segmentation fault caused by an uninitialized pointer.

1. Open `04_safety.cpp`.  
2. **Compile & Run** it immediately to see it crash (Segmentation Fault).  
3. Analyze why it crashed (hint: check the ptr initialization).  
4. Fix the code using a check for nullptr or by assigning a valid address.  
5. **Compile & Run:**  
   ```bash
   g++ 04_safety.cpp -o safety
   ./safety
   ```  
