// https://leetcode.com/problems/open-the-lock

class Solution {
public:
    int openLock(vector<string>& deadends, string target) {
      
      set <string> dds(deadends.begin(),deadends.end());
      set <string> visited ;
      queue<string> q;
      string initial = "0000";
      if(initial == target)
          return 0;
      // if the initial is in deadend then it's a big no 
      if(dds.find(initial)!= dds.end()){
          return - 1;
      }
    
      visited.insert(initial);
      q.push(initial);
    
      int steps =0;
        
      while(!q.empty()){
          int sz = q.size();
          for(int i =0 ;i<sz;i++){
              string s = q.front();
              q.pop();
              vector <string> possibilities = fun(s);
              
              for(auto str: possibilities){
                  if(str == target) return ++steps;
                  
                  if(visited.find(str)!=visited.end()){
                      continue;
                  }
                  
                  if(dds.find(str) == dds.end()){
                      q.push(str);
                      visited.insert(str);
                  }
                  
              }
          }
          steps++; 
      }
        return -1 ;
    }
    
    vector<string> fun(string s){
        vector <string > res ;
        for(int i =0 ;i<4;i++){
            string temp = s;
            temp[i] = (s[i] -'0'+1)%10 +'0';
            res.push_back(temp);
            temp[i]= (s[i]-'0'-1+10)%10+'0';
            res.push_back(temp);
        }
        return res ;
    }
};