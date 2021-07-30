// Problem Link : https://codeforces.com/contest/1555/problem/A

#include<bits/stdc++.h>

using namespace std;

int main() 
{
    int t;
    cin >> t;
    for (int z = 1; z <= t; z++){
        long long int n;
        cin >> n;

        long long large = 0; // number of large pizzas
        long long mid = 0; // number of medium pizzas
        long long small = 0; // number of small pizzas

        // first of all i will try to make large pizzas as more as possible
        large = n/10;
        n = n%10;
        
        // now if remining pizza is 9 then add one more large pizza because if i will not add then i have to make 2 medium pizza which will take more time
        if(n > 8){
            large++;
            n = 0;
            cout << large*25 + mid*20 + small*15 << endl;
            continue;
        }
        // if remining pizza is less than 7 then i will remove 1 large pizza because if i add large pizza then also i need another small pizza but i can achive same in 2 pizza of small or medium or 1 small and 1 medium in same or less time
        if(n <= 6 && n > 0){
            if(large > 0){
                large--;
                n += 10;
            }
        }
        // now i will try to make medium pizza
        mid = n/8;
        n = n%8;
        // now if remining pizza is 7 then add one more medium pizza because if i will not add then i have to make 2 small pizza which will take more time
        if(n > 6){
            mid++;
            cout << large*25 + mid*20 + small*15 << endl;
            continue;
        }
        // if remining pizza is less than 5 then i will remove 1 medium pizza because if i add medium pizza then also i need another small pizza but i can achive same in 2 pizza of small at same less time
        if(n <= 4 && n > 0){
            if(mid > 0){
                mid--;
                n += 8;
            }
        }
        // now i will make small pizzas whatever remaining 
        small = n/6;
        n = n%6;

        if(n > 0){
            small++;
        }

        // calculating answer
        cout << large*25 + mid*20 + small*15 << endl;
    }
    return 0;
}
