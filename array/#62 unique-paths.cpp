// Time:  O(m * n)
// Space: O(m * n)
// recursive

class Solution {
public:
    unordered_map<int, unordered_map<int, int>> lookup;
    int uniquePaths(int m, int n) {
        if (m == 0 || n == 0)
            return 0;
        
        if (m == 1 || n == 1)
            return 1;
        
        if (lookup.find(m) != lookup.end() && lookup[m].find(n) != lookup[m].end())
            return lookup[m][n];
        
        return lookup[m][n] = uniquePaths(m - 1, n) + uniquePaths(m, n - 1);
    }
};



// Time:  O(m * n)
// Space: O(m * n)
// dp

class Solution {
public:
    int uniquePaths(int m, int n) {
        int dp[m][n];

        for (int i = 0; i < m; ++i)
            dp[i][0] = 1;
        for (int j = 0; j < n; ++j)
            dp[0][j] = 1;
        for (int i = 1; i < m; ++i) {
            for (int j = 1; j < n; ++j)
                dp[i][j] = dp[i - 1][j] + dp[i][j - 1];
        }

        return dp[m - 1][n - 1];
    }
};



// Time:  O(m * n)
// Space: O(n)
// dp

class Solution {
public:
    int uniquePaths(int m, int n) {
        vector<int> dp(n, 1);

        for (int i = 1; i < m; ++i) {
            for (int j = 1; j < n; ++j)
                dp[j] += dp[j - 1];
        }

        return dp[n - 1];
    }
};