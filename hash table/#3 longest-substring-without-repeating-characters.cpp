// Time:  O(n)
// Space: O(1)
// sliding window & double pointer

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        unordered_map<char, int> lookup;
        int ans = 0;

        for (int left = 0, right = 0; right < s.length(); ++right) {
            if (lookup.count(s[right])) {
                // when find the repeated char in lookup, left should move to the next char
                left = max(left, lookup[s[right]] + 1);
            }

            lookup[s[right]] = right;   // char : idx
            ans = max(ans, right - left + 1);
        }

        return ans;
    }
};