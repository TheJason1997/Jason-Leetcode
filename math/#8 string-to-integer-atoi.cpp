// Time:  O(n)
// Space: O(1)

class Solution {
public:
    int myAtoi(string str) {
        // attention
        if (str.empty()) {
            return 0;
        }

        int i = 0;
        int ans = 0;
        int sign = 1;
        int max = numeric_limits<int>::max();
        int min = numeric_limits<int>::min();

        // skip blankspace
        while (str[i] == ' ' || str[i] == '\t') {
            ++i;
        }

        if (i == str.length()) {
            return 0;
        }

        // parse sign
        if (str[i] == '+') {
            ++i;
        }
        else if (str[i] == '-') {
            sign = -1;
            ++i;
        }

        // compute integer
        for (; i < str.length() && isdigit(str[i]); ++i) {  // need to examine whether the str is decimal digit rather word
            // overflow situation
            if (ans > (max - (str[i] - '0')) / 10) {    // ans * 10 + pop > max (from #7), pop = str[i] - '0'
                return sign > 0 ? max : min;
            }

            ans = ans * 10 + (str[i] - '0');
        }
        ans *= sign;

        return ans;
    }
};