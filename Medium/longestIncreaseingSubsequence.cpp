class Solution
{
    public:
    
    int solveRec(int n , int a[] , int curr , int prev){
        // base case
         if(curr == n)
          return 0;
           
         // include
        int take = 0;
        if(prev == -1 || a[curr] > a[prev]){
          take = 1 + solveRec(n, a, curr +1 , curr);
         
         // exclude
         int nottake = 0 + solveRec(n, a , curr +1 , prev);
         
         return max(take , nottake);
    }
     // TOP DOWN APPROACH
int solveMem(int n , int a[] , int curr , int prev , vector<vector<int>>&dp){
        // base case
         if(curr == n)
          return 0;
           
          if(dp[curr][prev+1] != -1)
              return dp[curr][prev+1];
              
         // include
         int take = 0;
        if(prev == -1 || a[curr] > a[prev]){
          take = 1 + solveMem(n, a, curr +1 , curr,dp);
        }
         // exclude
         int nottake = 0 + solveMem(n, a , curr +1 , prev,dp);
         
         return dp[curr][prev+1] =  max(take , nottake);
          
    }
    //BOTTOM UP APPROACH     //T.C O(N^2) S.C O(N^2)
    int solveTab(int n , int a[]){
        
        vector<vector<int>> dp(n+1, vector<int>(n+1 , 0));
        
        for(int curr = n-1 ; curr >= 0 ;curr--){
            for(int prev = curr-1;prev>=-1;prev--){
                
                //include
                 int take = 0;
                if(prev == -1 || a[curr] > a[prev]){
                  take = 1 + dp[curr+1][curr+1];
                }
                 // exclude
                 int nottake = 0 +  dp[curr+1][prev+1];
                 
                dp[curr][prev+1] =  max(take , nottake);
            }
        }
     return   dp[0][0];
    }
     //SPACE OPTIMAZATION WITH T.C O(NlogN) & S.C O(N)
    int solveOptimalSol(int n, int a[]){
        if(n == 0)
          return 0;
    
    vector<int>ans;
    ans.push_back(a[0]);
    
    for(int  i = 0 ;i<n;i++){
        if(a[i] > ans.back()){
            ans.push_back(a[i]);
        }
        else{
         int index = lower_bound(ans.begin(),ans.end(),a[i]) -ans.begin();
         ans[index] = a[i];
        }
    }
    return ans.size();
    }  
    //Function to find length of longest increasing subsequence.
    int longestSubsequence(int n, int a[])
    {
        // return solveRec(n, a, 0 , -1); // -1 last index
        
        // vector<vector<int>> dp(n, vector<int>(n+1 ,-1));
        // solveMem(n, a , 0, -1 , dp);
        
       return solveOptimalSol(n, a);
    }
};
