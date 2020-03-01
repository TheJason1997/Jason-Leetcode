// Time:  O(n^4)
// Space: O(n^3)
// dp

class Solution {
public:
    bool isScramble(string s1, string s2) {
        // attention
        if (s1.length() == 0 || s2.length() == 0 || s1.length() != s2.length()) {
            return false;
        }
        if (s1 == s2) 
            return true;

        int N = s1.length();
        vector<vector<vector<bool> > > dp(N + 1, vector<vector<bool> >(N, vector<bool>(N, false)));
        // dp[len][i][j]: whether s1[i, i + len) and s2[j, j + len) satisfy the condition
        // in other words, the len of s2 from i ---> the len of s2 from j

        for (int i = 0; i < N; ++i) {
            for (int j = 0; j < N; ++j) {
                dp[1][i][j] = (s1[i] == s2[j]);
            }
        }
        
        for (int len = 2; len <= N; ++len) {
            for (int i = 0; i < N && i + len - 1 < N; ++i) {
                for (int j = 0; j < N && j + len - 1 < N; ++j) {
                    for (int k = 1; k < len; ++k) {
                        // the left of s1 ---> the left of s2 && the right of s1 ---> the right of s2
                        if (dp[k][i][j] && dp[len - k][i + k][j + k]) {
                            dp[len][i][j] = true; 
                            break;
                        }
                        // the right of s1 ---> the left of s2 && the left of s1 ---> the right of s2
                        if (dp[k][i][j + len - k] && dp[len - k][i + k][j]) {
                            dp[len][i][j] = true;
                            break;
                        
                        }
                    }
                }
            }
        }
        
        return dp[N][0][0];
    }
};



// Time:  O(n)
// Space: O(n)
// recursive

class Solution {
public:
    bool isScramble(string s1, string s2) {
        // attention
        if (s1.length() == 0 || s2.length() == 0 || s1.length() != s2.length()) {
            return false;
        }
        if (s1 == s2) 
            return true;
        
        int n = s1.length();
        int memo[26] = {0};
        
        for (int i = 0; i < n; ++i) {
           ++memo[s1[i] - 'a'];
           --memo[s2[i] - 'a'];
        }
        
        for (int i = 0; i < 26; ++i) {
           if (memo[i] != 0) 
               return false;
        }
        
        for (int i = 1; i < n; ++i) {
           if ((isScramble(s1.substr(0, i), s2.substr(0, i)) && isScramble(s1.substr(i), s2.substr(i))) || 
               (isScramble(s1.substr(0, i), s2.substr(n - i)) && isScramble(s1.substr(i), s2.substr(0, n - i)))) {
               return true;
           }
        }

        return false;
    }
};