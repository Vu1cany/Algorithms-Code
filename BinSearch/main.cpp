#include <iostream>

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

int main() {
    const int N = 10;
    int arr[N] = {0, 1, 2, 3, 4, 10, 16, 20, 30, 32};
    std::cout << BinSearch(arr, N, 32);
    return 0;
}