// Time:  O(n) / O(n+k), k is the number of buckets
// Space: O(1)
// bucket sort(stable)

class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        bucketSort(nums);
        
        for (int i = 0; i < nums.size(); ++i) {
            if (nums[i] != i + 1)   // after sorting, traverse from the beginning, and find the discordant one
                return i + 1;
        }

        return nums.size() + 1;
    }

private:
    void bucketSort(vector<int>& nums) {
        for (int i = 0; i < nums.size(); ++i) {
            while (nums[i] > 0 && nums[i] <= nums.size() && nums[i] != nums[nums[i]-1]) {
                swap(nums[i], nums[nums[i]-1]);
            }
        }
    }
};

/**
 * [3, 4, -1, 1] [-1, 4, 3, 1] [-1, 1, 3, 4] [1, -1, 3, 4]
 * stop sorting, -1 can be exchanged the position if exists 2, so it is the dicordant one
 * 
 * Pigeonhole principle
 * 抽屉原理的一般含义为：“如果每个抽屉代表一个集合，每一个苹果就可以代表一个元素，假如有 n + 1 个元素放到 n 个集合中去，
 * 其中必定有一个集合里至少有两个元素。” 抽屉原理有时也被称为鸽巢原理。它是组合数学中一个重要的原理。
 * /