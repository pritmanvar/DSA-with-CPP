#include<bits/stdc++.h>

using namespace std; 

int main() 
{
    int t;
    cin >> t;
    for (int z = 1; z <= t; z++) 
    {
        int s[4] = {0};
        int m1 = 0; 
        for(int i = 0; i < 4; i++){
            cin >> s[i];
          
            if(s[m1] < s[i]){
                m1 = i;
            }
        }
        int m2 = m1 == 0? 1 : 0;
        for (int i = 0; i < 4; i++)
        {
            if(i != m1 && s[m2] < s[i]){
                m2 = i;
            }
        }
      
        if(m1 < 2 && m2 >= 2){
            cout << "YES\n";
        }else if(m1 >= 2 && m2 < 2){
            cout << "YES\n";
        }else{
            cout << "NO\n";
        }
    }
    return 0;
}
