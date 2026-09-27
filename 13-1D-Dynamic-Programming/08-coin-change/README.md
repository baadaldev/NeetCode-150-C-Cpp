# Coin Change

[![LeetCode](https://img.shields.io/badge/LeetCode-322-FFA116?style=flat-square&logo=leetcode&logoColor=white)](https://leetcode.com/problems/coin-change/)
[![Difficulty](https://img.shields.io/badge/Difficulty-Medium-eab308?style=flat-square)](#)

## 📌 Problem Overview
- **Topic:** 1-D Dynamic Programming
- **LeetCode ID:** [322 - Coin Change](https://leetcode.com/problems/coin-change/)
- **Difficulty:** 🟡 Medium
- **Time Complexity:** `O(amount * n)`
- **Space Complexity:** `O(amount)`

---

## 💡 Algorithmic Approach & Summary
Bottom-up DP: dp[i] = min(dp[i], 1 + dp[i - coin]).

---

## 💻 Source Code Solutions
- [C Implementation (solution.c)](solution.c)
- [C++ Implementation (solution.cpp)](solution.cpp)

---
*Part of [NeetCode 150 Solutions in C & C++](https://github.com/baadaldev/NeetCode-150-C-Cpp) by [@baadaldev](https://github.com/baadaldev).*
