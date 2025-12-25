class Solution {
public:
    long long maximumHappinessSum(vector<int>& happiness, int k) {
        int n = happiness.size();
        priority_queue<int, vector<int>, greater<int>> pq;
        for (int& i : happiness) {
            pq.push(i);
            if(pq.size() > k)pq.pop();
        }
        long long score = 0;
        int i = k-1;
        while(!pq.empty()){
            score += max(1LL * pq.top()-i , 0LL);
            pq.pop();
            i--;
        }
        
        return score;
    }
};