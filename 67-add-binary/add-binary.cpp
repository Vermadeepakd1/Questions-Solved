class Solution {
public:
    string addBinary(string a, string b) {
        int carry = 0;
        int n1 = a.length(), n2 = b.length();

        string result = "";
        int x=n1-1, y = n2-1;
        while(x>=0 || y>=0){
            int num1 = (x>=0 ? (a[x]-'0'):0);
            int num2 = (y>=0 ? (b[y]-'0'):0);
            int sum = num1+num2+carry;

            if(sum <=1){
                result += to_string(sum);
                carry=0;
            }else if(sum==2){
                carry = 1;
                result += '0';
            }else{
                carry=1;
                result+='1';
            }
            x--,y--;
        }
        if(carry >0)result +='1';
        reverse(result.begin(),result.end());
        return result;
    }
};