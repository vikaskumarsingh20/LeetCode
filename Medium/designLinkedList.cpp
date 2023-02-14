/*

Complexity Analysis:

Time Complexity: O(1), We have a pointer to the head and we can directly attach a node and change the pointer. So the Time complexity of inserting a node at the head position is O(1) as it does a constant amount of work.
Auxiliary Space: O(1)

*/
class Node {
public:
 //create data structure !!
    int val;
    Node* next;
    Node(int val) {
        this->val = val;
        next = NULL;
    }
};

class MyLinkedList {
public:
    int size = 0;
    Node* head = new Node(0);
    MyLinkedList() { }

    // t.c O(N)
    //s.c O(1)
    int get(int index) {
        if(index >= size) return -1;
        Node* temp = head->next;
        for(int i = 0 ; i < index ; i++) temp = temp->next;
        return temp->val;
    }

    void addAtHead(int val) {
        Node* temp = head->next;
        head->next = new Node(val);
        head->next->next = temp;
        size++;
    }
    
    // t.c O(1)
    // s.c O(1)
    void addAtTail(int val) {
        Node* temp = head;
        while(temp->next != NULL) temp = temp->next;
        temp->next = new Node(val);
        size++;
    }
    // T.C O(n)
    // S.C O(1)
    void addAtIndex(int index, int val) {
        if(index > size) return;
        Node* temp = head;
        for(int i = 0 ; i < index ; i++) temp = temp->next;
        Node* temp1 = temp->next;
        temp->next = new Node(val);
        temp->next->next = temp1;
        size++;
    }
//t.c O(N)
//s.c O(1)
    void deleteAtIndex(int index) {
        if(index >= size) return;
        Node* temp = head;
        for(int i = 0 ; i < index ; i++) temp = temp->next;
        Node* temp1 = temp->next;
        temp->next = temp1->next;
        temp1->next = NULL;
        size--;
        delete temp1;
    }
};
/**
 * Your MyLinkedList object will be instantiated and called as such:
 * MyLinkedList* obj = new MyLinkedList();
 * int param_1 = obj->get(index);
 * obj->addAtHead(val);
 * obj->addAtTail(val);
 * obj->addAtIndex(index,val);
 * obj->deleteAtIndex(index);
 */
