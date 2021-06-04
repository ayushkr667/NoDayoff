// Given a string digits containing 2 to 9 inclusive, 
// return in sorted lexicographic order all possible 
// strings it could represent when mapping to letters on a phone dialpad.

// These are the mappings on a phone dialpad:

// | 2 | abc  |
// | 3 | def  |
// | 4 | ghi  |
// | 5 | jkl  |
// | 6 | mno  |
// | 7 | pqrs |
// | 8 | tuv  |
// | 9 | wxyz |
  
// Input
// digits = "23"
  
// Output
// ["ad", "ae", "af", "bd", "be", "bf", "cd", "ce", "cf"]

////////////////////////////////////////////////////////////////////////////////////

void solve(vector<string> vect, vector<string>&res, string d, string s, int index){

    if(s.size() == d.size()){
        res.push_back(s);
        return;
    }

    int digit = d[index] - '0';

    for(int i = 0; i<vect[digit].size(); i++){
        solve(vect, res, d, s+vect[digit][i], index+1);
    }
}

vector<string> solve(string digits) {
    vector<string> vect{ "", "", "abc", "def", "ghi", "jkl",  "mno", "pqrs", "tuv", "wxyz" };
    
    vector<string>res;
    solve(vect, res, digits, "", 0);
    sort(res.begin(), res.end());
    return res;
}
