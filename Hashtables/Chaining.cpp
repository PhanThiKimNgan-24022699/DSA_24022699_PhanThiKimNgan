class HashTable {
    int bucketSize;
    vector<list<int>> table;

public:
    HashTable(int size) {
        bucketSize = size;
        table.resize(bucketSize);
    }

    int hashFunction(int key) {
        return key % bucketSize;
    }

    void insert(int key) {
        int idx = hashFunction(key);
        table[idx].push_back(key);
    }

    void remove(int key) {
        int idx = hashFunction(key);
        table[idx].remove(key);
    }

    bool search(int key) {
        int idx = hashFunction(key);
        for (int k : table[idx]) {
            if (k == key) return true;
        }
        return false;
    }

    void display() {
        for (int i = 0; i < bucketSize; i++) {
            cout << i << ": ";
            for (int k : table[i])
                cout << k << " -> ";
            cout << "NULL\n";
        }
    }
};