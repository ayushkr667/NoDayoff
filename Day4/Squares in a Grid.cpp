// Given two integers r and c, return the number of unique squares that can be made 
// from a grid with r rows and c columns of evenly-spaced points. Mod the result by 10 ** 9 + 7.

// A square consists of a set of 4 points that form the vertices of a square.
// Each side of the square must have the same length, and the square 
// does not necessarily have to be aligned with the axes of the grid.

//////////////////////////////////////////////////////////////////////////////////////////////

// SOLUTION: 

// square of side length i , which is parallel to grid axis are (r-i)(c-i)
// Now each of these squares of side I have (i-1) rotatable squares inside it
// with with various side lengths , 
// so there are submission (r-i)(c-i) squares + (r-i)(c-i)(i-1) squares (included) 
// inside it so total squares are (sum((r-i)*(c-i)*i)))


/////////////////////////////////////////////////////////////////////////////////

long long int mod = 1000000007;
int solve(int r, int c) {
    int sum = 0;
    for (int i = 1; i <= min(r, c) - 1; i++) {
        sum += ((((r - i) * (c - i)) % mod) * i) % mod;
        sum = sum % mod;
    }

    return sum % mod;
}
