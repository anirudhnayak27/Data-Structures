#include <stdio.h>

int main() {
    int size;
    printf("Enter the size of the array: ");
    scanf("%d", &size);

    // Declare an array with a variable length
    int arr[size];

    // Initialize the array with values
    for (int i = 0; i < size; i++) {
        arr[i] = i * 2;
    }

    // Print the array
    printf("Array: ");
    for (int i = 0; i < size; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");

    return 0;
}

