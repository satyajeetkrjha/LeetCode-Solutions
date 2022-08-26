// https://leetcode.com/problems/implement-trie-prefix-tree

class Trie {
public:
    struct Node{
        bool isEnd =false;
        Node *children[26]={NULL};
    };
    Node * root;
    /** Initialize your data structure here. */
    Trie() {
        root = new Node(); 
    }
    
    /** Inserts a word into the trie. */
    void insert(string word) {
      Node *cur = root ;
      for(int i=0;i<word.size();i++){
          int index = word[i]-'a';
          if(cur ->children[index] ==NULL){
              cur->children[index] = new Node();
          }
          cur = cur->children[index];
      }
        cur->isEnd =true;
    }
    
    /** Returns if the word is in the trie. */
    bool search(string word) {
        Node *cur = root;
        for(int i=0;i<word.size();i++){
            int index = word[i]-'a';
            if(cur->children[index] ==NULL){
                return false;
            }else{
                cur = cur->children[index];
            }
        }
        if(cur->isEnd ==true){
            return true;
        }
        else{
            return false;
        }
    }
    
    /** Returns if there is any word in the trie that starts with the given prefix. */
    bool startsWith(string prefix) {
        Node  *cur =root ;
        for(int i=0;i<prefix.size();i++){
            int index = prefix[i] -'a';
            if(cur->children[index] ==NULL){
                return false;
            }
            cur = cur->children[index];
        }
        if(cur->isEnd){
            return true;
        }
        return true ;
    }
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */