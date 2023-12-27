class Solution {
public:
    //direction in which we can move
    vector<pair<int, int>> dir{
        {1 ,0}, {0, 1}, {-1,0}, {0,-1}
    };

    //function for searching island
    void dfs(int i, int j, int m, int n, vector<vector<char>>& grid,vector<vector<int>>& vis){
        if(i<0 || i>=m || j<0 || j>=n || grid[i][j]=='0' || vis[i][j]==1){
            return ;
        }
        vis[i][j]=1;
        for(auto it: dir){
            int x=it.first+i;
            int y=it.second+j;
            dfs(x, y, m, n, grid, vis);
        }
    }

    int numIslands(vector<vector<char>>& grid) {
        int m=grid.size();
        int n=grid[0].size();

        //vector to store place is visited or not
        vector<vector<int>> vis(m, vector<int>(n, 0));

        //store count of island
        int island_count = 0;

        //check all the possible island
        for(int i=0; i<m; i++){
            for(int j=0; j<n; j++){
                if(vis[i][j]==0 && grid[i][j]=='1'){
                    dfs(i, j, m, n, grid, vis);
                    island_count++;
                }
            }
        }

        return island_count;
    }
};