class Solution {
public:
    int strStr(string haystack, string needle) {
        int n= haystack.size();
        int m = needle.size();

        for(int i = 0; i<n; i++){
            bool found = false;
            for(int j =i, k= 0; j<n && k<m; j++,k++){
                if(haystack[j] != needle[k]){
                    break;
                }
                if(k==m-1)found = true;
            }
            if(found)return i;
        }
        return -1;
    }
};