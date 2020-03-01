// Time:  O(n)
// Space: O(1)

class Solution {
public:
    int romanToInt(string s) {
        unordered_map<char, int> roman_map = {{'I', 1}, {'V', 5}, {'X', 10}, {'L', 50},
                                              {'C', 100}, {'D', 500}, {'M', 1000}};
        
        int ans = 0;
        for (int i = 0; i < s.length(); ++i) {
            if (i > 0 && roman_map[s[i]] > roman_map[s[i - 1]]) {
                // new_ans = last_ans + roman_map[s[i]] - 2 * roman_map[s[i - 1]]
                // or can use an tmp to store the last num
                ans += roman_map[s[i]] - 2 * roman_map[s[i - 1]];
            }
            else {
                ans += roman_map[s[i]];
            }
        }

        return ans;
    }
};


class Solution {
public:
    int romanToInt(string s) {
        unordered_map<char, int> roman_map = {{'I', 1}, {'V', 5}, {'X', 10}, {'L', 50},
                                              {'C', 100}, {'D', 500}, {'M', 1000}};
        
        int ans = 0;
        int prev_num = roman_map[s[0]];
        for (int i = 1; i < s.length(); ++i) {
            int curr_num = roman_map[s[i]];
            if (curr_num > prev_num) {
                ans -= prev_num;
            }
            else {
                ans += prev_num;
            }
            prev_num = curr_num;    // update
        }
        ans += prev_num;

        return ans;
    }
};