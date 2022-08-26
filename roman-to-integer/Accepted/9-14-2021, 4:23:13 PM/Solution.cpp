// https://leetcode.com/problems/roman-to-integer

class Solution {
public:
    int romanToInt(string s) {
        map <char ,int> m ;
        m['I'] =1;
        m['V'] = 5 ;
        m['X'] = 10 ;
        m['L'] = 50;
        m['C'] = 100;
        m['D'] = 500;
        m['M'] = 1000;
        
        int sum =0 ;
        int i = 0;
        while(i<s.size()){
           char firstCharacter = s[i];
           int  firstNumberValue = m[firstCharacter];
          // cout<<"i is "<<i <<endl;
          // cout<<"firstNumberValue is "<<firstNumberValue <<endl; 
           int secondNumberValue=0;
           if(i+1 < s.size()){
               char secondCharacter = s[i+1];
               secondNumberValue = m[secondCharacter];
            //   cout<<"condition true"<<endl;
              // cout<<"secondNumberValue "<<secondNumberValue <<endl;
           }
            //cout<<"both ...."<<firstNumberValue << " "<<secondNumberValue <<endl;
            if(firstNumberValue < secondNumberValue){
              //  cout<<"excuted"<<endl;
                sum += (secondNumberValue- firstNumberValue);
                i = i+2;
            }
            else{
                sum +=firstNumberValue;
                i++;
            }
            
            
        }
        return sum ;
        
    }
};