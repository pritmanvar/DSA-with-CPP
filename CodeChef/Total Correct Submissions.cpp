// Problem Link : https://www.codechef.com/START5C/problems/TOTCRT
#include<bits/stdc++.h>

using namespace std;

int main() 
{
    int t;
    cin >> t;
    for (int z = 1; z <= t; z++) 
    {
        int n;
        cin >> n;
        // to store every code and their accepted submissions
        unordered_map<string,int> mp;

        for(int i = 0; i < n; i++){ // foe every question
            for(int j = 0; j < 3; j++){ // for 3 div
                string str;
                int a;
                cin >> str >> a;
                mp[str] += a; // adding submissions in corrosponding question
            }
        }
        vector<int> v;
        for(auto i : mp){ // map to vector
            v.push_back(i.second);
        }
        sort(v.begin(),v.end()); // sorting vector

        for(int i = 0; i < v.size(); i++){ // printing output
            cout << v[i] << " ";
        }
        cout << endl;
    }
    return 0;
}
