# Valid Anagram

## Problem Description
Given two strings s and 	, return 	rue if 	 is an anagram of s, and alse otherwise.
An Anagram is a word or phrase formed by rearranging the letters of a different word or phrase, typically using all the original letters exactly once.

## Approaches & Complexity Analysis

| Approach | Time Complexity | Space Complexity | Description |
| :--- | :--- | :--- | :--- |
| **Sorting** | O(N log N) | O(1) or O(N) | Sort both strings and compare character-by-character. |
| **Hash Table / Frequency Array** | O(N) | O(1) | Use a fixed 26-element array to count character frequencies. |

## Key Insights
- Since the alphabet consists of 26 lowercase English letters, a fixed array of size 26 provides O(1) auxiliary space.
- Increment counts for characters in s and decrement for 	. If all frequencies return to 0, the strings are valid anagrams.
