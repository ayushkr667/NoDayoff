// Given an integer n, you can swap any two digits at most once. 
// Return the maximum value of the resulting number.

Input
n = 1929
Output
9921
Explanation
We swap the first and the last digits

//////////////////////////////////////////////////////////////////

int solve(int n)
{
    int max_digit = -1;
    int digit_idx = -1;
    int left = -1;
    int right = -1;
 
    string str = to_string(n);

    for (int i = str.size() - 1; i >= 0; i--) {
        if (str[i] > max_digit) {
            max_digit = str[i];
            digit_idx = i;
            continue;
        }
        if(str[i] < max_digit) {
            left = i;
            right = digit_idx;
        }
    }
    swap(str[left], str[right]);
    if(left != -1)
        return stoi(str);
    return n;
}
