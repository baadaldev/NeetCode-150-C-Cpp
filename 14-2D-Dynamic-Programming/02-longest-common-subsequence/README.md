# Longest Common Subsequence

[![LeetCode](https://img.shields.io/badge/LeetCode-1143-FFA116?style=flat-square&logo=leetcode&logoColor=white)](https://leetcode.com/problems/longest-common-subsequence/)
[![Difficulty](https://img.shields.io/badge/Difficulty-Medium-eab308?style=flat-square)](#)

## 📌 Problem Overview
- **Topic:** 2-D Dynamic Programming
- **LeetCode ID:** [1143 - Longest Common Subsequence](https://leetcode.com/problems/longest-common-subsequence/)
- **Difficulty:** 🟡 Medium
- **Time Complexity:** `O(m * n)`
- **Space Complexity:** `O(min(m, n))`

---

## 💡 Algorithmic Approach & Summary
If text1[i] == text2[j], dp[i][j] = 1 + dp[i+1][j+1]; else max(dp[i+1][j], dp[i][j+1]).

---

## 💻 Source Code Solutions
- [C Implementation (solution.c)](solution.c)
- [C++ Implementation (solution.cpp)](solution.cpp)

---
*Part of [NeetCode 150 Solutions in C & C++](https://github.com/baadaldev/NeetCode-150-C-Cpp) by [@baadaldev](https://github.com/baadaldev).*
