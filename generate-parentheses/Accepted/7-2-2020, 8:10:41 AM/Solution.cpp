// https://leetcode.com/problems/generate-parentheses

class Solution {
public:
    vector <string> ans;
    void stringmaker(int open,int close,int total,string currString){
        cout <<"currString"<<currString<<endl;
        if(close >open)
            return;
        if(open==total){
            if(close ==total){
               ans.push_back(currString); 
            }
            else{
                cout<<"when openis equal to total "<<endl;
                stringmaker(open,close+1,total,currString+")");
            }
        }
        else{
            cout<<"open+1 "<<open+1<<endl;
            stringmaker(open+1,close,total,currString+"(");
            cout<<"close+1 "<<close+1<<endl;
            stringmaker(open,close+1,total,currString+")");
            
        }
        return;
        
    } 
    
    vector<string> generateParenthesis(int n) {
        stringmaker(0,0,n,"");
        return ans;
    }
};