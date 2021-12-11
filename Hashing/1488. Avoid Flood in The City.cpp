// Problem Link : https://leetcode.com/problems/avoid-flood-in-the-city/
class Solution {
public:
    vector<int> avoidFlood(vector<int>& rains) {
        int n = rains.size();
        unordered_map<int,int> full; // to store full lakes, day when it got fulled.
        set<int> zeros; // will store index of zeros.
        vector<int> ans(n);
        
        for(int i = 0; i < n; i++){
            if(rains[i] != 0){
                ans[i] = -1; // if there is a rain at ith day then we can't dry any lake.
                
                // current lake is already full.
                if(full.count(rains[i]) == 1){
                    int last_rain = full[rains[i]]; // day when it get fulled.
                    
                    auto it = zeros.upper_bound(full[rains[i]]); // day after the last_rain day when there is no rain.
                    
                    // if that kind of day is not exist then will return empty vector.
                    if(it == zeros.end()){
                        return {};
                    }else{ // else we will dry current lake at *it day.
                        ans[*it] = rains[i];
                        zeros.erase(it);
                    }
                }
                full[rains[i]] = i; // now again lake will be fulled
            }else{
                zeros.insert(i); // insert new zero
            }
        }
        for(int i = 0; i < n; i++){
            if(ans[i] == 0)
                ans[i] = 1;
        }
        return ans;
    }
};
