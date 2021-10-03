// Problem Link : https://codeforces.com/problemset/problem/467/B

#include<bits/stdc++.h>

using namespace std;

int main() 
{ 
    // accepting input.
    int n,m,k;
    cin >> n >> m >> k;
    vector<int> arr(m+1);
    for(int i = 0; i < m+1; i++){
        cin >> arr[i];
    }

    int Friend = 0;
    for(int i = 0; i < m; i++){
        int temp = arr[i]^arr[m];
        int pos = 0;
        int count = 0;
        // if bit at pos in xor of both number is set then they contain different soldiers 
        // and since there can be only n soldiers i will check it for n pos only.
        while(temp > 0 && pos < n){
            if(temp%2 == 1){ // if it contains different soldier then i will increment the count
                count++;
            }
            if(count > k)
                break;
            pos++;
            temp /= 2;
        }
        // if number of different soliders is at most k then it will be friend.
        if(count <= k)
            Friend++;
    }
    cout << Friend << endl;
    return 0;
}
