// Time:  O(n)
// Space: O(1)
// double pointer: one slow(before), one fast(after)

class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int curr = -1;
        
        for (const auto& num : nums) {
            if (curr == -1 || nums[curr] != num)
                nums[++curr] = num;
        }

        return curr + 1;
    }
};