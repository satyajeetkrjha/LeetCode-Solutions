// https://leetcode.com/problems/counting-elements

class Solution {
public:
    int countElements(vector<int>& arr) {
        set <int> s;
        for(int i=0;i<arr.size();i++){
            s.insert(arr[i]);
        }
        int count =0;
        for(int i=0;i<arr.size();i++){
            int x = arr[i];
            // now check if x+ 1 is in the hashset or not
            if(s.count(x+1)>0){
                count++;
            }
        }
        return count ;
    }
};