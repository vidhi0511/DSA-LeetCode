class Solution {
public:
    int hIndex(vector<int>& citations) {
        sort(citations.rbegin(), citations.rend());
        int n = citations.size();
        for(int i=0; i<n; i++){
            if(citations[i] <= i) return i;
        }
        return n;
    }
};