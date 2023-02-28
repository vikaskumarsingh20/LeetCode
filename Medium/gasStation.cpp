Notes-
         1. first find the balance.
         2. If have enough balance then move forward. (balance >=0)
         3. otherwise can't reached one station to another station. (balance < 0)
 

          Time Complexity:(N) only onces time visit station
          Space Complexity:(1) only three variable declare.

 


class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
            int loss =0 ;
            int balance = 0;
            int start = 0 ;
        
     for(int  i=0 ; i<gas.size() ; i++){
          
         balance += gas[i] - cost[i];
         if(balance < 0){
             loss += balance; // can't reached
             start = i+1; // then try another station
             balance = 0 ;
             
         }
     }
     //have enough fuel to reached 
    if(loss + balance >= 0)
        return start;
    else
        return -1;
    }
};
