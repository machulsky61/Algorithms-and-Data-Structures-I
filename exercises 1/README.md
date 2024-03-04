# Laboratory

This repository contains the mandatory exercises for the Algorithms and Data Structures I laboratory course.

## Exercises

### Fibonacci

Write the `fibonacci` function which, given an integer `n`, with $\( n \geq 0 \)$, calculates iteratively and returns the n-th Fibonacci number. The Fibonacci sequence is defined as follows:

$\ F_0 = 0\$

$\ F_1 = 1\$

$\ F_n = F_{n-1} + F_{n-2}\$

### Swap

Implement the `swap` function that meets the following specification:

```cpp
void swap(int& a, int& b)
```

Precondition: $\( a = a_0 \)$ and $\( b = b_0 \)$

Postcondition: $\( a = b_0 \)$ and $\( b = a_0 \)$

### Division

Implement the `division` function that meets the following specification:

```cpp
void division(int dividend, int divisor, int& quotient, int& remainder)
```

Precondition: $\( dividend \geq 0 \)$ and $\( divisor > 0 \)$

Postcondition: $\( dividend = divisor \times quotient + remainder \)$ and $\( 0 \leq remainder < divisor \)$

Solve this exercise iteratively, without using the division (`/`) or mod (`%`) operations.

### Vector Rotation

Given a vector `v` and an integer `k`, rotate `v` k positions. Assume precondition $\( k > 0 \).$

Example:
For the vector `<1,2,3,4,5,6>` rotated by 2, it should return `<3,4,5,6,1,2>`.

### Check Order in a Vector

Given a vector `v` of integers, return true if it is sorted (either in increasing or decreasing order).
