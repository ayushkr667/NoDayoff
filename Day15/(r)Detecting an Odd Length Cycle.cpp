// Given an undirected graph as an adjacency list, 
// return whether the graph has an odd length cycle.

///////////////////////////////////////////////////////////

//graph does not contain a cycle of odd length if and only if it is Bipartite i.e., it can be colored with two colors.
int n, m;
vector<int>color;
bool dfs(int u, vector<vector<int>>& graph){
    color[u] = 0;
    queue<int>q;
    q.push(u);
    while(!q.empty()){
        auto u = q.front();
        q.pop();

        for(int v:graph[u]){
            if(v == u )
                return true; //self loop
            if(color[v] == -1){
                color[v] = color[u]^1;
                q.push(v);
            }
            //not bipartile
            else if(color[u] == color[v]){
                return true;
            }
        }
    }
    return false;
}

bool solve(vector<vector<int>>& graph) {
    n = graph.size();
    m = graph[0].size();
    color.clear();
    for(int i=0; i<n; i++){
        color.push_back(-1);
    }

    int res = false;
    for(int i=0; i<n; i++){
        if(color[i] == -1){
            bool col = dfs(i, graph);
            for(int i=0; i<n; i++){
                cout << color[i] << " ";
            }
            cout << "\n";
            cout << col << "\n";
            res = res | col;
        }
    }
    return res;
}

