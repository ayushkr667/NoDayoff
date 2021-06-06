// You are given three positive integers n, lower, and upper. You want to create a list of length n 
// that is strictly increasing and then strictly decreasing and all the numbers are 
// between [lower, upper], inclusive. Each of the increasing and decreasing parts should be non-empty.

// Return the lexicographically largest list possible, or the empty list if it's not possible

// Input
// n = 5
// lower = 2
// upper = 6

// Output
// [5, 6, 5, 4, 3]

// Explanation
// Note that [6, 5, 4, 3, 2] is not valid since the strictly increasing part has to be non-empty.

//////////////////////////////////////////////////////////////////////////////////////////////////////////

vector<int> solve(int n, int lower, int upper) {
    vector<int> res;
    if((upper-lower+1) < (n+1)/2)
        return res;

    int descTerms = min(n-2, (upper-lower));

    int ascTerms = n - descTerms;

    int val = upper - ascTerms + 1;
    if( val < lower ){
        return {};
    }
    for(int i=0; i< ascTerms; i++){
        res.push_back(val++);
    }
    val = upper -1;
    for(int i= 0; i<descTerms; i++){
        res.push_back(val--);
    }
    return res;
}
