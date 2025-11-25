# **Lecture 8 Exercises: Resource Management & RAII**

These exercises are designed to reinforce the concepts of RAII, `std::unique_ptr`, `std::shared_ptr`, and `std::weak_ptr`.

## **Setup**

You can compile these files using g++ in your terminal:

```bash
g++ -std=c++17 ex1_memory_leak.cpp -o ex1
./ex1
```

## **Exercise 1: The Safety Net**

**File:** `ex1_memory_leak.cpp`

**The Problem:** The provided code manually allocates memory using `new` and attempts to delete it later. However, the function `risky_operation()` throws an exception, causing the program to crash/exit before the `delete` statement is reached. This causes a memory leak.

**Your Task:**

1. Run the code and observe that "Memory successfully freed" never prints.  
2. Refactor `main()` to use `std::unique_ptr` instead of raw pointers.  
3. Ensure the destructor message prints even after the exception is caught.

## **Exercise 2: The RAII Wrapper**

**File:** `ex2_raii_class.cpp`

The Problem:  
We have a legacy C-style API (`connect_to_server` and `disconnect_from_server`) that requires manual closing. If a developer forgets to disconnect, the server connection hangs.  
**Your Task:**

1. Create a class named `ServerConnection`.  
2. In the **Constructor**, call `connect_to_server`.  
3. In the **Destructor**, call `disconnect_from_server`.  
4. Modify `main` to instantiate your class. Verify that the connection closes automatically when the object goes out of scope.

## **Exercise 3: Moving Ownership**

**File:** `ex3_move_semantics.cpp`

The Problem:  
`std::unique_ptr` cannot be copied, only moved. This exercise challenges you to pass unique pointers between functions correctly.  
**Your Task:**

1. Examine the `take_ownership` function. It takes a `unique_ptr` by value (sink).  
2. In `main`, create a `unique_ptr` to a `BigObject`.  
3. Try to pass it to `take_ownership`. The compiler will complain.  
4. Use `std::move()` to transfer ownership into the function.  
5. Verify that the original pointer is `nullptr` (empty) after the move.

## **Exercise 4: The Cycle of Doom**

**File:** `ex4_circular_logic.cpp`

The Problem:  
A `Manager` holds a `shared_ptr` to a `Worker`, and the `Worker` holds a `shared_ptr` back to the `Manager`. This creates a reference cycle. The reference count never reaches zero, and the destructors are never called.  
**Your Task:**

1. Run the code. Notice that "Manager Destroyed" and "Worker Destroyed" are NEVER printed.  
2. Change the type of one of the pointers (usually the "back-pointer" from `Worker` to `Manager`) from `std::shared_ptr` to `std::weak_ptr`.  
3. Run the code again and confirm that both objects are properly destroyed.

## **Exercise 5: Shared Resources (The Cache)**

**File:** `ex5_shared_resource.cpp`

The Problem:  
We want to simulate a texture cache. Multiple game entities (sprites) need to share the same "Texture" object to save memory. The Texture should only be destroyed when all sprites using it are gone.  
**Your Task:**

1. Use `std::make_shared` to create a `Texture`.  
2. Create a vector of `Sprite` objects.  
3. Pass the *same* shared pointer to multiple `Sprite`s.  
4. Observe how the Reference Count changes (printed in the console) as you add and remove Sprites.  
5. Verify the Texture is destroyed only after the vector is cleared.