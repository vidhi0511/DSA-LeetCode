class Solution {
public:
    int f(int ind, vector<int>& nums, vector<int> &dp){

        if(ind<0) return 0;
        if(ind==0) return nums[ind];
        if(dp[ind] != -1) return dp[ind];
        
        int pick = nums[ind] + f(ind-2, nums, dp);
        int notpick = f(ind-1,nums,dp);
        
        dp[ind] = max(pick,notpick);
        return dp[ind];
    }
    int rob(vector<int>& nums) {
        int n=nums.size();
        vector<int> dp(n,-1);
        return f(n-1,nums,dp);
    }
};