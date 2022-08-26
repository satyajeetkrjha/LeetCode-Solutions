// https://leetcode.com/problems/employee-importance

/*
// Definition for Employee.
class Employee {
public:
    int id;
    int importance;
    vector<int> subordinates;
};
*/

class Solution {
public:
    int getImportance(vector<Employee*> employees, int id) {
      map <int,Employee*>m;
      for(int i=0;i<employees.size();i++){
          cout<<"employees[i] is "<<employees[i]->id<<endl;
          m[employees[i]->id] = employees[i];
      }  
       int ans =0;
       queue <int> q;
        q.push(id);
        while(!q.empty()){
            int node = q.front(); // this node is the id of employees
            q.pop();
            ans+=m[node]->importance;
            for(int i=0;i<m[node]->subordinates.size();i++){
                q.push(m[node]->subordinates[i]);
            }
        }
        return ans;
    }
    
};