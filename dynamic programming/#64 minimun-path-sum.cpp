// Time: O(mn)
// Space: O(mn)
// dp

class Solution {
public:
    int minPathSum(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        vector<vector<int> > dp(m, vector<int>(n));

        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                
                if (i == 0 && j == 0)
                    dp[i][j] = grid[i][j];
                else if (i == 0)
                    dp[i][j] += dp[i][j - 1];
                else if (j == 0)
                    dp[i][j] += dp[i - 1][j];
                else
                    dp[i][j] += min(dp[i][j - 1], dp[i - 1][j]);

            }
        }

        return dp[m - 1][n - 1];
    }
};



// Time: O(mn)
// Space: O(1)
// dp

class Solution {
public:
    int minPathSum(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();

        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                
                if (i == 0 && j != 0)
                    grid[i][j] += grid[i][j - 1];
                else if (i != 0 && j == 0)
                    grid[i][j] += grid[i - 1][j];
                else if (i != 0 && j != 0)
                    grid[i][j] += min(grid[i][j - 1], grid[i - 1][j]);

            }
        }

        return grid[m - 1][n - 1];
    }
};