// A Roomba robot is currently sitting in a Cartesian plane at (0, 0). 
// You are given a list of its moves that it will make, containing NORTH, 
// SOUTH, WEST, and EAST.

// Return whether after its moves it will end up in the coordinate (x, y).

// Constraints

// n ≤ 100,000 where n is length of moves
// Example 1
// Input
// moves = ["NORTH", "EAST"]
// x = 1
// y = 1
// Output
// true
// Explanation
// Moving north moves it to (0, 1) and moving east moves it to (1, 1)


//////////////////////////////////////////////////////////////////////////////
bool solve(vector<string>& moves, int x, int y) {
    int pi = 0, pj = 0;
    for(int i=0; i<moves.size(); i++){
        if(moves[i] == "NORTH"){
            pj++;
        }
        if(moves[i] == "SOUTH"){
            pj--;
        }
        if(moves[i] == "EAST"){
            pi++;
        }
        if(moves[i] == "WEST"){
            pi--;
        } 
    }
    if( pi == x && pj == y){
        return true;
    } 
    return false;
}
