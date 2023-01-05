class Solution {
public:
  void preorder(TreeNode*root ,vector<int>&ans){
      if(root==nullptr) return;  // PREORDER -> root ,left ,right
      ans.push_back(root->val);
      preorder(root->left,ans);
      preorder(root->right,ans);
  }
  
      void postorder(TreeNode*root , vector<int>&ans){
        if(root==nullptr) return; //postorder left,right,root
        postorder(root->left,ans);
        postorder(root->right, ans);
        ans.push_back(root->val);
    }
  
      void inorder(TreeNode*root ,vector<int>&ans){
        if(root==nullptr) return; //inorder left,root ,right
        inorder(root->left , ans);
        ans.push_back(root->val);
        inorder(root->right, ans);
    }
  
    vector<int> preorderTraversal(TreeNode* root) {
       vector<int> ans;
       preorder(root , ans);
      postorder(root,ans);
      inorder(root,ans);
       return ans;
    }
};
