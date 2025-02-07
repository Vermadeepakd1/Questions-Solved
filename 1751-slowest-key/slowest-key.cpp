class Solution {
public:
    char slowestKey(vector<int>& releaseTimes, string keysPressed) {
        unordered_map<char,int>  dur;
        dur[keysPressed[0]] = releaseTimes[0];
        for(int i =1; i< releaseTimes.size(); i++){
            if(dur[keysPressed[i]]){
                dur[keysPressed[i]] = max(dur[keysPressed[i]],releaseTimes[i]-releaseTimes[i-1]);
            }
            else{
               dur[keysPressed[i]] = releaseTimes[i]-releaseTimes[i-1];
            }
        }
        int maxn = -1,maxc = -1;
        char maxi = 'a';
        for(auto &it : dur){
            if(it.second> maxn ){
                maxn = it.second;
                maxi = it.first;
            }
            else if(it.second == maxn){
                maxi = max(maxi,it.first);
            }
        }
        return maxi;
    }
};