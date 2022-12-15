int *CountingSort(int *arr, const int n) {
    int k = -INT_MAX;
    for (int i = 0; i < n; ++i) {
        k = std::max(k, arr[i]+1);
    }
    int CountArr[k] = {0};
    for (int i = 0; i < n; ++i) {
        CountArr[arr[i]] = ++CountArr[arr[i]];  //Считаем количество каждого числа
    }
    for (int i = 1; i < k; ++i) {
        CountArr[i] = CountArr[i] + CountArr[i-1];  //Считаем правые границы нового массива
    }
    int *sortArray = new int[n];
    for (int i = n-1; i >= 0; --i) {     //Переписываем все в сорт массив
        sortArray[CountArr[arr[i]] - 1] = arr[i];
        CountArr[arr[i]]--;
    }
    return sortArray;
}