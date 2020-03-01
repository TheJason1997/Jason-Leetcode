// Time:  O(logn)
// Space: O(1)
// binary search

class Solution {
public:
    int search(vector<int>& nums, int target) {
        int left = 0, right = nums.size() - 1;

        while (left <= right) { // need to consider the equal situation
            int mid = (left + right) >> 1;

            if (nums[mid] == target)
                return mid;
            else if (nums[mid] < nums[right]) { // the right half is sorted
                if (nums[mid] < target && target <= nums[right])
                    left = mid + 1;
                else
                    right = mid - 1;
            }
            else {  // the left half is sorted
                if (nums[mid] > target && target >= nums[left])
                    right = mid - 1;
                else
                    left = mid + 1;
            }
        }

        return -1;
    }
};

/**
 * 如果中间的数小于最右边的数，则右半段是有序的，若中间数大于最右边数，则左半段是有序的
 * 只要在有序的半段里用首尾两个数组来判断目标值是否在这一区域内，这样就可以确定保留哪半边
 * /