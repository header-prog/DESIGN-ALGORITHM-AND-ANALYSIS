#include <stdio.h>

// Function to perform binary search using Divide and Conquer
int binarySearch(int arr[], int low, int high, int target) {
    if (low > high)
        return -1; // Base case: target not found

    int mid = low + (high - low) / 2; // Avoids overflow

    if (arr[mid] == target)
        return mid; // Target found

    if (arr[mid] > target)
        return binarySearch(arr, low, mid - 1, target); // Search in left half
    else
        return binarySearch(arr, mid + 1, high, target); // Search in right half
}

int main() {
    int n, target, result;

    // Taking user input for array size
    printf("Enter the number of elements in the sorted array: ");
    scanf("%d", &n);

    int arr[n];

    // Taking user input for sorted array elements
    printf("Enter %d sorted elements: ", n);
    for (int i = 0; i < n; i++)
        scanf("%d", &arr[i]);

    // Taking user input for the target element
    printf("Enter the element to search: ");
    scanf("%d", &target);

    // Calling binary search function
    result = binarySearch(arr, 0, n - 1, target);

    // Displaying the result
    if (result != -1)
        printf("Element found at index %d\n", result);
    else
        printf("Element not found in the array\n");

    return 0;
}
