void QuickSort(int *arr, int left, int right) {
    int i = left;
    int j = right;
    int pivot = arr[(i+j)/2];
    while (i <= j) {
        while (arr[i] < pivot) i++;
        while (arr[j] > pivot) j--;
        if (i <= j) std::swap(arr[i++], arr[j--]);
    }
    if (left < j) QuickSort(arr, left, j);
    if (right > i) QuickSort(arr, i, right);
}