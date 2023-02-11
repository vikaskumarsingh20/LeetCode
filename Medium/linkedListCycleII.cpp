Given the head of a linked list, return the node where the cycle begins. If there is no cycle, return null.

There is a cycle in a linked list if there is some node in the list that can be reached again by continuously following the next pointer. Internally, pos is used to denote the index of the node that tail's next pointer is connected to (0-indexed). It is -1 if there is no cycle. Note that pos is not passed as a parameter.

Do not modify the linked list.

 

Example 1:


Input: head = [3,2,0,-4], pos = 1
Output: tail connects to node index 1
Explanation: There is a cycle in the linked list, where tail connects to the second node.
Example 2:


Input: head = [1,2], pos = 0
Output: tail connects to node index 0
Explanation: There is a cycle in the linked list, where tail connects to the first node.
Example 3:


Input: head = [1], pos = -1
Output: no cycle
Explanation: There is no cycle in the linked list
//CODE


/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
      // space complexity O(N) by hashing , there is exit best sol with SC (1)
    ListNode *detectCycle(ListNode *head) {
        unordered_set<ListNode*>set; // create hash table
        ListNode*curr = head;

        while(curr!= nullptr){
            // if found starting index o loop then simply return
            if(set.find(curr)!= set.end()){
                return curr;
            }
            // if not then insert into hash table
            else{
                set.insert(curr);
               curr= curr->next;
            }
        }
        return nullptr;
    }
};



class Solution {
public: // time complexity O(1)
    ListNode *detectCycle(ListNode *head) {
        if(head == NULL) return NULL;
        ListNode*slow = head;
        ListNode*fast = head;
        ListNode*entry = head;
        while(fast->next != NULL && fast->next->next != NULL){
            slow = slow->next;
            fast = fast->next->next;
            
            if(slow == fast){ // found the cycle the start traversal
                while(entry != slow){
                    slow = slow->next;
                    entry = entry->next;
                }
                return slow;
            }
        }
        return NULL;
    }
};
