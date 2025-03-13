class Solution {
public:
    vector<string> findRestaurant(vector<string>& list1, vector<string>& list2) {
        unordered_map<int ,vector<string>> mp;
        for(int i = 0; i<list1.size(); i++){
            for(int j = 0; j<list2.size(); j++){
                if(list1[i] == list2[j]){
                    mp[i+j].push_back(list1[i]);
                }
            }
        }
        int mini = INT_MAX;
        for(auto it: mp){
            if(it.first < mini){
                mini = it.first;
            }
        }
        return mp[mini];
    }
};