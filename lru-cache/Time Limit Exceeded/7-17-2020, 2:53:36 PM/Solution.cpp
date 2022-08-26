// https://leetcode.com/problems/lru-cache

//by razi
#include <iostream>
class LRUCache {
public:
  
  set<pair<int, int>> old;
  map<int, int> val, time;
  int t, cap;
  LRUCache(int capacity) {
    cap= capacity;
    t= 0;
  }

  int get(int key) {
    if (val. count (key) ==0) return -1;
    old. erase ({time [key], key});
       cout << "\nThe set s1 after erasing  in get is : "; 
    
     for (auto const &x : old) { 

        cout << "(" << x.first << ", "
             << x.second << ")"
             << " "; 
    }    
      
    old. insert ({time [key]= t++, key});
       cout << "\nThe set s1 after insert operation in get   is : "; 
    
     for (auto const &x : old) { 

        cout << "(" << x.first << ", "
             << x.second << ")"
             << " "; 
    }   
    return val[key];
  }

  void put(int key, int value) { 
    if (time. count (key)>0) { 
        cout<<"key is "<<key<<endl;
      old. erase ({time [key], key});
    }

    val[key] = value;
  //  cout<<"val is "<< t<<" "<<key<<endl;  
    old. insert ({time [key]= t++, key});
      cout<<"time is "<<endl;  
        for (auto const& x : time)
{
    std::cout << x.first  // string (key)
              << ':' 
              << x.second // string's value 
              << std::endl ;
}
    set <pair<int, int> > :: iterator itr; 
    cout << "\nThe set s1 in put  is : "; 
    
     for (auto const &x : old) { 

        cout << "(" << x.first << ", "
             << x.second << ")"
             << " "; 
    }
      cout<<endl;
      
      
    if (old. size () > cap) {
      auto p = *old. begin ();
      old. erase (old. begin ());
           cout << "\nThe set after erasing due to oversize is : "; 
    
     for (auto const &x : old) { 

        cout << "(" << x.first << ", "
             << x.second << ")"
             << " "; 
    }  
        cout<<endl;
        
      val. erase (p. second);
      time. erase (p. second);
       cout<<"oversize time is "<<endl; 
        for (auto const& x : time)
{
    std::cout << x.first  // string (key)
              << ':' 
              << x.second // string's value 
              << std::endl ;
}
        
    }
  }
};
/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */