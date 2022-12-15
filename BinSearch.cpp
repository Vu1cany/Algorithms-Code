int BinSearch(int *arr, const int n, const int key) {
    int l = -1;
    int r = n;
    while (l + 1 < r) {
        int mid = (l + r) / 2;
        if (arr[mid] < key) l = mid;
        else if (arr[mid] > key) r = mid;
        else return mid;
    }
    return -1;
}