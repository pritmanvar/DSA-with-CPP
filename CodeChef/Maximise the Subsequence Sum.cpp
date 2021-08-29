// Problem Link : https://www.codechef.com/START10B/problems/SIGNFLIP
#include<bits/stdc++.h>

using namespace std;

int main() 
{
    int t;
    cin >> t;
    for (int z = 1; z <= t; z++){
        int n,k;
        cin >> n >> k;
        priority_queue<int> pq;
        long long int sum = 0;

        for(int i = 0; i < n; i++){
            int temp;
            cin >> temp;
            if(temp >= 0){
                sum += temp;
            }else{
                if(pq.size() < k){
                    pq.push(temp);
                }else{
                    pq.push(temp);
                    pq.pop();
                }
            }
        }
        while(pq.size() > 0){
            sum += (-1)*pq.top();
            pq.pop();
        }
        cout << sum << endl;
    }
    return 0;
}
