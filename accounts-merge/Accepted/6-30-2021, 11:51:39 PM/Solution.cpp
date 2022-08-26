// https://leetcode.com/problems/accounts-merge

class Solution {
public:
    int find ( vector <int> &parent ,int i){
        while(parent[i]!=i){
            i = parent[i];
        }
        return i;
    }
    vector<vector<string>> accountsMerge(vector<vector<string>>& accounts) {
        vector <int> parent(accounts.size(),0);
        map <string ,int> emailtoindex ; 
        // this map basically maps the given emails to the accounts index 
        for(int i =0;i<accounts.size();i++){
            parent[i] =i;
             vector <string> temp = accounts[i]; 
            // temp[0] contains name but we want to map only emails in this step
            for(int j =1;j<temp.size();j++){
                if(emailtoindex.find(temp[j])!=emailtoindex.end()){ 
                    // this email already exists in the map
                   int parent1 = find(parent,i);
                   int parent2 = find(parent ,emailtoindex[temp[j]]); 
                   parent[parent1] = parent2;
                }
                else {
                    emailtoindex[temp[j]] = i;
                }
            }
        }
            
            map <int , vector<string> > groups ; 
            // group all elemets of a subset such that all enails with same parent will belong to one group
            for(auto it:emailtoindex){
                int root = find(parent ,it.second);
                groups[root].push_back(it.first);
            }
            
            vector< vector <string> > res; // this stores our result 
            
            for (auto it: groups){
                sort(it.second.begin(),it.second.end()) ; 
                vector <string> temp = {accounts[it.first][0]};
                cout<<temp[0]<<endl;
                for( auto i :it.second){
                    temp.push_back(i);
                }
                res.push_back(temp);
            }

           return res;
      }
        
    
};