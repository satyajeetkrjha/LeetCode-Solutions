// https://leetcode.com/problems/combination-sum

class Solution {
public:
    vector< vector <int> > res ;
    int sum ;
    int target ;
    
    void backtrack(vector<int>&candidates,vector<int> &cur,int start){
        if(sum >target) return ;
       // cout <<"target is "<< target << endl;
        if(sum == target){
            res.push_back(cur);
            return;
        }
        for(int i =start;i<candidates.size();i++){
            sum = sum+ candidates[i];
            cur.push_back(candidates[i]);
            backtrack(candidates,cur,i);
            sum = sum - candidates[i];
            cur.pop_back();
        }
    }
    
    vector<vector<int>> combinationSum(vector<int>& candidates, int t) {
        sum =0;
        target = t;
        sort(candidates.begin(),candidates.end());
        vector <int> temp;
        backtrack(candidates,temp,0);
        return res ;

    }
};