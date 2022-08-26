// https://leetcode.com/problems/subsets

class Solution {
public:
     vector<vector<int>>res;
    
     void printCur(vector <int> curr){
         cout <<"cur values are "<< endl;
         for(int i =0;i<curr.size();i++){
             cout <<curr[i]<< " ";
         }
         cout <<endl;
     }
    
     void printRes(vector <vector <int> >&vec){
      cout <<"RES VALUES ARE "<<endl;
         for (int i = 0; i < vec.size(); i++)
    {
    for (int j = 0; j < vec[i].size(); j++)
    {
        cout << vec[i][j]<< " ";
    }
              cout <<endl;
}
        
     }
     void backtrack(int start ,vector <int>& nums,vector <int>&curr){
        
        for(int i = start ;i<nums.size();i++){
            curr.push_back(nums[i]);
           // printCur(curr);
            res.push_back(curr);
           // printRes(res);
            backtrack(i+1,nums,curr);
            curr.pop_back();
            // printCur(curr);
        }
    
    }
    
    vector<vector<int>> subsets(vector<int>& nums) {
        vector <int> curr ;
        res.push_back(curr);
        backtrack(0,nums,curr);
        return res ;
        
    }
};

