class Solution {
public:
    char kthCharacter(int k) {
        string word = "a";
        string temp = "";
        int l = k;
        while(k--){
            temp = "";
            for(char c : word){
                if(c == 'z') temp += 'a';
                else temp += (c +1);
            }
            word += temp;

            cout << word << " " << temp << " " << word.length() << endl;
            if(word.length() >= l) break;
        }
        return word[l-1];
    }
};