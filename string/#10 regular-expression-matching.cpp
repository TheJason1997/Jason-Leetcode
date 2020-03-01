// Time:  O(m * n)
// Space: O(m * n)
// dynamic programming

class Solution {
public:
    bool isMatch(string s, string p) {
        //dp[i][j]: whether the first i of s can be matched by the first j of p
        vector<vector<bool>> dp(s.size() + 1, vector<bool>(p.size() + 1));
        dp[0][0] = true;
        
        // whether the first 0 of s can be matched by the first j of p
        for (size_t j = 1; j < p.size(); ++j) {
            if (p[j] == '*')
                dp[0][j + 1] = dp[0][j - 1];
        }

        for (size_t i = 0; i < s.size(); ++i) {
            for (size_t j = 0; j < p.size(); ++j) {
                if (s[i] == p[j] || p[j] == '.')    // element matching or match any single character
                    dp[i + 1][j + 1] = dp[i][j];
                
                else if (p[j] == '*' && j > 0) {    // match zero or more of the preceding element
                    if (s[i] != p[j - 1] && p[j - 1] != '.')    // not former element matching and match any single character
                        dp[i + 1][j + 1] = dp[i + 1][j - 1];

                    else
                        dp[i + 1][j + 1] = dp[i][j + 1] || dp[i + 1][j] || dp[i + 1][j - 1];
                    /**
                     * dp[i][j] = dp[i-1][j]: multi char match
                     * dp[i][j] = dp[i][j-1]: single char match
                     * dp[i][j] = dp[i][j-2]: no match
                     */
                }
            }
        }

        return dp[s.size()][p.size()];
    }
};