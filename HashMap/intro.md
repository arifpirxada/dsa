### HashMap
    - It is a data structure that stores keys and their values
    - Faster access: O(1); worst case: O(l); l => linked list

### Implementation
    - Initialize an array (vector) of linked list
    - Means each array's element will contain the head of a linked list
    - Each list's node will be a pair

### How to insert
***Hash function***   
    - This function will return a number, when it is given a key   
    - The key could be string, int etc   
    - This number will be used as index to the list in array   
    - where the key-value pair will be stored   

***How to insert***   
    - Traverse the list of array found using hash function   
    - Check if the key exists in the list   
    - if yes update the value   
    - else insert new node with key - value   

Rest functions are simple