long long int _mergeSort(long long int arr[], long long int temp[], 
                 long long int left,long long  int right);
long long int merge(long long int arr[], long long int temp[], long long int left, 
                  long long  int mid, long long int right);
long long int mergeSort(long long int arr[],long long int n)
{
   long long  int temp[n];
    return mergeSortarray(arr, temp, 0, n-1);
}
long long int mergeSortarray(long long int arr[],long long int temp[],  long long int left,long long  int right)
{
    long long int mid, inv_count = 0;
    if (right > left) {
        mid = (right + left) / 2;
        inv_count += mergeSortarray(arr, temp, 
                                left, mid);
        inv_count += mergeSortarray(arr, temp, 
                            mid + 1, right);
        inv_count += merge(arr, temp, left, 
                           mid + 1, right);
    }
    return inv_count;
}

long long int merge(long long int arr[], long long int temp[],long long  int left,
         long long  int mid, long long int right)
{
    int i, j, k;
    int inv_count = 0;

    i = left; 
    j = mid;
    k = left;
    while ((i <= mid - 1) && (j <= right)) {
        if (arr[i] <= arr[j]) {
            temp[k++] = arr[i++];
        }
        else {
            temp[k++] = arr[j++];
            inv_count = inv_count + (mid - i);
        }
    }

    while (i <= mid - 1)
        temp[k++] = arr[i++];
    while (j <= right)
        temp[k++] = arr[j++];
    for (i = left; i <= right; i++)
        arr[i] = temp[i];

    return inv_count;
}

long long int inversionCount(long long arr[], long long N)
{
    // Your Code Here
    return (mergeSort(arr,N));
}