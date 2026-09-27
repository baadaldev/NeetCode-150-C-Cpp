/**
 * LeetCode 50: Pow(x, n)
 * Time Complexity: O(log n)
 * Space Complexity: O(1)
 */
class Solution {
public:
    double myPow(double x, int n) {
        long long exp = n;
        if (exp < 0) {
            x = 1.0 / x;
            exp = -exp;
        }
        double res = 1.0;
        while (exp > 0) {
            if (exp % 2 == 1) res *= x;
            x *= x;
            exp /= 2;
        }
        return res;
    }
};
