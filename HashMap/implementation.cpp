#include <iostream>
#include <vector>
#include <list>
using namespace std;

template <typename KeyType, typename ValueType>
class HashMap
{
private:
    static const int hashGroups = 10;
    vector<list<pair<KeyType, ValueType>>> table;

    int hashFunction(KeyType key)
    {
        return hash<KeyType>{}(key) % hashGroups; // Modulus
    }

public:
    // Constructor
    HashMap() {
        table.resize(hashGroups);
    }

    void insert(KeyType key, ValueType value);
    ValueType get(KeyType key);
    void remove(KeyType key);
    bool contains(KeyType key); // Check if a key-value pair exists
};

template <typename KeyType, typename ValueType>
void HashMap<KeyType, ValueType>::insert(KeyType key, ValueType value) {
    int hashValue = hashFunction(key);
    auto& cell = table[hashValue];

    // Check if the key already exists in the list
    for (auto it = cell.begin(); it != cell.end(); ++it) {
        if (it->first == key) {
            it->second = value; // Update the existing value
            return;
        }
    }

    // If key does not exist: Insert new key-value pair
    cell.emplace_back(key, value);
}

template <typename KeyType, typename ValueType>
ValueType HashMap<KeyType, ValueType>::get(KeyType key) {
    int hashValue = hashFunction(key);
    auto& cell = table[hashValue];

    // Find the node where key == provided key and return it
    for (auto it = cell.begin(); it != cell.end(); ++it) {
        if (it->first == key) {
            return it->second;
        }
    }
    
    throw runtime_error("Key not found");
}

template <typename KeyType, typename ValueType>
void HashMap<KeyType, ValueType>::remove(KeyType key) {
    int hashValue = hashFunction(key);
    auto& cell = table[hashValue];

    // Find the node where key == provided key and remove it
    for (auto it = cell.begin(); it != cell.end(); ++it) {
        if (it->first == key) {
            cell.erase(it);
            return;
        }
    }
}

template <typename KeyType, typename ValueType>
bool HashMap<KeyType, ValueType>::contains(KeyType key) {
    int hashValue = hashFunction(key);
    auto& cell = table[hashValue];

    // Find the node where key == provided key and remove it
    for (auto it = cell.begin(); it != cell.end(); ++it) {
        if (it->first == key) {
            return true;
        }
    }

    return false;
}


int main () {
    HashMap<string, int> myMap;

    myMap.insert("arif", 73);
    myMap.insert("alice", 19);
    myMap.insert("in", 62);

    cout << "Arif's age: " << myMap.get("arif") << endl;
    cout << "alice's age: " << myMap.get("alice") << endl;
    cout << "in's age: " << myMap.get("in") << endl;

    cout << "\nIs \"alice\" present? " << (myMap.contains("alice") ? "Yes" : "No") << endl;
    cout << "Is \"border\" present? " << (myMap.contains("border") ? "Yes" : "No") << endl;

    myMap.remove("alice");
    cout << endl << "After removing alice: ";
    cout << "\nIs \"alice\" present? " << (myMap.contains("alice") ? "Yes" : "No") << endl;

    return 0;
}