// Given two strings s0 and s1, return whether they are anagrams of each other.

//////////////////////////////////////////////////////////////////////////////////////



bool solve(string s0, string s1) {
    sort(s0.begin(), s0.end());
    sort(s1.begin(), s1.end());
    if( s0 == s1)
        return true;
    return false;
}
