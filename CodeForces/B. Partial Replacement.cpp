// Problem Link : https://codeforces.com/problemset/problem/1506/B

#include<bits/stdc++.h>

using namespace std;

int main() 
{
    int t;
    cin >> t;
    for (int z = 1; z <= t; z++){
        int n,k;
        cin >> n >> k;
        string str;
        cin >> str;

        int count = 0;
        int i = 0, j = n-1;
        // lb = last * changed from begining
        // le = last * changed from end
        int lb = -1,le = -1;
        // to get 1st start from begin
        while(i < n && str[i] != '*')
            i++;
        // corner case
        if(i == n){
            cout << count << endl;
            continue;
        }else{ 
            str[i] ='x';
            lb = i;
            // i will select next * which distance from i is just smaller than k
            i += k;
            count++;
        }
        // to get 1st start from end
        while(j >= 0  && str[j] != '*')
            j--;
        // corner case
        if(j < 0){
            cout << count << endl;
            continue;
        }else{
            str[j] ='x';
            le = j;
            // i will select next * which distance from j is just smaller than k
            j -= k;
            count++;
        }
        while(le-lb > k){
            if(le-lb > k){
                // i is already at k distance from lb
                // so i will find nearest * befor it.
                while(i >= 0 && str[i] != '*')
                    i--;
                lb = i;
                count++;
                i += k;
            }
            if(le-lb > k){
                // j is already at k distance from le
                // so i will find nearest * after it.
                while( j < n && str[j] != '*')
                    j++;
                le = j;
                count++;
                j -= k;
            }
        }
        cout << count << endl;
    }
    return 0;
}
