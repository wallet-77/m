#include<stdio.h>
#include<stdlib.h>

void fnSwap(int *a, int *b) {
    int t = *a;
    *a = *b;
    *b = t;
}

int fnPartition(int a[], int l, int r) {
    int p = a[l];
    int i = l;
    int j = r + 1;
    do {
        do { i++; } while (i <= r && a[i] < p);
        do { j--; } while (a[j] > p);
        fnSwap(&a[i], &a[j]);
    } while (i < j);
    fnSwap(&a[i], &a[j]);
    fnSwap(&a[l], &a[j]);
    return j;
}

void fnQuickSort(int a[], int l, int r) {
    int s;
    if (l < r) {
        s = fnPartition(a, l, r);
        fnQuickSort(a, l, s - 1);
        fnQuickSort(a, s + 1, r);
    }
}

void fnDispArray(int X[], int n) {
    int i;
    for (i = 0; i < n; i++)
        printf(" %5d ", X[i]);
    printf("\n");
}

int main() {
    int iaArr[] = {5, 2, 8, 1, 9, 4, 7, 3, 6};
    int iNum = sizeof(iaArr) / sizeof(iaArr[0]);

    printf("\nUnsorted Array\n");
    fnDispArray(iaArr, iNum);

    fnQuickSort(iaArr, 0, iNum - 1);

    printf("\nSorted Array\n");
    fnDispArray(iaArr, iNum);

    return 0;
}