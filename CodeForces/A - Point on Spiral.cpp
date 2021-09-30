// Problem Link : https://codeforces.com/problemset/problem/279/A
// i found various patters after taking multiple test cases
#include<bits/stdc++.h>

using namespace std;

int main() 
{
    int x,y;
    cin >> x >> y;
    
    if((x == 0 && y == 0) || (x == 1 && y == 0)){
        cout << 0 << endl;
        exit(0);
    } 
    int turns = 0;
    if(y == 0){
        turns = 1 + (abs(x)-1)*4;
        if(x < 0)
            turns += 2;
    }else if(y > 0){
        turns = 1 + (max(abs(x),y)-1)*4;
        if(turns < 0)
            turns = 1;
        if(x < y && x >= -y)
            turns++;
        else if(x < 0 && abs(x) > y)
            turns += 2;
    }else{
        turns = 3 + (max(abs(x),-y)-1)*4;
        if(turns < 0)
            turns = 3;
        if(x > y && x <= -y)
            turns++;
        else if(x > 0 && x > y){
            turns -= 2;
            if(x-1 == -y)
                turns--;
        }
    }
    cout << turns << endl;
    return 0;
}
