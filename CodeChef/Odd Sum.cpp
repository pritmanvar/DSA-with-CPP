#include <bits/stdc++.h>
using namespace std;

int main()
{
    int t;
    scanf("%d",&t);
    for (int z = 1; z <= t; z++){
        unsigned long long int n;
        scanf("%llu",&n);

        if(n == 1 || n == 2){
            printf("1\n");
        }else{
            unsigned long long int sum = (n-2)*(n-1)+1;
            printf("%llu\n",sum);
        }
    }
    return 0;
}
