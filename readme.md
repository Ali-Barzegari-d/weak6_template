# CSI2372 — Week 6 Lab Handout  
**Topics:** Exception Safety • Ranges • Iterators • Borrowing vs Owning • Dependency Injection  
**Course:** Advanced Programming Concepts with C++ (Fall 2025, uOttawa)  

---

## 1. Overview  
In this lab you will practice advanced C++ design patterns involving exception safety, C++20 ranges, iterator support, and flexible design via ownership models and dependency injection.  

The lab consists of four graded tasks:  

- **Parse Helpers** – implement safe integer parsing with both status codes and exceptions.  
- **Ranges Pipeline** – design a pipeline using ranges views, sorting, and deduplication.  
- **PersonDirectory** – build a small container with strong exception guarantees.  
- **IterableProcessor** – combine iterators, borrowing vs owning semantics, and processing via function pointers.  

All work is autograded via CI/CTest. When the GitHub Actions build is green, you earn full marks.  

---

## 2. Learning Objectives  
By the end of this lab, you should be able to:  

- Implement exception-safe parsing routines using both `std::optional` and exceptions.  
- Use C++20 ranges views (`filter`, `transform`, `take`) with standard algorithms like `sort` and `unique`.  
- Apply **basic** and **strong exception guarantees** with the swap idiom.  
- Design classes that support both **borrowing** (reference semantics) and **owning** (move semantics).  
- Inject processing strategies using function pointers or `std::function`.  
- Expose proper iterators so custom classes integrate with range-based `for`.  

---

## 3. Task A – Parse Helpers  
You are given `parse.hpp` and `parse.cpp` with two unimplemented functions:  

- `std::optional<int> to_int_status(const std::string&)`  
  - Parse the string to an integer.  
  - Return `std::nullopt` if parsing fails.  

- `int to_int_exception(const std::string&)`  
  - Parse the string to an integer.  
  - Throw `std::invalid_argument` if parsing fails.  

Tests check successful conversions, invalid inputs, negatives, and overflow handling.  

---

## 4. Task B – Ranges Pipeline  
You are given `ranges_pipeline.hpp` and `ranges_pipeline.cpp` with a single unimplemented function:  

- `std::vector<int> top_unique_sorted_square_odds(const std::vector<int>&, std::size_t n)`  

**Required Behavior:**  
1. Filter only odd numbers.  
2. Transform each number to its square.  
3. Collect results into a vector.  
4. Sort the vector in ascending order.  
5. Remove duplicates.  
6. Return the first `n` elements.  

Tests ensure correct filtering, squaring, sorting, and deduplication.  

---

## 5. Task C – PersonDirectory  
You are given `person_directory.hpp` and `person_directory.cpp` containing two types:  

- **Person**  
  - Moveable but not copyable.  
  - `rename_strong(const std::string&)` must satisfy the **strong exception guarantee**: if name construction fails, the object remains unchanged.  

- **PersonDirectory**  
  - `add(Person)`, `removeByName(std::string)`, `findByName(std::string)`.  
  - `bulkRename(std::string suffix)` must satisfy the **strong exception guarantee**: if renaming any person fails, no person is changed.  

Tests simulate failures (`"Fail!"`) and check rollback safety.  

---

## 6. Task D – IterableProcessor  
You are given `iterable_processor.hpp` and `iterable_processor.cpp`.  

**Required Behavior:**  
- **Ownership**  
  - `setBorrowed(const std::vector<int>&)` → keeps a reference (borrowing).  
  - `setOwned(std::vector<int>)` → moves the vector (owning).  

- **Iteration**  
  - Implement `begin()`/`end()` (const and non-const) so the class works in range-based `for`.  

- **Processing**  
  - `process(std::function<int(int)>)` → apply the function to every element and return a new vector.  

Tests cover both borrowed and owned modes, as well as custom lambdas and function pointers.  

---

## 7. Building and Running  
Recommended portable workflow:  

```bash

cmake -S . -B build -DCMAKE_BUILD_TYPE=Debug
cmake --build build
ctest --test-dir build --output-on-failure

```

CI runs on GitHub automatically when you push.

## 8. Grading

100% autograded: your score = proportion of passing tests.

No manual grading.