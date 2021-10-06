// Problem Link : https://practice.geeksforgeeks.org/problems/handshakes1303/1/?category[]=Recursion&category[]=Recursion&difficulty[]=1&page=1&query=category[]Recursiondifficulty[]1page1category[]Recursion#
    int count(int N){
        if(N <= 2) // base case.
            return 1;
        int ans = 0;
        // 0th person will do hand shake with 1st,3rd,4th... person
        // so that number of person between 0th person and ith person will be even so they can do handshake internally.
        for(int i = 1; i < N; i+=2){
            ans += count(i-1)*count(N-i-1);
        }
        return ans;
    }
