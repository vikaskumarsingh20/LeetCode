 
                       
  Approach1- Brute Force Approach
                         Time Complexity:(N^2) two interations
                         Space Complexity:(1) only two variable

           int maxProfit(vector<int>*prices){
               int n = prices.size();
               int maxprofit = 0;
               for(int i=0;i<n;i++){
                   for(int j=i+1;j<n;j++){
                       int prfit = prices[j]-prices[i];
                       if(profit >maxprices)
                       profit = maxprofit;
                   }
               }
               return maxprofit;
           }


                        Approach2.

         Time complexity:  O(n). Only a single pass is needed.
        Space complexity: O(1). Only two variables are used.

 
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int mini = prices[0];
        int profit = 0;

        for(int  i = 1;i< prices.size();i++){
             int compare = prices[i] - mini;  
             profit = max(profit , compare);
             mini = min(mini , prices[i]);
        }
        return profit;
    }
};
