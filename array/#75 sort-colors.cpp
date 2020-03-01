// Time:  O(n)
// Space: O(1)
// Tri-Partition quick sort(double pointer)

class Solution {
public:
    void sortColors(vector<int>& nums) {
        static const int target = 1;

        for (int i = 0, left = 0, right = nums.size() - 1; i <= right;) {
            if (nums[i] > target) {
                swap(nums[i], nums[right--]);   // if swap right, do not increase i
            }
            else {
                if (nums[i] < target) {
                    swap(nums[left++], nums[i]);
                }
                ++i;    // when left < target, increase i
            }
        }
    }
};