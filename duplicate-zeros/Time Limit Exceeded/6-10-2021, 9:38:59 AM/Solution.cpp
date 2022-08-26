// https://leetcode.com/problems/duplicate-zeros

class Solution {
public:
    void duplicateZeros(vector<int>& arr) {
       
        for(int i=0;i<arr.size();i++){ 
            int n = arr.size()-1;
            cout<<"arr.size() before is "<<arr.size()<<endl;
            cout<<"n is "<<n<<endl;
            if(arr[i] ==0){
                cout<<"starts"<<endl;
                while(n>i){
                    
                    cout<<"n is "<<n<<endl;
                    arr[n]=arr[n-1];
                    n--;
                }
                cout<<"ends"<<endl;
                i++;
            }
        }
        cout<<"arr.size() is "<<arr.size()<<endl;
    }
};