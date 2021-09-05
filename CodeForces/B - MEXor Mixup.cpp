// Problem Link : https://codeforces.com/contest/1567/problem/B
#include<bits/stdc++.h>
 
using namespace std;
 
int main() 
{
    int t;
    cin >> t;
    for (int z = 1; z <= t; z++){
        int a,b;
        cin >> a >> b;
        int x = 0;
        int j = a;
        if(j > 1){
            if((j-1)%4 == 0){
                x = j-1;
            }else if((j-1)%4 == 1){
                x = 1;
            }else if((j-1)%4 == 2){
                x = j;
            }else{
                x = 0;
            }
        }
        if(x == b){
            cout << j << endl;
        }else{
            int ans = 0;
            int i = 0;
            while(x > 0 || b > 0){
                if(x%2 != b%2){
                    ans |= (1 << i);
                }
                i++;
                x /= 2;
                b /= 2;
            }
            if(ans == a){
                cout << j+2 << endl;
            }else{
                cout << j+1 << endl;
            }
        }
    }
    return 0;
}
