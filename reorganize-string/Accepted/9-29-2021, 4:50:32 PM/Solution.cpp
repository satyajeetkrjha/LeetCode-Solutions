// https://leetcode.com/problems/reorganize-string

class Solution {
public:
    string reorganizeString(string s) {
        int hash[26];
        memset(hash,0,sizeof(hash));
        
        for(int i =0 ;i<s.size();i++){
            cout<<s[i]-'a'<<endl;
            hash[s[i]-'a'] ++;
        }
        
        int maxhash = 0 ;
        int letter =0;
        for(int i =0 ;i<26;i++){
            if(hash[i]> maxhash){
                maxhash = hash[i];
                letter = i;
            }
        }
        
        if(maxhash > (s.size()+1)/2){
            return "";
        }
        char arr[s.length()]; // char array of length of the string 
        
        for(int i=0 ;i<s.size();i++){
            cout<<arr[i]<< " ";
        }
        cout<<endl;
        
        int index =0 ;
        while(hash[letter]>0){
            arr[index] =letter +'a';
            index = index+2 ;
            hash[letter]--;
        }
        cout <<"maxhash is "<<maxhash <<endl;
        cout <<"letter is "<<letter <<endl;
        
        for(int i = 0 ;i<s.size();i++){
            cout << arr[i]<< " ";
        }
        cout<<endl;
        for(int i =0 ;i<26;i++){
            cout<<"hash[i] for i "<<i << " is "<<hash[i]<<endl;
            while(hash[i]>0){
                if(index >= s.size()){
                    index = 1;
                }
                cout<<"index is "<<index <<endl;
                arr[index] = i+'a';
                cout<<"arr[index] is "<<arr[index]<<endl;
                index += 2;
                hash[i]--;
            }
        }
        string res;
        for(int i =0 ;i<s.length();i++){
            res += arr[i];
        }
        
        return res ;
        
    }
};