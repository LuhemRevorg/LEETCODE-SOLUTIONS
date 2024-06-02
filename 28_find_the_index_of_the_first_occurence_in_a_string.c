int strStr(char* haystack, char* needle) {

    int i = 0;
    int comp = strlen(needle);


    while (*(haystack + i)) {

        if (*(haystack + i) == *needle) {
            int j = 0;
            
            while (*(needle + j) && *(haystack + i + j) == *(needle + j)) {
                ++j;
            }
            
            if (j == comp) {
                return i;
            }
        }

        ++i;
    }


    return -1;

}