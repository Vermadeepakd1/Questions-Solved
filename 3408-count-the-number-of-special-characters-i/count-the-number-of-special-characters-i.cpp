class Solution {
public:
    int numberOfSpecialChars(string word) {
        vector<bool> capital(26,false),small(26,false);

        for(char &ch : word){
            if(islower(ch)){
                small[ch-'a'] = true;
            }else{
                capital[ch-'A']= true;
            }
        }

        int cnt = 0;
        for(int i = 0; i<26; i++){
            if(capital[i] && small[i])cnt++;
        }
        return cnt;
    }
};