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
         //   cout <<"key and value are "<< key << " "<< value << endl;
            bucket[value].push_back(key);
        }
        
        for(int i =n ;i>=0 ;i--){
            vector <int> temp = bucket[i];
            cout << "sz for i : "<< temp.size()<<" " << i <<endl;
            for(auto &it:temp){
                cout << it << " ";
            }
            cout << endl;
        }
        
        int op = 0 ;
        int count =  arr.size();
       // cout <<"count before is "<< count << endl;
        for(int i = n;i>=0;i--){
            vector <int> temp = bucket[i];
            for(auto &it: temp){
                cout << it << endl;
            }
            int sz = temp.size();
            //cout <<"sz is "<< sz<< endl;
            for(int k =0 ;k< sz;k++){
                count = count- i;
                op = op+1;
               // cout <<"count after removal "<< count << endl;
               // cout <<"op is "<< op << endl;
                if(count <= arr.size()/2){
                   // cout <<"here "<<endl;
                    return op;
                }
            }
        }
        return 0;
    }
};