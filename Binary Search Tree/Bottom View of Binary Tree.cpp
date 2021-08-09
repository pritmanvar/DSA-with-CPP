// Problem Link : https://practice.geeksforgeeks.org/problems/bottom-view-of-binary-tree/1#
    vector <int> bottomView(Node *root) {
        map<int,int> mp; // in this i will store bottom view, map of horizantal distance, data
        vector<int> ans; // answer
        queue<pair<Node*,int>> q; // queue for level order traversal
        
        // level order traversal
        q.push({root,0});
        while(q.empty() == false){
            int count = q.size();
            for(int i = 0; i < count; i++){
                pair<Node*, int> temp = q.front();
                q.pop();
                
                mp[temp.second] = temp.first->data; // here i am doing level order traversal so data will updated according to last level
                
                if(temp.first->left != NULL)
                    q.push({temp.first->left,temp.second-1});
                if(temp.first->right != NULL)
                    q.push({temp.first->right,temp.second+1});
            }
        }
        // converting map to vector
        for(auto i : mp){
            ans.push_back(i.second);
        }
        return ans;
    }
