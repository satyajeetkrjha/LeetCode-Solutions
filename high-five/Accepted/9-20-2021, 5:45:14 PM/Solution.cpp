// https://leetcode.com/problems/high-five

class Solution {

    
public:
    vector<vector<int>> highFive(vector<vector<int>>& items) {
        int k = 5 ;
        vector <vector <int> > res ;
        map <int , priority_queue <int> > scores ;// key and max heap for this
        for(auto it :items){
            int id  = it[0];
            int score = it[1];
            scores[id].push(score); // id and score addeed to the max heap
        }
        for( auto &[it,scoreval] :scores){
          int sum =0;
            for(int i =0 ;i<5;i++){
                sum += scoreval.top();
                scoreval.pop();
                cout<<"sum is ...."<<sum <<endl;
            }
            res.push_back({it,sum /5});
            
        }
        return res ;
        
    }
};