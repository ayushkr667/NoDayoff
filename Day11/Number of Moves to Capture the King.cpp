// You are given a two-dimensional integer matrix board containing 0s, 1s and 2s representing 
// some n x n chessboard. Each 0 represents an empty cell, 1 represents the knight and 2 
// represents the king. There is at least one knight but exactly one king.

// Given that the king stays still, return the minimum number of moves it would take 
// for some knight to land on the king. If there's no solution, return -1. A knight can't land on another knight.

// Input
// board = [
//     [1, 0, 0, 0, 0],
//     [0, 0, 0, 0, 0],
//     [0, 0, 0, 0, 2],
//     [1, 0, 0, 0, 0],
//     [0, 0, 0, 0, 0]
// ]
// Output
// 2

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

vector<vector<int>> visit; 

int dx[] = {-1, -1, 1, 1, -2, -2, 2, 2};
int dy[] = {2, -2, 2, -2, -1, 1, -1, 1};
int n;
bool isvalid(int x, int y){
    if(x >=0 && x<n && y>=0 && y<n && visit[x][y] == INT_MAX){
        return true;
    }
    return false;
}

int bfs(int c, int d, vector<vector<int>> board){
    queue<pair<int, int>> q;
    q.push({c,d});
    while(!q.empty()){
        int x = q.front().first;
        int y = q.front().second;
        q.pop();
        for(int i=0; i<8; i++){
            int x_n = x + dx[i];
            int y_n = y + dy[i];
            if(isvalid(x_n, y_n)){
                visit[x_n][y_n] = min(visit[x_n][y_n], visit[x][y] + 1);
                if(board[x_n][y_n] == 1)
                    return visit[x_n][y_n];

                q.push({x_n, y_n});
            }
        }
    }
    return -1;
}

int solve(vector<vector<int>>& board) {
    n = board.size();
    visit.assign(n, vector<int>(n, INT_MAX));
    int res = -1;
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            if(board[i][j] == 2){
                visit[i][j] = 0;
                res = bfs(i, j, board);
                break;
            }
        }
    }
    return res;
}
