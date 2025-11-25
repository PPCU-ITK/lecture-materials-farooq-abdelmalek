# **Lecture 9 Lab: STL Containers & Iterators**

**Objective:** Gain proficiency with std::vector, std::map, std::set, and modern range-based loops.

## **Setup**

1. Open your Codespace.  
2. Create the files provided below.  
3. Compile each using: `g++ -std=c++17 exN_filename.cpp -o exN`  
4. Run using: `./exN`

## **Exercise 1: Vector Statistics (ex1_vector_stats.cpp)**

Goal: Practice basic std::vector insertion and accessing elements.  
Task:

1. Complete the `analyze_data` function.  
2. It should calculate the **mean** (average) and find the **min** and **max** values in the vector.  
3. **Bonus:** Can you find the median? (Requires sorting).

## **Exercise 2: The Frequency Counter (ex2_frequency_map.cpp)**

Goal: Understand std::map and its sorted nature.  
Task:

1. You are given a raw string of text.  
2. Parse the words and store them in a `std::map<std::string, int>` where the key is the word and the value is the count.  
3. Print the words. Observe that std::map automatically sorts the output alphabetically.  
4. **Question to ponder:** What changes if you switch to `std::unordered_map`?

## **Exercise 3: The Reference Trap (ex3_reference_bug.cpp)**

Goal: Identify and fix a common bug with range-based for loops (auto vs auto&).  
Task:

1. Run the code. Notice that the "After doubling" output is exactly the same as the "Original".  
2. The loop `for (auto score : scores)` creates a **copy** of each element.  
3. Fix the loop definition so that it modifies the actual elements in the vector.

## **Exercise 4: The Unique Guest List (ex4_guest_list.cpp)**

Goal: Use std::set to handle uniqueness automatically.  
Task:

1. The `process_guest_list` function receives a vector with duplicate names.  
2. Copy these names into a `std::set<std::string>`.  
3. Print the contents of the set.  
4. Verify that duplicates are removed and names are sorted.