// You are given a string s containing lowercase and uppercase 
// alphabet characters as well as digits from "0" to "9". 
// Return whether s is a palindrome if we only consider the lowercase alphabet characters.

///////////////////////////////////////////////////////////////////////////////////////////

bool solve(string s) {
    string st = "";
    for(int i=0; i<s.size(); i++){
        if(!isdigit(s[i]) && !isupper(s[i])){
            st+=s[i];
        }
    }
    string rev = st;
    reverse(st.begin(), st.end());
    return rev == st;
}


