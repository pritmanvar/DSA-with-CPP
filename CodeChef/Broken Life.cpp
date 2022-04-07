// Problem Link : https://www.codechef.com/START33B/problems/BRKNLIFE

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
        int n,m;
        cin >> n >> m;

        string a,b;
        cin >> a >> b;

        int freq[5] = {0};
        int sub[n];
        int i = 0, j = 0;
        bool got = false;
        while(i < n){
            if(a[i] == b[j]){
                j++;
                if(j == m){
                    got = true;
                    break;
                }
            }
            sub[i] = j;
            i++;
        }
        if(got == true)
            cout << -1 << endl;
        else{
            for(int i = 0; i < m; i++){
                freq[b[i]-'a']++;
            }
            char ch = 'A';
            for(int i = 0; i < 5; i++){
                if(freq[i] == 0){
                    ch = 'a'+i;
                    break;
                }
            }
            for(int i = 0; i < n; i++){
                if(a[i] == '?'){
                    if(ch != 'A')
                        cout << ch;
                    else{
                        if(sub[i] > 0){
                            cout << b[0];
                        }else{
                            cout << b[b.length()-1];
                        }
                    }
                }
                else
                    cout << a[i];
            }
            cout << endl;
        }
    }
    return 0;
}
