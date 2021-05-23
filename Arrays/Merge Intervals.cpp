//Problem Link : https://leetcode.com/problems/merge-intervals/
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        
        //sorted an array according to 1st element in every row.
        sort(intervals.begin(),intervals.end());
        int n = intervals.size();
        
        vector<vector<int>> ans;//Vector created to store the answers
        vector<int> temp(2);
        temp[0] = intervals[0][0];
        temp[1] = intervals[0][1];
        
        //Add 1st interval in the answer
        ans.push_back(temp);
        int sz = 1;//Variable to trake the size of ans vector
        //Traversing through all other elements
        for(int i = 1; i < intervals.size(); i++){
            //If lower limit of last interval in ans is less or equal to the upper limit of current interrval then we will mearge both intervals
            if(intervals[i][0] <= ans[sz-1][1]){
                ans[sz-1][1] = max(intervals[i][1],ans[sz-1][1]);
            }else{//else simply add that interval as an answer
                temp[0] = intervals[i][0];
                temp[1] = intervals[i][1];
                ans.push_back(temp);
                sz++;
            }
        }
        return ans;
    }
