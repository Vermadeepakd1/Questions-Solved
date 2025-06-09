class Solution {
  public:
    // Function to find the maximum number of meetings that can
    // be performed in a meeting room.
    void pairsort(vector<int> &start, vector<int> &end){
        int n = start.size();
        vector<pair<int,int>> p(n);
        
        for(int i = 0; i< n; i++){
            p[i].first = end[i];
            p[i].second = start[i];
        }
        
        sort(p.begin(),p.end());
        
        for(int i = 0; i<n; i++){
            start[i] = p[i].second;
            end[i] = p[i].first;
        }
    }
    
    int maxMeetings(vector<int>& start, vector<int>& end) {
        // Your code here
        
        pairsort(start,end);
        
        int n = start.size();
        
        int ans = 1;
        int curr = end[0];
        
        for(int i = 1; i<n; i++){
            if(start[i] > curr){
                ans++;
                curr = end[i];
            }
        }
        
        return ans;
    }
};