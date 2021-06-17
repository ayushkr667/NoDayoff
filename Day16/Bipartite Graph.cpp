//Given an undirected graph represented as an 
//adjacency list, return whether the graph is bipartite.

////////////////////////////////////////////////////////////////

vector<int>color;
bool dfs(int u, vector<vector<int>>& graph){
    color[u] = 0;
    queue<int>q;
    q.push(u);
    while(!q.empty()){
        auto u = q.front();
        q.pop();

        for(int v:graph[u]){
            if(color[v] == -1){
                color[v] = !color[u];
                q.push(v);
            }
            //not bipartile
            else if(color[u] == color[v]){
                return false;
            }
        }
    }
    return true;
}

bool solve(vector<vector<int>>& graph) {
    int n = graph.size();
    color.clear();
    color.assign(n, -1);
    bool flag = true;
    for(int i=0; i<n; i++){
        if(color[i] == -1){
            flag = flag & dfs(i,graph);
        }
    }
    return flag;
}
