#include <iostream>

using namespace std;

class List {
private:
    int* data;
    int capacity;
    int size;

    void resize() {
        capacity *= 2;
        int* newData = new int[capacity];
        for (int i = 0; i < size; ++i)
            newData[i] = data[i];
        delete[] data;
        data = newData;
    }

public:
    List(int initialCapacity = 10) {
        capacity = initialCapacity;
        data = new int[capacity];
        size = 0;
    }

    ~List() {
        delete[] data;
    }

    int getSize() {
        return size;
    }
    //truy cap
    int get(int index) {
        if (index < 0 || index >= size)
             throw out_of_range("Index out of range"); //O(1)
        return data[index];
    }
    //chèn vào đầu
    void insertFirst(int value) {
        if (size == capacity) resize();
        for (int i = size; i > 0; --i) //O(n)
            data[i] = data[i - 1];
        data[0] = value;
        size++;
    }
    //chèn vào cuối
    void insertLast(int value) {
        if (size == capacity) resize();//O(1)/O(n)
        data[size++] = value;
    }
    //chen tại i
    void insertAt(int index, int value) {
        if (index < 0 || index > size)
            throw out_of_range("Index out of range");//O(n)
        if (size == capacity) resize();
        for (int i = size; i > index; --i)
            data[i] = data[i - 1];
        data[index] = value;
        size++;
    }
    //xóa đầu
    void deleteFirst() {
        if (size == 0) return;
        for (int i = 0; i < size - 1; ++i) //O(n)
            data[i] = data[i + 1];
        size--;
    }
    //xóa cuối O(1)
    void deleteLast() {
        if (size == 0) return;
        size--;
    }
    //xóa khỏi vị trí i
    void deleteAt(int index) {
        if (index < 0 || index >= size) {
            cout << endl;
            return;                             //O(n)
        }
        for (int i = index; i < size - 1; ++i)
            data[i] = data[i + 1];
        size--;
    }
    //duyệt xuôi O(n)
    void traverseForward() {
        for (int i = 0; i < size; ++i)
            cout << data[i] << " ";
        cout << endl;
    }
    //duyệt ngược O(n)
    void traverseBackward() {
        for (int i = size - 1; i >= 0; --i)
            cout << data[i] << " ";
        cout << endl;
    }
};
