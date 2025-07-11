class Solution {
    bool isVowel(char ch) {
        return (ch == 'a' || ch == 'e' || ch == 'i' || ch == 'o' || ch == 'u');
    }

public:
    long long countOfSubstrings(string word, int k) {
        int n = word.length();
        unordered_map<char, int> mp;

        vector<int> nextcons(n);
        int lastconsidx = n;
        for (int i = n - 1; i >= 0; i--) {
            nextcons[i] = lastconsidx;
            if (!isVowel(word[i])) {
                lastconsidx = i;
            }
        }

        int i = 0, j = 0;
        long long count = 0;
        int cons = 0;

        while (j < n) {
            char ch = word[j];
            if (isVowel(ch)) {
                mp[ch]++;
            } else {
                cons++;
            }

            while(cons > k){
                char ch = word[i];
                if(isVowel(ch)){
                    mp[ch]--;
                    if(mp[ch] == 0) mp.erase(ch);
                }else{
                    cons--;
                }
                i++;
            }

            while(mp.size() == 5 && cons == k){
                int idx = nextcons[j];
                count += idx - j;
                char ch = word[i];
                if(isVowel(ch)){
                    mp[ch]--;
                    if(mp[ch] == 0) mp.erase(ch);
                }else{
                    cons--;
                }
                i++;
            }
            j++;
        }
        return count;
    }
};