// https://leetcode.com/problems/reverse-words-in-a-string

class Solution {
public:
    string reverseWords(string s) {
       stack<string> st;
       string temp ="";
        string ans ="";
       for(int i=0;i<s.size();i++){
           if(s[i] == ' ' ) {
               cout<<"temp inside empty string check "<<temp<<" length "<<temp.length()<<endl;
               if(temp.length()>0)
               st.push(temp);
               temp="";
           }
           else
            temp =temp+s[i];
          cout<<"temp outisde is "<<temp<<endl;
       }
        ans = ans+temp;
     
        while(!st.empty()){
            string s =st.top();
            cout<<"s is"<<s<<endl;
            st.pop();
            ans =ans+" "+s;
        }
              if(ans.length() !=0 && ans[0]==' ')
                ans =ans.substr(1);
              
        return ans;
    }
};