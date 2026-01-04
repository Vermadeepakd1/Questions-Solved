class Solution {
public:
    vector<vector<int>> validArrangement(vector<vector<int>>& pairs) {
        unordered_map<int,vector<int>> adj;
        unordered_map<int,int> indegree, outdegree;

        for(auto &vec : pairs){
            int u = vec[0], v = vec[1];

            adj[u].push_back(v);
            indegree[v]++;
            outdegree[u]++;
        }


        int start = pairs[0][0];
        for(auto &it : adj){
            int node = it.first;
            if(outdegree[node] - indegree[node] == 1){
                start = node;
                break;
            }
        }

        vector<int> order;
        stack<int> st;
        st.push(start);

        while(!st.empty()){
            int curr = st.top();
            if(!adj[curr].empty()){
                int nbr = adj[curr].back();
                adj[curr].pop_back();
                st.push(nbr);
            }else{
                order.push_back(curr);
                st.pop();
            }
        }

        reverse(order.begin(),order.end());

        vector<vector<int>> result;
        for(int i=1; i<order.size(); i++){
            result.push_back({order[i-1],order[i]});
        }

        return result;
    }
};