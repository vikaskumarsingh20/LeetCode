Given the root of a binary tree, imagine yourself standing on the right side of it, return the values of the nodes you can see ordered from top to bottom.

 

Example 1:


Input: root = [1,2,3,null,5,null,4]
Output: [1,3,4]
Example 2:

Input: root = [1,null,3]
Output: [1,3]
Example 3:

Input: root = []
Output: [] 

Notes:
     1.Here level used to track the node.
     2.when level reached ans.size() that means node entered into a new level.
     3. then call function 1st right call & then left call .
     4. right node will be hide only can see the left node.

     Time Complexity:O(N) -> N no. nodes
     Space Complexity:O(N) -> size of vector


class Solution {
public:

    void helper(TreeNode*root , vector<int>&ans,int level){
        //base case 
        if(!root) return;
        
        // to entered into new level,tracker
        if(level == ans.size())
        ans.push_back(root->val);
    
      helper(root->left, ans, level+1);
      helper(root->right, ans,level+1);

    }
    vector<int> rightSideView(TreeNode* root) {
        vector<int>ans;
        helper(root,ans,0);
        return ans;
    }
};
