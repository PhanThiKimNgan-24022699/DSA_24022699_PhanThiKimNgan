class HashTable {
    int *table;
    int size;

public:
    HashTable(int s) {
        size = s;
        table = new int[size];
        for (int i = 0; i < size; i++) table[i] = -1; // -1 là trống
    }

    int hashFunction(int key) {
        return key % size;
    }

    void insert(int key) {
        int idx = hashFunction(key);
        int startIdx = idx;

        while (table[idx] != -1) {
            idx = (idx + 1) % size;
            if (idx == startIdx) {
                cout << "Hash table full!\n";
                return;
            }
        }
        table[idx] = key;
    }

    void remove(int key) {
        int idx = hashFunction(key);
        int startIdx = idx;

        while (table[idx] != -1) {
            if (table[idx] == key) {
                table[idx] = -2; // -2 = deleted
                return;
            }
            idx = (idx + 1) % size;
            if (idx == startIdx) return;
        }
    }

    bool search(int key) {
        int idx = hashFunction(key);
        int startIdx = idx;

        while (table[idx] != -1) {
            if (table[idx] == key) return true;
            idx = (idx + 1) % size;
            if (idx == startIdx) break;
        }
        return false;
    }

    void display() {
        for (int i = 0; i < size; i++) {
            if (table[i] >= 0)
                cout << i << ": " << table[i] << endl;
            else
                cout << i << ": NULL" << endl;
        }
    }
};