void reverseArray(int arr[], int n) {
    // Code here
    int s = 0, e = n-1;
    
    while(s <= e){
        int temp = arr[e];
        arr[e] = arr[s];
        arr[s] = temp;
        s++;
        e--;
    }
}