class MyHashMap {
private:
    struct ListNode {
        int key, val;
        ListNode* next;

        ListNode(int key = -1, int val = -1, ListNode* next = nullptr)
            : key(key), val(val), next(next) {}
    };

    vector<ListNode*> internalMap;

    int hash(int key) {
        return key % internalMap.size();
    }



public:
    MyHashMap() {
        internalMap.resize(1000);
        for (auto& bucket : internalMap) {
            bucket = new ListNode(0);
        }
    }
    
    void put(int key, int value) {
        ListNode* node = internalMap[hash(key)];
        while (node->next) {
            if (node->next->key == key) {
                node->next->val = value;
                return;
            }
            node = node->next;
        }
        node->next = new ListNode(key, value);
    }
    
    int get(int key) {
        ListNode* node = internalMap[hash(key)];
        while (node->next) {
            if (node->next->key == key) {
                return node->next->val;
            }
            node = node->next;
        }
        return -1;
    }
    
    void remove(int key) {
        ListNode* node = internalMap[hash(key)];
        while (node->next) {
            if (node->next->key == key) {
                ListNode* temp = node->next;
                node->next = node->next->next;
                delete temp;
                return;
            }
            node = node->next;
        }
    }
};

/**
 * Your MyHashMap object will be instantiated and called as such:
 * MyHashMap* obj = new MyHashMap();
 * obj->put(key,value);
 * int param_2 = obj->get(key);
 * obj->remove(key);
 */