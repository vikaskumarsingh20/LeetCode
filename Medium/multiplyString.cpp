43. Multiply Strings
Medium
5.8K
2.6K
Companies
Given two non-negative integers num1 and num2 represented as strings, return the product of num1 and num2, also represented as a string.

Note: You must not use any built-in BigInteger library or convert the inputs to integer directly.

 

Example 1:

Input: num1 = "2", num2 = "3"
Output: "6"
Example 2:

Input: num1 = "123", num2 = "456"
Output: "56088"
  //CODE

class Solution {
public:
    string multiply(string num1, string num2) {
        // handle edge-case where the product is 0
        if (num1 == "0" || num2 == "0") return "0";
        
        // num1.size() + num2.size() == max no. of digits
        vector<int> num(num1.size() + num2.size(), 0);
        
        // build the number by multiplying one digit at the time
        for (int i = num1.size() - 1; i >= 0; --i) { // ptr in ending
            for (int j = num2.size() - 1; j >= 0; --j) { // ptr in ending
            // why?1 bcz string index from 10
                num[i + j + 1] += (num1[i] - '0') * (num2[j] - '0'); // num1[i]-'0' -> str to int
                num[i + j] += num[i + j + 1] / 10; // for carry part
                num[i + j + 1] %= 10; // find reminder the add all integer
            }
        }
        
        // skip leading 0's
        int i = 0;
        while (i < num.size() && num[i] == 0) ++i;
        
        // transofrm the vector to a string
        string res = "";
        while (i < num.size()) res.push_back(num[i++] + '0');
        
        return res;
    }
};
