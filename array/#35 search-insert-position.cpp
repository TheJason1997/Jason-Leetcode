// Time:  O(logn)
// Space: O(1)
// binary search: just itself !!!

class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        int left = 0, right = nums.size() - 1;

        while (left <= right) {
            const auto mid = (left + right) >> 1;

            if (nums[mid] >= target) // lower_bound
                right = mid - 1;
            else
                left = mid + 1;
        }

        return left;
    }
};