class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        reverse(digits.begin(),digits.end());

        int carry = 1;
        int n = digits.size();
        for(int i = 0; i<n; i++){
            int dig = digits[i];
            int temp =carry + dig;

            carry = temp/10;
            digits[i] = temp%10;
        }
        if(carry > 0)digits.push_back(carry);

        reverse(digits.begin(),digits.end());

        return digits;
    }
};