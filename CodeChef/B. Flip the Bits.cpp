// Problem Link : https://codeforces.com/problemset/problem/1504/B

#include<bits/stdc++.h>

using namespace std;

int main() 
{
    int t;
    cin >> t;
    for (int z = 1; z <= t; z++){
        int n;
        cin >> n;
        string a;
        cin >> a;
        string b;
        cin >> b;
        
        // zero->to store number of zeros
        // one->to store number of ones
        // last->to store ending index of prefix where condition is satisfied.
        int zero = 0, one = 0, last = -1;
        bool ans = true;
        for(int i = 0; i < n; i++){
            // update ones and zeros
            if(a[i] == '0')
                zero++;
            else
                one++;
            
            // if at this moment number of ones and zeros are equal
            if(zero == one){
                int j = i;
                bool isSame = a[i] == b[i];
                // if element at current index in a and b are same then from last+1 to i all element should be same
                // if element at current index in a and b are not same then from last+1 to i all element should be distinct
                // it uper statment are not true then we can't get b from a by following given conditions so i will mark my answer as false.
                while(j > last){
                    if(isSame == true && a[j] != b[j]){
                        ans = false;
                        break;
                    }else if(isSame == false && a[j] == b[j]){
                        ans = false;
                        break;
                    }
                    j--;
                }
                if(ans == false)
                    break;
                last = i; // update last to current index.
            }
        }
        // since from last to n-1 is not a valid prefix we can't inverse that's digits so they must be same.
        for(int i = n-1; i > last; i--){
            if(a[i] != b[i]){
                ans = false;
                break;
            }
        }
        // print answer.
        if(ans)
            cout << "YES\n";
        else
            cout << "NO\n";
    }
    return 0;
}
