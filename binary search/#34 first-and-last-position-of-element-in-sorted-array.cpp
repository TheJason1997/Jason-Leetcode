// Time:  O(logn)
// Space: O(1)
// binary search

class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        const auto begin = lower_bound(nums, target);
        const auto end   = upper_bound(nums, target);

        if (begin < nums.size() && nums[begin] == target)
            return {begin, end - 1};
        
        return {-1, -1};
    }

private:
    int lower_bound(vector<int>& nums, int target) {
        int left = 0, right = nums.size() - 1;

        while (left <= right) {
            const auto mid = (left + right) >> 1;
            if (nums[mid] >= target)
                right = mid - 1;
            else
                left = mid + 1;
        }

        return left;
    }

    int upper_bound(vector<int>& nums, int target) {
        int left = 0, right = nums.size() - 1;

        while (left <= right) {
            const auto mid = (left + right) >> 1;
            if (nums[mid] > target)
                right = mid - 1;
            else
                left = mid + 1;
        }

        return left;
    }
};



// simple version

class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        const auto begin = lower_bound(nums.cbegin(), nums.cend(), target);
        const auto end   = upper_bound(nums.cbegin(), nums.cend(), target);

        if (begin != nums.cend() && *begin == target)
            return {begin - nums.cbegin(), end - nums.cbegin() - 1};
        
        return {-1, -1};
    }
};