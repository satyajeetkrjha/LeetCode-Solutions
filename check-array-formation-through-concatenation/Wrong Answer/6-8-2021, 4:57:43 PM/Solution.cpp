// https://leetcode.com/problems/check-array-formation-through-concatenation

class Solution {
public:
    bool canFormArray(vector<int>& arr, vector<vector<int>>& pieces) {
        map <int ,vector <int> > m;
        
        for(int i=0;i<pieces.size();i++){
            vector <int> v= pieces[i];
            int x =v[0];
            cout<<"x is "<<x<<endl;
            cout<<"v.size() is "<<v.size()<<endl;
            m[x] = pieces[i]; 
           }
         int i=0;
         while(i<arr.size()){
             int val = arr[i];
             if(m.count(val) == 0){
                 return false;
             }
             vector <int> targetvector = m[val];
             for(int j=0;j<targetvector.size();j++){
                 if(targetvector[j]!=val){
                     return false;
                 }
                 i++;
             }
         }
        
        
    return true;
    }
};