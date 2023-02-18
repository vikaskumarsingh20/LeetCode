1249. Minimum Remove to Make Valid Parentheses
Medium
5.6K
103
Companies
Given a string s of '(' , ')' and lowercase English characters.

Your task is to remove the minimum number of parentheses ( '(' or ')', in any positions ) so that the resulting parentheses string is valid and return any valid string.

Formally, a parentheses string is valid if and only if:

It is the empty string, contains only lowercase characters, or
It can be written as AB (A concatenated with B), where A and B are valid strings, or
It can be written as (A), where A is a valid string.
 

Example 1:

Input: s = "lee(t(c)o)de)"
Output: "lee(t(c)o)de"
Explanation: "lee(t(co)de)" , "lee(t(c)ode)" would also be accepted.
Example 2:

Input: s = "a)b(c)d"
Output: "ab(c)d"
Example 3:

Input: s = "))(("
Output: ""
Explanation: An empty string is also valid.
//CODE

/**
 * @param {string} s
 * @return {string}
 */
        Time Complexity: O(N) n-> size of the stack
        Space Complexity: O(N)
 
var minRemoveToMakeValid = (str)=> {
     const stack = []; // stack declare
  const splitted_str = str.split("");

  for (let i = 0; i < str.length; i++) {
        const char = str[i];

        if (char === "(") 
        stack.push(i); // if curr char is (  then we will push into our stack

        else if (char === ")") {
        if (stack.length === 0) {
            // if out stack is empty then we will make ) as ''
            splitted_str[i] = "";
        } else {
            //! if stack is not empty then we will pop top of the stack
            stack.pop();
        }
        }
  }
    // if we have extra ( bracket we will remove it by making it as ''
  for (let i = 0; i < stack.length; i++) {
    const char = stack[i];
    splitted_str[char] = "";
  }

  return splitted_str.join(""); // at last we will join the splitted_str
};
