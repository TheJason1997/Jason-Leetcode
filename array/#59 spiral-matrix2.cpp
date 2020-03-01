// Time:  O(n^2)
// Space: O(1)

class Solution {
public:
    vector<vector<int>> generateMatrix(int n) {
        vector<vector<int> > matrix(n, vector<int>(n));

        for (int num = 0, left = 0, right = n - 1, top = 0, down = n - 1;
             left <= right && top <= down;
             ++left, --right, ++top, --down) {
            
            for (int col = left; col <= right; ++col) {
                matrix[top][col] = ++num;
            }

            for (int row = top + 1; row < down; ++row) {
                matrix[row][right] = ++num;
            }

            for (int col = right; col >= left && top < down; --col) {
                matrix[down][col] = ++num;
            }

            for (int row = down - 1; row > top && left < right; --row) {
                matrix[row][left] = ++num;
            }

        }

        return matrix;
    }
};