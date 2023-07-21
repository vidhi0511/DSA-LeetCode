class Solution {
public:
    int f(vector<int>& prices, int i, vector<vector<int>>& dp,int buy){
        if(i == prices.size()) return 0;
        if(dp[i][buy] != -1) return dp[i][buy];
        int profit=0;
        
        if(buy==1){
            profit = max(-prices[i] + f(prices, i+1, dp, 0), f(prices, i+1, dp, 1));
        }
        else{
            profit = max(prices[i] + f(prices, i+1, dp, 1), f(prices, i+1, dp, 0));
        }
       
        return dp[i][buy] = profit;
    }
    int maxProfit(vector<int>& prices) {
        int n= prices.size();
        vector<vector<int>> dp(n,vector<int>(2,-1));
        
        return f(prices, 0, dp, 1);
    }
};
