int isBSTTraversal(int arr[], int size) {
    for(int i = 1; i < size; i++) {  
        if(arr[i] <= arr[i - 1]) {
            return 0;  // false
        }
    }
    return 1;  // true
}
