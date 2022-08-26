// https://leetcode.com/problems/design-hashmap

class MyHashMap {
public:
    
    vector < vector <pair <int ,int>>> vec;
    int sz ;
    MyHashMap() {
        sz =1000;
        vec.resize(1000);
    }
    
    void put(int key, int value) {
        
        int bucket = key % sz;
        vector <pair <int ,int> > &temp = vec[bucket];
        
        for(auto it = temp.begin();it!=temp.end();it++){
            if(it->first == key){
                it->second = value ;
                return ;
            }
        }
        temp.push_back({key ,value});
        
        
        
    }
    
    int get(int key) {
        int bucket = key %sz;
        vector <pair <int ,int> > &temp = vec[bucket];
        for(auto it = temp.begin();it!=temp.end();it++){
            if(it->first == key){
                return it->second;
            }
        }
        return -1;
    }
    
    void remove(int key) {
        int bucket = key %sz;
        vector <pair <int ,int> > &temp = vec[key];
        for(auto it =temp.begin();it!=temp.end();it++){
            if(it->first == key){
             temp.erase(it);
                return ;
            }
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