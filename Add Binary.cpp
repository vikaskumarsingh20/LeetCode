Given two binary strings a and b, return their sum as a binary string.

 

Example 1:

Input: a = "11", b = "1"
Output: "100"
Example 2:

Input: a = "1010", b = "1011"
Output: "10101"
 

Constraints:

1 <= a.length, b.length <= 104
a and b consist only of '0' or '1' characters.
Each string does not contain leading zeros except for the zero itself.

class Solution {
public:
    string addBinary(string a, string b) {
        int i = a.size()-1;
        int j = b.size()-1;
        
        int carry = 0;
        
        string ans = "";
        
        while(i>=0 || j>=0)
        {
            if(i>=0)
            {
         
                carry += a[i] - '0';  // store last number in carry
                i--; // decrement 1st string of index
				
            }
            // same as 2nd string
            if(j>=0)
            {
              
                carry += b[j] - '0';  // store last number in carry
                j--; //decrement  2nd string of index
				
            }
            ans += (carry%2) + '0';
            carry = carry/2;
        }
        
       
        if(carry)ans += '1';  // if value of carry is still there
        
        reverse(ans.begin() , ans.end());
        return ans;
    }
};
