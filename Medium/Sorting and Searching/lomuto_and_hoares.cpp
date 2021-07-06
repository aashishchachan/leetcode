//Lomuto’s Partition Scheme:

int partition_lomuto(int arr[], int low, int high){
    int pivot = arr[high];    
    int i = (low - 1); 
 
    for (int j = low; j <= high- 1; j++) {
        if (arr[j] <= pivot)  {
            i++;    
            swap(arr[i], arr[j]);
        }
    }
    swap(arr[i + 1], arr[high]);
    return (i + 1);
}

//Hoare’s Partition Scheme:

int partition_hoares(int arr[], int low, int high){
    int pivot = arr[low];
    int i = low - 1, j = high + 1;
 
    while (true) {
        // Find leftmost element greater than
        // or equal to pivot
        do {
            i++;
        } while (arr[i] < pivot);
 
        // Find rightmost element smaller than
        // or equal to pivot
        do {
            j--;
        } while (arr[j] > pivot);
 
        // If two pointers met.
        if (i >= j)
            return j;
 
        swap(arr[i], arr[j]);
    }
}