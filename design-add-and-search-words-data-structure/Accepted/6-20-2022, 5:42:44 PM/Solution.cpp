// https://leetcode.com/problems/design-add-and-search-words-data-structure


struct Node{
    
    Node* links [26];
    bool flag = false ;
    
    void set(char ch ,Node* node){
        links[ch-'a'] = node;
    }
    Node* get(char ch){
      return links[ch-'a'];
    }
    
    bool containsKey(char ch){
        return links[ch-'a']!=NULL;
    }
    
    void setEnd(){
        flag = true;
    }
    
    bool isEnd(){
        return flag;
    }  
};


class WordDictionary {
    
private :
   Node* root ;
public:
    
   
    WordDictionary() {
        root = new Node();
    }
    
    void insert(string word){
        Node* node = root ;
        for(int i =0 ;i<word.size();i++){
            char ch = word[i];
            if(!node->containsKey(ch)){
                node->set(ch,new Node());
            }
            node = node->get(ch);
        }
        node->setEnd();
    }
    
    bool searchTrie(Node* node ,string &word ,int pos){
        if(pos == word.size()){
            return node->isEnd() ;
        }
        
        if(word[pos] == '.'){
            for(int i = 0 ;i< 26;i++){
                if(node->links[i] && searchTrie(node->links[i] ,word,pos+1))
                    return true;
            }
            return false ;
         }
        
        node = node->get(word[pos]);
        return node && searchTrie(node,word,pos+1);
   }
    
    void addWord(string word) {
        insert(word);
    }
    
    bool search(string word) {
         Node* node = root ;
         return searchTrie(node ,word,0);
    }
};

/**
 * Your WordDictionary object will be instantiated and called as such:
 * WordDictionary* obj = new WordDictionary();
 * obj->addWord(word);
 * bool param_2 = obj->search(word);
 */