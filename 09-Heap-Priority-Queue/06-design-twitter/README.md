# Design Twitter

[![LeetCode](https://img.shields.io/badge/LeetCode-355-FFA116?style=flat-square&logo=leetcode&logoColor=white)](https://leetcode.com/problems/design-twitter/)
[![Difficulty](https://img.shields.io/badge/Difficulty-Medium-eab308?style=flat-square)](#)

## 📌 Problem Overview
- **Topic:** Heap / Priority Queue
- **LeetCode ID:** [355 - Design Twitter](https://leetcode.com/problems/design-twitter/)
- **Difficulty:** 🟡 Medium
- **Time Complexity:** `O(k log k)`
- **Space Complexity:** `O(users + tweets)`

---

## 💡 Algorithmic Approach & Summary
Keep users, followees hash set, and tweets. Merge top 10 tweets using a max heap of recent tweets.

---

## 💻 Source Code Solutions
- [C Implementation (solution.c)](solution.c)
- [C++ Implementation (solution.cpp)](solution.cpp)

---
*Part of [NeetCode 150 Solutions in C & C++](https://github.com/baadaldev/NeetCode-150-C-Cpp) by [@baadaldev](https://github.com/baadaldev).*
