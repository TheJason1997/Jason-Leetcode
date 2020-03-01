// Time:  O(m * n)
// Space: O(m * n)
// dynamic programming

class Solution {
public:
    bool isMatch(string s, string p) {
        //dp[i][j]: whether the first i of s can be matched by the first j of p
        vector<vector<bool>> dp(s.length() + 1, vector<bool>(p.length() + 1));
        dp[0][0] = true;
        
        for (size_t j = 0; j < p.length(); ++j) {
            if (p[j] == '*')
                dp[0][j + 1] = dp[0][j];
        }

        for (size_t i = 0; i < s.length(); ++i) {
            for (size_t j = 0; j < p.length(); ++j) {
                if (s[i] == p[j] || p[j] == '?')
                    dp[i + 1][j + 1] = dp[i][j];
                
                else if (p[j] == '*')
                    dp[i + 1][j + 1] = dp[i][j + 1] || dp[i + 1][j];
            }
        }

        return dp[s.length()][p.length()];
    }
};