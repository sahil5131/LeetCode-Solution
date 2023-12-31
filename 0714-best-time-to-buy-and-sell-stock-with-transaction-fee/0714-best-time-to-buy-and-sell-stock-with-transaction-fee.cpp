class Solution {
public:
    int solve(int buy, int i, vector<int>& prices, int fee, vector<vector<int>>& dp){
        if(i>=prices.size()){
            return 0;
        }
        if(dp[i][buy]!=-1){
            return dp[i][buy];
        }
        if(buy==0){
            return dp[i][buy] = max(solve(1, i+1, prices, fee, dp)-prices[i]-fee, solve(0, i+1, prices, fee, dp));
        }else{
            return dp[i][buy] = max(solve(0, i+1, prices, fee, dp)+prices[i], solve(1, i+1, prices, fee, dp));
        }
    }
    int maxProfit(vector<int>& prices, int fee) {
        int n=prices.size();
        vector<vector<int>> dp(n, vector<int>(2, -1));
        dp[0][0] = 0;
        dp[0][1] = -prices[0] - fee;
        for(int i=1; i<n; i++){
            dp[i][0] = max(dp[i-1][0], dp[i-1][1] + prices[i]);
            dp[i][1] = max(dp[i-1][1], dp[i-1][0] - prices[i] - fee);
        }
        return dp[n-1][0];
    }
};