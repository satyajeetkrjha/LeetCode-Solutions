// https://leetcode.com/problems/insert-delete-getrandom-o1

class RandomizedSet {
public:
    
    map <int ,int> m;
    vector <int> list ;
    
    RandomizedSet() {
        
    }
    
    bool insert(int val) {
        // elment already exists so just return false
        if(m.count(val) > 0){
            return false;
        }
        int sz = list.size();
        m[val]= sz;
        list.push_back(val);
        return true ;
    }
    
    bool remove(int val) {
        // element does not exist in the map
        if(m.count(val) == 0) return false;
        
        int indexToRemove = m[val] ;
        m.erase(val);
        
        if(indexToRemove < list.size()-1){
            int lastval = list[list.size()-1];
            list[indexToRemove] = lastval ;
            m[lastval] =indexToRemove;
        }
        list.pop_back();
        return true ;
    }
    
    int getRandom() {
       int sz = list.size();
       int randomIndex = rand()% sz;
        return list[randomIndex];
    }
};

/**
 * Your RandomizedSet object will be instantiated and called as such:
 * RandomizedSet* obj = new RandomizedSet();
 * bool param_1 = obj->insert(val);
 * bool param_2 = obj->remove(val);
 * int param_3 = obj->getRandom();
 */