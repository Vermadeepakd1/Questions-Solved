class Solution {
  public:
    double fractionalKnapsack(vector<int>& val, vector<int>& wt, int capacity) {
        // code here
        int n = val.size();
        vector<pair<int,int>> p(n);
        
        for(int i = 0; i<n; i++){
            p[i]= {val[i],wt[i]};
        }
        
        auto lambda = [](pair<int,int>&p1, pair<int,int>&p2){
            return (1.0*p1.first)/p1.second > (1.0*p2.first)/p2.second;
        };
        
        sort(p.begin(),p.end(), lambda);
        
        double result = 0.0;
        
        for(int i = 0; i<n; i++){
            if(p[i].second <= capacity){
                result += p[i].first;
                capacity -= p[i].second;
            }else{
                result += ( (1.0*capacity)/p[i].second)*p[i].first;
                break;
            }
        }
        return result;
    }
};
