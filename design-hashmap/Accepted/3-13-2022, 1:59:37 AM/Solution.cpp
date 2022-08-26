// https://leetcode.com/problems/design-hashmap

class MyHashMap {
public:
    vector<vector <pair <int ,int> > > vec;
    int sz = 1000;
    MyHashMap() {
        // root of 10 ^ 6 is 10^ 3
        vec.resize(sz);
    }
    
    void put(int key, int value) {
        int index = key % sz;
        // get the vector block at this index
        vector <pair <int ,int> >  &temp =  vec[index] ;
        // now loop through this block 
        for (auto it= temp.begin();it!=temp.end();it++){
            if(it->first == key){
                it->second = value;
                return ;
            }
        }
        temp.push_back({key,value}); // push it to the block
    }
    
    int get(int key) {
        int index = key % sz;
        vector<pair<int ,int> > &temp = vec[index];
        for (auto it= temp.begin();it!=temp.end();it++){
            if(it->first == key){
                return it->second ;
            }
        }
        return -1 ;
    }
    
    void remove(int key) {
        int index = key % sz ;
        vector <pair <int ,int> > &temp = vec[index];
        for ( auto it = temp.begin();it!=temp.end();it++){
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