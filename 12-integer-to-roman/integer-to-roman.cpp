class Solution {
public:
    string intToRoman(int num) {
        unordered_map<int,string> mp;
        mp[1]="I", mp[4]="IV", mp[9]="IX", mp[5]="V", mp[10]="X", mp[40]="XL", mp[50]="L",mp[90]="XC", mp[100]="C", mp[400]="CD",mp[500]="D", mp[900]="CM", mp[1000]="M";

        vector<int> val = {1000,900,500,400,100,90,50,40,10,9,5,4,1};

        string result = "";
        int i = 0;
        while(num!=0){
            while(num >= val[i]){
                num -= val[i];
                result += mp[val[i]];
            }
            i++;
        }
        return result;
    }
};