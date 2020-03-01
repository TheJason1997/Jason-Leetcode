// Time:  O(logx) = O(1), x has log10(x) bits
// Space: O(1)

class Solution {
public:
    int reverse(int x) {
        int ans = 0;
        int max = numeric_limits<int>::max();
        int min = numeric_limits<int>::min();

        while (x) {
            int pop = x % 10;
            x /= 10;

            // avoid overflow(ans * 10 + pop > max)
            if (ans > max / 10 || (ans == max / 10 && pop > max % 10)) {
                return 0;
            }
            if (ans < min / 10 || (ans == min / 10 && pop < min % 10)) {
                return 0;
            }

            ans = ans * 10 + pop;
        }

        return ans;
    }
};