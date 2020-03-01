// Time: O(n * 2^n)
// Space: O(1)
// back tracking

class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int> > ans(1);
        sort(nums.begin(), nums.end());

        for (size_t i = 0; i < nums.size(); ++i) {
            const size_t size = ans.size();

            for (size_t j = 0; j < size; ++j) {
                ans.emplace_back(ans[j]);
                ans.back().emplace_back(nums[i]);
            }
        }

        return ans;
    }
};