
143. Reorder List
Medium
8.2K
281
Companies
You are given the head of a singly linked-list. The list can be represented as:

L0 → L1 → … → Ln - 1 → Ln
Reorder the list to be on the following form:

L0 → Ln → L1 → Ln - 1 → L2 → Ln - 2 → …
You may not modify the values in the list's nodes. Only nodes themselves may be changed.

 

Example 1:


Input: head = [1,2,3,4]
Output: [1,4,2,3]
Example 2:


Input: head = [1,2,3,4,5]
Output: [1,5,2,4,3]
//CODE
Notes:
     1. find mid of list.
     2. divided into two list l1 & l2 .
     3. l1 have left ele from mid and l2 have right ele from mid with reverse.
     4. then merged l1 and l2.

     Time Complexity : O(N) iterate list
     Space Complexity: O(1) no using extra space 

/* Code */

class Solution {
    public void reorderList(ListNode head) {
        if(head == null || head.next == null) return;
        ListNode slow = head;
        ListNode fast = head;
        ListNode prev = head;

        while(fast != null && fast.next != null){
            prev = slow;
            slow = slow.next;
            fast = fast.next.next;
        } // break point from mid
        prev.next = null;
        ListNode l1 = head;
        ListNode l2 = reverse(slow);
        merge(l1, l2);    
    }
    
    private static ListNode reverse(ListNode l2){
        if(l2 == null) return null;
        ListNode prev = null;
        ListNode curr = l2;
        ListNode next = l2.next;
        while(curr != null){
            next = curr.next;
            curr.next = prev;
            prev = curr;
            curr = next;
        }
        return prev;
    }
    
    private static void merge(ListNode l1, ListNode l2) {
        while (l2 != null) {
            ListNode next = l1.next;
            l1.next = l2;
            l1 = l2;
            l2 = next;
        }
    }

}
