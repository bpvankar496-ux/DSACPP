// ==>Recursion Time Complexity — Basic Idea
// Recursive function call kare tyare call tree bane.
// Formula:
// T(n) = aT(n/b) + O(n^d)
// a = recursive calls per step
// b = input size reduction
// d = extra work per call


// ==>Common Recursive Examples
// 1. Recursive Sum of N Numbers
// T(n) = T(n-1) + O(1)
// → O(n)
// 2. Recursive Factorial
// T(n) = T(n-1) + O(1)
// → O(n)
// 3. Recursive Nth Fibonacci
// T(n) = T(n-1) + T(n-2) + O(1)
// → O(2^n)  ← exponential!


// ==> Master's Theorem
// T(n) = aT(n/b) + O(n^d) mate:
// Condition     Result  
// d > log_b(a)  O(n^d)
// d = log_b(a)  O(n^d · log n)
// d < log_b(a)  O(n^log_b(a))

//  Merge Sort Analysis
// T(n) = 2T(n/2) + O(n)
// a=2, b=2, d=1
// log_2(2) = 1 = d
// → O(n log n)


// ==>Power Function Analysis
// power(x, n) = power(x, n/2) * power(x, n/2)
// T(n) = 2T(n/2) + O(1)
// → O(n)

// // But if: power(x, n/2) ne store kariye to
// T(n) = T(n/2) + O(1)
// → O(log n)

