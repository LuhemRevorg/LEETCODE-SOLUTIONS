bool isMonotonic(int* nums, int numsSize) {
    
    int i = 0;

    while (i < numsSize - 1 && *(nums + i) == *(nums + i + 1)) {
        ++i;
    }
    
    if (i < numsSize - 1) {
        if (*(nums + i) > *(nums + i + 1)) {
            while (i < numsSize - 1) {
                if (*(nums + i) < *(nums + i + 1)) {
                    return false;
                }
                ++i;
            }
        } else {
            while (i < numsSize - 1) {
                if (*(nums + i) > *(nums + i + 1)) {
                    return false;
                }
                ++i;
            }
        }
    }


    return true;

}
