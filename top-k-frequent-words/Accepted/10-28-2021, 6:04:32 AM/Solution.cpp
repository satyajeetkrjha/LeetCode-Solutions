// https://leetcode.com/problems/top-k-frequent-words

class Solution {
public:
   static  bool compare(const pair<int ,string > p1, const pair <int ,string > p2){
        if(p1.first == p2.first){
          return   p1.second > p2.second;
        }
        return p1.first <p2.first ;
    }
    vector<string> topKFrequent(vector<string>& words, int k) {
 
       map <string ,int > m;
       for(auto word:words){
           m[word]++;
       }
       vector <pair <int,string >> v ;
        
       for(auto it :m){
           v.push_back({it.second ,it.first});
       }
       
        sort(v.begin(),v.end(),compare);
        
        /*
        cout <<"Start"<<endl;
        for(int i =0 ;i<v.size();i++){
            cout <<v[i].first << " "<< v[i].second <<endl;
        }
        cout <<"End "<<endl;
        */
        
        vector <string > res ;
        int ct =0;
        for(int i =v.size()-1 ;i>=0;i--){
        
            if(ct == k){
               break;
            }
            ct++;
            res.push_back(v[i].second);
        }
       return res ;
    }
};