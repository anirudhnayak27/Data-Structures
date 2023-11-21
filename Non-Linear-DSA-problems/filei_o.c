#include <stdio.h>
#include <stdlib.h>

// Function to perform bubble sort on an array of numbers
void bubble_sort(int arr[], int n) {
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                // Swap arr[j] and arr[j + 1]
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
}

int main() {
    int X;

    printf("Enter the value of X: ");
    scanf("%d", &X);

    // Open the input file for reading
    FILE* input_file = fopen("Input.txt", "r");
    if (input_file == NULL) {
        printf("Failed to open input file.\n");
        return 1;
    }

    // Read the X numbers from the input file
    int numbers[X];
    for (int i = 0; i < X; i++) {
        if (fscanf(input_file, "%d", &numbers[i]) != 1) {
            printf("Failed to read number from input file.\n");
            fclose(input_file);
            return 1;
        }
    }

    // Close the input file
    fclose(input_file);

    // Perform bubble sort on the array of numbers
    bubble_sort(numbers, X);

    // Open the output file for writing
    FILE* output_file = fopen("Output.txt", "w");
    if (output_file == NULL) {
        printf("Failed to open output file for writing.\n");
        return 1;
    }

    // Write the sorted numbers to the output file
    for (int i = 0; i < X; i++) {
        fprintf(output_file, "%d\n", numbers[i]);
    }

    // Close the output file
    fclose(output_file);

    printf("Numbers sorted and written to Output.txt.\n");

    return 0;
}

