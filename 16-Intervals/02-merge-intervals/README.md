# Merge Intervals

[![LeetCode](https://img.shields.io/badge/LeetCode-56-FFA116?style=flat-square&logo=leetcode&logoColor=white)](https://leetcode.com/problems/merge-intervals/)
[![Difficulty](https://img.shields.io/badge/Difficulty-Medium-eab308?style=flat-square)](#)

## 📌 Problem Overview
- **Topic:** Intervals
- **LeetCode ID:** [56 - Merge Intervals](https://leetcode.com/problems/merge-intervals/)
- **Difficulty:** 🟡 Medium
- **Time Complexity:** `O(n log n)`
- **Space Complexity:** `O(n)`

---

## 💡 Algorithmic Approach & Summary
Sort intervals by start time. Merge with previous interval if current.start <= prev.end.

---

## 💻 Source Code Solutions
- [C Implementation (solution.c)](solution.c)
- [C++ Implementation (solution.cpp)](solution.cpp)

---
*Part of [NeetCode 150 Solutions in C & C++](https://github.com/baadaldev/NeetCode-150-C-Cpp) by [@baadaldev](https://github.com/baadaldev).*
