// https://leetcode.com/problems/high-five

class Solution {
public:
    vector<vector<int>> highFive(vector<vector<int>>& items) {
        /* Create a map of id and max heap for that particular id .*/
        map <int ,priority_queue <int> > m;
        for(auto it :items){
            int id = it[0];
            int valforid= it[1];
            m[id].push(valforid);
        }
        
        vector <vector <int> > res ;
        for( auto &[id,scores]:m){
            int sum =0 ;
            cout<<"max heap for  "<<id <<" is "<<scores.size()<<endl;
            for(int j =0 ;j<5;j++){
                sum += scores.top();
                scores.pop();
            }
            res.push_back({id ,sum/5});
        }
        return res ;
        

    }
};