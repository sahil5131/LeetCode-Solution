class Solution {
public:
    void dfs(int s, vector<vector<int>>& graph, int n, vector<vector<int>>& paths, vector<int> currPath){
        if(s==n-1){
            paths.push_back(currPath);
            return;
        }
        for(auto it: graph[s]){
            currPath.push_back(it);
            dfs(it, graph, n, paths, currPath);
            currPath.pop_back();
        }
    }
    vector<vector<int>> allPathsSourceTarget(vector<vector<int>>& graph) {
        int n = graph.size();
        vector<vector<int>> paths;
        vector<int> currPath={0};
        dfs(0, graph, n, paths, currPath);
        return paths;
    }
};