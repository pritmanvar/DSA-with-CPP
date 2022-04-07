// Problem Link : https://www.codechef.com/START33B/problems/MTE

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

        vector<int> odd, even;
        for(int i = 0; i < n; i++){
            int temp;
            cin >> temp;

            if(temp%2 == 0)
                even.push_back(temp);
            else
                odd.push_back(temp);
        }
        if(odd.size()%2 == 1){
            cout << even.size() << endl;
        }else{
            cout << min(even.size(),odd.size()/2) << endl;
        }
    }
    return 0;
}
