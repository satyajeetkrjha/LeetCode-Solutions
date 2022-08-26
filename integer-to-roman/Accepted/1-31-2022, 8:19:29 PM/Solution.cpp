// https://leetcode.com/problems/integer-to-roman

class Solution {
public:
    const int val[13] = {1000,900,500,400,100,90,50,40,10,9,5,4,1};
    const string rom[13] ={"M","CM","D","CD","C","XC","L","XL","X","IX","V","IV","I"};
    string intToRoman(int N) {
        string res;
        for(int i =0 ;N>0 ;i++){
            //cout <<"i is "<< i << endl;
            //cout <<"val[i] is "<< val[i]<< endl;
            while(N>=val[i]){
              //  cout <<"here .."<<endl;
                //cout <<"i is "<< i << endl;
                //cout <<"rom[i] .."<< rom[i]<< endl;
                res+=rom[i];
                //cout <<"res is "<< res << endl;
                N= N-val[i];
            }
        }
        return res ;
    }
};