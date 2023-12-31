class Solution {
public:
int solve(vector<int>& prices, int n, int buy, int cap, vector<vector<vector<int>>>& t){
        if(cap==0){
            return 0;
        }
        if(n==prices.size()){
            return 0;
        }
        
        if(t[n][buy][cap]!=-1){
            return t[n][buy][cap];
        }
        int profit=0;

        if(buy){
            profit = max(-prices[n]+solve(prices, n+1, 0, cap, t), solve(prices, n+1, 1, cap, t));
        }else{
            profit = max(prices[n]+solve(prices, n+1, 1, cap-1, t), solve(prices, n+1, 0, cap, t));
        }
        return t[n][buy][cap]=profit;
    }
    int maxProfit(int cap, vector<int>& prices) {
        // int cap=2;
        int n = prices.size();
        vector<vector<vector<int>>> t(n+1, vector<vector<int>>(2, vector<int>(cap+1, -1)));
        return solve(prices, 0, 1, cap, t);
    }
};