class RecentCounter {
public:
   queue<int> pq;
    RecentCounter() {
        
    }
    
    int ping(int t) {
        while(!pq.empty() && pq.front() < t-3000)pq.pop();
        pq.push(t);
        return pq.size();
    }
};

/**
 * Your RecentCounter object will be instantiated and called as such:
 * RecentCounter* obj = new RecentCounter();
 * int param_1 = obj->ping(t);
 */