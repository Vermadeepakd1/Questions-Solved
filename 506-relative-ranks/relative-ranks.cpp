class Solution {
public:
    vector<string> findRelativeRanks(vector<int>& score) {
        vector<int> copy(score.begin(),score.end());
        sort(copy.rbegin(),copy.rend());
        unordered_map<int,string> mp;
        for(int i = 0; i< copy.size(); i++){
            if(i ==0){
                mp[copy[i]] = "Gold Medal";
            } else if(i ==1){
                mp[copy[i]] = "Silver Medal";
            } else if(i ==2 ){
                mp[copy[i]] = "Bronze Medal";
            } else{
                mp[copy[i]] = to_string(i+1);
            }
        }
        vector<string> result;
        for(int num : score){
            result.push_back(mp[num]);
        }
        return result;
    }
};