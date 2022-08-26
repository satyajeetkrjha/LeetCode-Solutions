// https://leetcode.com/problems/reorder-data-in-log-files

class Solution {
public:
    vector<string> reorderLogFiles(vector<string>& logs) {
        vector <pair <string ,string> > letterlogs ;
        vector <pair <string ,string> > digitlogs ;
        vector <string> ans ;
        for(auto str:logs){
            string s ="";
            string t= "";
            int sz = str.size();
            bool flag = false;
            for(int i =0 ;i<sz;i++){
                // found an empty space
               if(str[i] == ' ' && flag == false){
                   flag = true;
                   continue;
               }
                if(flag == false){
                    s+=(char)str[i];
                }
                else{
                    t+=(char)str[i];
                }
            }
            // cout<<s<< " "<<t<<endl;
            // cout<<"first character is "<<t[0]<<endl;
            if(t[0]>='a' && t[0]<='z'){
                // cout<<"to letterlog"<<t<<endl;
                letterlogs.push_back(make_pair(t,s));
            }
            else {
                // cout<<"to digitlog "<<t<<endl;
                digitlogs.push_back(make_pair(t,s));
            } 
        }
        
        sort(letterlogs.begin(),letterlogs.end());
        
        for(auto i: letterlogs){
            ans.push_back(i.second +" "+i.first);
        }
        for(auto i :digitlogs){
            ans.push_back(i.second + " "+i.first);
          
        }
        
        return ans ;
        
        
        
        
    }
};