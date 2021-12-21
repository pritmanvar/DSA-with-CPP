// Problem Link : https://leetcode.com/problems/serialize-and-deserialize-binary-tree/

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Codec {
public:

    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        if(root == NULL)
            return "n";
        string tree = "";
        
        // BFS
        // Traverse tree and add node into string in level order.
        // use 'n' to represent NULL.
        queue<TreeNode*> q;
        q.push(root);
        tree += to_string(root->val)+' ';
        
        while(q.size() > 0){
            int count = q.size();
            
            for(int i = 0; i < count; i++){
                TreeNode* temp = q.front();
                q.pop();
                
                if(temp->left != NULL){
                    q.push(temp->left);
                    tree += to_string(temp->left->val)+' ';
                }else{
                    tree += "n ";
                }
                if(temp->right != NULL){
                    q.push(temp->right);
                    tree += to_string(temp->right->val)+' ';
                }else{
                    tree += "n ";
                }
            }
        }
        return tree;
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        if(data == "n")
            return NULL;
        
        TreeNode* root = NULL;
        queue<TreeNode*> q;
        
        int len = data.length();
        int i = 0;
        // to decide that new node will be in left side or right side.
        // if count%2 will be 0 then new node will go to left side else new node will go the right side.
        int count = 0; 
        while(i < len){
            
            // get value of next node.
            string node = "";
            while(i < len && data[i] != ' '){
                node += data[i];
                i++;
            }
            i++;
            
            TreeNode* parent = q.front(); // parent of upcomming node.
            
            // upcomming node is NULL
            if(node == "n"){
                if(count%2 == 0){
                    parent->left = NULL;
                }else{
                    parent->right = NULL;
                    q.pop();
                }
                count++;
            }else{
                TreeNode* temp = new TreeNode(stoi(node));
                if(root == NULL){
                    root = temp;
                }else{
                    if(count%2 == 0){
                        parent->left = temp;
                    }else{ 
                        parent->right = temp;
                        q.pop(); // left and right of current parent is filled so pop that from queue.
                    }
                    count++;
                }
                q.push(temp); // add new node into queue.
            }
        }
        return root;
    }
};

// Your Codec object will be instantiated and called as such:
// Codec ser, deser;
// TreeNode* ans = deser.deserialize(ser.serialize(root));
