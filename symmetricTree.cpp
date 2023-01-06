Given the root of a binary tree, check whether it is a mirror of itself (i.e., symmetric around its center).

 

Example 1:


Input: root = [1,2,2,3,4,4,3]
Output: true
Example 2:


Input: root = [1,2,2,null,3,null,3]
Output: false
 
  
  class Solution {
public:

    void helper(TreeNode* left, TreeNode* right, bool& flag) {
        //if left exists and right is null, it's not symmetric,right exists and left is null, it's not symmetric
        if ((left && !right)||(!left && right))
            flag = false;
       

        //if both exists but the values of left/right aren't same(because it's symmetric you need to compare left and right not left and left), it's not symmetric
        if (left && right) {
            if (left->val != right->val)
                flag = false;

            //Check if leftNode's left side is symmetric with rightNode's right side
            helper(left->left, right->right, flag);
            //Check if leftNode's right side is symmetric with rightNode's left side
            helper(left->right, right->left, flag);
        }

    }

    bool isSymmetric(TreeNode* root) {
        //flag for checking if TreeNode is Symmetric or not
        bool flag = true;
        if (root)
            helper(root->left, root->right, flag);

        return flag;
    }
};
