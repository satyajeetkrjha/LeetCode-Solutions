// https://leetcode.com/problems/simplify-path

class Solution {
public:
    string simplifyPath(string path) {
        vector <string> st;
        string temp ,res ;
        stringstream ss(path);
        while(getline(ss,temp,'/')){
            if(temp == "." || temp =="") continue;
            else if(temp == ".." && !st.empty()) st.pop_back();
            else if(temp!="..") {
                st.push_back(temp);
            }
            
        }
        
        for(auto it: st){
            res+="/"+it;
        }
        if(res.empty()){
            return "/";
        }
        return res ;
    }
};