# **Lecture 7: Coding Exercises**

These exercises are designed to help you master C++ references, std::string, and std::vector.

## **Exercise 1: Reference Basics**

**Goal:** Understand that a reference is an *alias* for another variable.

**Task:**

1. Open `exercise1_basics.cpp`.  
2. Inside `main`, create an `int` variable named `original` and set its value to `10`.  
3. Create an `int&` (a reference) named `alias` and initialize it with `original`.  
4. Modify `original` to be `20`.  
5. Print both `original` and `alias` to the console. What do you expect?  
6. Now, modify `alias` to be `30`.  
7. Print both `original` and `alias` again. Observe that modifying the alias modifies the original.

## **Exercise 2: The "Swap" Function (Pass-by-Reference)**

**Goal:** Use pass-by-reference to write a function that modifies its arguments.

**Task:**

1. Open `exercise2_swap.cpp`.  
2. Implement the `swap_by_value` function. Inside `main`, call it and then print `a` and `b` again. Did their values change? Why not?  
3. Implement the `swap_by_reference` function. Your goal is to make this function swap the *actual* values of `a` and `b` in the `main` function.  
4. Call `swap_by_reference` from `main` and verify that `a` and `b` have been successfully swapped.

## **Exercise 3: Safe Reading (Pass-by-const-Reference)**

**Goal:** Use const references to pass data efficiently and safely (read-only).

**Task:**

1. Open `exercise3_const_ref.cpp`.  
2. Implement the `printVector` function. It should take a `const std::vector<int>&` as its parameter.  
3. Inside the function, use a range-based for loop (e.g., `for (int val : v)`) to print each element.  
4. **Bonus:** Inside `printVector`, try to add the line `v.push_back(10);`. What happens when you try to compile? Why is this a good thing? (Remember to remove the line afterward).

## **Exercise 4: Building a std::string**

**Goal:** Use std::string and pass-by-reference for both input and output.

**Task:**

1. Open `exercise4_strings.cpp`.  
2. Implement the `addGreeting` function. It should take a user's name (as a read-only `const std::string&`) and *append* a greeting string to the `profile_text` (which is passed as a normal `std::string&`).  
3. For example, if `profile_text` is `"User: "` and `name` is `"Alice"`, the function should change `profile_text` to `"User: Hello, Alice!"`.  
4. Run the program and verify the `userProfile` string in `main` is modified.

## **Exercise 5: Analyzing a std::vector**

**Goal:** Combine vector processing, const& for input, and & for modification.

**Task:**

1. Open `exercise5_vector.cpp`.  
2. Implement `sumVector`. It should take a `const std::vector<int>&`, loop over all its elements, and return their sum as an `int`.  
3. Implement `addTen`. It should take a `std::vector<int>&` and modify it in-place by adding `10` to *every* element in the vector.  
   * *Hint:* You will need a reference-based loop: `for (int& val : v)`  
4. Run the program to verify that `sumVector` correctly calculates the sum *before* and *after* `addTen` modifies the vector.