Given a string s containing just the characters '(', ')', '{', '}', '[' and ']', determine if the input string is valid.

An input string is valid if:

Open brackets must be closed by the same type of brackets.
Open brackets must be closed in the correct order.
 

Example 1:

Input: s = "()"
Output: true
Example 2:

Input: s = "()[]{}"
Output: true
Example 3:

Input: s = "(]"
Output: false

class Solution {
public:
bool isValid(string s) {
      stack <char>x;
      for(char&m:s){
        if(m=='('||m=='{'|| m=='['){
            x.push(m);
        }else{
            int c =m;
            int z=(!x.empty())?x.top():0;
            if((z+1)==c ||(z+2)==c){
                x.pop();
                }else{
                    x.push(m);
                }
        }
      
      }
        return x.empty();
    }
};
