// https://leetcode.com/problems/fixed-point

class Solution {
public:
    int fixedPoint(vector<int>& arr) {
    int sz = arr.size();
       int start = -sz;
        int end =sz;
        cout<<"Before loop thing "<<start <<" "<<end<< endl;
       while(end -start >1){
           int mid =(start+end)/2;
           cout<<"mid is "<<mid<<endl;
           bool flag =(arr[mid]>=mid );
           cout <<"condition is "<<flag<<endl;
           ((arr[mid]>=mid)?end:start) = mid;
           cout<<"start is "<<start<<endl;
           cout<<"end is "<<end<<endl;
         }
        return ((end<(arr.size()-1) && arr[end] == end))?end:-1;
    };   
       
};