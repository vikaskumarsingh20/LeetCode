class Solution {
public:

   int solveRec(vector<int>&nums1 ,vector<int>&nums2 , int index , bool swapped){
       //base case

       if(index == nums1.size())
          return 0;

     int ans = INT_MAX;
     // for compare the values 
     int prev1 = nums1[index -1];
     int prev2 = nums2[index -1];

     //catch or tricky 
       if(swapped)
       swap(prev1 ,prev2);

       //noswap case 
       if(nums1[index] > prev1 && nums2[index] > prev2)
        ans  = solveRec(nums1 ,nums2 , index+1 , 0);
    
       //swap case
        if(nums1[index] > prev2 && nums2[index] > prev1)
         ans = min(ans , 1 + solveRec(nums1 , nums2 , index +1 , 1));

         return ans;
   }

      int solveMem(vector<int>&nums1 ,vector<int>&nums2 , int index , bool swapped,vector<vector<int>>&dp){
       //base case

       if(index == nums1.size())
          return 0;
        
      if(dp[index][swapped] != -1)
         return dp[index][swapped];

     int ans = INT_MAX;
     // for compare the values 
     int prev1 = nums1[index -1];
     int prev2 = nums2[index -1];

     //catch or tricky 
       if(swapped)
       swap(prev1 ,prev2);

       //noswap case 
       if(nums1[index] > prev1 && nums2[index] > prev2)
        ans  = solveMem(nums1 ,nums2 , index+1 , 0 ,dp) ;
    
       //swap case
        if(nums1[index] > prev2 && nums2[index] > prev1)
         ans = min(ans , 1 + solveMem(nums1 , nums2 , index +1 , 1 , dp));

        return dp[index][swapped] = ans;
   }
  
   int solveTab(vector<int>&nums1 ,vector<int>&nums2){
       
       int n = nums1.size();
       vector<vector<int>> dp(n+1 , vector<int>(2, 0));

       for(int index = n-1;index >= 1;index --){
           for(int swapped = 1; swapped >= 0;swapped--){

                int ans = INT_MAX;
                // for compare the values 
                int prev1 = nums1[index -1];
                int prev2 = nums2[index -1];

                //catch or tricky 
                if(swapped)
                swap(prev1 ,prev2);

                //noswap case 
                if(nums1[index] > prev1 && nums2[index] > prev2)
                    ans  =  dp[index+1][0];
                
                //swap case
                    if(nums1[index] > prev2 && nums2[index] > prev1)
                    ans = min(ans , 1 +  dp[index+1][1]);

                 dp[index][swapped] = ans;
           }
       }

       return dp[1][0];
 
   }

   int solveSpaceOptimization(vector<int>&nums1 ,vector<int>&nums2){
       
      int n = nums1.size();
      int swap =0;
      int noswap =0;
      int currswap =0 ;
      int currnoswap =0 ;

       for(int index = n-1;index >= 1;index --){
           for(int swapped = 1; swapped >= 0;swapped--){

                int ans = INT_MAX;
                // for compare the values 
                int prev1 = nums1[index -1];
                int prev2 = nums2[index -1];

                //catch or tricky 
                if(swapped){
                  int temp = prev2;
                  prev2 = prev1;
                  prev1 = temp;
                }

                //noswap case 
                if(nums1[index] > prev1 && nums2[index] > prev2)
                    ans  =  noswap;
                
                //swap case
                    if(nums1[index] > prev2 && nums2[index] > prev1)
                    ans = min(ans , 1 + swap);

                    if(swapped)
                     currswap = ans;
                    else
                    currnoswap = ans;    
           }
           swap = currswap;
           noswap = currnoswap;
       }

        return min(swap , noswap);
 
   }

    int minSwap(vector<int>& nums1, vector<int>& nums2) {
        
        nums1.insert(nums1.begin() , -1);
        nums2.insert(nums2.begin() , -1);

     // it means that the previos index were is swapped or not 
        bool swapped = 0;
        // return solveRec(nums1 ,nums2 , 0 , swapped);
       int n = nums1.size();
        // vector<vector<int>> dp(n, vector<int>(2 , -1));
        //  return solveMem(nums1 , nums2 , 1 , swapped , dp);

        // return solveTab(nums1 , nums2);
        return solveSpaceOptimization(nums1 , nums2);
    }
};
