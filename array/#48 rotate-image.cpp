// Time:  O(n^2)
// Space: O(1)

class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        const int n = matrix.size();

        for (int i = 0; i < n / 2; ++i) {
            for (int j = i; j < n - 1 - i; ++j) {
                const auto tmp = matrix[i][j];
                matrix[i][j] = matrix[n - 1 - j][i];
                matrix[n - 1 - j][i] = matrix[n - 1 - i][n - 1 - j];
                matrix[n - 1 - i][n - 1 - j] = matrix[j][n - 1 - i];
                matrix[j][n - 1 - i] = tmp;
            }
        }
    }
};

/**
 * 1 2 3     7 2 1     7 4 1
 * 4 5 6  →  4 5 6  →  8 5 2
 * 7 8 9     9 8 3     9 6 3
 */


class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        const int n = matrix.size();
        
        // transpose matrix
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n - i; ++j) {
                swap(matrix[i][j], matrix[n - 1 - j][n - 1 - i]);
            }
        }
        
        // Horizontal mirror
        for (int i = 0; i < n / 2; ++i) {
            for (int j = 0; j < n; ++j) {
                swap(matrix[i][j], matrix[n - 1 - i][j]);
            }
        }  
    }
};