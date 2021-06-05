// Problem Link : https://practice.geeksforgeeks.org/problems/common-elements1132/1#
        vector <int> commonElements (int A[], int B[], int C[], int n1, int n2, int n3)
        {
            int i = 0;
            int j = 0;
            int k = 0;
            vector<int> ans;
             
            while(i < n1){ // Traversing throug array A and chaeck that current element is present in other arrays or not.
                if(j >= n2 || k >= n3)// If one of array goes out of bound then after that can not be same element.
                    break;
                // In case of same elments we don't want same element in answer so we will skip that
                if(i != 0 && A[i] == A[i-1]){
                    i++;
                    continue;
                }
                if(j != 0 && B[j] == B[j-1]){
                    j++;
                    continue;
                }
                if(k != 0 && C[k] == C[k-1]){
                    k++;
                    continue;
                }
                // We will move pointer to other arays till that points to smaller elements then current element in 1st array
                // Becasue befor that it can't store same number because arrays are sorted
                while(j < n2 && B[j] < A[i])
                    j++;
                while(k < n3 && C[k] < A[i])
                    k++;
                
                // If we found the element which is present in all array then we will add that in answer.
                if(j < n2 && k < n3 && B[j] == A[i] && A[i] == C[k]){
                    ans.push_back(A[i]);
                    j++;
                    k++;
                }
                i++;
            }
            return ans;
        }
