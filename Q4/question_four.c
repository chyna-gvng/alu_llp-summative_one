#include <stdio.h>
#include <stdlib.h>

// Function prototypes
void bubbleSort(int arr[], int n, int (*cmp)(int, int));
int ascendingOrder(int a, int b);
int descendingOrder(int a, int b);
void printArray(int arr[], int n);

int main() {
    int grades[] = {23, 45, 31, 36, 32, 26, 29, 30, 33, 35, 28, 37, 19, 20};
    int n = sizeof(grades) / sizeof(grades[0]);

    char orderChoice[4];
    printf("Enter order choice (asc for ascending and desc for descending): ");
    scanf("%s", orderChoice);

    int (*cmp)(int, int);

    if (strcmp(orderChoice, "asc") == 0)
        cmp = ascendingOrder;
    else if (strcmp(orderChoice, "desc") == 0)
        cmp = descendingOrder;
    else {
        printf("Invalid order choice.\n");
        return 1;
    }

    bubbleSort(grades, n, cmp);

    printf("Sorted grades in %sending order: ", orderChoice);
    printArray(grades, n);

    return 0;
}

// Bubble sort algorithm
void bubbleSort(int arr[], int n, int (*cmp)(int, int)) {
    int i, j, temp;
    for (i = 0; i < n-1; i++) {
        for (j = 0; j < n-i-1; j++) {
            if ((*cmp)(arr[j], arr[j+1])) {
                // Swap elements
                temp = arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = temp;
            }
        }
    }
}

// Comparison function for ascending order
int ascendingOrder(int a, int b) {
    return a > b;
}

// Comparison function for descending order
int descendingOrder(int a, int b) {
    return a < b;
}

// Function to print array elements
void printArray(int arr[], int n) {
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}
