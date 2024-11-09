#include <stdio.h>
int binarySearch(int arr[], int size, int key) {
    int s = 0;
    int e = size - 1;
    int mid;
    while(s <= e) {
        mid = s + (e - s) / 2;  
        if(arr[mid] == key) {
            return mid;
        }      
        if(key > arr[mid]) {
            s = mid + 1;
        } else {
            e = mid - 1;
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
    printf("Enter the array elements in sorted order: ");
    for(int i = 0; i < size; i++) {
        scanf("%d", &arr[i]);
    }
    printf("Enter the target element: ");
    scanf("%d", &target);

    int search = binarySearch(arr, size, target);
    if(search != -1) {
        printf("Element found at index %d\n", search);
    } else {
        printf("Element not found\n");
    }
    return 0;
}
