// https://leetcode.com/problems/check-array-formation-through-concatenation

class Solution {
public:
    bool canFormArray(vector<int>& arr, vector<vector<int>>& pieces) {
        map <int ,vector <int> > m;
        
        for(int i=0;i<pieces.size();i++){
            vector <int> v= pieces[i];
            int x =v[0];
            m[x] = pieces[i]; 
           }
         int i=0;
         while(i<arr.size()){
             int val = arr[i];
             if(m.count(val) == 0){
                 cout<<"count is zero"<<endl;
                 return false;
             }
             cout<<"val is "<<val<<endl;
             vector <int> targetvector = m[val];
             for(int j=0;j<targetvector.size();j++){
                 val=arr[i];
                 cout<<"targetvector[j] is "<<targetvector[j]<<"and j is "<<j<<endl;
                 if(targetvector[j]!=val){
                     cout<<"returning false"<<endl;
                     return false;
                 }
                 i++;
             }
         }
        
        
    return true;
    }
};