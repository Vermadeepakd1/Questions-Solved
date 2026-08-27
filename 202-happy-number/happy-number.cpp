class Solution {
public:
    bool isHappy(int n) {
        unordered_set<int> st;
        while(n!=1){
            if(st.count(n))return false;
            st.insert(n);
            int temp = 0;
            while(n!=0){
                int rem = n%10;
                n/=10;
                temp += rem*rem;
            }
            n = temp;
        }
        return true;
    }
};