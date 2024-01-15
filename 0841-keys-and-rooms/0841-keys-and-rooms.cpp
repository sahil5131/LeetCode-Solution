class Solution {
public:

    void dfs(int i, set<int>& keys, vector<vector<int>>& rooms, vector<int>& vis){
        vis[i]=1;
        for(auto it: rooms[i]){
            if(vis[it]==0){
                keys.insert(it);
                dfs(it, keys, rooms, vis);
            }
        }
    }

    bool canVisitAllRooms(vector<vector<int>>& rooms) {
        int n = rooms.size();
        set<int> keys;
        keys.insert(0);
        vector<int> vis(n, 0);

        for(int i=0; i<n; i++){
            if(keys.find(i)!=keys.end() && vis[i]==0){
                dfs(i, keys, rooms, vis);
            }
        }
        for(int i=0; i<n; i++){
            if(vis[i]==0){
                return false;
            }
        }
        return true;
    }
};