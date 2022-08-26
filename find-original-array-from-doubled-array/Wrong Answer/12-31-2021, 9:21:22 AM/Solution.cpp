// https://leetcode.com/problems/find-original-array-from-doubled-array

class Solution {
public:
    bool comp(int a ,int b){
        return abs(a) < abs(b);
    }
    vector<int> findOriginalArray(vector<int>& changed) {
        vector <int> res ;
        if(changed.size() % 2 == 1){
            return res ;
        }
        map <int ,int> m ;
        for(int i =0 ;i<changed.size();i++){
            m[changed[i]]++;
        }
        vector <int> keys ;
        for(auto it : m){
            keys.push_back(it.first);
        }
        
         sort(keys.begin(), keys.end(), [](int i, int j) {return abs(i) < abs(j);});
        
        for(auto it : keys){
            if(m[it] > m[2*it]){
                return res ;
            }
            cout <<"m[it] ...."<< m[it]<< endl;
            cout <<"m[2*it] ...."<< m[2*it]<< endl;
            for(int i =0 ;i< m[it];i++ ,m[2*it]--){
               cout << "it is ... "<< it << endl;
                res.push_back(it);
            }
        }
        return res ;
        
        
        
    }
};