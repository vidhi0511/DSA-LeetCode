class Solution {
public:

    int maxProfit(vector<int>& prices) {
        vector<vector<vector<int>>> dp(prices.size()+1,vector<vector<int>>(2,vector<int>(3,0)));
        
        for(int i=prices.size()-1; i>=0; i--)
        {
            for(int buy=0;buy<=1; buy++)
            {
                for(int cap=1; cap<=2; cap++)
                {
                    
                    if(buy==1){
                        dp[i][buy][cap] = max(dp[i+1][0][cap] - prices[i], dp[i+1][1][cap]);
                    }
                    else{
                        dp[i][buy][cap] = max(dp[i+1][1][cap-1] + prices[i], dp[i+1][0][cap]);
                    }
                    
                }
            }
        }
        return dp[0][1][2];
    }
};