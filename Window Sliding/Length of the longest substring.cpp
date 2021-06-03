// Problem Link : https://practice.geeksforgeeks.org/problems/length-of-the-longest-substring3036/1/?category[]=sliding-window&category[]=sliding-window&difficulty[]=1&page=1&sortBy=submissions&query=category[]sliding-windowdifficulty[]1page1sortBysubmissionscategory[]sliding-window
    int longestUniqueSubsttr(string S){
        int mlen = INT_MIN;
        int len = 0;
        int count[256] = {0};
        int st = 0;
        int ed = 0;
        while(ed < S.length()){
            // Increment the length while character at end is 1st time
            if(count[S[ed]] == 0){
                len++;
                count[S[ed]]++;
                ed++;
            }
            mlen = max(len,mlen);
            // If characteer at end was seen befor then we will remove elements from start till we see same element as end indec
            if(ed < S.length() && count[S[ed]] == 1){
                while(st < ed && S[ed] != S[st]){
                    count[S[st]]--;
                    st++;
                    len--;
                }
                ed++;
                st++;
            }
        }
        return mlen;
    }