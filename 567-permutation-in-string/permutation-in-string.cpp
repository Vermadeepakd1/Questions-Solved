class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        if (s1.length() > s2.length()) return false;
        vector<int> cnt1(26,0) , cnt2(26,0);

        for(char i : s1){
            cnt1[i-'a']++;
        }

        int left = 0, right = 0;

        for(right = 0; right < s1.length(); right++){
            cnt2[s2[right]-'a']++;
        }

        if(cnt1 == cnt2)return true;
        int n = s2.length();

        while(right < n){
            cnt2[s2[left]-'a']--;
            left++;
            cnt2[s2[right]-'a']++;
            right++;

            if(cnt1 == cnt2)return true;
        }
        return false;
    }
};