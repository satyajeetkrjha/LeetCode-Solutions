// https://leetcode.com/problems/minimum-add-to-make-parentheses-valid

/*

Keep adding 1 when you see ( and subtracting 1 if you see ).
If it goes below 0 then you have an unmatched close
Whick you need to match with a new open
Then whatever number you have in the end, that many need to be closed
me :how does ur algo work if i got open brackets but now ur count is not going negative
Positive count at end of scan gives number of( that remain to be closed
me : see we return count
me :What if i have just )))
if u have all ))) then bring count back to 0 but ans is incremented
*/
class Solution {
public:
    int count =0;
    int ans =0;
    int minAddToMakeValid(string s) {
        for(auto &ch:s){
            if(ch == '('){
                count ++;
            }
            else if(ch == ')'){
                count --;
            }
            
            if(count <0){
                ans ++;
                count =0;
            }
        }
        return ans + count ;
    }
};