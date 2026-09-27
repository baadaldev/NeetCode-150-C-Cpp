/**
 * LeetCode 43: Multiply Strings
 * Time Complexity: O(m * n)
 * Space Complexity: O(m + n)
 */
#include <string>
#include <vector>

class Solution {
public:
    std::string multiply(std::string num1, std::string num2) {
        if (num1 == "0" || num2 == "0") return "0";
        int m = num1.length(), n = num2.length();
        std::vector<int> res(m + n, 0);

        for (int i = m - 1; i >= 0; --i) {
            for (int j = n - 1; j >= 0; --j) {
                int mul = (num1[i] - '0') * (num2[j] - '0');
                int p1 = i + j, p2 = i + j + 1;
                int sum = mul + res[p2];
                res[p2] = sum % 10;
                res[p1] += sum / 10;
            }
        }
        std::string ans;
        for (int digit : res) {
            if (!(ans.empty() && digit == 0)) ans.push_back(digit + '0');
        }
        return ans.empty() ? "0" : ans;
    }
};
