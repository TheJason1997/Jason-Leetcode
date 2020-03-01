// Time:  O(n)
// Space: O(1)

class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
        vector<vector<int> > ans;

        // attention
        if (intervals.empty()) {
            ans.emplace_back(newInterval);
            return ans;
        }
        
        // insert intervals appeared before newInterval(no overlap)
        size_t i = 0;
        while (i < intervals.size() && newInterval.front() > intervals[i].back()) {
            ans.emplace_back(intervals[i++]);
        }
        
        // merge intervals that overlap with newInterval
        while (i < intervals.size() && newInterval.back() >= intervals[i].front()) {
            // the combination condition from #56:
            // the end of former interval >= the head of curr interval, then combine
            newInterval = {min(newInterval.front(), intervals[i].front()), 
                           max(newInterval.back(), intervals[i].back())};
            ++i;
        }
        ans.emplace_back(newInterval);  // merge before insert

        // insert intervals appearing after newInterval
        ans.insert(ans.end(), intervals.cbegin() + i, intervals.cend());

        return ans;
    }
};