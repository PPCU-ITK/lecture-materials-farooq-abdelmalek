# **C++ Lecture 6: Coding Exercises (Revised)**

These exercises are designed to give you hands-on practice with the "Big 3" pointer pitfalls and the concept of pass-by-pointer, but in slightly more realistic scenarios.

Your task is to find the bugs, fix them, and implement the correct pointer-based solutions.

## **Exercise 1: The Failed Update (Pass-by-Pointer)**

**File:** exercise1_reset_score.cpp

This program defines a simple Student struct. It includes a function reset_score_by_value that is *supposed* to reset a student's score to 0.

However, as you'll see, the function fails to modify the *original* student object in main(). This is because C++'s default is **pass-by-value**, and the function is only modifying a *copy* of the student.

### **Your Tasks**

1. **Compile and Run:** Compile and run the program. Notice that the score is "Reset to 0" inside the function, but in main, the student's score remains unchanged.  
2. **Implement the Fix:**  
   * Uncomment the skeleton for reset_score_by_pointer.  
   * This function should take a **pointer** to a Student object (Student\*).  
   * Inside the function, use the arrow operator (->) to access the score member of the *original* object and set it to 0.  
3. **Call Your Function:**  
   * In main(), call your new reset_score_by_pointer function.  
   * Remember to pass the **address** of student_a using the & operator.  
4. **Verify:** Re-compile and run. Your new function should successfully reset the student's score in main().

## **Exercise 2: The Runaway Program (Memory Leaks)**

**File:** exercise2_loop_leak.cpp

This program simulates a server application that constantly creates new user profiles. The function create_user_profile() allocates some memory on the heap for this new profile.

The problem is that the function "leaks" this memory by forgetting to delete it. In a single-run program, this is bad. In a loop, it's catastrophic.

### **Your Tasks**

1. **Compile the Program:**

```bash
g++ -g exercise2_loop_leak.cpp -o loop_leak
```
2. **Run and Observe (Briefly\!):**  
   Run:

```bash
./loop_leak
```

In another terminal, use `top -o MEM` or `htop`. Watch the MEM (or RES) column for `loop_leak` climb rapidly.  
   **Stop the program with Ctrl+C** after a few seconds.  
3. **Find the Leak:** Look at create_user_profile(). It allocates memory with new[] but never frees it.  
4. **Fix the Leak:** Add the correct delete[] call in the *one* place it makes sense.  
   * **Critical Thinking:** Where should the delete[] go? If you put it *inside* create_user_profile, is the pointer profile_data still useful? This exercise simulates a common "who owns this memory?" problem. For this exercise, assume the function's *only* job is to create and then immediately *discard* the profile (a bug). The simple fix is to delete[] it before returning. A better (more advanced) fix would be for the function to *return the pointer* and make main responsible for deleting it. For now, just fix the leak in the simplest way.  
5. **Verify:** Re-compile and run. Observe the memory usage in top again. It should now be stable.

## **Exercise 3: The Bad Lookup (SegFault / nullptr)**

**File:** exercise3_bad_lookup.cpp

This is a very common bug pattern. The program has a small, hard-coded "database" of students. The function find_student_by_id() searches this database.

* If it finds the student, it returns a **pointer** to it.  
* If it *doesn't* find the student, it returns nullptr.

The code in main() works fine when it searches for ID 102 (who exists), but it doesn't consider what happens when a student *isn't* found.

### **Your Tasks**

1. **Compile and Run:** The program will run fine for the first lookup (ID 102).  
2. **Uncomment the Bad Code:** In main(), uncomment the second block of code that searches for ID 999 (who doesn't exist).  
3. **Run and Crash:** Re-compile and run. The program will crash with a **Segmentation Fault** (or similar error).  
4. **Explain the Crash:** Why did it crash? It's because find_student_by_id(999) returned nullptr, and main tried to access p_student->name (which is nullptr->name). This is dereferencing a null pointer.  
5. **Fix the Bug:** In main(), add an if statement to check if p\_student is nullptr *before* trying to print the student's name.

## **Exercise 4: The Dangling Database (Dangling Pointers)**

**File:** exercise4_dangling_db.cpp

This exercise demonstrates a subtle but deadly form of dangling pointer. A function setup_database() creates a Student array on the **stack**. It then returns a pointer to the first student in that array.

The problem is that as soon as setup_database() returns, its entire stack frame (including the student_db array) is destroyed. The pointer returned to main() is now "dangling"—it points to memory that is no longer valid.

### **Your Tasks**

1. **Compile and Run:** Compile and run the program.  
2. **Observe:** It will *probably* crash. It might also print garbage data, or (if you are very "unlucky") it might *look* like it works, hiding the bug. This is Undefined Behavior.  
3. **Explain the Bug:** Look at setup_database(). Explain in your own words why returning &student_db[0] is a critical error. (Hint: Where does student_db live?)  
4. **Fix the Bug (The C++ Way):**  
   * This is a design problem. The best fix is to not use pointers at all.  
   * Change setup_database() to return a std::vector<Student> **by value**.  
   * Change main() to receive this std::vector and access db[0] normally.  
5. **Fix the Bug (The C-Style Pointer Way):**  
   * Alternatively, fix it by allocating the student_db array on the **heap** using new[].  
   * **Crucially:** If you do this, where and how will you delete[] this memory to prevent a memory leak? (This is a harder, more advanced fix, but good to think about!)  