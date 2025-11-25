# **Lecture 5 Exercises: Dynamic Memory Practice**

The goal of these exercises is to practice the manual memory management skills we learned in class. You will use `new`, `delete`, `new[]`, and `delete[]` and learn to spot common errors like memory leaks and dangling pointers.

Instructions:  
Complete the TODO tasks in each `.cpp` file.

### **Exercise 1: Basic Allocation (`ex1_basic.cpp`)**

**Goal:** Practice allocating and freeing a single object.

1. Open `ex1_basic.cpp`.  
2. Follow the TODO comments to:  
   1. Allocate a single int on the heap.  
   2. Set its value to 42 using the pointer.  
   3. Print the value.  
   4. delete the memory.  
   5. Set the pointer to `nullptr`.

### **Exercise 2: Array Allocation (`ex2_array.cpp`)**

**Goal:** Practice allocating and freeing a dynamically sized array.

1. Open `ex2_array.cpp`.  
2. Follow the TODO comments to:  
   1. Ask the user to enter a size for the array.  
   2. Allocate an array of doubles of that size on the heap.  
   3. Loop through the array and fill it with values (e.g., `index * 1.5`).  
   4. Loop through the array again and print all the values.  
   5. `delete[]` the array.  
   6. Set the pointer to `nullptr`.

### **Exercise 3: Spot the Memory Leak (`ex3_leak.cpp`)**

**Goal:** Learn to identify and fix a memory leak.

1. Open `ex3_leak.cpp`.  
2. Read the code. This program compiles and runs, but it "leaks" memory every time `leaky_function` is called because it allocates memory and never frees it.  
3. Your task: Add the single line of code that fixes the memory leak.

### **Exercise 4: Fix the Dangling Pointer (`ex4_dangling.cpp`)**

**Goal:** Understand the danger of using a pointer after it has been freed.

1. Open `ex4_dangling.cpp`.  
2. This program crashes or (worse) has undefined behavior because it uses a "dangling pointer."  
3. Your task:  
   1. Find the line of code that accesses the freed memory (the "dangling pointer").  
   2. Implement the "good practice" fix: after the memory is deleted, set the pointer to `nullptr`.  
   3. (Optional) Add an if statement to check if the pointer is `nullptr` before the dangerous access to prevent the crash.

### **Exercise 5: Mismatch Mayhem (`ex5_mismatch.cpp`)**

**Goal:** Learn to match new with delete and new\[\] with delete\[\].

1. Open `ex5_mismatch.cpp`.  
2. This program has a critical bug: it allocates an *array* with `new[]` but tries to free it with `delete`.  
3. Your task: Find the incorrect `delete` and replace it with the correct deallocation operator for an array.