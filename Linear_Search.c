#include <stdio.h>
int linearSearch(int arr[], int size, int target) {
    for(int i = 0; i < size; i++) {
        if(arr[i] == target) {
            return i;
        }
    }
    return -1;
}
int main() {
    int size, target;
    printf("Enter the size of the array: ");
    scanf("%d", &size);
    if (size <= 0) {
        printf("Invalid size. Size should be a positive integer.\n");
        return 1; 
    }
    int arr[size];
    printf("Enter the array elements: ");
    for(int i = 0; i < size; i++) {
        scanf("%d", &arr[i]);
    }
    printf("Enter the target element: ");
    scanf("%d", &target);
    int search = linearSearch(arr, size, target);
    if(search != -1) {
        printf("Element found at index %d\n", search);
    } else {
        printf("Element not found\n");
    }
    return 0;
}