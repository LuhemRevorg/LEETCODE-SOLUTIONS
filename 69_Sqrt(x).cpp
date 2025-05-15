int mySqrt(int x) {

    int save = 0;
    for(int i = 46341; --i;) {
        if (i*i <= x) {
            save = i;
            break;
        }
    }
    return save;
}