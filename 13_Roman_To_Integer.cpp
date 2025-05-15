int romanToInt(char* s) {
    int i = 0;
    int val = 0;
    
    while (*(s+i)){
        char *curr = s+i;
        if (*curr == 'I') {
            if (*(curr+1) == 'X') {
                val += 9;
                ++i;
            } else if (*(curr+1) == 'V') {
                val += 4;
                ++i;
            } else {
                val+=1;
            }
        } else if (*curr == 'V') {
            val += 5;
        } else if (*curr == 'X') {
            if (*(curr+1)=='L') {
                val+=40;
                ++i;
            } else if (*(curr+1)=='C') {
                val+=90;
                ++i;
            } else {
                val+=10;
            }
        } else if (*curr == 'L') {
            val+=50;
        } else if (*curr=='C') {
            if (*(curr+1)=='D') {
                val+=400;
                ++i;
            } else if (*(curr+1)=='M') {
                val+=900;
                ++i;
            } else {
                val+=100;
            }
        } else if (*curr == 'D') {
            val+=500;
        } else if (*curr=='M') {
            val+=1000;
        }

        ++i;    
    
    }

    

    return val;

}