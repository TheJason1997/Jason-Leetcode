// Time:  O(logm + logn)
// Space: O(1)
// binary search

class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        // attention
        if (matrix.empty()) {
            return false;
        }

        // treat matrix as 1d array
        const int m = matrix.size();
        const int n = matrix[0].size();
        int left = 0, right = m * n - 1;

        // binary search: row = idx / n, col = idx % n (idx: the idex of 1d array)
        while (left <= right) {
            auto mid = (left + right) >> 1;
            auto pivot = matrix[mid / n][mid % n];
            
            if (pivot > target) {
                right = mid - 1;
            }
            else if (pivot < target) {
                left = mid + 1;
            }
            else {
                return true;
            }
        }

        return false;
    }
};