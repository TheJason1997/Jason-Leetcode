// Time: O(n!)
// Space: O(1)
// back tracking, dfs
// each element could be chosen repeatedly

class Solution {
public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>> ans;
        vector<int> res;

        sort(candidates.begin(), candidates.end()); // make the array sorted

        backTrack(candidates, target, 0, res, ans);

        return ans;
    }

private:
    void backTrack(vector<int>& candidates, int gap, int begin, vector<int>& res, vector<vector<int>>& ans) {
        if (gap == 0) { // satisfy the ending condition
            ans.push_back(res);
            return;
        }

        for (int i = begin; i < candidates.size(); ++i) {   // selections
            if (gap < candidates[i])    // pruning(small ending condition)
                return;
            
            res.push_back(candidates[i]);   // select
            backTrack(candidates, gap - candidates[i], i, res, ans);
            res.pop_back(); // deselect
        }
    }
};