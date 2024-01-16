class Solution {
public:
    int minReorder(int n, vector<vector<int>>& connection) {
        vector<pair<int, int>> adj[n];
        for(int i=0; i<connection.size(); i++){
            adj[connection[i][0]].push_back({connection[i][1], 1});
            adj[connection[i][1]].push_back({connection[i][0], -1});
        }
        queue<pair<int, int>> q;
        q.push({0, -1});
        int ans=0;
        int cnt=0;
        vector<int> vis(n,0);
        while(!q.empty()){
            pair<int, int> node = q.front();
            q.pop();
            vis[node.first]=1;
            for(auto it: adj[node.first]){
                if(vis[it.first]==0){
                    if(it.second==-1){
                        ans++;
                    }
                    q.push({it.first, it.second});    
                    cnt++;           
                }
            }
        }
        return cnt-ans;
    }
};