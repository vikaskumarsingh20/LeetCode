155. Min Stack
Medium
10.8K
712
Companies
Design a stack that supports push, pop, top, and retrieving the minimum element in constant time.

Implement the MinStack class:

MinStack() initializes the stack object.
void push(int val) pushes the element val onto the stack.
void pop() removes the element on the top of the stack.
int top() gets the top element of the stack.
int getMin() retrieves the minimum element in the stack.
You must implement a solution with O(1) time complexity for each function.

 

Example 1:

Input
["MinStack","push","push","push","getMin","pop","top","getMin"]
[[],[-2],[0],[-3],[],[],[],[]]

Output
[null,null,null,null,-3,null,0,-2]

Explanation
MinStack minStack = new MinStack();
minStack.push(-2);
minStack.push(0);
minStack.push(-3);
minStack.getMin(); // return -3
minStack.pop();
minStack.top();    // return 0
minStack.getMin(); // return -2
//CODE

TIME COMPLEXITY: O(N) //size of stack
SPACE COMPLEXITY: O(1) // not using extra memory
class MinStack {
private:
   private:
    stack<int> s1;    
    stack<int> s2;   //for store min element
public:
    void push(int val) {
	    s1.push(val);
	    if(s2.empty() || val<=s2.top()) //s2 is empty or full s1 then push element in that.
            s2.push(val);
    }
    void pop() {
	    if(s1.top()==s2.top())
            s2.pop();
	    s1.pop();
    }
    int top() {
	    return s1.top();
    }
    int getMin() {
	    return s2.top();
    }
};
