// https://leetcode.com/problems/verifying-an-alien-dictionary

class Solution {
public:
    bool isAlienSorted(vector<string>& words, string order) {
        int orderMap[26]={0};
        for(int i =0 ;i<order.size();i++){
            int c= order[i]-'a';
            orderMap[c]=i;
        }
        
        
        
        for(int i =0 ;i<words.size()-1;i++){
            for(int j =0 ;j<words[i].size();j++){
                if(j >= words[i+1].size()) {
                    return false;
                }
                string firstword = words[i];
                string secondword= words[i+1];
                if(firstword[j]!=secondword[j]){
                    int currentword = firstword[j]-'a';
                    int nextword = secondword[j]-'a';
                    if(orderMap[currentword]>orderMap[nextword]){
                        return false;
                    } 
                    else{
                        break;
                    }
                }
            }
        }
        return true ;
    }
};