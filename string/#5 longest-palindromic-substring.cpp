// Time:  O(n)
// Space: O(n)
// Manacher's Algorithm

class Solution {
public:
    string longestPalindrome(string s) {
        string T = preProcess(s);   // insert "#"
        
        const int n = T.length();
        vector<int> L(n);

        int C = 0, R = 0;   // initialize center and end(left/right) position
        for (int i = 1; i < n - 1; ++i) {
            int i_mirror = 2 * C - i;   // i' = C - (i - C)

            L[i] = (R > i) ? min(R - i, L[i_mirror]) : 0;

            // attempt to expand palindrome centered at i
            while (T[i + 1 + L[i]] == T[i - 1 - L[i]]) {
                ++L[i];
            }

            // If palindrome centered at i expands the past R,
            // adjust center based on expanded palindrome
            if (i + L[i] > R) {
                C = i;
                R = i + L[i];
            }
        }

        // find the maximum element in L
        int max_i = 0;
        for (int i = 1; i < n - 1; ++i) {
            if (L[i] > L[max_i])
                max_i = i;
        }

        return s.substr((max_i - L[max_i]) / 2, L[max_i]);
    }

private:
    string preProcess(const string& s) {
        if (s.empty())
            return "^$";
        
        string T = "^";
        for (int i = 0; i < s.length(); ++i)
            T += "#" + s.substr(i, 1);
        T += "#$";

        return T;
    }
};