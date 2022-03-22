// Problem Link : https://codingcompetitions.withgoogle.com/kickstart/round/00000000008cb33e/00000000009e7021

#include<bits/stdc++.h>
#define ll long long int

using namespace std;

int main() 
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin >> t;
    for (int z = 1; z <= t; z++){
        string str1,str2;
        cin >> str1 >> str2;

        bool possible = true;
        int j = 0;
        int ans = 0;
        for(int i = 0; i < str1.length(); i++){
            while(j < str2.length() && str1[i] != str2[j]){
                j++;
                ans++;
            }
            if(j >= str2.length()){
                possible = false;
                break;  
            }
            j++;
        }
        ans += str2.length()-j;
        cout << "Case #" << z << ": ";
        if(possible){
            cout << ans << endl;
        }else{
            cout << "IMPOSSIBLE" << endl;
        }
    }
    return 0;
}
