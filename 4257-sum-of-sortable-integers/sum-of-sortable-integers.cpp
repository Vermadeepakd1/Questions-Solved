class Solution {
    void computelps(vector<int>&pattern, vector<int>&lps){
        int m = pattern.size();
        int len = 0;

        lps[0] = 0;
        int i = 1;
        while(i<m){
            if(pattern[i]==pattern[len]){
                len++;
                lps[i]=len;
                i++;
            }else{
                if(len != 0 ){
                    len = lps[len-1];
                }else{
                    lps[i]=0;
                    i++;
                }
            }
        }
    }

    bool kmpsearch(vector<int>&pat, vector<int>&text){
        int n = text.size();
        int m = pat.size();
        if(m==0)return true;

        vector<int>result;

        vector<int> lps(m,0);
        computelps(pat,lps);

        int i = 0; int j = 0;
        while(i<n){
            if(pat[j] == text[i]){
                i++;
                j++;
            }
            if(j==m){
                return true;
            }else if(i<n && pat[j] != text[i]){
                if(j!=0)j=lps[j-1];
                else i++;
            }
        }
        return false;
    }


    bool isrotpossible(vector<int> &vec1, vector<int> &vec2){
        vector<int> text = vec2;
        text.insert(end(text),vec2.begin(),vec2.end());

        return kmpsearch(vec1,text);
    }
public:
    int sortableIntegers(vector<int>& nums) {
        int n = nums.size();
        vector<int> sorted  = nums;
        sort(sorted.begin(),sorted.end());

        int result = 0;
        for(int k = 1; k<=n; k++){
            if(n%k )continue;
            bool valid = true;
            for(int start = 0; start <n; start+=k ){
                vector<int> vec1(nums.begin()+start, nums.begin()+start+k);
                vector<int> vec2(sorted.begin()+start, sorted.begin()+start+k);
                if(!isrotpossible(vec1,vec2)){
                    valid = false;
                    break;
                }
            }
            if(valid)result += k;
        }
        return result;
    }
};