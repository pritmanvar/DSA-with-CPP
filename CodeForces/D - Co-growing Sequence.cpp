// Problem Link : https://codeforces.com/contest/1547/problem/D

#include<bits/stdc++.h>
 
using namespace std;

// this function will check that two numbers are growing or not
// and return vector which contain the possition of bits where n has set bit but m has not
vector<int> isGrowing(int n, int m){
    vector<int> pos;
 
    int i = 0;
    while(n != 0){
        if((n&1) == 1 && (m&1) == 0){
            pos.push_back(i);
        }
        i++;
        n /= 2;
        m /= 2;
    }
    return pos;
}
 
int main() 
{
    int t;
    cin >> t;
    for (int z = 1; z <= t; z++) 
    {
        int n;
        cin >> n;
 
        vector<int> arr(n);
 
        for(int i = 0; i < n; i++){
            cin >> arr[i];
        }
      
        // to make number minimum we will not do anything with first number so y0 will be 0
        cout << 0 << " ";
      
        // for every pair we will do required changes
        for(int i = 0; i < n-1; i++){
          
            vector<int> temp = isGrowing(arr[i],arr[i+1]);
            if(temp.size() == 0){ // if returned vector is empty means thease two numbers are growing so we will not do anything with anyone so yi will be 0
                cout << 0 << " ";
            }else{
                int num = 0;
                // we will make a number which will only contain set bit at the possitions
                for(int j = 0; j < temp.size(); j++){
                    num |= (1<<temp[j]);
                }
                cout << num << " "; // this number will be our yi
                arr[i+1] ^= num; // update the number too
            }
        }
        cout << endl;
    }
    return 0;
}
