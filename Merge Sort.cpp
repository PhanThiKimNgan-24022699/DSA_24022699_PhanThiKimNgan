// Hàm trộn hai mảng con
void merge(int arr[], int left, int mid, int right) {
    int n1 = mid - left + 1;  // số phần tử mảng trái
    int n2 = right - mid;     // số phần tử mảng phải

    int* L = new int[n1];
    int* R = new int[n2];

    // Sao chép dữ liệu vào mảng tạm
    for (int i = 0; i < n1; i++) L[i] = arr[left + i];
    for (int j = 0; j < n2; j++) R[j] = arr[mid + 1 + j];

    // Gộp hai mảng
    int i = 0, j = 0, k = left;
    while (i < n1 && j < n2) {
        if (L[i] <= R[j])
            arr[k++] = L[i++];
        else
            arr[k++] = R[j++];
    }

    // Copy phần còn lại
    while (i < n1) arr[k++] = L[i++];
    while (j < n2) arr[k++] = R[j++];

    delete[] L;
    delete[] R;
}

// Thuật toán Merge Sort
void mergeSort(int arr[], int left, int right) {
    if (left < right) {
        int mid = left + (right - left) / 2;

        mergeSort(arr, left, mid);      // sắp xếp nửa đầu
        mergeSort(arr, mid + 1, right); // sắp xếp nửa sau
        merge(arr, left, mid, right);   // trộn
    }
}
