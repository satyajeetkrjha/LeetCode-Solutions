// https://leetcode.com/problems/maximum-points-you-can-obtain-from-cards

class Solution {
public:
    int maxScore(vector<int>& cardPoints, int k) {
        int n =cardPoints.size();
        int front[k+5];
        int back[k+5];
        for(int i=0;i<k+1;i++){
            front[i]=0;
            back[i]=0;
        }
        // a0 a1 a2 a3 a4 a5 a6 a7
        // front contains a0+a1+a2
        //back contians   a7+a6+5
        // we test which is max out of (a0,a7,a6) or (a0,a1,a7) ...
        for(int i=0;i<k;i++){
            front[i+1]= front[i]+cardPoints[i];
            back[i+1] =back[i]+cardPoints[n-i-1];
        }
        for(int i=0;i<k;i++){
            cout<<"val1 "<<front[i]<<endl;
            cout<<"val2 "<<back[i]<<endl;
        }
        int maxsum =INT_MIN;
        for(int i=0;i<k;i++){
            cout<<"front[i]+back[k-i] is "<<front[i]+back[k-i]<<endl;
            maxsum =max(maxsum,front[i]+back[k-i]);
        }
        return maxsum;
    }
};