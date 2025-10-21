class Solution {
public:
    int finalValueAfterOperations(vector<string>& operations) {
        int cnt = 0;
        for(string s : operations){
            if(s == "++X" || s== "X++"){
                cnt++;
            }else{
                cnt--;
            }
        }
        return cnt;
    }
};