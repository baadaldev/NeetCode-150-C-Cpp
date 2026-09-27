# Counting Bits

[![LeetCode](https://img.shields.io/badge/LeetCode-338-FFA116?style=flat-square&logo=leetcode&logoColor=white)](https://leetcode.com/problems/counting-bits/)
[![Difficulty](https://img.shields.io/badge/Difficulty-Easy-22c55e?style=flat-square)](#)

## 📌 Problem Overview
- **Topic:** Bit Manipulation
- **LeetCode ID:** [338 - Counting Bits](https://leetcode.com/problems/counting-bits/)
- **Difficulty:** 🟢 Easy
- **Time Complexity:** `O(n)`
- **Space Complexity:** `O(1) auxiliary`

---

## 💡 Algorithmic Approach & Summary
dp[i] = dp[i >> 1] + (i & 1).

---

## 💻 Source Code Solutions
- [C Implementation (solution.c)](solution.c)
- [C++ Implementation (solution.cpp)](solution.cpp)

---
*Part of [NeetCode 150 Solutions in C & C++](https://github.com/baadaldev/NeetCode-150-C-Cpp) by [@baadaldev](https://github.com/baadaldev).*
