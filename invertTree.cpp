226. Invert Binary Tree
Easy
10.7K
153
Companies
Given the root of a binary tree, invert the tree, and return its root.

 

Example 1:


Input: root = [4,2,7,1,3,6,9]
Output: [4,7,2,9,6,3,1]
Example 2:


Input: root = [2,1,3]
Output: [2,3,1]
Example 3:

Input: root = []
Output: []


class Solution {
public:
    TreeNode* invertTree(TreeNode* root) {
        if(root ==nullptr) return root;
        swap(root->left,root->right);// swap values in left ans right
        invertTree(root->left);  // left call
        invertTree(root->right); // right call
        return root;
    }
};
