// Problem Link : https://practice.geeksforgeeks.org/problems/subsets-1587115621/1#
    
    vector<string> ans; // to store answer
    unordered_set<string> st; // to avoid duplicates 
    
    void solve(vector<int> arr, int n, string current){
        if(n == 0){ // if we have processed whole arr then add that in ans and return that
            if(st.count(current) == 0){ // if current subset is not present then and only then we will add that
                st.insert(current);
                ans.push_back(current);
            }
            return;
        }
        
        solve(arr,n-1,current); // case 1 : current element will not appear in subset
        solve(arr,n-1,current+to_string(arr[n-1])); // case 2 : current element will appear in subset
    }
    vector<vector<int> > AllSubsets(vector<int> arr, int n)
    {
        // clearing global variables
        ans.clear();
        st.clear();
        
        sort(arr.begin(),arr.end(),greater<int>()); // sorting array to get desired order
        
        solve(arr,n,"");
        
        sort(ans.begin(),ans.end()); // sorting ans to get desired order
        
        vector<vector<int>> answer; // to convert string to vector of int.
        // we can do this method because 1 <= arr[i] <= 9
        for(int i = 0; i < ans.size(); i++){
            vector<int> temp;
            for(int j = 0; j < ans[i].length(); j++){
                temp.push_back(ans[i][j]-'0');
            }
            answer.push_back(temp);
        }
        return answer;
    }
