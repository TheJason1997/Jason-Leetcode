// Time:  O(nlogn)
// Space: O(1)

class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        // attention
        if (intervals.empty())
            return intervals;
        
        sort(intervals.begin(), intervals.end(),
            [&, this](vector<int>& v1, vector<int>& v2) { return v1.front() < v2.front(); });    // lambda function
        
        vector<vector<int> > ans{intervals[0]};
        for (int i = 1; i < intervals.size(); ++i) {
            
            // the end of former interval >= the head of curr interval, then combine
            if (intervals[i].front() <= ans.back().back())
                // combination: max(the end of former interval, the end of curr interval)
                ans.back().back() = max(ans.back().back(), intervals[i].back());
            
            else
                ans.emplace_back(intervals[i]);
        
        }

        return ans;
    }
};