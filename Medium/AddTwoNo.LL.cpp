 Input: l1 = [2,4,3], l2 = [5,6,4]
Output: [7,0,8]
Explanation: 342 + 465 = 807.
Example 2:

Input: l1 = [0], l2 = [0]
Output: [0]
Example 3:

Input: l1 = [9,9,9,9,9,9,9], l2 = [9,9,9,9]
Output: [8,9,9,9,0,0,0,1]

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

       ----------Note -----------
        1. find sum of list1
        2. then find sum of list2;
        3. add them with carry;
        4. find carry then repeat all above steps

class Solution {
public:
      // time complexity O(N+M)
      // space complexity O(N+M)
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode* dummy = new ListNode();
        ListNode* temp = dummy;

         int carry= 0; 
         while(l1!=nullptr || l2!=nullptr || carry){
             int sum =0;
             if(l1!=nullptr){
                 sum += l1->val;
                 l1 = l1->next;
             }
             if(l2!=nullptr){
                 sum+= l2->val;
                 l2 = l2->next;
             }
             sum += carry;
             carry = sum/10;
      
      ListNode* newnode = new ListNode(sum%10);
         temp->next = newnode;
         temp = temp->next;
         }
        return dummy->next;
    }
};
