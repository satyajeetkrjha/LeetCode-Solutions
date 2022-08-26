// https://leetcode.com/problems/h-index

class Solution {
public:
    int hIndex(vector<int>& citations) {
        
        int n = citations.size();
        sort(citations.begin(),citations.end(),greater<int>());
        
        for(auto it: citations){
            cout << it << " ";
        }
        cout << endl;
        
        for(int i =0 ;i< citations.size();i++){
            if( i >= citations[i]){
                return i ;
            }
        }
        return citations.size();
        
    }
};