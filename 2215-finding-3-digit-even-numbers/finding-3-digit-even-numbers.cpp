class Solution {
public:
    bool canmake(int i, map<int,int> freq){
        int rem = 0;
        while(i > 0){
            rem = i%10;
            if(freq[rem]){
                freq[rem]--;
            }
            else{
                return false;
            }
            if(freq[rem] == 0){
                freq.erase(rem);
            }
            i /= 10;
        }
        return true;
    }
    vector<int> findEvenNumbers(vector<int>& digits) {
        int n = digits.size();
        map<int,int> freq;
        for(int digit : digits) freq[digit]++;
        vector<int> result;
        for(int i = 100; i<=998; i=i+2){
            if(canmake(i,freq)){
                result.push_back(i);
            }
        }
        return result;
    }
};