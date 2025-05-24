# Assignments

###Problem 1: Shopkeeper Simulation with STL

Problem Summary

Simulate a shop with multiple product types and multiple customers. Each customer has a budget and a set of product purchase queries, each with a payoff value. We aim to maximize payoff under budget constraints and dynamic inventory.

Key Concepts

Use of STL containers like unordered_map and vector for product/customer/query storage.

Variant of 0/1 Knapsack to maximize payoff within customer budget.

Dynamic stock management: Restocking if insufficient quantity.

Financial handling: Loans with 10% interest if restocking funds are insufficient.

STL Used

unordered_map for fast lookup of products by ID.

vector for storing customer queries and transaction logs.

Structured types (struct) for clean abstraction of entities.

What Could Be Improved

Adding persistent data storage for logs (e.g., writing to file).

More realistic handling of loans (partial repayments, loan limits).

Problem 2: Echoes of the Blood Moon (Recursion Trial)

Problem Summary

Given an array of echoes (energy values), find the longest strictly increasing path Tanjiro can follow by only moving forward.

Approach

Use recursion with memoization (top-down DP).

At each index, try jumping to any higher-value index ahead and memoize results.

STL Used

vector to represent the echo array and memoization table.

Complexity

Time complexity: O(n^2)

Could be optimized to O(n log n) using binary search (LIS DP).

What Could Be Improved

Could use an iterative DP + binary search method for better performance.

Problem 3: O(n) Sorting Algorithm

Sorting Algorithm: Counting Sort

When to Use

When elements are integers and within a known small range.

Time complexity is O(n + k), where k is the range.

Code Summary

Count frequency of each element.

Reconstruct the sorted array using counts.

STL Used

vector to count occurrences and store result.

What Could Be Improved

Generalize to handle negative numbers or larger ranges using offset.
