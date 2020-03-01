// Time:  O(logx) = O(1)
// Space: O(1)

class Solution {
public:
    bool isPalindrome(int x) {
        if (x < 0) {
            return false;
        }

        int divisor = 1;
        while (x / divisor >= 10) { // let the bits of divisor equal to the bits of x
            divisor *= 10;
        }

        for (; x > 0; x = (x % divisor) / 10, divisor /= 100) { // shrink from both left and right
            // x % divisor -> remove the head of x, / 10 -> remove the tail of x, the bits of divisor reduce 2 bits
            // double pointer
            int left = x / divisor; // the head of x
            int right = x % 10;
            if (left != right) {
                return false;
            }
        }

        return true;
    }
};