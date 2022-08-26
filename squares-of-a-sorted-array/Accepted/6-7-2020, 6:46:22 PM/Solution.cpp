// https://leetcode.com/problems/squares-of-a-sorted-array

class Solution {
public:
    vector<int> sortedSquares(vector<int>& a) {
        
        int n=a.size();
        vector <int> ans(n,0);
        int j=0;
        for(int i=0;i<n;i++){
            if(a[i]<0)
                j++;
        }
        int i=j-1;
        int t=0;
        cout<<"i is "<<i<<endl;
        cout<<"j is "<<j<<endl;
        while (i>=0 && j<n){
            if(a[i]*a[i]<a[j]*a[j]){
                ans[t++]=a[i]*a[i];
                i--;
            }
            else {
                ans[t++]=a[j]*a[j];
                j++;
            }
        }
        while(i>=0){
            ans[t++]=a[i]*a[i];
            i--;
        }
        while(j<n){
            ans[t++]=a[j]*a[j];
            j++;
        }
        return ans;
    }
};