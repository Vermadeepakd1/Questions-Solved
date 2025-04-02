class Solution {
public:
    bool checkIfExist(vector<int>& arr) {
        set<int> st(arr.begin(),arr.end());
        int z = 0;
        for(int num : arr){
            if(num != 0 && st.count(num*2) != 0){
                return true;
            }
            if(num == 0)
                z++;
        }
        if(z > 1){
            return true;
        }
        return false;
    }
};