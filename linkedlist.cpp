#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next;
};

class Linked_List {
private:
    Node* head;
    Node* tail;

public:
    Linked_List() : head(NULL), tail(NULL) {}

    ~Linked_List() {
        while (head != NULL) {
            Node* temp = head;
            head = head->next;
            delete temp;
        }
    }

    // Chèn vào đầu danh sách O(1)
    void insertFront(int value) {
        Node* newNode = new Node{value, head};
        head = newNode;
        if (tail == NULL) tail = newNode;
    }

    // Chèn vào cuối danh sách O(n)
    void insertBack(int value) {
        Node* newNode = new Node{value, NULL};
        if (tail != NULL) {
            tail->next = newNode;
            tail = newNode;
        } else {
            head = tail = newNode;
        }
    }

    // Chèn vào vị trí i O(n)
    void insertAt(int index, int value) {
        if (index == 0) {
            insertFront(value);
            return;
        }
        Node* current = head;
        for (int i = 0; i < index - 1 && current != NULL; i++) {
            current = current->next;
        }
        if (current == NULL) {
            cout << "Index out of bounds\n";
            return;
        }
        Node* newNode = new Node{value, current->next};
        current->next = newNode;
        if (newNode->next == NULL) tail = newNode;
    }

    // Xóa đầu
    void deleteFront() {
        if (head == NULL) return; //O(1)
        Node* temp = head;
        head = head->next;
        delete temp;
        if (head == NULL) tail = NULL;
    }

    // Xóa cuối
    void deleteBack() {
        if (head == NULL) return;//O(n)
        if (head->next == NULL) {
            delete head;
            head = tail = NULL;
            return;
        }
        Node* current = head;
        while (current->next != tail) {
            current = current->next;
        }
        delete tail;
        tail = current;
        current->next = NULL;
    }

    // Xóa vị trí i
    void deleteAt(int index) {
        if (index == 0) {
            deleteFront();
            return;
        }
        Node* current = head; //O(n)
        for (int i = 0; i < index - 1 && current != NULL; i++) {
            current = current->next;
        }
        if (current == NULL || current->next == NULL) {
            cout << "Index out of bounds\n";
            return;
        }
        Node* temp = current->next;
        current->next = temp->next;
        if (temp == tail) tail = current;
        delete temp;
    }

    // Truy cập phần tử tại vị trí i
    int getAt(int index) {
        Node* current = head;
        for (int i = 0; i < index && current != NULL; i++) {  //O(n)
            current = current->next;
        }
        if (current == NULL) {
            return -1;
        }
        return current->data;
    }

    // Duyệt xuôi
    void traverseForward() {
        Node* current = head; //O(n)
        while (current != NULL) {
            cout << current->data << " ";
            current = current->next;
        }
        cout << endl;
    }

    // Duyệt ngược (đệ quy)
    void traverseBackwardHelper(Node* node) {
        if (node == NULL) return;
        traverseBackwardHelper(node->next); //O(n)
        cout << node->data << " ";
    }

    void traverseBackward() {
        traverseBackwardHelper(head);
        cout << endl;
    }
};
