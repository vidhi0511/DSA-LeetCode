class Solution {
public:
    long long putMarbles(vector<int>& weights, int k) {
        vector<int> v;
        int n = weights.size();
        
        for(int i=1;i<weights.size();i++)
        {
            int num = weights[i] + weights[i-1];
            v.push_back(num);
        }
        sort(v.begin(),v.end());
        long long ans=0;
        
        for(int i=0;i<k-1;i++)
        {
            ans += v[n-2-i]-v[i];
        }
        return ans;
    }
};