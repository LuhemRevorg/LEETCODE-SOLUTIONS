bool validMountainArray(int* arr, int arrSize){

    int i = 0;
    if (arrSize == 1) {return false;}
    if (*(arr + 1) < *arr) {
        return false;
    }

    while (i < arrSize - 1 && *(arr + i) < *(arr + i + 1)) {
        ++i;
    }

    if (i == arrSize - 1) {
        return false;
    }

    while (i < arrSize - 1 && *(arr + i) > *(arr + i + 1)) {
        ++i;
    }


    return i + 1 == arrSize;

}