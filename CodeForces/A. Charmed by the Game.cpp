// Problem Link : https://codeforces.com/problemset/problem/1558/A

#include<bits/stdc++.h>

using namespace std;

int main() 
{
    int t;
    cin >> t;
    for (int z = 1; z <= t; z++){
        int a,b;
        cin >> a >> b;

        set<int> ans;
        // if alice start to service
        int p = (int)ceil((double)(a+b)/2); // number of service alice will get because in case of odd number service by alice will be (a+b)/2+1
        int q = (a+b)/2; // number of service borys will get

        // lets assume alice will break i service of borys
        // and assume borys will break j service of alice
        // hence borys has q service so i can not be larger than q  
        for(int i = 0; i <= q; i++){
            // if alice will break i service of borys then points for alice will be
            // a = p-j+i 
            // i will check that j is valid or not it is valid then i will add them into answer.
            if(p+i-a <= p && p+i-a >= 0){
                ans.insert(i+p+i-a);
            }
        }

        // if borys will start to service
        p = (a+b)/2; // number of service alice will get.
        q = (int)ceil((double)(a+b)/2); // number of service borys will get


        // again i am following same logic as the case when alice will start to service.
        for(int i = 0; i <= q; i++){
            if(p+i-a <= p && p+i-a >= 0){
                ans.insert(i+p+i-a);
            }
        }

        // Print Answer.
        cout << ans.size() << endl;
        for(auto i : ans)
            cout << i << " ";
        cout << endl;
    }
    return 0;
}
