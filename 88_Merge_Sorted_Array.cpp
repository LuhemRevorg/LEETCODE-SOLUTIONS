void merge(int* nums1, int nums1Size, int m, int* nums2, int nums2Size, int n) {
    
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


}