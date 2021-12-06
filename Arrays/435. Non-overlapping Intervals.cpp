// Problem Link : https://leetcode.com/problems/non-overlapping-intervals/

class Solution {
public:
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        int ans = 0;
        
        sort(intervals.begin(),intervals.end()); // sort intervals
        vector<int> last = intervals[0];
        
        for(int i = 1; i < intervals.size(); i++){
            if(intervals[i][0] < last[1]){ // two intervals are overlaping
                // if end time of current interval is smaller than last one then i will remove last interval else i will remove current interval
                if(intervals[i][1] <= last[1]) 
                    last = intervals[i];
                ans++;
            }else{
                last = intervals[i];
            }
        }
        return ans;
    }
};
