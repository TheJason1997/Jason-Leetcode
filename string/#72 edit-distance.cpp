// Time: O(mn)
// Space: O(mn)
// dp

class Solution {
public:
    int minDistance(string word1, string word2) {
        int m = word1.length();
        int n = word2.length();
        int dp[m + 1][n + 1];

        // attention: if one word is empty
        if (n * m == 0)
            return (n + m);
        
        // initialize boundaries
        for (int i = 0; i < m + 1; ++i)
            dp[i][0] = i;
        for (int j = 0; j < n + 1; ++j)
            dp[0][j] = j;

        for (int i = 1; i < m + 1; ++i) {
            for (int j = 1; j < n + 1; ++j) {
                int insert  = dp[i][j - 1] + 1;
                int remove  = dp[i - 1][j] + 1;
                int replace = dp[i - 1][j - 1];
                if (word1[i - 1] != word2[j - 1])
                    replace += 1;
                
                dp[i][j] = min(replace, min(insert, remove));
            }
        }

        return dp[m][n];
    }
};