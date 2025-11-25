# **Lecture 4: Coding Exercises**

## **C-Style Arrays, Pointers, and C-Strings**

These exercises are designed to give you hands-on practice with the low-level memory concepts we discussed in Lecture 4. The goal is to move away from the "safe" abstractions of Python and understand what C++ is doing under the hood.

**Pay close attention to comments** in the starter .cpp files. They contain hints and instructions for where to write your code.

### **Exercise 1: Array Basics & Traversal**

**File:** `exercise1_arrays.cpp`

**Goal:** Get comfortable with declaring, initializing, and iterating over a C-style array using standard index-based [] notation.

**Tasks:**

1. Declare an integer array and initialize it with some values.

```
int data[] = {10, 20, 30, 40};
```

2. Calculate the number of elements in the array using the sizeof operator. Remember the "sizeof gotcha".

```
size_t n = sizeof(data) / sizeof(data[0]);
```

3. Write a standard for loop that iterates from `i = 0` to `n - 1`.

```
for (size_t i = 0; i < n; ++i) {
    // ...
}
```

4. Inside the loop, use the `[]` operator to access and print each element.

```
std::cout << data[i] << '\n';
```

### **Exercise 2: Pointer Arithmetic Traversal**

**File:** `exercise2_pointers.cpp`

**Goal:** Perform the *exact same task* as Exercise 1, but this time, you are **forbidden** from using the [] operator. You must use pointer arithmetic.

**Tasks:**

1. Initialize the same array of data.

```
int data[] = {10, 20, 30, 40};
```

2. Create a pointer that points to the beginning of the array.

```
int* p = data;
```

3. Create a "past-the-end" pointer that points just after the last element.

```
int* p_end = data + n;
```

4. Write a while loop that continues as long as `p != p_end`.

```
while (p != p_end) {
    // ...
}
```

5. Inside the loop:

```
std::cout << *p << '\n';
++p;
```

### **Exercise 3: C-String Basics (Writing my_strlen)**

**File:** `exercise3_strlen.cpp`

**Goal:** Understand that C-strings are just char arrays terminated by a null character (`\0`) and learn how C-string functions exploit this.

**Tasks:**

1. In the main function, a C-style string is provided.

```
char greeting[] = "Hello";
```

2. Complete the function `my_strlen(const char* str)`.
3. Inside this function, you must:  
   * Initialize a counter for the length.  
   * Create a while loop that continues as long as the value at the current pointer (`*str`) is not the null character (`\0`).  
   * Inside the loop, increment your length counter and increment the pointer (`++str`) to move to the next character.  
   * Return the final length.  
```
size_t my_strlen(const char* str) {
    size_t length = 0;
    while (*str != '\0') {
        ++length;
        ++str;
    }
    return length;
}
```

4. The main function will call your function and print the result.

### **Exercise 4: C-String Reversal (In-Place)**

**File:** `exercise4_reverse.cpp`

**Goal:** Combine pointer arithmetic and C-string concepts to perform a common algorithm. This is a classic interview-style question.

**Tasks:**

1. Complete the function `reverse_string(char* str)`. This function must reverse the string in-place.

```
void reverse_string(char* str) {
    // ...
}
```

2. Inside the function, you will need two pointers:  
   * A left pointer that starts at the beginning of the string (`str`).  
   * A right pointer that starts at the end of the string.  

```
char* left = str;
char* right = str + my_strlen(str) - 1;
```

3. To find the end, you can either call `my_strlen` and do some pointer math, or you can write a loop that advances the right pointer until it hits `\0`, then step it back by one.  
4. Write a while loop that continues as long as the left pointer is to the left of the right pointer.  
5. Inside the loop:  
   * Swap the characters at the left and right positions (use a temporary `char`).  
   * Move the left pointer forward (`++left`).  
   * Move the right pointer backward (`--right`).  
6. The main function will print the string *before* and *after* calling your function.

```
while (left < right) {
    char temp = *left;
    *left = *right;
    *right = temp;
    ++left;
    --right;
}
```

### **Exercise 5: (Challenge) C-String Copy (Writing my_strcpy)**

**File:** `exercise5_strcpy.cpp`

**Goal:** Re-create the dangerous strcpy function to understand *why* buffer overflows happen.

**Tasks:**

1. Complete the function `my_strcpy(char* destination, const char* source)`.  
2. This function should copy every character from source into destination, one by one, including the final `\0` null terminator.  
3. Write a while loop that continues copying forever (e.g., `while (true)`).  
4. Inside the loop:  
   * Copy the character from `*source` to `*destination`.  
   * Check if the character you just copied was `\0`. If it was, break from the loop.  
   * Increment both source and destination pointers.  

```
char* my_strcpy(char* destination, const char* source) {
    char* dest_start = destination;
    while (true) {
        *destination = *source;
        if (*source == '\0') {
            break;
        }
        ++destination;
        ++source;
    }
    return dest_start;
}
```

5. In `main`, experiment by making the destination buffer smaller than the source string. The program will still run, but you have just created a **buffer overflow** (and it may crash on some systems). To visualize:

```
char small[4];
const char* big = "Overflow!";
my_strcpy(small, big); // Undefined behavior
```