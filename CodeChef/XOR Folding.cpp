// Problem Link : https://www.codechef.com/COOK130C/problems/XORFOLD

// we have to convert nxm array into 1x1
// means this 1x1 array will contain xor of all elements in the array
#include<bits/stdc++.h>

using namespace std;

int main() 
{
    int t;
    cin >> t;
    
    for (int z = 1; z <= t; z++) 
    {
        int n,m;
        cin >> n >> m;

        int count = 0;
        for(int i = 0; i < n; i++){
            string str;
            cin >> str;
            for(int j = 0; j < m; j++){
                if(str[j] == '1'){ // counting number of one in the all input
                    count++;
                }
            }
        }
        if(count%2 == 0){ // if number of one is even then xor of all will be 0
            printf("NO\n");
            
        }else{ // if number of one is odd then xor of all will be 1
            printf("YES\n");
        }
    }
    return 0;
}
