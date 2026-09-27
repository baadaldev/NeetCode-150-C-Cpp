/**
 * LeetCode 371: Sum of Two Integers
 * Time Complexity: O(1)
 * Space Complexity: O(1)
 */
int getSum(int a, int b) {
    while (b != 0) {
        unsigned int carry = (unsigned int)(a & b) << 1;
        a = a ^ b;
        b = carry;
    }
    return a;
}
