# Word Break

[![LeetCode](https://img.shields.io/badge/LeetCode-139-FFA116?style=flat-square&logo=leetcode&logoColor=white)](https://leetcode.com/problems/word-break/)
[![Difficulty](https://img.shields.io/badge/Difficulty-Medium-eab308?style=flat-square)](#)

## 📌 Problem Overview
- **Topic:** 1-D Dynamic Programming
- **LeetCode ID:** [139 - Word Break](https://leetcode.com/problems/word-break/)
- **Difficulty:** 🟡 Medium
- **Time Complexity:** `O(n * m * k)`
- **Space Complexity:** `O(n)`

---

## 💡 Algorithmic Approach & Summary
dp[i] = true if any word in dictionary matches s[i : i + wordLen] and dp[i + wordLen] is true.

---

## 💻 Source Code Solutions
- [C Implementation (solution.c)](solution.c)
- [C++ Implementation (solution.cpp)](solution.cpp)

---
*Part of [NeetCode 150 Solutions in C & C++](https://github.com/baadaldev/NeetCode-150-C-Cpp) by [@baadaldev](https://github.com/baadaldev).*
