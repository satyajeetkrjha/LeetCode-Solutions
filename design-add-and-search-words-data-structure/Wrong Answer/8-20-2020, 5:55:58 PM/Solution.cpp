// https://leetcode.com/problems/design-add-and-search-words-data-structure

class WordDictionary {
public:
    struct Node{
      bool isEnd =false;
      Node* children[26]  ={NULL}; 
    };
    Node *root;
    /** Initialize your data structure here. */
    WordDictionary() {
       root = new Node();
    }
    
    /** Adds a word into the data structure. */
    void addWord(string word) {
        Node * temp = new Node();
        for(int i=0;i<word.size();i++){
            char c= word[i];
            if(temp->children[c-'a'] ==NULL){
                temp->children[c-'a'] = new Node();
            }
            temp = temp->children[c-'a'];
        }
        temp->isEnd =true;
    }
    
    /** Returns if the word is in the data structure. A word could contain the dot character '.' to represent any one letter. */
     bool searchFun(string word,int index,Node *temp){
        if(temp ==NULL){
            return false;
        }
         if(index == word.length()){
             cout<<"temp->isEnd is "<<temp->isEnd<<endl;
             return temp->isEnd;
         }
         char c = word[index];
         if( c == '.'){
             for(int i=0;i<26;i++){
                 if(searchFun(word,index+1,temp->children[i])) return true;
             }
         }
         else{
             if(searchFun(word,index+1,temp->children[c-'a'])) return true;
         }
         return false;
    }
    bool search(string word) {
       Node *temp = root;
       return searchFun(word,0,temp);
        
    }
};

/**
 * Your WordDictionary object will be instantiated and called as such:
 * WordDictionary* obj = new WordDictionary();
 * obj->addWord(word);
 * bool param_2 = obj->search(word);
 */