// Time:  O(n)
// Space: O(1)
// dp

class Solution {
public:
    int numDecodings(string s) {
        // attention
        if (s.empty()) {
            return 0;
        }

        // dp[i]: the number of decoding ways of s(0...i)
        int prev = 0, curr = 1; // dp[i - 2], dp[i - 1]
        for (int i = 0; i < s.length(); ++i) {
            if (s[i] == '0') {
                curr = 0; // dp[i - 1] = 0
            }

            if (i == 0 || !(s[i - 1] == '1' || (s[i - 1] == '2' && s[i] <= '6'))) {
                prev = 0;   // dp[i - 2] = 0
            }

            int temp = curr;
            curr += prev;   // dp[i] = dp[i - 1] + dp[i - 2]
            prev = temp;
        }

        return curr;
    }
};