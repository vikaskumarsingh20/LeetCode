 

Given a binary tree, find the lowest common ancestor (LCA) of two given nodes in the tree.

According to the definition of LCA on Wikipedia: “The lowest common ancestor is defined between two nodes p and q as the lowest node in T that has both p and q as descendants (where we allow a node to be a descendant of itself).”

 

Example 1:


Input: root = [3,5,1,6,2,0,8,null,null,7,4], p = 5, q = 1
Output: 3
Explanation: The LCA of nodes 5 and 1 is 3.
Example 2:


Input: root = [3,5,1,6,2,0,8,null,null,7,4], p = 5, q = 4
Output: 5
Explanation: The LCA of nodes 5 and 4 is 5, since a node can be a descendant of itself according to the LCA definition.
Example 3:

Input: root = [1,2], p = 1, q = 2
Output: 1
  //CODE
Notes-
        1. LCA means two calls for left and right and find both have the same common val and it must be lowest in common.
        2. here two calls left and right with some conditions.

        Time Complexity:O(N) n no. of nodes
        Space Complexity:O(H) h no. of elements

 
 
class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        // when both p and q have same common node then return root
        if(root->val==p->val || root->val==q->val){
            return root;
        }
        //for left part and right part
        TreeNode* left = NULL, *right= NULL;
        if(root->left!=NULL){ //left call
            left=lowestCommonAncestor(root->left, p, q);
        }
        
        if(root->right!=NULL){ //right call
            right=lowestCommonAncestor(root->right, p, q);
        }
        //when p and q are not exsit in B Tree means both are null then return null
        if(left==NULL && right==NULL){
            return NULL;
        }
        // only left part have nodes and right have null then simply return left
        if(left!=NULL && right==NULL){
            return left;
        }
        //only right part have nodes and left have null then simply return right
        if(left==NULL && right!=NULL){
            return right;
        }
        // to finding common in both left and right
        if(left!=NULL && right!=NULL){
            return root;
        }
        return root;
        
    }
};
