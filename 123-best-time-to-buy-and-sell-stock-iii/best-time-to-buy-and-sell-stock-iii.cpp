class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();

        vector<vector<int>> next(2,vector<int>(3,0)), curr(2,vector<int>(3,0));

        for(int i=n-1; i>=0; i--){
            for(int hasstock=0; hasstock<=1; hasstock++){
                for(int numstock = 0; numstock <2; numstock++){
                    int one = 0, two = 0, three= 0;

                    if(hasstock){
                        one = prices[i] + next[false][numstock+1];
                    }else{
                        two = next[true][numstock] - prices[i];
                    }
                    three = next[hasstock][numstock];

                    curr[hasstock][numstock] = max({one,two,three});
                }
            }
                next =curr;
        }

        return curr[0][0];
    }
};