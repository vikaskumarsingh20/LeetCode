
Notes:
     1.Travesal in leftToRight and RightToLeft.
     2.take a queue and push tree's elements one by one.
     3.after pushed ele then pop and again push its child inot queue.
     4.Repeat this step until all tree will not complete.

     Time Complexity: O(N) ->N N0. of nodes
     Space Complexity:O(W) -> size of width of tree.


Example : `root` = [3,9,20,null,null,15,7]

Initially `queue` = [3], level = 0
In first pass
    size = 1 `queue` = [3]
    `curr[0]` = 3
    We push 3->left and 3->right in queue
    `queue` = [9, 20]
    So our loop only run 1 time beacuase size is 1.

Now we push curr to `output` vector `output` = [[3]]
Now `level` = 1

In Second pass
    size = 2 `queue` = [9, 20]
    `curr[1]` = 20
    `curr[0]` = 9
    We push 20->left and 20->right in queue
    `queue` = [15, 7]
    And 9->left = NULL , 9->right = NULL so we do not push it.
    So our loop run 2 times beacuase size is 2.

Now we push curr to `output` vector `output` = [[3], [20, 9]]
Now `level` = 0

In this way me iterate for the 15 and 7.
So answer is `[[3], [20, 9], [15, 7]]
//CODE

class Solution {
public:
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        
        if (!root) return {}; // no element ,simply return
        
        queue<TreeNode*> q;
        vector<vector<int>> out;
            
        q.push(root);  
        bool level = false; /* to alternate levels, or a bool variable */
        
        while (!q.empty()) {
            
            int sz = q.size();  
            vector<int> curr(sz); 
            
            for (int i = 0; i < sz; i++) {
                
                TreeNode* tmp = q.front();
                q.pop();
                
                if (level == 0) {
                    curr[i] = tmp->val; // odd level, insert like 0, 1, 2, 3 etc. 
                } else {
                    curr[sz - i - 1] = tmp->val; /* even level insert from end. 3, 2, 1, 0. (sz - i - 1) to get the index from end */
                }
                
                if (tmp->left) q.push(tmp->left);
                if (tmp->right) q.push(tmp->right);
            }
            out.push_back(curr); // now push the level traversed to output vector
            level = !level; // toggle the level using negation. or level == 0 ? level = 1 : level = 0;
        }
        return out;
    }
};
