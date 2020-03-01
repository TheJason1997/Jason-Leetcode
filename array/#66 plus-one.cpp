// Time:  O(n)
// Space: O(1)

class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        for (int idx = digits.size() - 1; idx >= 0; --idx) {
            if (digits[idx] == 9) {
                digits[idx] = 0;
            }

            else {
                ++digits[idx];
                return digits;
            }
        }
        digits[0] = 1;
        digits.emplace_back(0);

        return digits;
    }
};