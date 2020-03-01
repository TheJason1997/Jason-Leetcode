// Time:  O(n^3)
// Space: O(1)
// double pointers: one left(low), one right(high)

class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        vector<vector<int>> ans;
        int len = nums.size();

        // make nums in increasing order. Time: O(nlogn)
        sort(nums.begin(), nums.end());

        // attention
        if (len < 4)
            return ans;

        for (int i = 0; i < len - 3; ++i) {
            if (i && nums[i] == nums[i - 1])    // skip duplicated, || → &&, != → ==
                continue;

            for (int j = i + 1; j < len - 2; ++j) {
                if (j == i + 1 || nums[j] != nums[j - 1]) {
                    int lo = j + 1, hi = len - 1;
                    int sum = target - nums[i] - nums[j];

                    while (lo < hi) {
                        if (lo - 1 > j && nums[lo] == nums[lo - 1]) // skip duplicated
                            ++lo;
                        else if (hi + 1 < nums.size() && nums[hi] == nums[hi + 1])  // skip duplicated
                            --hi;
                        else {
                            if (nums[lo] + nums[hi] == sum) {
                                ans.push_back({nums[i], nums[j], nums[lo], nums[hi]});
                                ++lo, --hi;
                            }
                            else if (nums[lo] + nums[hi] < sum)
                                ++lo;
                            else
                                --hi;
                        }
                    }
                }
            }
        }

        return ans;
    }
};



// Time:  O(n^4)
// Space: O(n^2)
// hash table

class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        vector<vector<int>> ans;
        unordered_multimap<int, pair<int, int>> cache;

        // make nums in increasing order. Time: O(nlogn)
        sort(nums.begin(), nums.end());

        // attention
        if (nums.size() < 4)
            return ans;

        // caching
        for (int i = 0; i < nums.size(); ++i) {
            for (int j = i + 1; j < nums.size(); ++j)
                cache.emplace(nums[i] + nums[j], make_pair(i, j));
        }
        
        // matching
        for (auto i = cache.begin(); i != cache.end(); ++i) {
            auto a = i->second.first;
            auto b = i->second.second;

            auto range = cache.equal_range(target - i->first);  // find the matching result, return the idex of iterator
            for(auto j = range.first; j != range.second; ++j) {
                auto c = j->second.first;
                auto d = j->second.second;
                if (b < c)  // need to examine
                    ans.push_back({nums[a], nums[b], nums[c], nums[d]});
            }
        }

        sort(ans.begin(), ans.end());   // before duplicated, sort first
        ans.erase(unique(ans.begin(), ans.end()), ans.end());
        // unique() emplace all repeated elements in the end of vector, and return the iterator of 1st repeated element,
        // then use erase() to erase all repeated elements from 1st to the end

        return ans;
    }
};