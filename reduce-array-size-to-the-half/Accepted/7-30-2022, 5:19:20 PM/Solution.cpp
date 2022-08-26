// https://leetcode.com/problems/reduce-array-size-to-the-half

class Solution {
public:
    int minSetSize(vector<int>& arr) {
        int n = arr.size();
       // cout <<"array size is "<< n << endl;
        vector <vector <int> > bucket ;
        bucket.resize(n+1);
        map <int ,int> m ;
        for(auto &it: arr){
            m[it]++;
        }
        
        for(auto[key,value]:m){
            bucket[value].push_back(key);
        }
        
      
        
        int op = 0 ;
        int count =  arr.size();
       
        for(int i = n;i>=0;i--){
            vector <int> temp = bucket[i];
            
            int sz = temp.size();
            
            for(int k =0 ;k< sz;k++){
                count = count- i;
                op = op+1;
             
                if(count <= arr.size()/2){
                    return op;
                }
            }
        }
        return 0;
    }
};