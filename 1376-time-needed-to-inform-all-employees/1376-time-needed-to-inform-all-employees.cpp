class Solution {
public:
    int numOfMinutes(int n, int headID, vector<int>& manager, vector<int>& informTime) {
        vector<pair<int, int>> adj[n];

        for(int i=0; i<n; i++){
            if(manager[i]!=-1){
                adj[manager[i]].push_back({i, informTime[manager[i]]});
            }
        }
        for(auto it: adj){
            for(auto node: it){
                cout<<node.first<<" "<<node.second<<", ";
            }
            cout<<endl;
        }
        //bfs
        queue<vector<int>> q;
        q.push({headID, informTime[headID], 0});
        vector<int> vis(n, 0);
        int time = 0;
        while(!q.empty()){
            vector<int> node = q.front();
            q.pop();
            vis[node[0]]=1;
            time = max(time, node[2]);
            for(auto it: adj[node[0]]){
                if(vis[it.first]==0){
                    q.push({it.first, it.second, node[2]+it.second});
                }
            }
           
        }
        return time;
    }
};