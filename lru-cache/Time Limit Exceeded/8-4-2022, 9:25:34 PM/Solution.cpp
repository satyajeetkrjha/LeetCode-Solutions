// https://leetcode.com/problems/lru-cache

class LRUCache {
public:
    class node{
      public:
        int key ;
        int val ;
        node* prev ;
        node* next ;
        node(int _key ,int _val){
            key = _key;
            val = _val;
        }
    };
    
    node *head = new node(-1,-1);
    node* tail = new node( -1,-1);
    
    int cap ;
    unordered_map <int ,node*> m;
    
    LRUCache(int capacity) {
        cap = capacity;
        head->next = tail;
        tail->prev = head ;
    }
    
    void deleteNode(node* resnode){
        node* deleteprev = resnode->prev ;
        node *deletenext = resnode->next;
        deleteprev->next = deletenext;
        deletenext->prev = deleteprev;
    }
    
    void addNode(node* newnode){
        node* temp = head->next ;
        newnode->next = temp;
        newnode->prev = head ;
        head->next = newnode ;
        temp->prev = newnode;
        
    }
    int get(int key) {
        if(m.find(key)!=m.end()){
            auto *resnode = m[key];
            int retval = resnode->val;
            deleteNode(resnode);
            addNode(resnode);
            m[key] = head->next ;
            return retval ;
        }
        return -1;
    
    }
    
    void put(int key, int value) {
        if(m.find(key)!=m.end()){
            auto *resnode = m[key];
            deleteNode(resnode);
            m.erase(key);
        }
        if(m.size() == cap){
            m.erase(tail->prev->key);
            deleteNode(tail->prev);
        }
        addNode(new node(key,value));
        m[key] = head->next;
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */