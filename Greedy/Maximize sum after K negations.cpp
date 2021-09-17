// Problem Link : https://practice.geeksforgeeks.org/problems/maximize-sum-after-k-negations1149/1#
    long long int maximizeSum(long long int a[], int n, int k)
    {
        sort(a,a+n); // sort array
        long long int sum = accumulate(a,a+n,0); // calculate sum of array
        
        int i = 0;
        for(i = 0; i < k && i < n; i++){
            // if current element is negarive then i will replace that with -a[i] else i will end the loop
            if(a[i] < 0){
                sum -= 2*a[i];
                a[i] = -a[i];
            }else{
                break;
            }
        }
        // if remaining number of modifications are even then i can take half elements and modify that two times to get max sum
        if((k-i)%2 == 0)
            return sum;
        else{
            // else i will get smallest element and modify that
            if(i < n)
                return sum -= 2*a[i%n];
            else{
                sort(a,a+n);
                return sum -= 2*a[0];
            }
        }
    }
