# Two Sum

## Problem Description
Given an array of integers 
ums and an integer 	arget, return indices of the two numbers such that they add up to 	arget.
You may assume that each input would have exactly one solution, and you may not use the same element twice.

## Approaches & Complexity Analysis

| Approach | Time Complexity | Space Complexity | Description |
| :--- | :--- | :--- | :--- |
| **Brute Force** | O(N²) | O(1) | Nested loops checking every possible pair. |
| **One-Pass Hash Map** | O(N) | O(N) | Hash map storing 	arget - nums[i] complements for O(1) lookups. |

## Key Insights
- By storing previously seen elements in a hash map (complement = target - nums[i]), we trade space for time.
- In C++, std::unordered_map provides average O(1) time complexity for lookup and insertion.
