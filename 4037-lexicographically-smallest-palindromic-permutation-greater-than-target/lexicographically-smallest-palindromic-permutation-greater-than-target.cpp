class Solution {
public:
    char midchar ='%';
    int halflen =0;
    string result = "";

    bool solve(string curr, vector<int>&count, string target, int idx, bool alreadygreater){
        if(curr.length() == halflen){
            string left = curr;
            string right = curr;
            reverse(right.begin(),right.end());

            if(midchar != '%'){
                left += midchar;
            }
            left +=right;
            if(left > target){
                result = left;
                return true;}
            return false;
        }

        for(char  ch='a'; ch<='z'; ch++){
            if(count[ch-'a'] == 0)continue;

            if(!alreadygreater && ch <target[idx]){
                continue;
            }

            curr.push_back(ch);
            count[ch-'a']--;
            alreadygreater = alreadygreater || (ch > target[idx]);
            if(solve(curr,count,target,idx+1 , alreadygreater))return true;

            curr.pop_back();
            count[ch-'a']++;
        }
        return false;
    }

    string lexPalindromicPermutation(string s, string target) {
        int n = s.length();

        vector<int> count(26, 0);
        for (char& ch : s) {
            count[ch - 'a']++;
        }

        int oddcount = 0;
        for (int i = 0; i < 26; i++) {
            if (count[i] & 1) {
                oddcount++;
                midchar = i + 'a';
            }
        }
        if (oddcount > 1)
            return "";

        for(int i = 0; i<26; i++)count[i]/=2;

        halflen = n/2;

        string curr;
        if(solve(curr, count,target,0,false))return result;
        return "";

    }
};