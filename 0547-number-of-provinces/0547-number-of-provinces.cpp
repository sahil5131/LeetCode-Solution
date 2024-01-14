class Solution {
public:

    void dfs(int i, int n, vector<vector<int>>& isConnected, vector<int>& vis){
        vis[i]=1;
        for(int j=0; j<n; j++){
            if(isConnected[i][j]==1 && i!=j && vis[j]!=1){
                dfs(j, n, isConnected, vis);
            }
        }
    }

    int findCircleNum(vector<vector<int>>& isConnected) {
        int n = isConnected.size();
        vector<int> vis(n, -1);

        int count = 0;

        for(int i=0; i<n; i++){
            if(vis[i]==-1){
                dfs(i, n, isConnected, vis);
                count++;
            }
        }

        return count;
    }
};