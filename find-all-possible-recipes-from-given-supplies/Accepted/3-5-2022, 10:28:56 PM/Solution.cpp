// https://leetcode.com/problems/find-all-possible-recipes-from-given-supplies

class Solution {
public:
    vector<string> findAllRecipes(vector<string>& recipes, vector<vector<string>>& ingredients, vector<string>& supplies) {
        
        map <string ,int> indegree ;
        map <string ,vector <string> > adj;
        
        for(int i =0 ;i< ingredients.size();i++){
            for(int j = 0 ;j<ingredients[i].size();j++){
                string item = ingredients[i][j] ;
                adj[item].push_back(recipes[i]);
                indegree[recipes[i]]++;
            }
        }
        
        queue <string> q ;
        for(auto &it: supplies){
            q.push(it);
        }
        
        vector<string> ans ;
        
        while(!q.empty()){
            auto s = q.front();
            q.pop();
            for(auto neighbour: adj[s]){
                indegree[neighbour] --;
                if(indegree[neighbour] == 0){
                    q.push(neighbour);
                }
            }
        }
        
        for(auto &item :recipes){
            if(indegree[item] == 0){
                ans.push_back(item);
            }
        }
        return ans ;
        
    }
};