#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> jobSequencing(vector<int> &deadline, vector<int> &profit) {
        int n = deadline.size();

        // Step 1: Store jobs as (profit, deadline)
        vector<pair<int, int>> jobs(n);
        for (int i = 0; i < n; i++) {
            jobs[i] = {profit[i], deadline[i]};
        }

        // Step 2: Sort jobs by profit in descending order
        sort(jobs.rbegin(), jobs.rend());

        // Step 3: Find max deadline
        int maxDeadline = *max_element(deadline.begin(), deadline.end());

        // Step 4: Initialize available time slots
        vector<int> parent(maxDeadline + 1);
        for (int i = 0; i <= maxDeadline; i++) parent[i] = i;

        // Helper function: find the latest available slot
        function<int(int)> find = [&](int x) {
            if (parent[x] == x) return x;
            return parent[x] = find(parent[x]); // path compression
        };

        int totalJobs = 0, totalProfit = 0;

        for (auto &job : jobs) {
            int available = find(job.second);
            if (available > 0) {
                // Assign job to this slot
                totalJobs++;
                totalProfit += job.first;

                // Mark this slot as used (merge with previous)
                parent[available] = find(available - 1);
            }
        }

        return {totalJobs, totalProfit};
    }
};
