// https://leetcode.com/problems/count-binary-substrings

class Solution {
public:
    int countBinarySubstrings(string s) {
        vector <int> groups(s.size());
        int idx =0 ;
        groups[idx]=1 ;
        for(int i =1 ;i<s.size();i++){
            if(s[i]!=s[i-1]){
                idx++;
                groups[idx] =1;
            }
            else{
                groups[idx]++;
            }
        }
        
        /*
        for(int i = 0 ;i<= idx;i++){
            cout << groups[i]<< "  ";
        }
        cout << endl;
        cout <<"idx is "<< idx<< endl;
        */
        int ans =0 ;
        for(int i =1 ;i<= idx;i++){
         //   cout <<" i is "<< i << endl;
            ans += min(groups[i],groups[i-1]);
        }
        return ans ;
    }
};