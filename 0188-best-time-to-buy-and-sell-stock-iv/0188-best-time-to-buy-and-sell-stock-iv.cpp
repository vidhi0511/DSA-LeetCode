class Solution {
public:
    int maxProfit(int k, vector<int>& prices) {
        vector<vector<int>> dp(prices.size()+1,vector<int>(2*k+1,0));
        
        for(int i=prices.size()-1; i>=0; i--)
        {
            
            for(int tran=2*k-1; tran>=0; tran--)
            { 
                if(tran%2 == 0){
                    dp[i][tran] = max(dp[i+1][tran+1] - prices[i], dp[i+1][tran]);
                }
                else{
                    dp[i][tran] = max(dp[i+1][tran+1] + prices[i], dp[i+1][tran]);
                }
                
            }
            
        }
        return dp[0][0];
    }
};