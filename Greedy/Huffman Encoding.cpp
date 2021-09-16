// Problem Link : https://practice.geeksforgeeks.org/problems/huffman-encoding3345/1#
    // What is Huffman Encoding : https://www.geeksforgeeks.org/huffman-coding-greedy-algo-3/
    
    // structure to represent a node
    struct Node{
        int data;
        Node* left;
        Node* right;
        
        Node(int x){
            data = x;
            left = right = NULL;
        }
    };
    // this is an structure which implements the
    // operator overloading
    struct comp{
	    bool operator()(Node* nd1, Node* nd2){
	        return nd1->data > nd2->data;
	    }
    };
    // PreOrder Traversal
    void preorder(Node* node, vector<string>& ans, string str){
        if(node == NULL)
            return;
        
        if(node->left == NULL && node->right == NULL) // if current node is leaf then add it's str into the answer
            ans.push_back(str);
        
        preorder(node->left,ans,str+'0');
        preorder(node->right,ans,str+'1');
    }
	vector<string> huffmanCodes(string S,vector<int> f,int N)
	{
	    priority_queue<Node*, vector<Node*>, comp> pq; // min heap
	    
	    // add node of every frequency into min heap
	    for(int i = 0; i < N; i++){
	        Node* temp = new Node(f[i]);
	        pq.push(temp);
	    }
	    while(pq.size() > 1){
	        // extract 2 nodes from min heap
	        Node* nd1 = pq.top();
	        pq.pop();
	        Node* nd2 = pq.top();
	        pq.pop();
	        
	        // create 2 node whose data will be sum of 2 extracted nodes
	        Node* temp = new Node(nd1->data + nd2->data);
	        temp->left = nd1; // smaller node will go to left child
	        temp->right = nd2; // larger node will go to right child
	        
	        pq.push(temp); // push temp into min heap
	    }
	    vector<string> ans; // to store answer
	    string str = ""; // intital code will be empty string
	    
	    preorder(pq.top(), ans, str); // pre-order traversal
	    
	    return ans; // return answer
	}
