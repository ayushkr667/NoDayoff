// You are given a two-dimensional integer matrix matrix where

// 0 represents empty cell
// 1 represents a person
// 2 represents fire
// 3 represents a wall
// You can assume there's only one person and in each turn fire expands 
// in all four directions although fire can't expand through walls.

// Return whether the person can move to either the top left corner or 
// the bottom right corner. In each turn, the person moves first, 
// then the fire expands. If the person makes it to either square as 
// the same time as the fire, then they're safe.

// Note that if you go a the square and then the fire expands in the 
// same turn to the same square, you still survive.

// Example 1
// Input
// matrix = [
//     [0, 0, 0],
//     [0, 1, 0],
//     [0, 2, 0]
// ]
// Output
// true
// Explanation
// The person can get to the top left corner.

// Example 2
// Input
// matrix = [
//     [0, 2, 0],
//     [0, 1, 0],
//     [0, 2, 0]
// ]
// Output
// false
// Explanation
// There's fire getting in the way of the top left and bottom right corners.

/////////////////////////////////////////////////////////////////////////////////

int vis[301][301];
int dx[] = {1, -1, 0, 0};
int dy[] = {0, 0, 1, -1};
vector<vector<int>> mat;
int n ,m;

bool isValid(int i,int j){
    if((i >= 0 && i < n) && (j>=0 && j < m) 
            && (vis[i][j] == 0) && (mat[i][j] != 3)){
        return true;
    }
    return false;
}

bool solve(vector<vector<int>>& mati) {
    mat.clear();
    mat = mati;
    n = mat.size();
    m = mat[0].size();
    int iF = -1;
    int jF = -1;
    int sti,stj;
    queue<pair<int,int>> q1;
    queue<pair<int,int>> q2;
    for(int i=0;i<n;++i){
        for(int j=0;j<m;++j){
            vis[i][j] = 0;
            if(mat[i][j] == 2){
                q2.push({i,j});
                vis[i][j] = 1;
            }
            if(mat[i][j] == 1){
                sti = i;
                stj = j;
                vis[i][j] = 1;
            }
        }
    }
    if((mat[0][0] == 3 && mat[n-1][m-1] == 3)){
        return false;
    }
    if((sti == 0 && stj == 0) || (sti == n-1 && stj == m-1) ) {
        return true;
    }
    
    q1.push({sti,stj});
    while(!q1.empty() || !q2.empty())
    {
        int n1 = q1.size(); //bfs person
        for(int h=0;h<n1;++h){
            auto temp = q1.front();
            q1.pop();
            int x = temp.first;
            int y = temp.second;
            if((x == 0 && y == 0)  || (x == n-1 && y == m-1) ) {
                return true;
            }
            for(int i=0; i<4; i++){
                int x_n = x + dx[i];
                int y_n = y + dy[i];
                if( isValid(x_n, y_n) ){
                    q1.push({x_n, y_n});
                    vis[x_n][y_n] = 1;
                }
            }
        }

        n1 = q2.size(); // bfs fire
        for(int h=0;h<n1;++h){
            auto temp = q2.front();
            q2.pop();
            int x = temp.first;
            int  y = temp.second;
            for(int i=0; i<4; i++){
                int x_n = x + dx[i];
                int y_n = y + dy[i];
                if( isValid(x_n, y_n) ){
                    q2.push({x_n, y_n});
                    vis[x_n][y_n] = 1;
                }
            }
        }
    }
    return false;
}



