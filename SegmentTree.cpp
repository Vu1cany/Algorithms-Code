void buildThree(int *arr, int *arrNew, int i, int L, int R, int n) {
    if (L == R - 1) {
        if (L < n) {
            arrNew[i] = arr[L];
        }
        return;
    }
    int mid = (L + R) / 2;
    buildThree(arr, arrNew, 2 * i + 1, L, mid, n);
    buildThree(arr, arrNew, 2 * i + 2, mid, R, n);
    arrNew[i] = arrNew[2 * i + 1] + arrNew[2 * i + 2];
}

int Sum(int *arrNew, int i, int L, int R, int left, int right) {
    if (right <= L || left >= R) {
        return 0;
    } else if (left <= L && R <= right) {
        return arrNew[i];
    }

    int mid = (L + R) / 2;
    return Sum(arrNew, 2 * i + 1, L, mid, left, right) + Sum(arrNew, 2 * i + 2, mid, R, left, right);
}

void SetNew(int *arrNew, int i, int L, int R, int index, int newVal) {
    if (L == R - 1) {
        arrNew[i] = newVal;
        return;
    }

    int mid = (L + R) / 2;
    if (index < mid) {
        SetNew(arrNew, 2 * i + 1, L, mid, index, newVal);
    } else {
        SetNew(arrNew, 2 * i + 2, mid, R, index, newVal);
    }
    arrNew[i] = arrNew[2 * i + 1] + arrNew[2 * i + 2];
}