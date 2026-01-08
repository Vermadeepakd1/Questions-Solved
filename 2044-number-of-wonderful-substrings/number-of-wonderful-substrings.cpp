class Solution {
    typedef long long ll;
public:
    long long wonderfulSubstrings(string word) {
        unordered_map<ll,ll> mp;
        ll cumxor = 0;
        mp[cumxor]++;

        ll result = 0;

        for(char &ch : word){
            cumxor ^= (1 << (ch-'a'));
            result += mp[cumxor];
            for(char c = 'a';c <= 'j'; c++){
                result += mp[(cumxor ^ (1 << (c-'a')))];
            }
            mp[cumxor]++;
        }
        return result;
    }
};