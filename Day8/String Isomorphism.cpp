// Given lowercase alphabet strings s, and t return whether you can create a 1-to-1 mapping for each letter in s to another 
// letter (could be the same letter) such that s could be mapped to t, 
// with the ordering of characters preserved.

// Input
// s = "coco"
// t = "kaka"
  
// Output
// true

// Explanation
// We can create this mapping:

// "c" -> "k"
// "o" -> "a"

//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

bool solve(string s, string t) {
    unordered_map<char, char>mp, mp1;

    if(s.size() != t.size())
        return false;

    for(int i=0; i<s.size(); i++){
        if( mp[s[i]] ){
            if( mp[s[i]] != t[i])
                return false;
        }
        else if( mp1[t[i]] ){
            if( mp1[t[i]] != s[i])
                return false;
        }
        else{
            mp[s[i]] = t[i];
            mp1[t[i]] = s[i];
        }
    }
    return true;
}
