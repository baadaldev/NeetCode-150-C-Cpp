# Group Anagrams

## Problem Description
Given an array of strings strs, group the anagrams together. You can return the answer in any order.

## Approaches & Complexity Analysis

| Approach | Time Complexity | Space Complexity | Description |
| :--- | :--- | :--- | :--- |
| **Categorize by Sorted String** | O(N * K log K) | O(N * K) | Sort each string of length K and use as map key. |
| **Categorize by Count** | O(N * K) | O(N * K) | Generate a 26-char frequency tuple/string as map key. |

## Key Insights
- For small string lengths K, sorting each string (std::sort) is concise and extremely fast.
- The sorted string serves as a canonical signature for all its anagrams.
