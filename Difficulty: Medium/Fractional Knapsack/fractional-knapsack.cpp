// class implemented
/*
struct Item{
    int value;
    int weight;
};
*/

class Solution {
  public:
    double fractionalKnapsack(vector<int>& val, vector<int>& wt, int capacity) {
        // code here
        double profit = 0;
        int n = val.size();
        vector<int> indices(val.size());
        for(int i = 0; i<n; i++){
            indices[i] = i;
        }
        
        sort(indices.begin(), indices.end(), 
              [&](int i1, int i2) {
                return static_cast<double>(val[i1]) / wt[i1] > static_cast<double>(val[i2]) / wt[i2];
              });
              
        for(int i : indices){
            if(wt[i] <= capacity){
                profit+= (double)val[i];
                capacity -= wt[i];
            }else{
                profit += (double)val[i]*capacity/wt[i];
                break;
            }
        }
        return profit*1000000.0/1000000.0;
    }
};
