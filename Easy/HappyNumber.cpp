202. Happy Number
Easy
7.9K
991
Companies
Write an algorithm to determine if a number n is happy.

A happy number is a number defined by the following process:

Starting with any positive integer, replace the number by the sum of the squares of its digits.
Repeat the process until the number equals 1 (where it will stay), or it loops endlessly in a cycle which does not include 1.
Those numbers for which this process ends in 1 are happy.
Return true if n is a happy number, and false if not.

 

Example 1:

Input: n = 19
Output: true
Explanation:
12 + 92 = 82
82 + 22 = 68
62 + 82 = 100
12 + 02 + 02 = 1
Example 2:

Input: n = 2
Output: false
  //CODE
  

class Solution {
public:
    bool isHappy(int n) {
        // HashTable
        map<int,int> mp;

        while(n!=1){
            int sum = 0, current = n;

            while(current){   //19 = 19%10= 9
                int digit = current % 10;
                sum += (digit * digit); // 9*9=81
                current /= 10; //19/10= 1
            }
                  // number is presented
            if(mp.find(sum)!=mp.end())
                return false;
          // insert into hashmap
            mp[sum]++;
            n = sum;
        }

        return true;

    }
};
