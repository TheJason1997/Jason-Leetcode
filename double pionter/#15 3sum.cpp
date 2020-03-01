// Time:  O(n^2)
// Space: O(1)
// double pointers: one left(low), one right(high)

class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> ans;
        const int target = 0;

        // make nums in increasing order. Time: O(nlogn)
        sort(nums.begin(), nums.end());

        // attention
        if (nums.size() < 3 || nums[0] > 0 || nums[nums.size() - 1] < 0)
            return ans;

        for (int i = 0; i < nums.size() - 2; ++i) {
            if (i == 0 || nums[i] != nums[i - 1]) { // skip duplicated
                // int lo = i + 1, hi = nums.size() - 1;
                // while (lo < hi)
                for (int lo = i + 1, hi = nums.size() - 1; lo < hi; ) {   // Time: O(n) for each i
                    if (lo - 1 > i && nums[lo] == nums[lo - 1]) // skip duplicated
                        ++lo;
                    else if (hi + 1 < nums.size() && nums[hi] == nums[hi + 1])  // skip duplicated
                        --hi;
                    else {
                        const auto sum = nums[i] + nums[lo] + nums[hi];
                        if (sum > target)   // decrease sum
                            --hi;
                        else if (sum < target)  // increase sum
                            ++lo;
                        else {
                            ans.push_back({nums[i], nums[lo], nums[hi]});
                            ++lo, --hi;
                        }
                    }
                }
            }
        }

        return ans;
    }
};

/**
[-1, 0, 1, 2, -1, -4] →
[-4, -1, -1, 0, 1, 2]
 i   lo            hi
 */