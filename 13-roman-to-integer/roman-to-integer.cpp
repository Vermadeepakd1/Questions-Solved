class Solution {
public:
    int romanToInt(string s) {
        unordered_map<char,int> mp;
        mp['I']=1;
        mp['V']=5;
        mp['X']=10;
        mp['L']=50;
        mp['C']=100;
        mp['D']=500;
        mp['M']=1000;

        int ans = 0;
        int last = 0;

        for(char ch : s){
            if(mp[ch] > last)ans -= 2*last;
            ans += mp[ch];
            last = mp[ch];
        }
        return ans;
    }
};