
#include <stdio.h>
#include <stdbool.h>

int expt(int n, int x) {
    
    int i = 1;
    
    while (n) {
        i *= x;
        --n;
    }

    return i;
}


bool isPalindrome(int x) {
    
    if (x < 0) {
        return false;
    }
    
    int digits = 0;
    int save = x;
    
    while(save) {
        digits++;
        save /= 10;
    }

    int saved = x;
    for (int i = 1; i <= digits / 2; ++i) {
        if (x % 10 != (saved / expt(digits - i, 10)) % 10) {
            return false;
        }
        x /= 10;
    }

    return true;
}