class Solution {
public:
    int solve(int i, int transactions, int buy, vector<int>& prices, vector<vector<vector<int>>>& dp){
        if(i==prices.size()){
            return 0;
        }
        if(transactions==2){
            return 0;
        }
        if(dp[i][transactions][buy]!=-1){
            return dp[i][transactions][buy];
        }
        if(buy==0){
            return dp[i][transactions][buy]=max(-prices[i]+solve(i+1, transactions, 1, prices, dp), solve(i+1, transactions, 0, prices, dp));
        }else{
            return dp[i][transactions][buy] =  max(solve(i+1, transactions+1, 0, prices, dp)+prices[i], solve(i+1, transactions, 1, prices, dp));
        }
    }
    int maxProfit(vector<int>& prices) {
        int n=prices.size();
        vector<vector<vector<int>>> dp(n, vector<vector<int>>(2, vector<int>(2, -1)));
        return solve(0, 0, 0, prices, dp);
    }
};