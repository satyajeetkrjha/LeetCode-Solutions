// https://leetcode.com/problems/daily-temperatures

#include <algorithm>
class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& T) {
        vector <int> v;
        if(T.size() ==0)
            return v;
        stack < pair<int,int> > s;
        int sz = T.size()-1;
        s.push({T[sz],sz}) ;// pushed last element andf it's index onto stack
        v.push_back(0);
        for(int i= sz-1;i>=0;i--){
         pair <int,int> cur = s.top();
         s.pop();
            cout<<"cur->first "<< cur.first << " "<<cur.second<<endl;
         if(T[i] <cur.first){
             cout<<"T[i] is "<<T[i]<<endl;
             v.push_back(0);
             s.push({T[i],i});
         }
            else {
                while(!s.empty() && cur.first < T[i]){
                    cur = s.top();
                    
                    s.pop();
                }
                cout<<"cur->first  in second step is "<< cur.first << " "<<cur.second<<endl;
                
                if(s.empty()){
                    v.push_back(0);
                }
                else {
                    v.push_back(cur.second - i);
                }
                 s.push({T[i],i});
            }
            cout<<"reached here "<<endl;
        }
        cout<<"did it reach here "<<endl;
         reverse(v.begin(),v.end());
        return v;
    }
};