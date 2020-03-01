// Time:  O(m * n)
// Space: O(n)
// dp

class Solution {
public:
    int maximalRectangle(vector<vector<char>>& matrix) {
        // attention
        if (matrix.empty() || matrix[0].empty())
            return 0;

        int m = matrix.size();
        int n = matrix[0].size();
        int ans = 0;
        vector<int> H(n, 0);  // height of all ones rectangle include matrix[i][j]
        vector<int> L(n, 0);  // left closed bound of all ones rectangle include matrix[i][j]
        vector<int> R(n, n);  // right open bound of all ones rectangle include matrix[i][j]

        for (int i = 0; i < m; ++i) {
            int left = 0, right = n;

            for (int j = 0; j < n; ++j) {
                if (matrix[i][j] == '1') {
                    ++H[j]; // update height
                    L[j] = max(L[j], left); // update left bound
                }
                else {
                    left = j + 1;
                    H[j] = L[j] = 0;
                }
            }

            for (int j = n - 1; j >= 0; --j) {
                if(matrix[i][j] == '1') {
                    R[j] = min(R[j], right);    // update right bound
                    ans = max(ans, H[j] * (R[j] - L[j]));
                }
                else
                    right = j;  // is j not j - 1
            }
        }

        return ans;
    }
};



// Time:  O(m * n)
// Space: O(n)
// ascending stack solution

class Solution {
public:
    int maximalRectangle(vector<vector<char>>& matrix) {
        // attention
        if (matrix.empty() || matrix[0].empty())
            return 0;
        
        int m = matrix.size();
        int n = matrix[0].size();
        int ans = 0;
        vector<int> height(n, 0);
        
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j)
                height[j] = (matrix[i][j] == '1') ? height[j] + 1 : 0;
            
            ans = max(ans, largestRectangleArea(height));
        }

        return ans;
    }

private:
    int largestRectangleArea(const vector<int>& height) {
        int max_area = 0;
        stack<int> increasing_height;

        for (int i = 0; i <= height.size(); ) { // should include the condition of i = size
            if (increasing_height.empty() || (i < height.size() && height[i] > height[increasing_height.top()])) {
                increasing_height.emplace(i);   // stk store the index, and need to ascending
                ++i;
            }
            else {
                // max_area = (i - stk[top - 1] - 1) * height[stk[top]]
                auto h = height[increasing_height.top()];
                increasing_height.pop();
                auto left = (increasing_height.empty()) ? -1 : increasing_height.top();
                max_area = max(max_area, h * (i - left - 1));
            }
        }

        return max_area;
    }
};