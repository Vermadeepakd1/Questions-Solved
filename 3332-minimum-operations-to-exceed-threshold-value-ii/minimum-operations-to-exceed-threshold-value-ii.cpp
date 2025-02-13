class Solution {
public:
    int minOperations(vector<int>& nums, int k) {
        priority_queue<long long, vector<long long>, greater<long long>> pq(nums.begin(), nums.end());
        int count = 0;

        while (!pq.empty() && pq.top() < k) {
            long long smallest = pq.top(); pq.pop();
            if (pq.empty()) break; // Edge case: Single element case
            long long second_smallest = pq.top(); pq.pop();

            long long newn = smallest * 2LL + second_smallest; // Prevent overflow
            pq.push(newn);
            count++;
        }
        return count;
    }
};