# Lowest Common Ancestor of a BST

[![LeetCode](https://img.shields.io/badge/LeetCode-235-FFA116?style=flat-square&logo=leetcode&logoColor=white)](https://leetcode.com/problems/lowest-common-ancestor-of-a-bst/)
[![Difficulty](https://img.shields.io/badge/Difficulty-Medium-eab308?style=flat-square)](#)

## 📌 Problem Overview
- **Topic:** Trees
- **LeetCode ID:** [235 - Lowest Common Ancestor of a BST](https://leetcode.com/problems/lowest-common-ancestor-of-a-bst/)
- **Difficulty:** 🟡 Medium
- **Time Complexity:** `O(h)`
- **Space Complexity:** `O(1)`

---

## 💡 Algorithmic Approach & Summary
Move down the BST: if both p and q are smaller go left, if both larger go right; otherwise split node is LCA.

---

## 💻 Source Code Solutions
- [C Implementation (solution.c)](solution.c)
- [C++ Implementation (solution.cpp)](solution.cpp)

---
*Part of [NeetCode 150 Solutions in C & C++](https://github.com/baadaldev/NeetCode-150-C-Cpp) by [@baadaldev](https://github.com/baadaldev).*
