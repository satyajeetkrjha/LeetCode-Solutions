// https://leetcode.com/problems/expression-add-operators

class Solution {
public:
    vector <string> res ;
    string s ;
    int target ;
    vector<string> addOperators(string num, int target) {
        this->s = num;
        this->target = target;
        backtrack(0,"",0,0);
        return res ;
    }
    
    void backtrack(int i ,const string &path ,long ressofar,long prevnum){
        if(i== s.size()){
            if(ressofar == target){
                res.push_back(path);
            }
            return;
        }
        string numstr ;
        long num =0 ;
        for(int j =i ;j<s.size();j++){
            if(j > i  && s[i] =='0') break;
            numstr += s[j];
            num = num*10+s[j]-'0';
            if( i == 0){
                backtrack(j+1,path+numstr,num,num);
            }
            else{
                 backtrack(j + 1, path + "+" + numstr, ressofar + num, num);
                backtrack(j + 1, path + "-" + numstr, ressofar - num, -num);
                backtrack(j + 1, path + "*" + numstr, ressofar - prevnum + prevnum * num, prevnum * num); 
            }
                
            
        }
    }
};