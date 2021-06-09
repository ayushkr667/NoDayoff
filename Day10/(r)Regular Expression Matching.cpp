// Implement regular expression matching with the following special characters:

// . (period) which matches any single character
// * (asterisk) which matches zero or more of the preceding element
// That is, implement a function that takes in a valid regular expression pattern and a s
//tring s and returns whether or not the string matches the regular expression.

// Note: The input pattern is guaranteed not to have consecutive asterisks.

// Input
// pattern = "ra."
// s = "ray"

// Output
// true

// Explanation
// We have ra and then a single character

//////////////////////////////////////////////////////////////////////////////////////////////

//.* can form 0 or more .
// mis* is same as mi or miss*. 
bool solve(string pattern, string s) {
    int row = pattern.size() + 1; //row has pattern
    int col = s.size() + 1; //col has string

    bool dp[row][col];

    for(int r=0; r<row; r++){
        for(int c=0; c<col; c++){
            //if blank string and blank pattern
            if(r==0 && c==0){
                dp[r][c] = true;
            }
            //if 0th col..means blank pattern and string till c
            else if(r == 0){
                dp[r][c] = false;
            }
            //if 0th row..means blank string and pattern till r
            else if(c == 0){
                if( pattern[r-1] == '*' ){
                    dp[r][c] = dp[r-2][c];
                }else{
                    dp[r][c] = false;
                }
            }
            //remaining cell
            else{
                if(pattern[r-1] == '*'){
                    //case1: mis* = mi 
                    dp[r][c] = dp[r-2][c];
                    //case2: mis* = miss*
                    if(pattern[r-2] == '.'||pattern[r-2] == s[c-1]){
                        dp[r][c] |= dp[r][c-1];
                    } 
                }
                else if(pattern[r-1] == '.'){
                    dp[r][c] = dp[r-1][c-1];
                }
                else if(pattern[r-1] == s[c-1]){
                    dp[r][c] = dp[r-1][c-1];
                }
                else{
                    dp[r][c] = false;
                }
            }
        }
    }
    return dp[row-1][col-1];
}
