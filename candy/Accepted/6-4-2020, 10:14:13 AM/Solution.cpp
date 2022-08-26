// https://leetcode.com/problems/candy

//https://www.youtube.com/watch?v=h6_lIwZYHQw
class Solution {
public:
    int candy(vector<int>& ratings) {
        int n= ratings.size();
        int left[n+1];
        int right[n+1];
        for(int i=0;i<n;i++){
            left[i]=1;
            right[i]=1;
        }
        int ans =0;
        for(int i =1;i<n;i++){
            left[i]=(ratings[i]>ratings[i-1])?left[i-1]+1:left[i];
        }
       
        cout<<endl;
        for(int i=n-2;i>=0;i--){
            right[i]=(ratings[i]>ratings[i+1])?right[i+1]+1:right[i];
        }
        
         for(int i=0;i<n;i++){
            cout<<left[i]<<" ";
        }
        cout<<endl;
        for(int i=0;i<n;i++){
            cout<<right[i]<<" ";
        }
        cout<<endl;
        for(int i=0;i<n;i++){
            ans+=max(left[i],right[i]);
        }
        return ans;
    }
};