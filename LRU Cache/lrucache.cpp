#include<bits/stdc++.h>
using namespace std;

// A Least Recently Used Cache system (LRU) with O(1) access.

/* Key functions:
    1. put(key,value) -> To store key value pairs in a hashmap
    2. get(key) -> To retrieve stored value for key
    3. O(1) operations
    4. Evicting Least Recently used items when memory capacity exceeds
*/


/* High Level Architecture of Doubly linked list:
    Head - MRU - - - LRU - Tail 
    
    Pointer invariants are the conditions about pointer relationships
    that must always hold true for a data structure to remain correct,
    regardless of operations.
    
    Head and Tail are sentinel nodes; they never point to an actual node. Hence they exist 
    the whole time, this eliminates the need to perform repetitive checks for head and tail values. 
*/


/* 
    Thread Safety is ensured by adding mutex locks in  

*/

// Node STructure 
struct Node{
    int key;
    int value;
    Node* prev;
    Node* next;

    Node(int k, int v): key(k), value(v), prev(nullptr), next(nullptr) {}
};

class LRUCache{
private:
    mutex mtx;
    int capacity;
    unordered_map<int, Node*> cache;    
    Node* head;
    Node* tail;

    // The linked list is never empty;
    // This is possible due to Sentinel (Dummy) Nodes, head and tail.


    void removeNode(Node* node){
        node->prev->next = node->next;
        node->next->prev = node->prev;
    }

    // -- node - head - - - - tail 

    void addToFront(Node* node){
        node->next = head->next;
        node->prev = head;
        head->next->prev = node;
        head->next = node; 
    }
public:
    LRUCache(int c=5){  
        capacity = c;
        head = new Node(-1,-1);
        tail = new Node(-1,-1);
        head->next = tail;
        tail->prev = head;
    }

    // Destructor to ensure deletion and enforcing production safety
    
    ~LRUCache(){
        Node* curr = head;
        while(curr){
            Node* next = curr->next;
            delete(curr);
            curr = next;
        }
    }

    int get(int key){
        lock_guard<mutex> lock(mtx);

        if(cache.find(key) == cache.end()) return -1;
        
        Node* node = cache[key];
        removeNode(node);
        addToFront(node);
        return node->value;
    }

    void put(int key, int value){
        lock_guard<mutex> lock(mtx);

        if(cache.find(key) != cache.end()){
            Node* node = cache[key];
            node->value = value;    
            removeNode(node);
            addToFront(node);
        } else {
            if(cache.size() == capacity){
                Node* lru = tail->prev;
                cache.erase(lru->key);
                removeNode(lru);
                delete(lru);
            }
            Node* node = new Node(key, value);
            cache[key] = node;
            addToFront(node);
        }
    }

};


int main(){
    LRUCache cache(2); // Cache with size 2
    cache.put(1,5);
    cache.put(2,10);
    cout<<cache.get(1)<<endl;
    cache.put(3,15);
    cout<<cache.get(2)<<endl; // -1 as it is evicted from the cache 
    cout<<cache.get(3)<<endl;
    return 0;
}