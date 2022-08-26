// https://leetcode.com/problems/simplify-path

class Solution {
public:
    string simplifyPath(string path) {
        
        string res,temp;
        vector <string> stk;
        stringstream ss(path);
        while(getline(ss,temp,'/')){
            if(temp == "." || temp =="") continue ;
            if(temp == ".." && !stk.empty()) stk.pop_back();
            else if (temp !="..") stk.push_back(temp);      
        }
        
        for(auto it :stk){
            res += "/"+ it;
        }
        if(res.empty()){
            return "/";
        }
        return res;
        
        
    }
};