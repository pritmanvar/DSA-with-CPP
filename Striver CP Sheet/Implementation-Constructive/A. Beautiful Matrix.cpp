// Problem Link : https://codeforces.com/problemset/problem/263/A

// index of cell at center will be 2,2 so minimum moves required is abs(i-2)+abs(j-2)
#include<bits/stdc++.h>
#define ll long long int

using namespace std;

int main() 
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int ans = 0;
    for(int i = 0; i < 5; i++){
        for(int j = 0; j < 5; j++){
            int temp;
            cin >> temp;

            if(temp == 1){
                ans = abs(2-i)+abs(2-j);
            }
        }
    }
    cout << ans << endl;
    return 0;
}
 
