Given a string s which represents an expression, evaluate this expression and return its value. 

The integer division should truncate toward zero.

You may assume that the given expression is always valid. All intermediate results will be in the range of [-231, 231 - 1].

Note: You are not allowed to use any built-in function which evaluates strings as mathematical expressions, such as eval().

 

Example 1:

Input: s = "3+2*2"
Output: 7
Example 2:

Input: s = " 3/2 "
Output: 1
Example 3:

Input: s = " 3+5 / 2 "
Output: 5
 
code-******-------
  class Solution {
public:
    int calculate(string s) {
       stack<int> st;
        s += '+';
        int n = s.size(), ans = 0, current = 0;
        char sign = '+';
        
        for(int i=0; i<n; i++){
            
            if(isdigit(s[i])) current = current*10 + (s[i]-'0');
            
            else if(s[i] == '+' || s[i] == '-' || s[i] == '*' || s[i] == '/'){
                if(sign == '+'){
                    st.push(current);
                } 
                else if(sign == '-'){
                    st.push(-1 * (current));
                } 
                else if(sign == '*'){
                    int a = st.top();
                    st.pop();
                    st.push(a*current);
                } 
                else if(sign == '/'){
                    int a = st.top();
                    st.pop();
                    st.push(a/current);
                } 
                current = 0;
                sign = s[i];
            }
        }
        while(!st.empty()){
            ans += st.top();
            st.pop();
        }
        return ans;
    }
};
