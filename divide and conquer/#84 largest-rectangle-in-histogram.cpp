// Time:  O(n)
// Space: O(n)
// ascending stack solution

class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        int max_area = 0;
        stack<int> increasing_height;

        for (int i = 0; i <= heights.size(); ) { // should include the condition of i = size
            if (increasing_height.empty() || (i < heights.size() && heights[i] > heights[increasing_height.top()])) {
                increasing_height.emplace(i);   // stk store the index until descending
                ++i;
            }
            else {
                // max_area = (i - stk[top - 1] - 1) * heights[stk[top]]
                auto h = heights[increasing_height.top()];
                increasing_height.pop();
                auto left = (increasing_height.empty()) ? -1 : increasing_height.top();
                max_area = max(max_area, h * (i - left - 1));
            }
        }

        return max_area;
    }
};



// Time:  average-O(nlogn)
//        worst-O(n^2), if the vector is sorted
// Space: O(n), recursion needs O(n)
// divide and conquer

class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        return calculateArea(heights, 0, heights.size() - 1);
    }

private:
    int calculateArea(vector<int>& heights, int start, int end) {
        // attention
        if (start > end) {
            return 0;
        }

        // find the index of the smallest element in histogram
        int minIdx = start;
        for (int i = minIdx; i <= end; ++i) {
            if (heights[minIdx] > heights[i]) {
                minIdx = i;
            }
        }

        return max(heights[minIdx] * (end - start + 1),
                   max(calculateArea(heights, start, minIdx - 1), calculateArea(heights, minIdx + 1, end)));
    }
};