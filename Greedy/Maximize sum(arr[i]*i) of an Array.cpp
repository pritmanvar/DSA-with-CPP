// Problem Link : https://practice.geeksforgeeks.org/problems/maximize-arrii-of-an-array0026/1
    
    int N = 1e9+7;
    int Maximize(int a[],int n)
    {
        sort(a,a+n); // sory array
        unsigned long long int ans = 0; // to store answer
        for(int i=0;i<n;i++)
            ans = (ans + ((unsigned long long)a[i]*i)%N )%N; // modulo arithmatic
        return ans;
    }
