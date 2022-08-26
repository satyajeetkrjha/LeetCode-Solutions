// https://leetcode.com/problems/sort-array-by-parity

class Solution {
public:
    void printvector (vector <int> v){
        for(int i=0;i<v.size();i++){
            cout<<v[i]<<" ";
        }
        cout<<endl;
    }
    vector<int> sortArrayByParity(vector<int>& A) {
        int n = A.size();
        int count =0;
        vector <int> result(n);
        for(int i=0;i<n;i++){
           // printvector(A);
            if(A[i]%2==0){
              //  cout<<"A[i] is "<<A[i]<<endl;
                result[count]=A[i];
                count++;
            }
        }
        for(int j=0;j<n;j++){
          //  printvector(A);
            if(A[j]%2!=0){
              //  cout<<"A[j] is "<<A[j]<<endl;
                result[count]=A[j];
                count++;
            }
        }
        return result;
    }
};