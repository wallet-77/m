#include <stdio.h>

int merge(int a[], int low, int mid, int high);
void sort(int a[], int low, int high);

int merge(int a[], int low, int mid, int high) {
    int b[500];
    int i = low;
    int k = low;
    int j = mid + 1;

    while (i <= mid && j <= high) {
        if (a[i] < a[j]) {
            b[k++] = a[i++];
        } else {
            b[k++] = a[j++];
        }
    }
    while (i <= mid) {
        b[k++] = a[i++];
    }
    while (j <= high) {
        b[k++] = a[j++];
    }
    for (int z = low; z < k; z++) {
        a[z] = b[z]; 
    }
    return 0;
}

void sort(int a[], int low, int high) {
    int mid;
    if (low < high) {
        mid = (low + high) / 2;
        sort(a, low, mid);
        sort(a, mid + 1, high);
        merge(a, low, mid, high);
    }
}

void main() {
    int x[] = {5, 2, 8, 1};
    int n = sizeof(x) / sizeof(x[0]);
    sort(x, 0, n - 1);
    printf("[");
    for (int i = 0; i < n; i++) {
        printf("%d", x[i]);
        if (i < n - 1) {
            printf(",");
        }
    }
    printf("]\n");
}
