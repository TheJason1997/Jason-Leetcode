// Time: O(m * n)
// Space: O(m + n)
// dp

class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        const int m = obstacleGrid.size();
        const int n = obstacleGrid[0].size();
        vector<long long> dp(n, 0); // avoid overflow

        dp[0] = 1;
        for (int i = 0; i < m; ++i) {
            if (obstacleGrid[i][0] != 0)
                dp[0] = 0;
            
            for (int j = 1; j < n; ++j) {   // column start at 1
                if (obstacleGrid[i][j] == 0)
                    dp[j] += dp[j - 1];
                else
                    dp[j] = 0;
            }
        }

        return dp[n - 1];
    }
};