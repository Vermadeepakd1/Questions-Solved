class Solution {
public:
    string addBinary(string a, string b) {
        int i = a.size() - 1, j = b.size() - 1;
        int carry = 0;
        string result = "";

        while (i >= 0 || j >= 0 || carry) {
            int bitA = i >= 0 ? a[i--] - '0' : 0;
            int bitB = j >= 0 ? b[j--] - '0' : 0;

            int sum = bitA + bitB + carry;
            result += (sum % 2) + '0';
            carry = sum / 2;
        }

        reverse(result.begin(), result.end());
        return result;
    }
};
