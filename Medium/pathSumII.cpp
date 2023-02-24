Given the root of a binary tree and an integer targetSum, return all root-to-leaf paths where the sum of the node values in the path equals targetSum. Each path should be returned as a list of the node values, not node references.

A root-to-leaf path is a path starting from the root and ending at any leaf node. A leaf is a node with no children.

Example 1:


Input: root = [5,4,8,11,null,13,4,7,2,null,null,5,1], targetSum = 22
Output: [[5,4,11,2],[5,8,4,5]]
Explanation: There are two paths whose sum equals targetSum:
5 + 4 + 11 + 2 = 22
5 + 8 + 4 + 5 = 22
Example 2:


Input: root = [1,2,3], targetSum = 5
Output: []
Example 3:

Input: root = [1,2], targetSum = 0
Output: []
//CODE
        Time Complexity:O(N)
        Spce Complexity:O(N)
 
class Solution {
  public:
         vector<int>path;
        void dfs(TreeNode* root, int newtarget, vector<int>& path) {
        if (!root) return; // if current root is null return
        path.push_back(root->val);
        newtarget -= root->val; // new target will be the privious target- the value of that node
        if (newtarget == 0 &&!root->left && !root->right)  // check whether it is a leaf node or not
            // if we get valid path, pushback in our answer
                answer.push_back(path);
         
            dfs(root->left, newtarget, path);
            dfs(root->right, newtarget, path);
            path.pop_back(); // for the backtracking
    }

    vector<vector<int>> answer;
    vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
        vector<int> path;
        dfs(root, targetSum, path);// using dfs to traverse on each node
        return answer;
    }
   
};
