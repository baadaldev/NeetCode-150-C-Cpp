# Time Based Key-Value Store

[![LeetCode](https://img.shields.io/badge/LeetCode-981-FFA116?style=flat-square&logo=leetcode&logoColor=white)](https://leetcode.com/problems/time-based-key-value-store/)
[![Difficulty](https://img.shields.io/badge/Difficulty-Medium-eab308?style=flat-square)](#)

## 📌 Problem Overview
- **Topic:** Binary Search
- **LeetCode ID:** [981 - Time Based Key-Value Store](https://leetcode.com/problems/time-based-key-value-store/)
- **Difficulty:** 🟡 Medium
- **Time Complexity:** `Set: O(1), Get: O(log n)`
- **Space Complexity:** `O(n)`

---

## 💡 Algorithmic Approach & Summary
Map each key to an array of (timestamp, value) pairs. Use binary search to find the largest timestamp <= requested.

---

## 💻 Source Code Solutions
- [C Implementation (solution.c)](solution.c)
- [C++ Implementation (solution.cpp)](solution.cpp)

---
*Part of [NeetCode 150 Solutions in C & C++](https://github.com/baadaldev/NeetCode-150-C-Cpp) by [@baadaldev](https://github.com/baadaldev).*
