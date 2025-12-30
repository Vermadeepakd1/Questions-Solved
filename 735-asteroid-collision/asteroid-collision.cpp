class Solution {
public:
    vector<int> asteroidCollision(vector<int>& asteroids) {
        stack<int> st;

        for(int &at : asteroids){
            if((st.empty() && at < 0) || (at > 0)){
                st.push(at);
            }else{
                if(!st.empty() && st.top() > 0){
                    while(!st.empty() && abs(at) > st.top() && st.top() >0){
                        st.pop();
                    }
                    if(!st.empty() &&abs(at) == st.top())st.pop();
                    else if(st.empty() || ( st.top() < 0))st.push(at);
                }else{
                    st.push(at);
                }
            }
        }
        vector<int> result;
        while(!st.empty()){
            result.push_back(st.top());
            st.pop();
        }
        reverse(result.begin(),result.end());
        return result;
    }
};