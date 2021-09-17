// Problem Link : https://practice.geeksforgeeks.org/problems/shop-in-candy-store1145/1#
    vector<int> candyStore(int candies[], int N, int K)
    {
        int mn = 0; // to store minimum ammount
        int mx = 0; // to store maximum ammount
        
        sort(candies,candies+N); // sort candies
        int st = 0,ed = N; // starting and ending pointer to the candies array
        
        // in each move i will but candy with min prise which is available and get K candies with max prise which is avaible to make ammount minimum
        while(st < ed){
            mn += candies[st++];
            ed -= K;
        }
        st = -1,ed = N-1;
        // in each move i will but candy with max prise which is available and get K candies with min prise which is avaible to make ammount maximum
        while(st < ed){
            mx += candies[ed--];
            st += K;
        }
        return {mn,mx}; // return answer
    }
