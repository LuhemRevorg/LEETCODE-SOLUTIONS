/*void merge(int* nums1, int nums1Size, int m, int* nums2, int nums2Size, int n) {
    
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < nums1Size; ++j) {
            if (*(nums2 + i) < *(nums1 + j)) {
                for (int k = nums1Size - 2; k > j; --k) {
                    *(nums1 + k + 1) = *(nums1 + k);
                }
                *(nums1 + j) = *(nums2  + i);
            }
        }
    }


}*/

void merge(int* nums1, int nums1Size, int m, int* nums2, int nums2Size, int n) {
    int i = 0, j = 0, k = 0;
    
    while (i < m && j < n) {
        if (nums2[j] < nums1[i]) {
            for (k = nums1Size - 2; k >= i; --k) {
                nums1[k + 1] = nums1[k];
            }
            nums1[i] = nums2[j];
            j++;
            m++;
        }
        i++;
    }

    // If nums2 has remaining elements
    while (j < n) {
        nums1[i++] = nums2[j++];
    }
}
