class Solution {
public:

    int solve(int buy, vector<int>& prices, int i, vector<vector<int>>& dp){
        if(i>=prices.size()){
            return 0;
        }
        if(dp[i][buy]!=-1){
            return dp[i][buy];
        }
        if(buy==0){
            return dp[i][buy] = max(solve(1, prices, i+1, dp)-prices[i], solve(0, prices, i+1, dp));
        }
        else{
            return dp[i][buy] = max(solve(0, prices, i+2, dp)+prices[i], solve(1, prices, i+1, dp));
        }
        
    }
    int maxProfit(vector<int>& prices) {
        int buy = 0;
        int n=prices.size();
        vector<vector<int>> dp(n, vector<int>(2, -1));
        return solve(buy, prices, 0, dp);
    }
};