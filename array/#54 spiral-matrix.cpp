// Time:  O(m * n)
// Space: O(1)

class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        vector<int> ans;

        // attention
        if (matrix.empty())
            return ans;
        
        int m = matrix.size(), n = matrix[0].size();
        
        for (int left = 0, right = n - 1, top = 0, down = m - 1;
             left <= right && top <= down;
             ++left, --right, ++top, --down) {
            
            for (int col = left; col <= right; ++col)
                ans.emplace_back(matrix[top][col]);
            
            for (int row = top + 1; row < down; ++row)
                ans.emplace_back(matrix[row][right]);
            
            for (int col = right; col >= left && top < down; --col)
                ans.emplace_back(matrix[down][col]);
            
            for (int row = down - 1; row > top && left < right; --row)
                ans.emplace_back(matrix[row][left]);
        
        }

        return ans;
    }
};