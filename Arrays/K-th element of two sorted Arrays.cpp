//Problem Link : https://practice.geeksforgeeks.org/problems/k-th-element-of-two-sorted-array1317/1
    //GeeksForGeeks has mantioned more optimal solution in editorial
    int kthElement(int arr1[], int arr2[], int n, int m, int k)
    {
        // I had merged two sorted array and then returned k-1th element in merged array
        int *temp = new int[n+m];
        
        int i = 0;
        int j = 0;
        int l = 0;
        
        while(i < n && j < m){
            if(arr1[i] <= arr2[j]){
                temp[l] = arr1[i];
                i++;
                l++;
            }else{
                temp[l] = arr2[j];
                j++;
                l++;
            }
        }
        while(i < n){
            temp[l] = arr1[i];
            i++;
            l++;
        }
        while(j < m){
            temp[l] = arr2[j];
            j++;
            l++;
        }
        return temp[k-1];
    }
