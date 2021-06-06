// You are given an undirected graph represented as an adjacency list, 
//where graph[i] represents node i's neighbors.

// Return the number of possible edges that, 
//if removed, causes the graph to become disconnected.

//find bridges

////////////////////////////////////////////////////////////////////////
int In[500], vis[500], low[500], timer;
int ans = 0;

void dfs(vector<vector<int>>& graph, int node, int parent){
    vis[node] = 1;
    low[node] = In[node] = timer++;

    for(int child : graph[node] ){
        if(child == parent ) continue;

        //back edge
        if( vis[child] == 1 ){
            //minimise low time
            low[node] = min(low[node], In[child]);
        }
        else{
            dfs(graph, child, node);
            //bridge condition
            if(low[child] > In[node]){
                ans++;
            }
            low[node] = min(low[node], low[child]);
        }
    }
}



int solve(vector<vector<int>>& graph) {
    memset(In, 0, sizeof(In));
    memset(vis, 0, sizeof(vis));
    memset(low, 0, sizeof(low));

    dfs(graph, 0, -1);
    int bridges = ans;
    ans = 0;
    return bridges;
}


