// You are given a two-dimensional list of non-negative integers matrix
// where each element represents the height of a terrain. 
// Suppose it will rain and all the spaces in valleys get filled up.

// Return the amount of rain that would be caught between the valleys.
  
//  Input
// matrix = [
//     [3, 3, 3, 5],
//     [3, 1, 2, 3],
//     [3, 3, 3, 3]
// ]

// Output
// 3

// Explanation
// We can hold 3 unit of water in between the 1 and 2 squares.

///////////////////////////////////////////////////////////////////////////

struct cell{
    int x, y, height;
    cell(int xx, int yy, int hh) : x(xx), y(yy), height(hh){
    }
};

struct compare{
    bool operator()(cell &a, cell &b){
        return a.height > b.height;
    }
};

int solve(vector<vector<int>>& m) {
    int row = m.size();
    int col = m[0].size();

    if( row <= 2 || col <= 2 )
        return 0;

    vector<vector<bool>> visited(row, vector<bool>(col, false));

    //min heap
    priority_queue<cell, vector<cell>, compare> pq;

    //push all the boundaries in heap
    for(int y=0; y<col; ++y){
        pq.push(cell{0, y, m[0][y]});
        pq.push(cell{row-1, y, m[row-1][y]});
        visited[0][y] = visited[row-1][y] = true;
    }

    for(int x=1; x<row-1; ++x){
        pq.push(cell{x, 0, m[x][0]});
        pq.push(cell{x, col-1, m[x][col-1]});
        visited[x][0] = visited[x][col-1] = true;
    }

    int result = 0;
    vector<vector<int>> dirs{{0,1}, {1,0}, {0,-1}, {-1,0}};

    //visit each cell starting from minimim height
    while(!pq.empty()){
        cell curr = pq.top();
        pq.pop();

        //visit neighbours if valid
        for(auto &dir : dirs){
            int xx = curr.x + dir[0];
            int yy = curr.y + dir[1];

            if(xx < 0 || yy < 0 || xx >= row || yy >= col || visited[xx][yy]){
                continue;
            }

            //mark current visited
            visited[xx][yy] = true;

            //if current cell has height lower than 
            int height = m[xx][yy];
            if(height < curr.height){
                result += (curr.height - height);
                //update height to water collected
                m[xx][yy] = curr.height;
            }
            pq.push(cell{xx, yy, m[xx][yy]});
        }
    }
    return result;
}
