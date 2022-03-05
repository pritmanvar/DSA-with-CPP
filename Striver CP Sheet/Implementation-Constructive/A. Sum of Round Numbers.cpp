// Problem Link : https://codeforces.com/problemset/problem/1352/A
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
        int n;
        cin >> n;

        int count = 0;
        vector<int> ans;

        while(n > 0){
            int temp = (n%10)*pow(10,count);
            count++;
            n /= 10;

            if(temp > 0)
                ans.push_back(temp);
        }
        cout << ans.size() << endl;
        for(int i = 0; i < ans.size(); i++){
            cout << ans[i] << " ";
        }
        cout << endl;
    }
    return 0;
}
