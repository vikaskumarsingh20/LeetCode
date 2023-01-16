
572. Subtree of Another Tree
Easy
6.7K
381
Companies
Given the roots of two binary trees root and subRoot, return true if there is a subtree of root with the same structure and node values of subRoot and false otherwise.

A subtree of a binary tree tree is a tree that consists of a node in tree and all of this node's descendants. The tree tree could also be considered as a subtree of itself.

 

Example 1:


Input: root = [3,4,5,1,2], subRoot = [4,1,2]
Output: true
Example 2:


Input: root = [3,4,5,1,2,null,null,null,null,0], subRoot = [4,1,2]
Output: false
  //CODE 
class Solution {
public:
    bool areTheySame(TreeNode* root1, TreeNode* root2){
        // both not null 
        if(!root1||!root2) return root1==root2;
        // values not matched
        if(root1->val!=root2->val) return false;
        // left and right calls in both root , subroot
        return areTheySame(root1->left,root2->left)&&areTheySame(root1->right,root2->right);
    }
    bool dfs(TreeNode* root ,TreeNode* subroot){
        if(!root) return false;
        // matched both
        if(areTheySame(root,subroot)) return true;
        // left or right calls
        return dfs(root->left,subroot)||dfs(root->right,subroot);
    }
    bool isSubtree(TreeNode* root, TreeNode* subRoot) {
        return dfs(root,subRoot);
    }
};
