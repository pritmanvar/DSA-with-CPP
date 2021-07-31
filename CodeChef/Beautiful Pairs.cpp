// Problem Link : https://www.codechef.com/LTIME98B/problems/BUTYPAIR

// basically i have to find pirs in which Ai > Aj
#include<bits/stdc++.h>

using namespace std;

int main() 
{
    int t;
    cin >> t;
    for (int z = 1; z <= t; z++){
        int n;
        cin >> n;
        unordered_map<int,long long int> mp; // to store frequency of every element
        
        // taking input and adding all elements into map
        for(int i = 0; i < n; i++){
            int temp;
            cin >> temp;
            mp[temp]++;
        }
        long long int ans = 0; 

        // answer will be sum of (number of element which is not equal to current one)*(frequency of current element)
        // because if element is greater then current one than i will consider that as Ai and if smaller than current one then consider that element as Aj
        // i can do same for every element which value is same so i will multiplay that with frequency of current element
        for(auto i : mp){
            ans += i.second*(n-i.second);
        }
        cout << ans << endl;
        
    }
    return 0;
}
