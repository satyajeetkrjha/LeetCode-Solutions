// https://leetcode.com/problems/sort-characters-by-frequency

class Solution {
public:
   static bool comp(  const pair <char,int> &a, const pair<char ,int> &b){
        return a.second >b.second;
    }
    string frequencySort(string s) {
       map <char ,int> m;
       for(int i=0;i<s.size();i++){
           char c =s[i];
           m[c]++;
       }
       
        vector <pair <char ,int> > v;
         map <char ,int >::iterator it ;
        for(it=m.begin();it!=m.end();it++){
            v.push_back(make_pair(it->first,it->second));
        }
        sort(v.begin(),v.end(),comp);
        string res;
        for(int i=0;i<v.size();i++){
            cout <<v[i].first<<" "<<v[i].second<<endl;
            for(int j=0;j<v[i].second;j++){
                res+=v[i].first;
            }
        }
        
        return res;
        
    }
};