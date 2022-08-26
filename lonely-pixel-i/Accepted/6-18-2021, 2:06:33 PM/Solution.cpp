// https://leetcode.com/problems/lonely-pixel-i

class Solution {
    
public:
    
    
    int findLonelyPixel(vector<vector<char>>& picture) {
        //count number of Bs in each row and column
     //then do another sweep and every time you see a B, check if its row and column counts are 1
        int R= picture.size();
        int C = picture[0].size();
       vector <int> cnt1(R+1);
        vector <int> cnt2(C+1);
        for(int i=0;i<R;i++){
            for(int j=0;j<C;j++){
                if(picture[i][j] =='B'){
                    ++cnt1[i];
                    ++cnt2[j];
                }
            }
        }
        for(int i =0 ;i<R;i++){
            cout<<cnt1[i]<<" ";
        }
        cout<<endl;
        for(int j=0;j<C;j++){
            cout<<cnt2[j]<<" ";
        }
        cout<<endl;
        int ans =0;
        for(int i=0;i<R;i++){
            for(int j =0;j<C;j++){
                if(picture[i][j] == 'B' && cnt1[i] == 1 && cnt2[j] ==1){
                    ans++;
                }
            }
        }
        return ans;
    }
};