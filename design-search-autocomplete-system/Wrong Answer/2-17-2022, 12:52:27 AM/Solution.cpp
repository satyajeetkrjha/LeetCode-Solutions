// https://leetcode.com/problems/design-search-autocomplete-system


struct Node{
  
    map <char ,Node*> links;
    map <string ,int> counter;
    
    bool flag ;
    
    
    void setEnd(){
        flag = true;
    }
    
    bool getEnd(){
        return flag ;
    }
    
    Node* get( char ch){
        return links[ch];
    }
    
    bool containsKey(char ch){
       // cout <<ch << endl;
        return links[ch] !=NULL;
    }
    void put(char ch , Node* node) {
        links[ch] = node;
    }
     
};


class AutocompleteSystem {
    
private :
    
    Node* root = new Node();
    string prefix ;
    
    struct compare{
      bool operator()(pair <int,string> &l,pair <int ,string> &r){
          return l.first < r.first || (l.first == r.first && l.second.compare(r.second)>0);
      }  
    };
    
public:
    
    void insert(string word ,int times){
        Node* node = root ;
        for(int i =0 ;i<word.size();i++){
            char ch  = word[i];
            if(!node->containsKey(ch)){
                node->put(ch,node);
            }
            node = node->get(ch);
            node->counter[word]+= times ;
        }
        node->setEnd();   
    }
    
    
    
    AutocompleteSystem(vector<string>& sentences, vector<int>& times) {
        
        Node *node = root;
        for(int i =0 ;i<sentences.size();i++){
            insert(sentences[i],times[i]);
        }
    }
    
    vector<string> input(char c) {
        if( c == '#'){
            insert(prefix,1);
            prefix.clear();
            return {};
        }
     
        prefix+= c;
        
        
        cout <<"prefix is "<< prefix << endl;
        Node* node = root ;
        for(auto ch :prefix){
            if(!node->containsKey(ch)){
                return {} ;
            }
            node  = node->get(ch);
        }
        
        
        
        priority_queue<pair <int ,string> ,vector <pair <int,string>>,compare > pq;
        
        for(auto p:node->counter){
            
            cout <<"p.second and firts are "<< p.second << "  "<< p.first << endl;
            pq.push({p.second,p.first});
        
        }
        vector <string> res ;
        for(int i =0 ;i<3 && !pq.empty();i++){
            res.push_back(pq.top().second);
            pq.pop();
        }
        return res ;
    
    }
};

/**
 * Your AutocompleteSystem object will be instantiated and called as such:
 * AutocompleteSystem* obj = new AutocompleteSystem(sentences, times);
 * vector<string> param_1 = obj->input(c);
 */