/*You are required to complete this method*/
class Solution {
  public:
    int startStation(vector<int> &gas, vector<int> &cost) {
        int deficit = 0, balance = 0, start = 0;
        int n = gas.size();
        for(int i = 0 ; i<n; i++){
            balance += gas[i] - cost[i];
            
            if(balance < 0){
                deficit += balance;
                balance = 0;
                start = i+1;
            }
        }
        if(deficit + balance >=0 ){
            return start;
        }
        return -1;
    }
};