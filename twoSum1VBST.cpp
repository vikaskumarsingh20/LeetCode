653. Two Sum IV - Input is a BST
Easy
5.5K
236
Companies
Given the root of a binary search tree and an integer k, return true if there exist two elements in the BST such that their sum is equal to k, or false otherwise.

 

Example 1:


Input: root = [5,3,6,2,4,null,7], k = 9
Output: true
Example 2:


Input: root = [5,3,6,2,4,null,7], k = 28
Output: false
  
  

class Solution {
public:
    void inorder(TreeNode* root, vector<int>& vec){
        if(!root) return;
        inorder(root->left,vec); // inorder -> left-root-right 
        vec.push_back(root->val); // inorder travesal always sorted
        inorder(root->right,vec);
    }
    bool findTarget(TreeNode* root, int k) {
        //not found 
        if(!root) return false;
        vector<int> vec;
        inorder(root,vec);

        int left=0,right=vec.size()-1;
        while(left < right){
            int sum = vec[left]+vec[right]; //two pointer 
            if(sum < k) left++; // less then increment
            else if(sum>k) right--; // more decrement
            else return true;
        }
        return false;
    }
};
