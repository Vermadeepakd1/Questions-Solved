class Solution {
public:
    vector<int> findClosestElements(vector<int>& arr, int k, int x) {
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>> > pq;

        for(int i : arr){
            pq.push({abs(i-x),i});
            cout << abs(i-x) << " " << i << endl;
        }
        vector<int>result(k);
        for(int i = 0; i<k; i++){
            auto [d,val] = pq.top();
            pq.pop();
            result[i] = val;
        }
        sort(result.begin(),result.end());
        return result;
    }
};