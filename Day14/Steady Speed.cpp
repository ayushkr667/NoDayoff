// You are given a list of integers positions representing the position of 
// a car at equally spaced intervals of time. Return the length of the 
// longest sublist where the car was traveling at a constant speed.

///////////////////////////////////////////////////////////////////////////////

// Input
// positions = [0, 3, 6, 3, 0]
// Output
// 5
// Explanation
// The car is always traveling at 3 units of distance per time

///////////////////////////////////////////////////////////////////////////////

int solve(vector<int>& pos) {
    if(pos.size() <= 2)
        return pos.size();
    
    vector<int> speed;
    for(int i=1; i<pos.size(); i++){
        speed.push_back(abs(pos[i] - pos[i-1]));
    }
    int res = 0, temp = 1;
    // cout << speed[0] << " ";
    for(int i=1; i<speed.size(); i++){
        // cout << speed[i] << " ";
        if(speed[i] == speed[i-1]){
            temp++;
        }
        else
        {
            res = max(res, temp);
            temp = 1;
        }
        // cout << res << " ";
    }
    res = max(res, temp);
    return res+1;
}
