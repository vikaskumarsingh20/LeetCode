201. Bitwise AND of Numbers Range
Medium
2.7K
196
Companies
Given two integers left and right that represent the range [left, right], return the bitwise AND of all numbers in this range, inclusive.

 

Example 1:

Input: left = 5, right = 7
Output: 4
Example 2:

Input: left = 0, right = 0
Output: 0
Example 3:

Input: left = 1, right = 2147483647
Output: 0
  ///CODE

class Solution {
public:
  // Here not using the & operator just observe all pattern and then u can see 
  // take 1 and last and shifting one by one 0 remove and inclde 0  1 remove incldue 0
  // count all the shift and final shift all count number
    int rangeBitwiseAnd(int left, int right) {
         int shift_right = 0;
         while(left != right){
             left = left >>1;
             right = right >>1;
             shift_right++;
         }
         return right <<shift_right;
    }
};
