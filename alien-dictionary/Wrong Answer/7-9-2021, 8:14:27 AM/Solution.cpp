// https://leetcode.com/problems/alien-dictionary

class Solution {
public:
    map <char ,int > indegree ;
    map <char ,vector <char> > graph ;// this is our graph 
    string res;
    
    string alienOrder(vector<string>& words) {
        res = "";
        for(int i =0;i<words.size();i++){
            string word = words[i];
            for(int j =0;j<word.size();j++){
                char c = word[j];
                indegree[c]=0;
                graph[c] = vector <char>();
            }
        }
        cout<<"working fine"<<endl;
    
    // building the graph 
 
    for(int i =0;i<words.size()-1;i++){
       string w1 = words[i];
        string w2 = words[i+1];
        
        if(w1.size() > w2.size() && w1.find(w2) == 0){
            return " ";
        }
        for(int j =0;j<min(w1.size(),w2.size());j++){
            char parent = w1[j];
            char child = w2[j];
            
            if( parent != child){
            // cout<<"parent is "<<parent <<endl;
            // cout<<"child is "<<child <<endl;
                graph[parent].push_back(child);
                indegree[child]++;
                break;
            }
        }
    }
        // cout<<"till queue "<<endl;
    
    queue<char> q;
      
     // for( auto it :indegree){
     //     cout<<"it->first is "<<it.first<< "  and it->second is "<<it.second<<endl;
     // }   
        
        
        
        
    // loop through indegree map 
    for( auto it: indegree){
        if(it.second == 0){
            q.push(it.first);
        }
    }
        // cout<<"q.size() is "<<q.size()<<endl;
    
    while(!q.empty()){
         char current = q.front();
         q.pop();
         res+= current ;
         vector <char > neighbours = graph[current];
         // cout<<"sz is "<<neighbours.size()<<endl;
         for(int i =0;i<neighbours.size();i++){
             char c = neighbours [i];
             indegree[c]--;
             if(indegree[c] == 0){
                 q.push(c);
             }
         }
         
       }
        if(res.size() !=indegree.size()){
            return " ";
        }
     return res ;
    }
    
    
};