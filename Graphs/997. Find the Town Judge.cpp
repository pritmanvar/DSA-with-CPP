// Problem Link : https://leetcode.com/problems/find-the-town-judge/

/*****************************Approch*****************************

The possible judge can be the integer who don't trusts on anybody.
There are 3 possible cases : 
    case 1: there is only one element who don't trust on anybody.
            In this case this element can be possible judge but still we have to check it.
    case 2: there is more than one elements who don't trusts on anybody.
            In this case town doesn't have any judge because of we consider one of the element as judge then it will violate 2nd condition that because there is a person who don't trusts on anyone.
    case 3: Town doesn't contain any person who don't trusts on anybody.
            In this case also town doesn't contain any judge because we can't found any person who can full fill 1st condition.

*/
class Solution {
public:
    int findJudge(int n, vector<vector<int>>& trust) {
        unordered_set<int> st; // it will store integers who trusts on someone.
        int size = trust.size();
        
        for(int i = 0; i < size; i++){
            st.insert(trust[i][0]);
        }
        
        int judge = -1;
        for(int i = 1; i <= n; i++){
            if(judge == -1 && st.count(i) == 0) // case : 1
                judge = i;
            else if(judge > 0 && st.count(i) == 0) // case : 2
                return -1;
        }
        if(judge == -1) // case : 3
            return -1;
        
        // check that possible judge is actual judge or not.
        // if we are at this point that means we have only one possible judge
        // and that's why our set must contain every element except possible judge.
        for(int i = 0; i < size; i++){
            if(trust[i][1] == judge) // if person x trusts on possible judge then we will remove that from set.
                st.erase(trust[i][0]);
        }
        
        // now our set will contain person who don't trusts on possible judge
        // so if there is any element present in our set then answer will be -1 else out possible judge is an actual judge.
        return st.empty() ? judge : -1;
    }
};
