// Problem Link : https://www.codechef.com/COOK131B/problems/XORORED

#include<bits/stdc++.h>

using namespace std;

int main() 
{
    int t;
    cin >> t;
    for (int z = 1; z <= t; z++){
        int n;
        cin >> n;

        int arr[n];
        int a[32] = {0}; // in this i will store how many times (i)th bit is set

        for(int i = 0; i < n; i++){
            cin >> arr[i];

            int count = 0;
            int temp = arr[i];

            while(temp > 0){ // update the array a
                if((temp&1) != 0)
                    a[count]++;
                
                temp /= 2;
                count++;
            }
        }
        int ans = 0; // xor number
        int Or = 0; // number after or
        for(int i = 0; i < 32; i++){
            if(a[i] == n){ // if ith bit is set in every bit then i will unset it so in my ans ith bit will be set
                ans |= 1 << i;
            }
        }
        for(int i = 0; i < n; i++){ // makig or of all elements after xor
            Or |= (arr[i]^ans);
        }

        cout << ans << " " << Or << endl; // printing answer
    }
    return 0;
}
