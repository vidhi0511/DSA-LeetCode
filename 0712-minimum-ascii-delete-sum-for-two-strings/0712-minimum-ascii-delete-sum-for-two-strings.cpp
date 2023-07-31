class Solution {
public:
    int f(string &s1, string &s2,int i, int j,vector<vector<int>> &dp){
        if(i==s1.length() && j==s2.length()) 
            return dp[i][j] = 0;
        if(dp[i][j] != -1) 
            return dp[i][j];

        if(i==s1.length()) 
            return dp[i][j] = f(s1,s2,i,j+1,dp) + s2[j];
        if(j==s2.length()) 
            return dp[i][j] = f(s1,s2,i+1,j,dp) + s1[i];
        if(s1[i]==s2[j]) 
            return dp[i][j] = f(s1,s2,i+1,j+1,dp);

        dp[i][j] = min(f(s1,s2,i+1,j,dp) + s1[i], f(s1,s2,i,j+1,dp) + s2[j]);
        return dp[i][j];
    }
    int minimumDeleteSum(string s1, string s2) {
        vector<vector<int>> dp(s1.length()+1, vector<int> (s2.length()+1,-1));
        return f(s1,s2,0,0,dp);
    }
};