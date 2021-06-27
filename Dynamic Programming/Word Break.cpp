// Problem Link : https://practice.geeksforgeeks.org/problems/word-break1352/1
int wordBreak(string A, vector<string> &B) {
    int n=B.size();
    
    set<string> mp;
    // adding all words in map to do search operation in O(1)
    for(int i=0;i<n;i++){
        mp.insert(B[i]);
    }
    int len = A.size();
    vector<bool> dp(len + 1, false);
    // we can always find empty string so making that true
    dp[0] = true;

    for(int i = 1; i <= len; i++) { // to fill whole dp array
        for(int j = i - 1; j >= 0; j--) { // we will find substring from j to i in words
            if(dp[j] && mp.find(A.substr(j, i - j)) != mp.end()) { // if we can find substring in words and answer for substring from 0 to j-1 is true means we found this string too
                dp[i] = true;
                break;
            }
        }
    }
    return dp[len];   
}
