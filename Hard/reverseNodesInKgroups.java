
25. Reverse Nodes in k-Group
Hard
10.4K
560
Companies
Given the head of a linked list, reverse the nodes of the list k at a time, and return the modified list.

k is a positive integer and is less than or equal to the length of the linked list. If the number of nodes is not a multiple of k then left-out nodes, in the end, should remain as it is.

You may not alter the values in the list's nodes, only nodes themselves may be changed.

 

Example 1:


Input: head = [1,2,3,4,5], k = 2
Output: [2,1,4,3,5]
Example 2:


Input: head = [1,2,3,4,5], k = 3
Output: [3,2,1,4,5]

 
 Time Complexity :O(N) iterate over list
 Space Complexity: O(N)


   //CODE
class Solution {
    public ListNode reverseKGroup(ListNode head, int k) {
        if(head==null || k==1) return head;

        ListNode temp = new ListNode();
        temp.next = head;

        ListNode curr = temp;
        ListNode next = temp;
        ListNode prev = temp;

        int count=0; 
    // counting number of nodes.
        while(curr.next!=null){
            curr = curr.next;            
            count++;
        }
       /*
          iterate till groups of k.   
          put curr at first and nex at second node of that group.
          rum loop K-1 times and revrerse every link.

       */
        while(count>=k){                
            curr = prev.next;            
            next = curr.next;           
            for(int i=1;i<k;i++){        
                curr.next = next.next;
                next.next = prev.next;
                prev.next = next;
                next = curr.next;
            }
            /*
               to make pre stand at last node of previous reversed group of size k.
               decrementing count by k as the group is reversed and we move to next group of k if present.
               t
            */
            prev = curr;                  
            count-=k;                   
        }
        return temp.next;
    }
}
