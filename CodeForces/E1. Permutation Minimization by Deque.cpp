// Problem Link : https://codeforces.com/problemset/problem/1579/E1

#include<bits/stdc++.h>

using namespace std;

int main() 
{
    int t;
    cin >> t;
    for (int z = 1; z <= t; z++){
        int n;
        cin >> n;

        deque<int> dq;
        for(int i = 0; i < n; i++){
            int temp;
            cin >> temp;

            if(dq.empty()){
                dq.push_front(temp);
            }else{
                if(temp <= dq.front()){
                    dq.push_front(temp);
                }else{
                    dq.push_back(temp);
                }
            }
        }
        while(!dq.empty()){
            cout << dq.front() << " ";
            dq.pop_front();
        }
        cout << endl;
    }
    return 0;
}
