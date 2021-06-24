// Problem Link : https://practice.geeksforgeeks.org/problems/smallest-distant-window3132/1#
    string findSubString(string str)
    {  
        unordered_set<char> dist; // making set to store distinct char
        unordered_map<char,int> window; // making map for track chars in our window
        
        for(int i = 0; i < str.length(); i++){ // adding all element in the set
            dist.insert(str[i]);
        }
        int ans = str.length(); // initially ans will be length of string and we will reduce it

        int j = 0; // to traverse string and points to upcoming element in the window
        while(window.size() < dist.size()){ // creating 1st window who contains all distinct element
            window[str[j++]]++;
        }

        int i = 0; // points to next leaving element in window
        while(j < str.length()){ // traverse through whole string
            if(dist.size() > window.size()){ // if window doesn't contain all distinct element then we will add them
                window[str[j++]]++;
            }else{ // if window contain all distinct elements then update ans if possible and removeing elements from starting of window
                while(i < j && dist.size() == window.size()){
                    ans = min(ans, j-i);
                    window[str[i]]--;
                    if(window[str[i]] == 0){ // if this element is not present in window then removin it
                        window.erase(str[i]);
                    }
                    i++;
                }
            }
        }
        while(i < j && dist.size() == window.size()){ // if j is at the end but still we can remove something from starting of window
            ans = min(ans, j-i);
            window[str[i]]--;
            if(window[str[i]] == 0){
                window.erase(str[i]);
            }
            i++;
        }
        // returning smallens substring who contains all element of string 
        return str.substr(i-1,ans);
    }
