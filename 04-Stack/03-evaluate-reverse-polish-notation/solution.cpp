/**
 * LeetCode 150: Evaluate Reverse Polish Notation
 * Time Complexity: O(n)
 * Space Complexity: O(n)
 */
#include <vector>
#include <string>
#include <stack>

class Solution {
public:
    int evalRPN(std::vector<std::string>& tokens) {
        std::stack<int> st;
        for (const auto& t : tokens) {
            if (t == "+" || t == "-" || t == "*" || t == "/") {
                int b = st.top(); st.pop();
                int a = st.top(); st.pop();
                if (t == "+") st.push(a + b);
                else if (t == "-") st.push(a - b);
                else if (t == "*") st.push(a * b);
                else if (t == "/") st.push(a / b);
            } else {
                st.push(std::stoi(t));
            }
        }
        return st.top();
    }
};
