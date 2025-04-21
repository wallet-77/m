#include<stdio.h>
#include<stdlib.h>

void swapElements(int *firstElement, int *secondElement) {
    int temporary = *firstElement;
    *firstElement = *secondElement;
    *secondElement = temporary;
}

int partitionArray(int array[], int lowIndex, int highIndex) {
    int pivotValue = array[lowIndex];
    int i = lowIndex;
    int j = highIndex + 1;
    do {
        do { i++; } while (i <= highIndex && array[i] < pivotValue);
        do { j--; } while (array[j] > pivotValue);
        swapElements(&array[i], &array[j]);
    } while (i < j);
    swapElements(&array[i], &array[j]);
    swapElements(&array[lowIndex], &array[j]);
    return j;
}

void quickSortArray(int array[], int lowIndex, int highIndex) {
    int splitPoint;
    if (lowIndex < highIndex) {
        splitPoint = partitionArray(array, lowIndex, highIndex);
        quickSortArray(array, lowIndex, splitPoint - 1);
        quickSortArray(array, splitPoint + 1, highIndex);
    }
}

void displayArray(int dataArray[], int numberOfElements) {
    int i;
    for (i = 0; i < numberOfElements; i++)
        printf(" %5d ", dataArray[i]);
    printf("\n");
}

int main() {
    int integerArray[] = {5, 2, 8, 1, 9, 4, 7, 3, 6};
    int elementCount = sizeof(integerArray) / sizeof(integerArray[0]);

    printf("\nUnsorted Array\n");
    displayArray(integerArray, elementCount);

    quickSortArray(integerArray, 0, elementCount - 1);

    printf("\nSorted Array\n");
    displayArray(integerArray, elementCount);

    return 0;
}
