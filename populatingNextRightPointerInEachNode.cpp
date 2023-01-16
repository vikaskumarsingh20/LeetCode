116. Populating Next Right Pointers in Each Node
Medium
8.2K
275
Companies
You are given a perfect binary tree where all leaves are on the same level, and every parent has two children. The binary tree has the following definition:

struct Node {
  int val;
  Node *left;
  Node *right;
  Node *next;
}
Populate each next pointer to point to its next right node. If there is no next right node, the next pointer should be set to NULL.

Initially, all next pointers are set to NULL.

 

Example 1:


Input: root = [1,2,3,4,5,6,7]
Output: [1,#,2,3,#,4,5,6,7,#]
Explanation: Given the above perfect binary tree (Figure A), your function should populate each next pointer to point to its next right node, just like in Figure B. The serialized output is in level order as connected by the next pointers, with '#' signifying the end of each level.
Example 2:

Input: root = []
Output: []


//BFS METHOD 

class Solution {
public:
    Node* connect(Node* root) {
        if(!root) return root; //base case
        queue<Node*> q; //FIFO
        q.push(root);

        while(!q.empty()){
            int size = q.size();
            while(size--){
                Node* ans = q.front();
                q.pop();
                cout<<ans->val<<" ";
                if(size!= 0){
                    ans->next = q.front();
                }
                if(ans->left)  q.push(ans->left);
                if(ans->right) q.push(ans->right);
            }
        }
        return root;
    }
};

// DFS METHOD

 class Solution {
public:
    
    void dfs(Node* root)
    {
        if(root->left==nullptr && root->right==nullptr)
            return;
        if(root->left)
            root->left->next=root->right;
        if(root->right && root->next)
            root->right->next=root->next->left;
        dfs(root->left);
        dfs(root->right);
    }
    
    Node* connect(Node* root) {
        if(root==nullptr)
            return nullptr;
        dfs(root);
        return root;
    }
};
 
