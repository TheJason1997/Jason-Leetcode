// Time: O(n)
// Space: O(n)
// dp

class Solution {
public:
    int climbStairs(int n) {
        // attention
        if (n == 1)
            return 1;
        
        vector<int> dp(n + 1);  // need to expand 1
        dp[1] = 1;  // dp[0] = 0
        dp[2] = 2;

        for (int i = 3; i <= n; ++i)    // start from 3, and end at n
            dp[i] = dp[i - 1] + dp[i - 2];
        
        return dp[n];
    }
};



// Time: O(logn)
// Space: O(1)
// fibonacci formula(find the nth fib number)

class Solution {
public:
    int climbStairs(int n) {
        double sqrt5 = sqrt(5);
        
        double fib_num = (pow((1 + sqrt5) / 2, n + 1) - pow((1 - sqrt5) / 2, n + 1)) / sqrt5;

        return (int) (fib_num);
    }
};