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
        
        int index =0 ;
        while(index < n && citations[index] > index){
            index ++;
        }
        return citations[index-1];
        
        
    }
};