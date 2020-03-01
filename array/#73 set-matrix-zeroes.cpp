// Time:  O(m * n)
// Space: O(1)

class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        // attention
        if (matrix.empty()) {
            return;
        }
        
        // to avoid repeated assignment, use an variable to record whether the first col is tagged
        // use matrix[0][0] to record whether the first row is tagged
        bool col_has_zero = false;
        int m = matrix.size();
        int n = matrix[0].size();

        for (int i = 0; i < m; ++i) {
            // if the element of first col is zero
            if (matrix[i][0] == 0) {
                col_has_zero = true;
            }

            for (int j = 1; j < n; ++j) {   // start from the second col
                // if an element is zero, set the first element of the corresponding row and col to 0
                if (matrix[i][j] == 0) {
                    matrix[i][0] = 0;
                    matrix[0][j] = 0;
                }
            }
        }

        // iterate from the second row and second col again, using the first elemnt of the corresponding row and col
        for (int i = 1; i < m; ++i) {
            for (int j = 1; j < n; ++j) {
                if (matrix[i][0] == 0 || matrix[0][j] == 0) {
                    matrix[i][j] = 0;
                }
            }
        }

        // see if the first row need to be set to zero as well
        if (matrix[0][0] == 0) {
            for (int j = 0; j < n; ++j) {
                matrix[0][j] = 0;
            }
        }

        // see if the first col need to be set to zero as well
        if (col_has_zero) {
            for (int i = 0; i < m; ++i) {
                matrix[i][0] = 0;
            }
        }
    }
};