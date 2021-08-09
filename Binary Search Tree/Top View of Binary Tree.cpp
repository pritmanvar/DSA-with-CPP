// Problem Link : https://practice.geeksforgeeks.org/problems/top-view-of-binary-tree/1#
    vector<int> topView(Node *root){
        map<int,int> mp; // map of horizontal distance, data. to store top view
        vector<int> ans; // to store answer
        queue<pair<Node*,int>> q; // queue for level order traversal
        
        // level order traversal
        q.push({root,0});
        while(q.empty() == false){
            int count = q.size();
            for(int i = 0; i < count; i++){
                pair<Node*,int> temp = q.front();
                q.pop();
                
                // if node at current distance appears 1st time then add this into map
                if(mp.count(temp.second) == 0){
                    mp[temp.second] = temp.first->data;
                }
                if(temp.first->left != NULL){
                    q.push({temp.first->left,temp.second-1});
                }
                if(temp.first->right != NULL){
                    q.push({temp.first->right,temp.second+1});
                }
            }
        }
        // converting map to vector
        for(auto i : mp){
            ans.push_back(i.second);
        }
        return ans;
    }
