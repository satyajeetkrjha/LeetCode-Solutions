// https://leetcode.com/problems/frog-jump

class Solution {
public:
    map <int, set <int>> m;
    bool canCross(vector<int>& stones) {
        for(int i=0 ;i<stones.size();i++){ 
            set<int> s;
            m[stones[i]] =s;
        }
        
        set <int> x;
        x.insert(1);
        m[stones[0]]=x;
        

        
        for(int i =0 ;i<stones.size();i++){
            int current = stones[i];
            set<int> possiblejumps = m[current];
            
            for(auto jump :possiblejumps){
                
                 int newpos = current + jump ;
                cout<<"newpos is "<<newpos<<endl;
                if(newpos == stones[stones.size()-1]){
                    return true;
                }
                
                // this newpos is in the map now
                if(m.find(newpos)!=m.end()){
                   set <int> temp = m[newpos];
                   if(jump-1 >0){
                       temp.insert(jump-1);
                   }
                    temp.insert(jump+1);
                    temp.insert(jump);
                    m[newpos] =temp;
                } 
            } 
        }
            
        return false;
        
        
    }
};