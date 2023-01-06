Given the root of a binary tree, return the level order traversal of its nodes' values. (i.e., from left to right, level by level).

 

Example 1:


Input: root = [3,9,20,null,null,15,7]
Output: [[3],[9,20],[15,7]]
Example 2:

Input: root = [1]
Output: [[1]]
Example 3:

Input: root = []
Output: []

// SOLUTION GIVEN BELOW 
class Solution {
public:
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>>ans;
        if(root== NULL) return ans;
    
        queue<TreeNode*>q; // this is used bcz first push inside queue then pop ,FIFO
        q.push(root);

        while(!q.empty()){

            vector<int>level; 
            int size = q.size();
            for(int i=0;i<size;i++){
              TreeNode*node = q.front();
                q.pop();
            if(node->left != NULL) q.push(node->left);
            if(node->right != NULL) q.push(node->right);
              level.push_back(node->val);
            }
            ans.push_back(level);
        }
        return ans;
    }
};
