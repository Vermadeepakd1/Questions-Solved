//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

/*You are required to complete this function*/

class Solution {
  public:
    int maxLen(vector<int>& arr) {

        unordered_map<int,int> sumindex;
        int len = 0,currsum = 0;
        for(int i = 0; i<arr.size(); i++){
            
            currsum += arr[i];
            
            if (currsum == 0) {
                len = i + 1; // from index 0 to i
            } else if (sumindex.find(currsum) != sumindex.end()) {
                len = max(len, i - sumindex[currsum]);
            } else {
                sumindex[currsum] = i; 
            }
        }
        return len;
    }
};



//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    cin.ignore(); // to ignore the newline after the integer input
    while (t--) {
        int n;
        vector<int> a;
        string input;

        // Input format: first number n followed by the array elements
        getline(cin, input);
        stringstream ss(input);
        int num;
        while (ss >> num)
            a.push_back(num);

        Solution obj;
        cout << obj.maxLen(a) << endl;
        cout << "~\n";
    }

    return 0;
}

// } Driver Code Ends