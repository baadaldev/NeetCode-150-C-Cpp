# Word Search II

[![LeetCode](https://img.shields.io/badge/LeetCode-212-FFA116?style=flat-square&logo=leetcode&logoColor=white)](https://leetcode.com/problems/word-search-ii/)
[![Difficulty](https://img.shields.io/badge/Difficulty-Hard-ef4444?style=flat-square)](#)

## 📌 Problem Overview
- **Topic:** Tries
- **LeetCode ID:** [212 - Word Search II](https://leetcode.com/problems/word-search-ii/)
- **Difficulty:** 🔴 Hard
- **Time Complexity:** `O(m * n * 4^L)`
- **Space Complexity:** `O(total characters in words)`

---

## 💡 Algorithmic Approach & Summary
Insert all dictionary words into a Trie, then run DFS on board with in-place character masking.

---

## 💻 Source Code Solutions
- [C Implementation (solution.c)](solution.c)
- [C++ Implementation (solution.cpp)](solution.cpp)

---
*Part of [NeetCode 150 Solutions in C & C++](https://github.com/baadaldev/NeetCode-150-C-Cpp) by [@baadaldev](https://github.com/baadaldev).*
