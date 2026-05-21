class Solution {
public:
    int longestCommonPrefix(vector<int>& arr1, vector<int>& arr2) {
        int maxi = 0;
        int n = arr1.size(),m = arr2.size();
        set<string> st;
        for(int num : arr1){
            string s = to_string(num);
            string temp = "";
            for(char ch : s){
                temp += ch;
                st.insert(temp);
            }
        }

        for(int num : arr2){
            string s = to_string(num);
            string temp = "";
            for(char ch : s){
                temp += ch;
                if(st.count(temp)){
                    int l = temp.length();
                    maxi = max(maxi,l);
                }
            }
        }
        return maxi;
    }
};