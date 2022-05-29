// Problem Link : https://leetcode.com/problems/max-value-of-equation/
class Solution {
public:
    // to my answer can be effected by Yj - Xj. so pq is sorted on base of Yj - Xj for points before i.
    struct comparePoints {
        bool operator()(vector<int>& p1, vector<int>& p2)
        {
            // return "true" if "p1" is ordered
            // before "p2", for example:
            return p1[1]-p1[0] < p2[1]-p2[0]; 
        }
    };
    int findMaxValueOfEquation(vector<vector<int>>& points, int k) {
        int ans = INT_MIN;
        
        priority_queue<vector<int>,vector<vector<int>>,comparePoints> pq; 
        pq.push(points[0]);
        
        for(int i = 1; i < points.size(); i++){
            // top of pq is not valid for current i
            // if it is not valid for i then it can't be valid for i+1 (reason : sorted order) so I can remove that from pq
            while(pq.size() > 0 && points[i][0] - pq.top()[0] > k) 
                pq.pop();
            
            if(pq.size() > 0){ // calculate answer
                ans = max(ans, points[i][1] + pq.top()[1] + points[i][0] - pq.top()[0]);
            }
            pq.push(points[i]);
        }
        return ans;
    }
};
