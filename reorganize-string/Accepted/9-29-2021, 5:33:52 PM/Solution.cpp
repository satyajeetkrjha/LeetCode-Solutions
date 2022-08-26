// https://leetcode.com/problems/reorganize-string

class Solution {
public:
    string reorganizeString(string s) {
      // First calulate the frequency of all characters and store the one with the highest frequency 
    
        int hash [26];
         for(int i =0 ;i<26;i++){
            hash[i] =0;
        }
        
        for(int i =0 ;i<s.size();i++){
            char c= s[i];
            hash[c-'a']++;
        }
        
       
        // now my hash looks like this
        //2 0 0 1 ........... upto index 25 
     
        int maxhash = 0 ;
        int letter =0;
        for(int i =0 ;i<26 ;i++){
            if(hash[i]> maxhash){
                maxhash = hash[i];
                letter = i ;
            }
        }
        
        //cout<< "maxhash is "<<maxhash <<endl;
        //cout <<" letter is "<<letter <<endl;
        // 0 2 4 6 ..... we will with this maxletter
        if(maxhash > (s.size()+1)/2){
            return "";
        }
        
        char res[s.size()];
        int index =0 ;
        while(hash[letter]>0){
           res[index] = letter+'a';
            index = index+2;
            hash[letter]--;
        }
        
        
        //cout <<"hash thing "<<endl;
        for(int i =0 ;i<s.size();i++){
            cout<<res[i]<<" ";
        }
        cout <<endl;
       // cout <<"hash values "<<endl;
       
        
        for(int i =0 ;i<26;i++){
            while(hash[i]>0){
               if(index>=s.size()){
                   index = 1;
               }
                res[index] = (i+'a');
                index = index+2;
                hash[i]--;
            }
        }
        
        string  ans ;
        for(int i =0 ;i<s.size();i++){
            ans += res[i];
        }
        return ans ;
        
        
        
        
    }
};