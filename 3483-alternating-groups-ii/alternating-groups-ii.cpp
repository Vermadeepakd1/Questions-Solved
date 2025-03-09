class Solution {
public:
    int numberOfAlternatingGroups(vector<int>& colors, int k) {

        int n = colors.size();
    
    vector<bool> notAlternating(n, false);
    for (int i = 0; i < n; i++) {
        if (colors[i] == colors[(i + 1) % n]) {
            notAlternating[i] = true;
        }
    }
 
    int nonAltCount = 0;
    for (int i = 0; i < k - 1; i++) {
        if (notAlternating[i]) {
            nonAltCount++;
        }
    }
    
    int validCount = (nonAltCount == 0) ? 1 : 0;
    
    for (int i = 1; i < n; i++) {
     
        int outPos = (i - 1) % n;
        if (notAlternating[outPos]) {
            nonAltCount--;
        }
        
        int inPos = (i + k - 2) % n;
        if (notAlternating[inPos]) {
            nonAltCount++;
        }
        
        if (nonAltCount == 0) {
            validCount++;
        }
    }
    
    return validCount;
    }
};