24. Swap Nodes in Pairs
Medium
9.1K
353
Companies
Given a linked list, swap every two adjacent nodes and return its head. You must solve the problem without modifying the values in the list's nodes (i.e., only nodes themselves may be changed.)

 

Example 1:


Input: head = [1,2,3,4]
Output: [2,1,4,3]
Example 2:

Input: head = []
Output: []
Example 3:

Input: head = [1]
Output: [1]
//CODE

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
 


                 Time Complexity O(N) N no.of nodes
                 Space complexity O(1)


class Solution {
public:
    ListNode* swapPairs(ListNode* head) {
                //check edge cases
        if(!head || !head->next) return head;

        //swap head->value & head->next->value
        if(head != NULL && head->next != NULL){
            swap(head->val,head->next->val);
            //recursively call function on head->next->next
            swapPairs(head->next->next);
        }
        return head;
    }
};
