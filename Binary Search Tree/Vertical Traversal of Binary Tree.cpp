// Problem Link : https://practice.geeksforgeeks.org/problems/print-a-binary-tree-in-vertical-order/1/?track=P100-Binary%20Search%20Tree#
    vector<int> verticalOrder(Node *root)
    {
        unordered_map<int,vector<int>> mp; // to store nodes with same horizontal distance
        queue<pair<Node*,int>> q; // queue for level order traversal
        int mn = 0,mx = 0; // to store max and min horizontal distane 
        
        // level order traversal
        q.push({root,0});
        mp[0].push_back(root->data); // add root in the horizontal distance 0
        while(q.empty() == false){
            int count = q.size();
            for(int i = 0; i < count; i++){
                pair<Node*,int> temp = q.front();
                q.pop();
                
                // if it is left size then its horizontal distance will be distance of parent-1
                // and add that in queue and map
                if(temp.first->left){
                    q.push({temp.first->left,temp.second-1});
                    mp[temp.second-1].push_back(temp.first->left->data);
                    mn = min(mn,temp.second-1);
                }
                // if it is right size then its horizontal distance will be distance of parent+1
                // and add that in queue and map
                if(temp.first->right){
                    q.push({temp.first->right,temp.second+1});
                    mp[temp.second+1].push_back(temp.first->right->data);
                    mx = max(mx,temp.second+1);
                }
            }
        }
        // traverse through map and add nodes into the answer
        vector<int> ans;
        for(int i = mn; i <= mx; i++){
            for(int j = 0; j < mp[i].size(); j++){
                ans.push_back(mp[i][j]);
            }
        }
        return ans;
    }
