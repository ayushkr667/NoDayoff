// The factorial of a number n is defined as n! = n * (n - 1) * (n - 2) * ... * 1.

// Given a positive integer a, return n such that n! = a. 
//If there is no integer n that is a factorial, then return -1.


/////////////////////////////////////////////////////////////////////////////////////////

int solve(int a) {
    int num = 1;
    int i =1;
    while(1){
        num *= i;
        if(num == a)
            return i;
        if(num > a)
            return -1;
        i++;
    }
    return -1;
}
