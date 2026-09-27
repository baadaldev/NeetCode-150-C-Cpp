# Min Cost Climbing Stairs

[![LeetCode](https://img.shields.io/badge/LeetCode-746-FFA116?style=flat-square&logo=leetcode&logoColor=white)](https://leetcode.com/problems/min-cost-climbing-stairs/)
[![Difficulty](https://img.shields.io/badge/Difficulty-Easy-22c55e?style=flat-square)](#)

## 📌 Problem Overview
- **Topic:** 1-D Dynamic Programming
- **LeetCode ID:** [746 - Min Cost Climbing Stairs](https://leetcode.com/problems/min-cost-climbing-stairs/)
- **Difficulty:** 🟢 Easy
- **Time Complexity:** `O(n)`
- **Space Complexity:** `O(1)`

---

## 💡 Algorithmic Approach & Summary
cost[i] += min(cost[i+1], cost[i+2]) backwards from top to bottom.

---

## 💻 Source Code Solutions
- [C Implementation (solution.c)](solution.c)
- [C++ Implementation (solution.cpp)](solution.cpp)

---
*Part of [NeetCode 150 Solutions in C & C++](https://github.com/baadaldev/NeetCode-150-C-Cpp) by [@baadaldev](https://github.com/baadaldev).*
