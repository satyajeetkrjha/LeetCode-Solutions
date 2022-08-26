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
        /*
        This portion was a bit tough to understand so here it goes .
        First thing first ,we store the indexof the element we are removing from map by just doing 
        int indexToRemove = m[val] ;
        and then we remove it 
        m.erase(val);
        
        .Till now ,it looks easy where you just stored the index of the element ina varaible and deleted the element from map .
        
        Next ,we store the element at last index in your list .let's call it A.
        Now ,suppose that your indexToremove is 2 and ur list is of size 10 so 
        you place the element presesnt at last to the index 2 in ur vector/list .
        Wait ,do you see that element at last index had some index in ur map .It 
        must have been (element,10) but now it has been moved to index 2
        so yeah ,update it to (elememt,2);
        
        int lastval = list[list.size()-1];
        list[indexToRemove] = lastval ;
        m[lastval] =indexToRemove;
        
        
        At last just pop the lement from list .
        
        
        */
        
        
        
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