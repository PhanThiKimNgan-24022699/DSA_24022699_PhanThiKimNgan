class priorityQueue {
private:
    vector<int> heap;
    //// Hàm hỗ trợ: đẩy phần tử lên đúng vị trí để đảm bảo max-heap
    void swim(int k) {
        while (k > 0 && heap[k] > heap[(k - 1) / 2]) {
            swap(heap[k], heap[(k - 1) / 2]);
            k = (k - 1) / 2;
        }
    }
    //đẩy xuống
    void sink(int k) {
        int n = heap.size();
        while (2 * k + 1 < n) {
            int j = 2 * k + 1;
            if (j + 1 < n && heap[j + 1] > heap[j]) j++;
            if (heap[k] >= heap[j]) break;
            swap(heap[k], heap[j]);
            k = j;
        }
    }

public:
    // Chèn giá trị
    void insert(int value) {
        heap.push_back(value);
        swim(heap.size() - 1);
    }

    bool isEmpty() {
        return heap.empty();
    }

    int size() {
        return heap.size();
    }

    int max() {
        if (isEmpty()) {
            cout << "Queue is empty. Cannot get max.\n";
            return -1;
        }
        return heap[0];
    }
    //Xóa và trả về giá trị lớn nhất
    int delMax() {
        if (isEmpty()) {
            cout << "Queue is empty. Cannot delete max.\n";
            return -1;
        }
        int maximum = heap[0];
        swap(heap[0], heap[heap.size() - 1]);
        heap.pop_back();
        sink(0);
        return maximum;
    }
};
