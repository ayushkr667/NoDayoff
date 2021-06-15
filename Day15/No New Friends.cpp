// You are given n people represented as an integer 
// from 0 to n - 1, and a list of friends tuples, 
// where person friends[i][0] and person friends[i][1] are friends.

// Return whether everyone has at least one friend

///////////////////////////////////////////////////////////////////////////

bool solve(int n, vector<vector<int>>& fr) {
    vector<vector<int>> graph;
    graph.assign(n, vector<int>());
    for(int i=0; i<fr.size(); i++){
        graph[fr[i][0]].push_back(fr[i][1]);
        graph[fr[i][1]].push_back(fr[i][0]);
    }
    for(int i=0; i<n; i++){
        if(graph[i].size() == 0)
            return false;
    }
    return true;
}



