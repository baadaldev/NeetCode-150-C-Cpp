# Minimum Interval to Include Each Query

[![LeetCode](https://img.shields.io/badge/LeetCode-1851-FFA116?style=flat-square&logo=leetcode&logoColor=white)](https://leetcode.com/problems/minimum-interval-to-include-each-query/)
[![Difficulty](https://img.shields.io/badge/Difficulty-Hard-ef4444?style=flat-square)](#)

## 📌 Problem Overview
- **Topic:** Intervals
- **LeetCode ID:** [1851 - Minimum Interval to Include Each Query](https://leetcode.com/problems/minimum-interval-to-include-each-query/)
- **Difficulty:** 🔴 Hard
- **Time Complexity:** `O(n log n + q log q)`
- **Space Complexity:** `O(n + q)`

---

## 💡 Algorithmic Approach & Summary
Sort intervals and sorted queries. Min-heap keyed by interval length, popping expired intervals.

---

## 💻 Source Code Solutions
- [C Implementation (solution.c)](solution.c)
- [C++ Implementation (solution.cpp)](solution.cpp)

---
*Part of [NeetCode 150 Solutions in C & C++](https://github.com/baadaldev/NeetCode-150-C-Cpp) by [@baadaldev](https://github.com/baadaldev).*
