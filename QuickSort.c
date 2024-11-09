#include<stdio.h>
#include <stdbool.h>
void swap(int arr[], int nums1, int nums2) {
    int temp = arr[nums1];
    arr[nums1] = arr[nums2];
    arr[nums2] = temp;
}
int partition(int arr[], int left, int right, int pivot) {
    int leftPointer = left;
    int rightPointer = right - 1;
    while (true) {
        while (arr[leftPointer] < pivot && leftPointer < rightPointer) {
            leftPointer++;
        }
        while (arr[rightPointer] > pivot && rightPointer > left) {
            rightPointer--;
        }
        if (leftPointer >= rightPointer) {
            break;
        } else {
            swap(arr, leftPointer, rightPointer);
        }
    }
    swap(arr, leftPointer, right);  
    return leftPointer;
}
void quickSort(int arr[], int left, int right) {
    if (left >= right) return;
    int pivot = arr[right];
    int partitionPoint = partition(arr, left, right, pivot);
    quickSort(arr, left, partitionPoint - 1);
    quickSort(arr, partitionPoint + 1, right);
}
void printArray(int arr[], int size) {
    for (int i = 0; i < size; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}
int main() {
    int n;
    printf("Enter the number of elements: ");
    scanf("%d", &n);
    if (n <= 0) {
        printf("Array size must be greater than 0.\n");
        return 1;
    }
    int arr[n];
    printf("Enter the elements: ");
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }
    quickSort(arr, 0, n - 1);
    printf("Sorted array: ");
    printArray(arr, n);
    return 0;
}