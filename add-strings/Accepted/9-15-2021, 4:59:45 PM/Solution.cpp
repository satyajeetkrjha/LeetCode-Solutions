// https://leetcode.com/problems/add-strings

class Solution {
public:
    string addStrings(string num1, string num2) {
        int carry =0 ;
        int n = num1.size()-1;
        int m = num2.size()-1;
        
        string res;
        while(n>=0 || m>=0){
            int val1= n>=0 ?num1[n]-'0':0;
            int val2 =m>=0 ? num2[m]-'0':0;
            int sum =(val1+val2+carry)%10;
           // cout<<"sum "<<sum<<endl;
            carry = (val1+val2+carry)/10;
            res= to_string(sum)+res;
            m--;
            n--;
            //cout<<"val1 "<<val1<<endl;
            //cout<<"val2 "<<val2<<endl;
            
            //cout<<"carry is "<<carry<<endl;
            //cout<<"res is "<<res<<endl;
            
        }
        if(carry){
            res=to_string(carry)+res;
        }
        return res ;
    }
};