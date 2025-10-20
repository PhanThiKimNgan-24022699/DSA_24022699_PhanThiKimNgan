void swap(int &a, int &b) {
    int temp = a;
    a = b;
    b = temp;
}

//chia dãy con
int partition(int arr[], int low, int high) {
    int pivot = arr[high];  // chọn phần tử cuối làm pivot
    int i = low - 1;        // chỉ số của phần tử nhỏ hơn pivot

    for (int j = low; j < high; j++) {
        if (arr[j] < pivot) {
            i++;
            swap(arr[i], arr[j]);
        }
    }
    swap(arr[i + 1], arr[high]);
    return i + 1;  // vị trí pivot sau khi chia
}

// Thuật toán Quick Sort
void quickSort(int arr[], int low, int high) {
    if (low < high) {
        int pi = partition(arr, low, high); // chỉ số chia mảng

        quickSort(arr, low, pi - 1);   // sắp xếp bên trái
        quickSort(arr, pi + 1, high);  // sắp xếp bên phải
    }
}
