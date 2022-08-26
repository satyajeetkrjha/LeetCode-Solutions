// https://leetcode.com/problems/encode-and-decode-strings


#include <sstream>
class Codec {
public:

    // Encodes a list of strings to a single string.
    string encode(vector<string>& strs) {
        
        string res ;
        for(int i =0 ;i<strs.size();i++){
            string temp = strs[i];
            res += to_string(temp.size())+"#"+temp;
        }
        return res ;    
    }

    // Decodes a single string to a list of strings.
    vector<string> decode(string s) {
        vector <string> res ;
        int i =0 ;
        int j ;
        cout << "s is "<< s << endl;
        while(i <s.size()){
            j = i ;
            while(s[j]!='#'){
                j ++;
            }
            
            cout << "j is "<< j << endl;
            string numinstring= s.substr(i, j-i);
            cout <<"numinstring is "<<numinstring << endl;
            int len = stoi(numinstring);
            string word = s.substr(j+1,len);
            cout <<"word is "<< word << endl;
            res.push_back(word);
            i = j + len+1;
        }
        return res ;
    }
};

// Your Codec object will be instantiated and called as such:
// Codec codec;
// codec.decode(codec.encode(strs));