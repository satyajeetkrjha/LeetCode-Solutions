// https://leetcode.com/problems/minimum-window-substring

class Solution {
public:
    string minWindow(string s, string t) {
        if(s.length() == 0|| s.length() < t.length()){
            return "";
        }
        map <char ,int> m ;
        for(int i =0;i<t.length();i++){
            m[t[i]]++;
        }
        
        for(auto it = m.begin();it!=m.end();++it){
            cout<<it->first <<" "<<it->second <<endl;
        }
        
        int count =0;
        int minlength =INT_MAX ;
        int end =0;
        int start =0;
        int leftstart =0;
        
        while(end <s.length()){
            // the s[i] word exists in the map
            if(m.find(s[end]) != m.end()){
                cout<<"------------"<<endl;
               cout<<"index end  val is "<<end<<endl;
                m[s[end]]--;
                if(m[s[end]] >= 0){
                    count++;
                }
                cout<<"count of "<<s[end]<<" is "<<m[s[end]]<<endl;
                
                 for(auto it = m.begin();it!=m.end();++it){
            cout<<it->first <<" "<<it->second <<endl;
        }
            }
            cout<<"------------"<<endl;
            cout<<"count is "<<count<<endl;
            cout<<"start here is "<<start <<endl;
            cout<<"end is "<<end<<endl;
            while( count == t.length()){
                // update the min length and the starting index 
                minlength= min(minlength,(end-start)+1);
                leftstart = start;
                cout<<"minlength is "<<minlength <<endl; 
                cout<<"leftstart is "<<leftstart <<endl;
                
                // exists
                if(m.find(s[start]) != m.end()){
                    m[s[start]]++;
                    if(m[s[start]] >0){
                        count --;
                    }
                }
                start++; 
            }
            
            end++;
        }
        if(minlength >s.length()){
            return "";
        }
        cout<<"at last leftstart"<<leftstart <<endl;
        cout<<"at last minlength is "<<minlength <<endl;
        return s.substr(leftstart,minlength);
        
        
    }
};