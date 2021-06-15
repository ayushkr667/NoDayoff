// Given a two-dimensional integer matrix of 1s and 0s, return the number of
// "islands" in the matrix. A 1 represents land and 0 represents water, 
// so an island is a group of 1s that are neighboring whose perimeter is surrounded by water.
// Note: Neighbors can only be directly horizontal or vertical, not diagonal.
  
// Example 1
// Input
// matrix = [
//     [1, 1],
//     [1, 0]
// ]
// Output
// 1
// Example 2
// Input
// matrix = [
//     [1, 0, 0, 0, 0],
//     [0, 0, 1, 1, 0],
//     [0, 1, 1, 0, 0],
//     [0, 0, 0, 0, 0],
//     [1, 1, 0, 0, 1],
//     [1, 1, 0, 0, 1]
// ]
// Output
// 4

////////////////////////////////////////////////////////////////////////////////////////////////////////////////

// int dx[] = { -1, 0, 1, -1, 1, -1, 0, 1 };
// int dy[] = { -1, -1, -1, 0, 0, 1, 1, 1 };
int dx[] = {1, -1, 0, 0};
int dy[] = {0, 0, 1, -1};
vector<vector<bool>>vis;
int n, m;

bool isValid(int x, int y){
    if(x >= 0 && x < n && y >=0 && y <m && (!vis[x][y]) ){
        return true;
    }
    return false;
}

void dfs(vector<vector<int>> m, int x, int y){
    vis[x][y] = true;
    for(int i=0; i<4; i++){
        int n_x = x + dx[i];
        int n_y = y + dy[i];
        if( isValid(n_x, n_y) && m[n_x][n_y] ){
            dfs(m, n_x, n_y);
        }
    }
}

int solve(vector<vector<int>>& matrix) {
    n = matrix.size();
    m = matrix[0].size();

    vis.assign(n, vector<bool>());
    
    for(int i=0; i<n; i++){
        vis[i].assign(m, false);
    }

    int res = 0;
    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            if(matrix[i][j] && (!vis[i][j])){
                dfs(matrix, i, j);
                res++;
            }
        }
    }
    return res;
}
