

105. Construct Binary Tree from Preorder and Inorder Traversal
Medium
12.2K
358
Companies
Given two integer arrays preorder and inorder where preorder is the preorder traversal of a binary tree and inorder is the inorder traversal of the same tree, construct and return the binary tree.

 

Example 1:


Input: preorder = [3,9,20,15,7], inorder = [9,3,15,20,7]
Output: [3,9,20,null,null,15,7]
Example 2:

Input: preorder = [-1], inorder = [-1]
Output: [-1]
//CODE
/*

Time complexity: O(N).
Space complexity: O(N).

Working...

*/
class Solution {
public:
    TreeNode* build(vector<int>& preorder,int preStart,int preEnd,vector<int>& inorder,int inStart, int inEnd,unordered_map<int,int>&mp){
        // no element in pre or no solution
        if(preStart>preEnd || inStart>inEnd){
            return NULL;
        }
        
        TreeNode* root = new TreeNode(preorder[preStart]);
        int rootIndex = mp[root->val];
        int numsLeft = rootIndex-inStart;   
        root->left = build(preorder,preStart+1,preStart+numsLeft,inorder,inStart,rootIndex-1,mp);
        root->right=build(preorder,preStart+numsLeft+1,preEnd,inorder,rootIndex+1,inEnd,mp);
        return root;
    }
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        unordered_map<int,int>mp;
        for(int i=0;i<inorder.size();i++){
            mp[inorder[i]]=i;
        }
        TreeNode* root = build(preorder,0,preorder.size()-1,inorder,0,inorder.size()-1,mp);
        return root;
    }
};
