class Solution {
public:
    int reverseBits(int n) {
        string binary_str = bitset<32>(n).to_string();
        reverse(binary_str.begin(),binary_str.end());
        bitset<32>bits(binary_str);
        int num = bits.to_ullong();
        return num;
    }
};