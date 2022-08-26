// https://leetcode.com/problems/lru-cache

class LRUCache {
public:
    
    class node{
        public:
         int key ;
         int val ;
         node* next ;
         node* prev;
         node(int _key,int _val){
             key = _key;
             val = _val;
         }
    };
    
    node* head = new node(-1,-1);
    node* tail = new node(-1,-1);
    
    int cap ;
    unordered_map <int ,node*> m ;
    
    LRUCache(int capacity){
        cap = capacity ;
        head->next = tail ;
        tail->prev = head ;
    }
    
    void addnode(node* newnode){
        node* temp = head->next ;
        newnode->next = temp ;
        newnode->prev = head ;
        head->next = newnode ;
        temp ->prev = newnode ;
    }
    
    void deletenode(node* deletenode){
        node *deletenext = deletenode->next ;
        node *deleteprev = deletenode->prev;
        
        deleteprev->next = deletenext ;
        deletenext->prev = deleteprev;
        
    }
    
    int get(int key) {
        if(m.find(key)!=m.end()){
            node *resnode = m[key];
            int res = resnode->val ;
            m.erase(key);
            deletenode(resnode);
            addnode(resnode);
            m[key]  = head->next ;
            return res;
        }
        return -1 ;
    }
    
    void put(int _key, int value) {
        if(m.find(_key)!=m.end()){
            node *resnode = m[_key];
            m.erase(_key);
            deletenode(resnode);
        }
        
        if(m.size() == cap){
            m.erase(tail->prev->key);
            deletenode(tail->prev);
        }
        
        addnode(new node(_key,value));
        m[_key] = head->next ;
        
        
    }
};
