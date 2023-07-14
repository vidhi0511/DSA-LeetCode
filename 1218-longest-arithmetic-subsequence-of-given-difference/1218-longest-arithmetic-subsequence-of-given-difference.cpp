class Solution {
public:
    int longestSubsequence(vector<int>& arr, int difference) {
        
        unordered_map<int,int> dp;
        int res=0;
        
        for(int i:arr){
            int num = dp.count(i - difference)>0 ? dp[i - difference] : 0;
            dp[i] = 1 + num;
            res = max(dp[i],res);
        }
        return res;
    }
};