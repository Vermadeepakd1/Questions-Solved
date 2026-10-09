class Solution {
public:

    int minInsertions(string s) {
        int count= 0,ans=0;
        int n = s.length();
        
        for(int i = 0; i<s.length(); i++){
            if(s[i]==')'){
                if( i+1 < n && s[i+1]==')'){
                    i++;
                    count--;
                    if(count<0){
                        ans++;count =0;
                    }
                }
                else{
                    ans++;
                    count--;
                    if(count<0){
                        ans++; count =0;
                    }
                }
            }
            else{
                count++;
            }
        }
        return ans+(2*count);
    }
};