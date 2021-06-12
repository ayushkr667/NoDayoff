// Given a lowercase alphabet string s and an integer k, 
// return whether we can create k palindromes using all characters in s.

// Constraints

// 0 ≤ n ≤ 100,000 where n is length of s.
// Example 1
// Input
// s = "racelevelcar"
// k = 2
// Output
// true
// Explanation
// We can make "racecar" and "level"

// Example 2
// Input
// s = "dog"
// k = 2
// Output
// false
// Explanation
// We can't make any 2-letter palindromes with the letters given.

// Example 3
// Input
// s = "dog"
// k = 3
// Output
// true
// Explanation
// Each letter is a palindrome: "d", "o", "g".

/////////////////////////////////////////////////////////////////////////////////

bool solve(string s, int k) {
    if(k > s.size())
        return false;
        
    unordered_map<char, int>mp;
    for(int i=0; i<s.size(); i++){
        mp[s[i]]++;
    }
    int odd = 0;
    int even = 0;
    for(auto it = mp.begin(); it!= mp.end(); it++){
        if( (it->second)%2 ){
            odd++;
        }
        else{
            even++;
        }
    }
    if(odd <= k)
        return true;

    return false;
}
