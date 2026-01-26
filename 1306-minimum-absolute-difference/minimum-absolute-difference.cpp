class Solution {
public:
    vector<vector<int>> minimumAbsDifference(vector<int>& arr) {
        map<int,vector<vector<int>> > mp;
        sort(arr.begin(),arr.end());
        int n = arr.size();
        for(int i = 0; i<n-1; i++){
            mp[arr[i+1]-arr[i]].push_back({arr[i],arr[i+1]});
        }

        vector<vector<int>> result = (mp.begin())->second;

        return result;
    }
};