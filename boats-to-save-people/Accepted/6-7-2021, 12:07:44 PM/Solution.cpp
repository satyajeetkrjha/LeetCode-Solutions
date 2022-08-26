// https://leetcode.com/problems/boats-to-save-people

class Solution {
public:
    int numRescueBoats(vector<int>& people, int limit) {
      sort(people.begin(),people.end());
        int i =0;
        int j = people.size()-1;
        int result =0;
        while(i<=j){
            result ++;
            if(people[i]+people[j]<=limit){
                i++;
               
            }
            j--;
        }
        return result ;
    }
};