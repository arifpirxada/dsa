// https://leetcode.com/problems/design-hashmap/

class MyHashMap {
private:
    int hashGroup = 100;
    vector<list<pair<int, int>>> table;

    int hashFunction(int key) {
        return hash<int>{}(key) % hashGroup;
    }

public:
    MyHashMap() {
        table.resize(hashGroup);
    }
    
    void put(int key, int value) {
        int hashValue = hashFunction(key);
        auto& cell = table[hashValue];
        
        for (auto it = cell.begin(); it != cell.end(); it++) {
            if (it->first == key) {
                it->second = value;
                return;
            }
        }

        cell.emplace_back(key, value);
    }
    
    int get(int key) {
        int hashValue = hashFunction(key);
        auto& cell = table[hashValue];

        for (auto it = cell.begin(); it != cell.end(); it++) {
            if (it->first == key) {
                return it->second;
            }
        }
        return -1;
    }
    
    void remove(int key) {
        int hashValue = hashFunction(key);
        auto& cell = table[hashValue];

        for (auto it = cell.begin(); it != cell.end(); it++) {
            if (it->first == key) {
                cell.erase(it);
                return;
            }
        }
    }
};