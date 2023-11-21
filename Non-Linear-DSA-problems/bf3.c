#include <stdio.h>

int maxSubarraySum(int arr[], int n)
{
    int max_sum = 0;
    for (int i = 0; i < n; i++) {
        int current_sum = 0;
        for (int j = i; j < n; j++) {
            current_sum += arr[j];
            if (current_sum > max_sum)
                max_sum = current_sum;
        }
    }
    return max_sum;
}

int main()
{
    int arr[] = {-2, -3, 4, -1, -2, 1, 5, -3};
    int n = sizeof(arr)/sizeof(arr[0]);
    int max_sum = maxSubarraySum(arr, n);
    printf("Maximum subarray sum is %d\n", max_sum);
    return 0;
}

