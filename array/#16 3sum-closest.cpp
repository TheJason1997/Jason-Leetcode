// Time:  O(n^2)
// Space: O(1)
// double pointers: one left(low), one right(high)

class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        int ans  = numeric_limits<int>::max();
        int diff = numeric_limits<int>::max();

        // make nums in increasing order. Time: O(nlogn)
        sort(nums.begin(), nums.end());

        for (int i = 0; i < nums.size() - 2; ++i) {
            if (i == 0 || nums[i] != nums[i - 1]) { // skip duplicated
                int lo = i + 1, hi = nums.size() - 1;

                while (lo < hi) {
                    const auto sum = nums[i] + nums[lo] + nums[hi];

                    if (sum < target)
                        ++lo;
                    else if (sum > target)
                        --hi;
                    else
                        return target;
                    
                    if (abs(sum - target) < diff) {
                        diff = abs(sum - target);
                        ans = sum;
                    }
                }
            }
        }

        return ans;
    }
};