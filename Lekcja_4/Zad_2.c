#include <stdio.h>

int binarySearchRecursive(int arr[], int left, int right, int target) {
    if (right >= left) {
        int mid = left + (right - left) / 2;

        if (arr[mid] == target)
            return mid;

        if (arr[mid] > target)
            return binarySearchRecursive(arr, left, mid - 1, target);

        return binarySearchRecursive(arr, mid + 1, right, target);
    }

    return -1;
}

int main() {
    int arr[] = {2, 4, 5, 8, 10, 12, 56, 16, 18, 20};
    int n = sizeof(arr) / sizeof(arr[0]);
    int target = 14;

    int result = binarySearchRecursive(arr, 0, n - 1, target);
    if (result == -1)
        printf("Element %d nie został znaleziony w tablicy.\n", target);
    else
        printf("Element %d został znaleziony na indeksie %d.\n", target, result);

    return 0;
}