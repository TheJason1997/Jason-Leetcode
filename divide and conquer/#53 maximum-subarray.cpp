// Time:  O(n)
// Space: O(1)
// dynamic programming

class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int ans  = numeric_limits<int>::min();
        int curr = numeric_limits<int>::min();

        for (const auto& num : nums) {
            curr = (curr == numeric_limits<int>::min()) ? num : max(curr + num, num);
            ans = max(ans, curr);
        }

        return ans;
    }
};

/**
 * nums: 2 3 -6 2 4
 * curr: 2 5 -1 2 6
 */



// Time:  O(nlogn)
// Space: O(logn)
// divide and conquer

class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int ans = numeric_limits<int>::min();

        ans = maxSubArrayHelper(nums, 0, nums.size() - 1);

        return ans;
    }

private:
    int maxSubArrayHelper(vector<int>& nums, int left, int right) {
        if (left == right)
            return nums[left];
        
        int mid = (right + left) >> 1;
        int leftSum  = maxSubArrayHelper(nums, left, mid);
        int rightSum = maxSubArrayHelper(nums, mid + 1, right);
        int midSum   = maxSubArrayCross(nums, left, mid, right);

        int ans = max(leftSum, rightSum);
        ans = max(ans, midSum);

        return ans; 
    }

    int maxSubArrayCross(vector<int>& nums, int left, int mid, int right) {
        int leftSum  = numeric_limits<int>::min();
        int rightSum = numeric_limits<int>::min();
        int sumLeft = 0, sumRight = 0;

        for (int i = mid; i >= left; --i) {
            sumLeft += nums[i];
            leftSum = max(leftSum, sumLeft);
        }

        for (int i = mid + 1; i <= right; ++i) {
            sumRight += nums[i];
            rightSum = max(rightSum, sumRight);
        }

        return (leftSum + rightSum);
    }
};