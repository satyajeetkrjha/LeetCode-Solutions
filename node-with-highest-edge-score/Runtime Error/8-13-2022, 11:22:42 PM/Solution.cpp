// https://leetcode.com/problems/node-with-highest-edge-score


class Solution {
public:
    int scores[100005];
    
    int edgeScore(vector<int>& edges) {
       
         int n = edges.size();
        for(int i =0 ;i<edges.size();i++){
            scores[edges[i]]+= i;
        }
        /*
         for(int i =0 ;i<n;i++){
            cout << scores[i]<<" ";
        }
        cout << endl;
        */
        int ans = 0 ;
        int node=0 ;
        for(int i =n-1 ;i>=0;i--){
            if(scores[i]>=ans){
                ans = scores[i];
                node = i;
            }
        }
        
        
       
        
        return node ;
    }
};