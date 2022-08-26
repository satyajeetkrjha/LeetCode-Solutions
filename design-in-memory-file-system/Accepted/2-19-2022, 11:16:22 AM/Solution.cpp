// https://leetcode.com/problems/design-in-memory-file-system

class FileSystem {
public:
    
    struct filenode{
      unordered_map <string ,filenode*> next;
      bool isfile;
      string content;
      filenode():isfile(false),content(""){}  
    };
    
    
    filenode* root ;
    
    FileSystem() {
        root =new filenode();
    }
    
    
    filenode* gotopathfolder(string path){
        filenode* cur = root ;
        stringstream s(path);
        string folder ;
        while(getline(s,folder,'/')){
            if(folder.size() != 0){
                if(cur->next[folder]==NULL){
                    cur->next[folder] = new filenode();
                }
                cur = cur->next[folder];
            }
        }
        return cur;
    }
    

    vector<string> ls(string path) {
        filenode* cur = gotopathfolder(path);
        if(cur->isfile){
            return {path.substr(path.find_last_of('/')+1)};
        }
        vector <string> res ;
        for(auto &p:cur->next){
            res.push_back(p.first);
        }
        sort(res.begin(),res.end());
        return res ;
        
    }
    
    void mkdir(string path) {
        filenode *cur = gotopathfolder(path);
        
    }
    
    void addContentToFile(string filePath, string content) {
        filenode* cur = gotopathfolder(filePath);
        cur->content+= content ;
        cur->isfile = true;
    }
    
    string readContentFromFile(string filePath) {
        filenode* cur = gotopathfolder(filePath);
        return cur->content;
    }
};

/**
 * Your FileSystem object will be instantiated and called as such:
 * FileSystem* obj = new FileSystem();
 * vector<string> param_1 = obj->ls(path);
 * obj->mkdir(path);
 * obj->addContentToFile(filePath,content);
 * string param_4 = obj->readContentFromFile(filePath);
 */