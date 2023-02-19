      Given an integer array nums where the elements are sorted in ascending order, convert it to a 
      height-balanced
       binary search tree.

      Example 1:
      Input: nums = [-10,-3,0,5,9]
      Output: [0,-3,9,-10,null,5]
      Explanation: [0,-10,5,null,-3,null,9] is also accepted:

      Example 2:
      Input: nums = [1,3]
      Output: [3,1]
      Explanation: [1,null,3] and [3,1] are both height-balanced BSTs.
        //CODE

      class Solution {
      public:

      /*

      Time Complexity: O(logN) ->
      Space Compexity: O(N)

      */
         TreeNode* helper(vector<int>& nums, int left, int right){

              //base case
              //If the left pointer crosses right return null;
              if(left > right){
                  return NULL;
              }

              // as middle of the array will be the root node
              int mid = (left + right) / 2;
              TreeNode* temp = new TreeNode(nums[mid]);

              //left part from middle will be left subtree
              temp->left = helper(nums, left, mid-1);

              //right part of array will be right subtree
              temp->right = helper(nums, mid+1 , right);
              return temp;
          }

          TreeNode* sortedArrayToBST(vector<int>& nums) {
              return helper(nums, 0, nums.size()-1);
          }


      };

          // JAVASCRIPTS CODE

       if (nums.length < 1) return null;
          let middle = Math.floor(nums.length/2);
          let node = new TreeNode(nums[middle]);
          node.left = sortedArrayToBST(nums.slice(0, middle))
          node.right = sortedArrayToBST(nums.slice(middle+1))
          return node;
