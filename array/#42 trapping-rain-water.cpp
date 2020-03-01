// Time:  O(n)
// Space: O(1)
// double pointer

class Solution {
public:
    int trap(vector<int>& height) {
        // attention
        if (height.empty())
            return 0;

        int i = 0, j = height.size() - 1;
        int left  = height[0];
        int right = height[height.size() - 1];
        int vol = 0;
        
        while (i < j) {
            if (left < right) {
                ++i;
                vol += max(0, left - height[i]);  // trap water
                left = max(left, height[i]);    // update current max height from left
            }

            else {
                --j;
                vol += max(0, right - height[j]);    // trap water
                right = max(right, height[j]);     // update current max height from right
            }
        }

        return vol;
    }
};