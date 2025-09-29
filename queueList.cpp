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
             cout << endl; //O(1)
        return data[index];
    }
    //chèn vào đầu
    void addFirst(int value) {
        if (size == capacity) resize();
        for (int i = size; i > 0; --i) //O(n)
            data[i] = data[i - 1];
        data[0] = value;
        size++;
    }
    //chèn vào cuối
    void addtLast(int value) {
        if (size == capacity) resize();//O(1)/O(n)
        data[size++] = value;
    }
    //chen tại i
    void addtAt(int index, int value) {
        if (index < 0 || index > size)
            cout << endl;    //O(n)
        if (size == capacity) resize();
        for (int i = size; i > index; --i)
            data[i] = data[i - 1];
        data[index] = value;
        size++;
    }
    //xóa đầu
    void removeFirst() {
        if (size == 0) return;
        for (int i = 0; i < size - 1; ++i) //O(n)
            data[i] = data[i + 1];
        size--;
    }
    //xóa cuối O(1)
    void removeLast() {
        if (size == 0) return;
        size--;
    }
    //xóa khỏi vị trí i
    void removeAt(int index) {
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

class Queue {
private:
    List list;

public:

    bool isEmpty() {
        return list.getSize() == 0;
    }

    void enqueue(int item) {
        list.addtFirst(item); // O(1) 
    }

    int dequeue() {
        if (isEmpty()) {
            cout << "Queue underflow!" << endl;
            return -1;
        }
        int value = list.get(list.getSize() - 1);
        list.removeLast(); //O(n)
        return value;
    }

    int front() {
        if (isEmpty()) {
            cout << "Queue is empty!" << endl;
            return -1;
        }
        return list.get(list.getSize() - 1); // Phần tử cuối là front
    }

     int size() {
        return list.getSize();
    }
};
