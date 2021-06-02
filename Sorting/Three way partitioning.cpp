// Problem Link : https://practice.geeksforgeeks.org/problems/three-way-partitioning/1

    //Function to partition the array around the range such 
    //that array is divided into three parts.
    void threeWayPartition(vector<int>& arr,int a, int b)
    {
        int i = 0;// This is to Points the first element which is > a from current posion
        int j = 0;// This pointer is used to trsaverse the array
        int k = arr.size()-1;// This is to point the last element which is < b element in array
        // traverse through all array
        while(j <= k){
            if(arr[j] < a){ // If element is < a then swap it with first element which is >= a
                swap(arr[i],arr[j]);
                i++;
            }else if(arr[j] > b){//If element is > b then swap it with last element which is <= b element in array
                swap(arr[k],arr[j]);
                k--;
                j--; //here we decrement j because we don't know about comming element 
            }
            j++;
        }
    }