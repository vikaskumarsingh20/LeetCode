82. Remove Duplicates from Sorted List II
Medium
7.1K
187
Companies
Given the head of a sorted linked list, delete all nodes that have duplicate numbers, leaving only distinct numbers from the original list. Return the linked list sorted as well.

 

Example 1:


Input: head = [1,2,3,3,4,4,5]
Output: [1,2,5]
Example 2:


Input: head = [1,1,1,2,3]
Output: [2,3]

//CODE
//Recursion Method 
class Solution {
public:
    ListNode* deleteDuplicates(ListNode* head) {
        // when not found or last element 
        if (head==NULL || head->next==NULL){
            return head;
        }
        bool j = false;
        while (head->next!=NULL && head->val == head->next->val){
            j = true;
            head->next = head->next->next;
        }
        if (j){
            head = deleteDuplicates(head->next);
            return head;
        }
        head->next = deleteDuplicates(head->next);
        return head;
    }
};
// Iterratively Method

class Solution {
public:
    ListNode* deleteDuplicates(ListNode* head) {
        // create a fake node that acts like a fake head of list pointing to the original head...
        ListNode* fake = new ListNode(0);
        // fake node points to the original head...
        fake->next = head;
        ListNode* pre = fake;     //pointing to last node which has no duplicate...
        ListNode* curr = head;      // To traverse the linked list...
        // Now we traverse nodes and do the process...
        while (curr != NULL) {
            // Create a loop until the current and previous values are same, keep updating curr...
            while (curr->next != NULL && pre->next->val == curr->next->val)
                curr = curr->next;
            // if curr has non-duplicate value, move the pre pointer to next node...
            if (pre->next == curr)
                pre = pre->next;
            // If curr is updated to the last duplicate value, discard it & connect pre and curr->next...
            else
                pre->next = curr->next;
                // Move curr forward...
                // In next iteration, we still need to check whether curr points to duplicate value...
                curr = curr->next;
        }
        // Return the linked list...
        return fake->next;
    }
};
