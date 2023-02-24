Given the root of a binary tree and an integer targetSum, return the number of paths where the sum of the values along the path equals targetSum.

The path does not need to start or end at the root or a leaf, but it must go downwards (i.e., traveling only from parent nodes to child nodes).

 

Example 1:


Input: root = [10,5,-3,3,2,null,11,3,-2,null,1], targetSum = 8
Output: 3
Explanation: The paths that sum to 8 are shown.
Example 2:

Input: root = [5,4,8,11,null,13,4,7,2,null,null,5,1], targetSum = 22
  
  //CODE
Notes-
     1.Brute Force Approach
     2.take two pointers one fixed and other start the moving to find the target.
     3.repeat again and again.

     Time Complexity:O(N^2)
     Space Complexity:O(N) n no. of nodes


class Solution {
public:
       int total =0;
     void findPathSum(TreeNode*root, int sum,int currentSum){
         if(root==nullptr)
           return;
        currentSum +=root->val;
        if(sum == currentSum)
            total++;
        findPathSum(root->left,sum,currentSum);
        findPathSum(root->right,sum,currentSum);
     }
    int pathSum(TreeNode* root, int targetSum) {
        if(root ==nullptr) 
          return 0;
       
        findPathSum(root,targetSum,0);
        pathSum(root->left,targetSum);
        pathSum(root->right,targetSum);
        
        return total;
    }
  
                         Optimal Solution
           Time Complexity:O(N)
           Space Complexity:O(N)

 
    class Solution {
public:
       int total=0;
    void dfs(TreeNode* root,long long tar){
        if(!root) return ;
        
        if(root->val== tar)
           total++;
        dfs(root->left, tar-(root->val));
        dfs(root->right,tar-(root->val));
    }
    
    
    int pathSum(TreeNode* root, int tar) {
        if(!root)return 0;
        
        dfs(root,tar);
        pathSum(root->left, tar);
        pathSum(root->right,tar);
        
        return total;
    }
};
