
/**
 * Definition for singly-linked list.
 * public class ListNode {
 *     int val;
 *     ListNode next;
 *     ListNode(int x) {
 *         val = x;
 *         next = null;
 *     }
 * }
 */

 Time Complexity: O(N)
 Space Complexity:O(1)
   
   
public class Solution {
    public ListNode getIntersectionNode(ListNode headA, ListNode headB) {


        
        int sizeA = 0;      //stores size of listA.
        int sizeB = 0;      //stores size of listA.

        //declare temp pointer initially. (saves space)
        ListNode temp;

        //traverse listA and store its size in sizeA variable.
        for(temp = headA; temp != null; temp = temp.next)
        {
            //increment sizeA with each next node.
            sizeA++;            
        }
        
        //traverse listB and store its size in sizeB variable.
        for(temp = headB; temp != null; temp = temp.next)
        {
            //increment sizeA with each next node.
            sizeB++;         
        }

        //Now make the two lists equal by removing nodes of
        //the greater list.

        //if size of listA is greater than size of listB.
        while(sizeA > sizeB)
        {
            //go to next node of the listA.
            headA = headA.next;
            sizeA--;
        }

        //similarly, do it if sizeB > sizeA
        while(sizeB > sizeA)
        {
            headB = headB.next;
            sizeB--;
        }

        //check the nodes untill the node becomes equal.
        while(headA != headB)
        {
            headA = headA.next;
            headB = headB.next;
        }

        //finally, return either of the two nodes.
        //if there is no intersection, then headA and headB
        //will point to null.
        return headA;       //return headB;        
    }
}
