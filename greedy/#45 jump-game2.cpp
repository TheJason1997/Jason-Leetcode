// Time:  O(n)
// Space: O(1)
// greedy

class Solution {
public:
    int jump(vector<int>& nums) {
        int jump_cnt = 0;
        int reachable = 0, curr_reachable = 0;

        for (int i = 0; i< nums.size(); ++i) {
            if (i > reachable)
                return -1;
            if (i > curr_reachable) {   // update when the index i > curr_reachable
                curr_reachable = reachable;
                jump_cnt += 1;
            }
            reachable = max(reachable, i + nums[i]);
        }

        return jump_cnt;
    }
};