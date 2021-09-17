// Problem Link : https://practice.geeksforgeeks.org/problems/choose-and-swap0531/1#
    string chooseandswap(string a){
        vector<int> left(26,-1); // to store left most index of every element
        int n = a.length();
        // filling left vector
        for(int i = n-1; i >= 0; i--){
            left[a[i]-'a'] = i;
        }
        char first,second; // to store first and second char which i have to replace
        bool found = false; 
        for(int i = 0; i < n; i++){
            // if i had founded my first and second char then i will break the loop
            if(found)
                break;
            // i will search for the smallest element than current one whose left most index is larger than left most index of current char
            // if i found such char then i will set my first,second and mark found as true and break the loop
            for(int j = 0; j < a[i]-'a'; j++){
                if(left[j] > left[a[i]-'a']){
                    first = a[i];
                    second = j+'a';
                    found = true;
                    break;
                }
            }
        }
        string ans = a; // to store answer key
        
        // replace first with second and second with first
        for(int i = 0; i < n; i++){
            if(ans[i] == first)
                ans[i] = second;
            else if(ans[i] == second)
                ans[i] = first;
        }
        return ans; // return answer
    }
