// Problem Link : https://practice.geeksforgeeks.org/problems/find-all-four-sum-numbers1732/1#
    vector<vector<int> > fourSum(vector<int> &arr, int k) {
        // Your code goes here
        set<int> st;
        set<vector<int>> ans;
        for(int i = 0; i < arr.size(); i++){// selecting 1st element
            int sumi = arr[i];
            for(int j = i+1; j < arr.size(); j++){// selecting 2st element
                int sumj = sumi;
                sumj += arr[j];
                for(int l = j+1; l < arr.size(); l++){// selecting 3st element
                    int suml = sumj;
                    suml += arr[l];
                    if(st.count(k-suml) == 1){// checking that 4th element is avaible or not
                        vector<int> temp;
                        temp.push_back(arr[i]);
                        temp.push_back(arr[j]);
                        temp.push_back(arr[l]);
                        temp.push_back(k-suml);
                        sort(temp.begin(),temp.end());
                        ans.insert(temp);// ans is set to avoid duplicates
                    }
                }
            }
            st.insert(arr[i]);
        }
        vector<vector<int>> ans1;
        for(i : ans){// converting set to vector
            ans1.push_back(i);
        }
        return ans1;
    }
